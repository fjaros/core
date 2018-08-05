
#include "scriptPCH.h"
#include "deadmines.h"

enum
{

};

struct boss_vancleefAI : public ScriptedAI
{

    boss_vancleefAI(Creature* pCreature) : ScriptedAI(pCreature)
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
