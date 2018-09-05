#include "scriptPCH.h"
#include "deadmines.h"

enum eSpells
{
    SPELL_CONSUMING_SHADOWS = 17716,               // Consuming Shadows aura proc
    SPELL_MARK_OF_KAZZAK = 21056,                  // Mark of Kazzak mana leech
    SPELL_SHADOWBOLT_VOLLEY = 28407,               // Shadowbolt Volley
    SPELL_SHADOWWORD_PAIN = 24212                  // SWP DoT
};

enum eEvents
{
    EVENT_CONSUMING_SHADOWS = 1,
    EVENT_MARK_OF_KAZZAK = 2,
    EVENT_SHADOWBOLT_VOLLEY = 3,
    EVENT_SHADOWWORD_PAIN = 4
};

struct boss_johnsonAI : public ScriptedAI
{
    explicit boss_johnsonAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        boss_johnsonAI::Reset();
    }

    void Reset() override
    {
        m_Events.Reset();
        m_Events.ScheduleEvent(eEvents::EVENT_CONSUMING_SHADOWS, Seconds(2));
        m_Events.ScheduleEvent(eEvents::EVENT_MARK_OF_KAZZAK, Seconds(urand (10, 20)));
        m_Events.ScheduleEvent(eEvents::EVENT_SHADOWBOLT_VOLLEY, Seconds(urand(10, 20)));
        m_Events.ScheduleEvent(eEvents::EVENT_SHADOWWORD_PAIN, Seconds(urand(10, 20)));
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
            case eEvents::EVENT_CONSUMING_SHADOWS:
            {
                DoCastSpellIfCan(m_creature, eSpells::SPELL_CONSUMING_SHADOWS, CF_AURA_NOT_PRESENT);
                m_Events.Repeat(Seconds(2));
                break;
            }
            case eEvents::EVENT_MARK_OF_KAZZAK:
            {
                auto l_Target = me->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
                DoCastSpellIfCan(l_Target, eSpells::SPELL_MARK_OF_KAZZAK, CF_AURA_NOT_PRESENT);
                m_Events.Repeat(Seconds(urand(10, 20)));
                break;
            }
            case eEvents::EVENT_SHADOWBOLT_VOLLEY:
            {
                auto l_Target = me->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 0);
                DoCastSpellIfCan(m_creature, eSpells::SPELL_SHADOWBOLT_VOLLEY, CF_TRIGGERED);
                m_Events.Repeat(Seconds(urand(10, 20)));
                break;
            }
            case eEvents::EVENT_SHADOWWORD_PAIN:
            {
                for (int i = 0; i < 4; i++)
                {
                    auto l_Target = me->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
                    DoCastSpellIfCan(l_Target, eSpells::SPELL_SHADOWWORD_PAIN, CF_AURA_NOT_PRESENT + CF_TRIGGERED);
                }
                m_Events.Repeat(Seconds(urand(10, 20)));
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

CreatureAI* GetAI_boss_johnson(Creature* pCreature)
{
    return new boss_johnsonAI(pCreature);
}

void AddSC_boss_johnson()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_johnson";
    newscript->GetAI = &GetAI_boss_johnson;
    newscript->RegisterSelf();
}
