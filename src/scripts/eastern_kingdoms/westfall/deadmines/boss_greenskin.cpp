#include "scriptPCH.h"
#include "deadmines.h"

enum eSpells
{
    SPELL_HEAL = 25807,
    SPELL_BLOODLUST = 24185,
    SPELL_POISON_VOLLEY = 24099,
    SPELL_MUTATING_INJECTION = 28169,
    SPELL_GRASPING_VINES = 22924
};

enum eEvents
{
    EVENT_HEAL = 1,
    EVENT_BLOODLUST = 2,
    EVENT_POISON_VOLLEY = 3,
    EVENT_MUTATING_INJECTION = 4,
    EVENT_GRASPING_VINES = 5
};

struct boss_greenskinAI : public ScriptedAI
{
    explicit boss_greenskinAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        boss_greenskinAI::Reset();
    }

    void Reset() override
    {
        m_Events.Reset();
        m_Events.ScheduleEvent(eEvents::EVENT_HEAL, Seconds(8));
        m_Events.ScheduleEvent(eEvents::EVENT_BLOODLUST, Seconds(urand(10, 20)));
        m_Events.ScheduleEvent(eEvents::EVENT_POISON_VOLLEY, Seconds(urand(10, 15)));
        m_Events.ScheduleEvent(eEvents::EVENT_MUTATING_INJECTION, Seconds(urand(5, 10)));
        m_Events.ScheduleEvent(eEvents::EVENT_GRASPING_VINES, (Seconds(10)));
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
            case eEvents::EVENT_HEAL:
            {
                DoCastSpellIfCan(m_creature, eSpells::SPELL_HEAL, CF_FORCE_CAST);
                m_Events.Repeat(Seconds(8));
                break;
            }
            case eEvents::EVENT_BLOODLUST:
            {
                DoCastSpellIfCan(m_creature, eSpells::SPELL_BLOODLUST, CF_FORCE_CAST);
                m_Events.Repeat(Seconds(urand(10, 20)));
                break;
            }
            case eEvents::EVENT_POISON_VOLLEY:
            {
                auto l_Target = me->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
                DoCastSpellIfCan(l_Target, eSpells::SPELL_POISON_VOLLEY, CF_TRIGGERED);
                m_Events.Repeat(Seconds(urand(10, 15)));
                break;
            }
            case eEvents::EVENT_MUTATING_INJECTION:
            {
                auto l_Target = me->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
                DoCastSpellIfCan(l_Target, eSpells::SPELL_MUTATING_INJECTION, CF_TRIGGERED + CF_FORCE_CAST);
                m_Events.Repeat(Seconds(urand(5, 10)));
                break;
            }
            case eEvents::EVENT_GRASPING_VINES:
            {
                DoCastSpellIfCan(m_creature, eSpells::SPELL_GRASPING_VINES, CF_TRIGGERED + CF_FORCE_CAST);
                m_Events.Repeat(Seconds(10));
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

CreatureAI* GetAI_boss_greenskin(Creature* pCreature)
{
    return new boss_greenskinAI(pCreature);
}

void AddSC_boss_greenskin()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_greenskin";
    newscript->GetAI = &GetAI_boss_greenskin;
    newscript->RegisterSelf();
}
