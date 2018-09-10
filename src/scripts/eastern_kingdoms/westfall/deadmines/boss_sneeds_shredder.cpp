
#include "scriptPCH.h"
#include "deadmines.h"

enum
{
    SAY_TERMINATING = -2000002,
    SPELL_SNEED_ID = 5141,
    SPELL_SNEED_FLAGS = 7,
    SPELL_PIERCE_ARMOR = 6016,
    SPELL_LIVING_BOMB = 20475
};

struct boss_sneeds_shredderAI : public ScriptedAI
{
    uint32 m_base_Attack_Timer;
    uint32 m_Terminating_Timer;
    uint32 m_Pierce_Timer;
    bool m_isTerminating;
    uint32 m_Recharging_Timer;
    uint32 m_Living_Bomb_Timer;
    
    boss_sneeds_shredderAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_base_Attack_Timer = m_creature->GetFloatValue(UNIT_FIELD_BASEATTACKTIME + BASE_ATTACK);

        Reset();
    }
    
    void Reset()
    {
        m_Living_Bomb_Timer = 7000;
        m_Terminating_Timer = 10000;
        m_Pierce_Timer = 10000; //lets start off with a faster pierce, force a tank cd off the bat
        m_isTerminating = false;
        m_Recharging_Timer = 2000;
        m_creature->setAttackTimer(BASE_ATTACK, m_base_Attack_Timer);
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;
        
        if (m_Living_Bomb_Timer < diff)
        {
            Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER);
            if (pTarget && DoCastSpellIfCan(pTarget, SPELL_LIVING_BOMB) == CAST_OK)
                m_Living_Bomb_Timer = 9000;
        }
        else
            m_Living_Bomb_Timer -= diff;
        
        if (m_isTerminating)
        {
            if (m_Terminating_Timer < diff)
            {
                m_creature->SetFloatValue(UNIT_FIELD_BASEATTACKTIME + BASE_ATTACK, m_base_Attack_Timer);
                m_Terminating_Timer = 10000;
                m_isTerminating = false;
            }
            else
                m_Terminating_Timer -= diff;	// otherwise decrease the timer
        }
        else
        {
            if (m_Recharging_Timer < diff)	//recharged, lets terminate
            {
                DoScriptText(SAY_TERMINATING, m_creature);
                m_creature->SetFloatValue(UNIT_FIELD_BASEATTACKTIME + BASE_ATTACK, 300);
                m_Recharging_Timer = 12000;
                m_isTerminating = true;
            }
            else
                m_Recharging_Timer -= diff;
        }

        if (m_Pierce_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->getVictim(), SPELL_PIERCE_ARMOR) == CAST_OK)
                m_Pierce_Timer = 10000;
        }
        else
            m_Pierce_Timer -= diff;

        DoMeleeAttackIfReady();
    }
    
    void JustDied(Unit *pKiller)
    {
        // Cast spell eject sneed
        DoCastSpellIfCan(m_creature, SPELL_SNEED_ID, SPELL_SNEED_FLAGS, m_creature->GetGUID());
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
