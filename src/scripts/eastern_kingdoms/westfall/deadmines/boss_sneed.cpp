
#include "scriptPCH.h"
#include "deadmines.h"

enum
{

};

struct boss_sneedAI : public ScriptedAI
{
    
    boss_sneedAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }
    
    void Reset()
    {

    }
    
    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;
    }
};

CreatureAI* GetAI_boss_sneed(Creature* pCreature)
{
    return new boss_sneedAI(pCreature);
}

void AddSC_boss_sneed()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_sneed";
    newscript->GetAI = &GetAI_boss_sneed;
    newscript->RegisterSelf();
}
