
#include "scriptPCH.h"
#include "deadmines.h"

enum
{
    SAY_TERMINATING = -2000002
};

struct boss_sneeds_shredderAI : public ScriptedAI
{
    uint32 m_base_Attack_Timer;
    uint32 m_Terminating_Timer;
    bool m_isTerminating;
    uint32 m_Recharging_Timer;
    
    boss_sneeds_shredderAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_base_Attack_Timer = m_creature->GetFloatValue(UNIT_FIELD_BASEATTACKTIME + BASE_ATTACK);

        Reset();
    }
    
    void Reset()
    {
        m_Terminating_Timer = 10000;
        m_isTerminating = false;
        m_Recharging_Timer = 0;
        m_creature->setAttackTimer(BASE_ATTACK, m_base_Attack_Timer);
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;
        
        if (m_isTerminating)
        {
            if (m_Recharging_Timer < diff)
            {
                m_Terminating_Timer = urand(12000, 15000);
                m_isTerminating = false;
            }
            else
                m_Recharging_Timer -= diff;
        }
        else
            m_creature->SetFloatValue(UNIT_FIELD_BASEATTACKTIME + BASE_ATTACK, m_base_Attack_Timer);
        
        if (m_Terminating_Timer < diff)
        {
            DoScriptText(SAY_TERMINATING, m_creature);
            m_creature->SetFloatValue(UNIT_FIELD_BASEATTACKTIME + BASE_ATTACK, 500);
            m_Terminating_Timer = 20000;
            m_isTerminating = true;
            m_Recharging_Timer = 6000;
        }
        else
            m_Terminating_Timer -= diff;
        
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_sneeds_shredder(Creature* pCreature)
{
    return new boss_sneeds_shredderAI(pCreature);
}

void AddSC_boss_sneeds_shredder()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_sneeds_shredder";
    newscript->GetAI = &GetAI_boss_sneeds_shredder;
    newscript->RegisterSelf();
}
