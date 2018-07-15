
#include "scriptPCH.h"
#include "deadmines.h"

enum
{
    SAY_COOKIE = -2000003
};

struct boss_cookieAI : public ScriptedAI
{
    uint32 m_cone_Timer;
    uint32 m_spawn_Timer;
    
    boss_cookieAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }
    
    void Reset()
    {
        m_cone_Timer = 10000;
        m_spawn_Timer = 17000;
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;
        
//        if (m_cone_Timer < diff)
//        {
//            
//        }
//        else
//            m_cone_Timer -= diff;
//        
//        if (m_spawn_Timer < diff)
//        {
//            ThreatList const& tList = m_creature->getThreatManager().getThreatList();
//            for (ThreatList::const_iterator i = tList.begin(); i != tList.end(); ++i)
//            {
//                Unit* pTarget = m_creature->GetMap()->GetUnit((*i)->getUnitGuid());
//
//                if (pTarget && m_creature->IsInRange(pTarget, min, max))
//                    return pTarget;
//            }
//        }
//        else
//            m_spawn_Timer -= diff;
        
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_cookiAI(Creature* pCreature)
{
    return new boss_cookieAI(pCreature);
}

void AddSC_boss_cookie()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_cookie";
    newscript->GetAI = &GetAI_boss_cookiAI;
    newscript->RegisterSelf();
}
