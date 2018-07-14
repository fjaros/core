
#include "scriptPCH.h"
#include "deadmines.h"

enum
{
    SPELL_THROW_LIQUID_FIRE = 23970
};

struct boss_gilnidAI : public ScriptedAI
{
    
    uint32 m_liquidFire_Timer;
    
    boss_gilnidAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }
    
    void Reset()
    {
        m_liquidFire_Timer = 10000;
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;
        
        if (m_liquidFire_Timer < diff)
        {
            ThreatList const& tList = m_creature->getThreatManager().getThreatList();
            for (ThreatList::const_iterator i = tList.begin(); i != tList.end(); ++i)
            {
                Unit* attacker = m_creature->GetMap()->GetUnit((*i)->getUnitGuid());
                
                DoCastSpellIfCan(attacker, SPELL_THROW_LIQUID_FIRE);
            }
            
            m_liquidFire_Timer = urand(6000, 9000);
        }
        else
            m_liquidFire_Timer -= diff;
        
        DoMeleeAttackIfReady();
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
