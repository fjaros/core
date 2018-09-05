
#include "scriptPCH.h"
#include "deadmines.h"

enum
{
    SAY_SUMMON = 1048,
    SAY_AGGRO = 6061,
    SAY_KILL = 6062,
    SAY_HEALTH_75 = 6063,
    SAY_HEALTH_35 = 6064,
    SAY_HEALTH_10 = 6065,
    SPELL_HAMSTRING = 9080,
    SPELL_CANNON_FIRE = 17501,
    SPELL_ENGULFING_FLAMES = 20019
};

struct boss_vancleefAI : public ScriptedAI
{
    bool summon[9];
    bool said75;
    bool said35;
    bool said10;
    uint32 m_Cannon_Fire_Timer;
    uint32 m_Hamstring_Timer;

    boss_vancleefAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    void Reset()
    {
        said75 = false;
        said35 = false;
        said10 = false;
        for (int i = 0; i != 9; i++)
            summon[i] = false;
        m_Cannon_Fire_Timer = 9000;
        m_Hamstring_Timer = 5000;
    }

    void Aggro(Unit* pWho)
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void KilledUnit(Unit* pVictim)
    {
        DoScriptText(SAY_KILL, m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        if (m_Cannon_Fire_Timer < diff)
        {
            Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
            if (pTarget)
            {
                std::vector<Unit*> nearbyTargets = GetNearbyTargets(pTarget, 4.0f);
                if (DoCastSpellIfCan(pTarget, SPELL_CANNON_FIRE) == CAST_OK)
                {
                    for (Unit *nearbyTarget : nearbyTargets)
                        DoCastSpellIfCan(nearbyTarget, SPELL_CANNON_FIRE, CF_TRIGGERED);
                    m_Cannon_Fire_Timer = urand(8000, 12000);
                }
            }
        }
        else
            m_Cannon_Fire_Timer -= diff;

        if (m_Hamstring_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->getVictim(), SPELL_HAMSTRING) == CAST_OK)
                m_Hamstring_Timer = urand(8000, 12000);
        }
        else
            m_Hamstring_Timer -= diff;

        if (!said75 && m_creature->GetHealthPercent() <= 75.0) {
            DoScriptText(SAY_HEALTH_75, m_creature);
            said75 = true;
        }

        if (!said35 && m_creature->GetHealthPercent() <= 35.0) {
            DoScriptText(SAY_HEALTH_35, m_creature);
            said35 = true;
        }

        if (!said10 && m_creature->GetHealthPercent() <= 10.0) {
            DoScriptText(SAY_HEALTH_10, m_creature);
            said10 = true;
        }

        for (int i = 0; i != 9; i++)
        {
            if (!summon[i] && m_creature->GetHealthPercent() <= 10 * (i + 1))
                summonAllies(i);
        }

        DoMeleeAttackIfReady();
    }

    void SpellHitTarget(Unit* target, const SpellEntry* spell)
    {
        // Trigger bomb AoE on the ground
        if (target && spell && spell->Id == SPELL_CANNON_FIRE)
        {
            if (DoCastSpellIfCan(target, SPELL_ENGULFING_FLAMES, CF_TRIGGERED) == CAST_OK)
            {
                if (m_creature->getThreatManager().getThreat(target))
                    m_creature->getThreatManager().modifyThreatPercent(target, -100);
            }
        }
    }

    std::vector<Unit*> GetNearbyTargets(Unit *target, float radius)
    {
        std::vector<Unit*> units;

        ThreatList const& tList = m_creature->getThreatManager().getThreatList();
        for (ThreatList::const_iterator i = tList.begin(); i != tList.end(); ++i)
        {
            Unit* pTarget = m_creature->GetMap()->GetUnit((*i)->getUnitGuid());
            if (pTarget && pTarget->GetDistance(target) <= radius)
                units.push_back(pTarget);
        }

        return units;
    }

    void summonAllies(int which)
    {
        DoScriptText(SAY_SUMMON, m_creature);
        m_creature->SummonCreature(636,
                m_creature->GetPositionX() - 2, m_creature->GetPositionY(), m_creature->GetPositionZ(),
                0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
        m_creature->SummonCreature(636,
                m_creature->GetPositionX() + 2, m_creature->GetPositionY(), m_creature->GetPositionZ(),
                0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
        summon[which] = true;
    }
};

CreatureAI* GetAI_boss_vancleef(Creature* pCreature)
{
    return new boss_vancleefAI(pCreature);
}

void AddSC_boss_vancleef()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_vancleef";
    newscript->GetAI = &GetAI_boss_vancleef;
    newscript->RegisterSelf();
}
