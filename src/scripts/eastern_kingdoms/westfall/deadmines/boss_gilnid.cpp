
#include "scriptPCH.h"
#include "deadmines.h"

enum
{
    SAY_PHASE_TWO = -2000007,
    SPELL_MOLTEN_METAL = 5213,
    SPELL_THROW_LIQUID_FIRE = 23970,
    SPELL_BOMB = 19629,
    SPELL_ARCANEEXPLOSION = 19712
};

struct boss_gilnidAI : public ScriptedAI
{
    int phase;
    uint32 m_moltenMetal_Timer;
    uint32 m_Aoe_Timer;
    uint32 m_Infernal_Timer;
    
    boss_gilnidAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }
    
    void Reset()
    {
        m_moltenMetal_Timer = 4000;
        m_Aoe_Timer = 9000;
        m_Infernal_Timer = 12000;
        phase = 1;
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        if (phase == 1 && m_creature->GetHealthPercent() <= 40.0f)
        {
            DoScriptText(SAY_PHASE_TWO, m_creature);
            m_Aoe_Timer = 7000;
            phase = 2;
        }
        
        if (m_moltenMetal_Timer < diff)
        {
            if (Unit* pUnit = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (DoCastSpellIfCan(pUnit, SPELL_MOLTEN_METAL, CF_TRIGGERED) == CAST_OK)
                    m_moltenMetal_Timer = 4000;
            }
        }
        else
            m_moltenMetal_Timer -= diff;
        
        if (m_Aoe_Timer < diff)
        {
            switch (phase) {
                case 1:
                    if (DoCastSpellIfCan(m_creature->getVictim(), SPELL_THROW_LIQUID_FIRE) == CAST_OK)
                    {
                        ThreatList const& tList = m_creature->getThreatManager().getThreatList();
                        for (ThreatList::const_iterator i = tList.begin(); i != tList.end(); ++i)
                        {
                            Unit* attacker = m_creature->GetMap()->GetUnit((*i)->getUnitGuid());
                            if (urand(1, 100) <= 50)
                                DoCastSpell(attacker, sSpellMgr.GetSpellEntry(SPELL_THROW_LIQUID_FIRE), true);
                        }
                    }
                    break;
                case 2:
                    ThreatList const& tList = m_creature->getThreatManager().getThreatList();
                    for (ThreatList::const_iterator i = tList.begin(); i != tList.end(); ++i)
                    {
                        Unit* attacker = m_creature->GetMap()->GetUnit((*i)->getUnitGuid());
                        if (urand(1, 100) <= 50)
                            DoCastSpell(attacker, sSpellMgr.GetSpellEntry(SPELL_ARCANEEXPLOSION), true);
                    }
                    break;
            }
            m_Aoe_Timer = urand(8000, 12000);
        }
        else
            m_Aoe_Timer -= diff;

        if (phase == 2)
            if (m_Infernal_Timer < diff)
            {
                std::vector<Unit*> attackers = RandomPlayers(50.0f);
                for (Unit* attacker : attackers)
                {
                    m_creature->SummonCreature(14668,
                        attacker->GetPositionX(),
                        attacker->GetPositionY(),
                        attacker->GetPositionZ(),
                        attacker->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                }
                m_Infernal_Timer = 20000;
            }
            else
                m_Infernal_Timer -= diff;
        
        DoMeleeAttackIfReady();
    }

    std::vector<Unit*> RandomPlayers(float percentage)
    {
        std::vector<Unit*> allPlayers;
        std::vector<Unit*> randomPlayers;

        ThreatList const& tList = m_creature->getThreatManager().getThreatList();
        for (ThreatList::const_iterator i = tList.begin(); i != tList.end(); ++i)
            allPlayers.push_back(m_creature->GetMap()->GetUnit((*i)->getUnitGuid()));

        if (allPlayers.empty())
            return randomPlayers;

        int howMany = std::max(1, (int)(allPlayers.size() * (percentage / 100)));
        for (int i = 0; i != howMany; i++)
        {
            int place = rand() % allPlayers.size();
            randomPlayers.push_back(allPlayers[place]);
            allPlayers.erase(allPlayers.begin() + place);
        }

        return randomPlayers;
    }
    
    void SpellHitTarget(Unit* target, const SpellEntry* spell)
    {
        // Trigger bomb AoE on the ground
        if (target && spell && spell->Id == SPELL_THROW_LIQUID_FIRE)
            m_creature->CastSpell(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), SPELL_BOMB, false);
    }
};

CreatureAI* GetAI_boss_gilnid(Creature* pCreature)
{
    return new boss_gilnidAI(pCreature);
}

void AddSC_boss_gilnid()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_gilnid";
    newscript->GetAI = &GetAI_boss_gilnid;
    newscript->RegisterSelf();
}
