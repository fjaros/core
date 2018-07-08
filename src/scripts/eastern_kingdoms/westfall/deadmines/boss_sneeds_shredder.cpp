
#include "scriptPCH.h"
#include "deadmines.h"

enum
{

};

struct boss_sneeds_shredderAI : public ScriptedAI
{
    
    boss_sneeds_shredderAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }
    
    void Reset()
    {

    }
    
    void Aggro(Unit* pWho)
    {
        DoScriptText(AGGRO_YELL, m_creature);
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;
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
