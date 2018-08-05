
#include "scriptPCH.h"
#include "deadmines.h"

enum
{
    SPELL_MOLTEN_METAL = 5213,
    SPELL_THROW_LIQUID_FIRE = 23970,
    SPELL_BOMB = 19629
};

struct boss_gilnidAI : public ScriptedAI
{
    uint32 m_moltenMetal_Timer;
    uint32 m_liquidFire_Timer;
    
    boss_gilnidAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }
    
    void Reset()
    {
        m_liquidFire_Timer = 7000;
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;
        
        if (m_moltenMetal_Timer < diff)
        {
            if (Unit* pUnit = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (DoCastSpellIfCan(pUnit, SPELL_MOLTEN_METAL) == CAST_OK)
                    m_moltenMetal_Timer = urand(4000, 5000);
            }
        }
        else
            m_moltenMetal_Timer -= diff;
        
        if (m_liquidFire_Timer < diff)
        {           
            if (DoCastSpellIfCan(m_creature->getVictim(), SPELL_THROW_LIQUID_FIRE) == CAST_OK)
            {
                ThreatList const& tList = m_creature->getThreatManager().getThreatList();
                for (ThreatList::const_iterator i = tList.begin(); i != tList.end(); ++i)
                {
                    Unit* attacker = m_creature->GetMap()->GetUnit((*i)->getUnitGuid());
                    if (urand(1, 100) <= 50)
                        DoCastSpell(attacker, sSpellMgr.GetSpellEntry(SPELL_THROW_LIQUID_FIRE), true);
                }
                m_liquidFire_Timer = urand(6000, 8000);
            }
        }
        else
            m_liquidFire_Timer -= diff;
        
        DoMeleeAttackIfReady();
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
