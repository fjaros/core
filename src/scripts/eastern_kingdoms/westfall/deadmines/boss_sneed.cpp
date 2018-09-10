/*
*  Script rewritten by Cabbage for The Construct
*/

#include "scriptPCH.h"
#include "deadmines.h"

enum eSpells
{
    SAY_END_COMBAT = -2000008,
    SPELL_MC_ARUGAL = 7621,                //    Arugal's Curse
    SPELL_MC_INSANITY = 24327,             //    Cause Insanity
    SPELL_MC_DOMINATE = 20740,             //    Dominate Mind
    SPELL_CURSE_LUCIFRON = 19703           //    Lucifron's Curse
};

enum eEvents
{
    EVENT_MC_ARUGAL = 1,
    EVENT_MC_INSANITY = 2,
    EVENT_MC_DOMINATE = 3,
    EVENT_CURSE_LUCIFRON = 4
};

struct boss_sneedAI : public ScriptedAI
{
    explicit boss_sneedAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        boss_sneedAI::Reset();
    }

    void Reset() override
    {  
        m_Events.Reset();
        m_Events.ScheduleEvent(eEvents::EVENT_MC_ARUGAL, Seconds(10));
        m_Events.ScheduleEvent(eEvents::EVENT_MC_INSANITY, Seconds(10));
        m_Events.ScheduleEvent(eEvents::EVENT_MC_DOMINATE, Seconds(10));
        m_Events.ScheduleEvent(eEvents::EVENT_CURSE_LUCIFRON, Seconds(15));
    }
    
    void EnterEvadeMode() override
    {
        ScriptedAI::EnterEvadeMode();
        
        Creature *shredder = m_creature->FindNearCreature(79223, 1000.0f);
        if (shredder->isDead())
        {
            DoScriptText(SAY_END_COMBAT, m_creature);
            shredder->Respawn();
            m_creature->DespawnOrUnsummon();
        }
    }

    void UpdateAI(const uint32 p_Diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;

        m_Events.Update(p_Diff);
        while (auto l_EventId = m_Events.ExecuteEvent())
        {
            switch (l_EventId)
            {
                case eEvents::EVENT_MC_ARUGAL:
                {
                    if (auto l_Target = me->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                    {
                        DoCastSpellIfCan(l_Target, eSpells::SPELL_MC_ARUGAL, CF_TRIGGERED);
                        m_Events.Repeat(Seconds(10));
                    }
                    break;
                }
                case eEvents::EVENT_MC_INSANITY:
                {
                    if (auto l_Target = me->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 0))
                    {
                        DoCastSpellIfCan(l_Target, eSpells::SPELL_MC_INSANITY, CF_TRIGGERED);
                        m_Events.Repeat(Seconds(10));
                    }
                    break;
                }
                case eEvents::EVENT_MC_DOMINATE:
                {
                    if (auto l_Target = me->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                    {
                        DoCastSpellIfCan(l_Target, eSpells::SPELL_MC_DOMINATE, CF_TRIGGERED);
                        m_Events.Repeat(Seconds(10));
                    }
                    break;
                }
                case eEvents::EVENT_CURSE_LUCIFRON:
                {
                    if (DoCastSpellIfCan(m_creature, eSpells::SPELL_CURSE_LUCIFRON, CF_TRIGGERED) == CAST_OK)
                        m_Events.Repeat(Seconds(15));
                    else
                        m_Events.Repeat(Milliseconds(100));
                    break;
                }
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    EventMap m_Events;
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
