
#include "scriptPCH.h"
#include "deadmines.h"

enum
{
    SAY_COOKIE_START = -2000003,
    SAY_COOKIE_WIPE = -2000004,
    SAY_COOKIE_END = -2000005,
    SPELL_ACID_SPLASH = 6306,
    SPELL_MORTAL_STRIKE = 24573,
    SPELL_MASSIVEGEYSER = 22421
};

struct boss_cookieAI : public ScriptedAI
{
    uint32 m_acid_splash_Timer;
    uint32 m_mortal_strike_Timer;
    uint32 m_geyser_Timer;
    uint32 m_spawn_Timer;
    
    boss_cookieAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }
    
    void Reset()
    {
        m_acid_splash_Timer = 3000;
        m_mortal_strike_Timer = 10000;
        m_geyser_Timer = 16000;
    }
    
    void Aggro(Unit* pWho)
    {
        DoScriptText(SAY_COOKIE_START, m_creature);
    }
    
    void OnCombatStop()
    {
        DoScriptText(SAY_COOKIE_WIPE, m_creature);
        ScriptedAI::OnCombatStop();
    }
    
    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_COOKIE_END, m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;
        
        if (m_acid_splash_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->getVictim(), SPELL_ACID_SPLASH) == CAST_OK)
                m_acid_splash_Timer = urand(3000, 5000);
        }
        else
            m_acid_splash_Timer -= diff;
        
        if (m_mortal_strike_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->getVictim(), SPELL_MORTAL_STRIKE) == CAST_OK)
                m_mortal_strike_Timer = urand(8000, 11000);
        }
        else
            m_mortal_strike_Timer -= diff;
        
        if (m_geyser_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->getVictim(), SPELL_MASSIVEGEYSER) == CAST_OK)
            {
                ThreatList const& tList = m_creature->getThreatManager().getThreatList();
                for (ThreatList::const_iterator i = tList.begin(); i != tList.end(); ++i)
                {
                    Unit* attacker = m_creature->GetMap()->GetUnit((*i)->getUnitGuid());
                    if (urand(1, 100) <= 67)
                        DoCastSpell(attacker, sSpellMgr.GetSpellEntry(SPELL_MASSIVEGEYSER), true);
                    
                    DoResetThreat();
                }
                m_geyser_Timer = urand(15000, 18000);
            }
        }
        else 
            m_geyser_Timer -= diff;
        
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_cookieAI(Creature* pCreature)
{
    return new boss_cookieAI(pCreature);
}

void AddSC_boss_cookie()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_cookie";
    newscript->GetAI = &GetAI_boss_cookieAI;
    newscript->RegisterSelf();
}
