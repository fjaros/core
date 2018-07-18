
#include "scriptPCH.h"
#include "deadmines.h"

enum
{
    AGGRO_YELL = 5619,
    SAY_CHARGE = -2000001,
    SPELL_CHARGE = 24408,
    SPELL_CLEAVE = 15284
};

struct boss_rhahkzorAI : public ScriptedAI
{
    uint32 m_uiCleave_Timer;
    uint32 m_uiSayCharge_Timer;
    uint32 m_uiCharge_Timer;
    uint64 m_chargeTarget;
    std::set<uint64> m_alreadyCharged;
    
    boss_rhahkzorAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }
    
    void Reset()
    {
        m_uiCharge_Timer = 19000;
        m_uiSayCharge_Timer = m_uiCharge_Timer - 3000;
        m_chargeTarget = 0;
        m_alreadyCharged.clear();
    }
    
    void Aggro(Unit* pWho)
    {
        DoScriptText(AGGRO_YELL, m_creature);
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->getVictim())
            return;
        
        if (m_uiCleave_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->getVictim(), SPELL_CLEAVE);
            m_uiCleave_Timer = urand(5000, 7000);
        }
        else
            m_uiCleave_Timer -= diff;
        
        if (m_uiSayCharge_Timer < diff) 
        {
            if (Unit* pTarget = m_creature->GetFarthestVictimInRange(0.0f, 40.0f))
            {
                if (Player* pPlayer = pTarget->GetCharmerOrOwnerPlayerOrPlayerItself())
                {
                    DoScriptText(SAY_CHARGE, m_creature, pTarget);
                    m_chargeTarget = pTarget->GetGUID();
                    m_uiSayCharge_Timer = 20000;
                }
            }
        }
        else
            m_uiSayCharge_Timer -= diff;
        
        if (m_uiCharge_Timer < diff) 
        {
            if (Unit* pTarget = GetFinalTarget())
            {
                if (Player* pPlayer = pTarget->GetCharmerOrOwnerPlayerOrPlayerItself())
                {
                    DoCastSpellIfCan(pPlayer, SPELL_CHARGE);
                    if (m_alreadyCharged.find(pPlayer->GetGUID()) != m_alreadyCharged.end())
                    {
                        m_creature->DoKillUnit(pPlayer);
                        m_alreadyCharged.erase(pPlayer->GetGUID());
                    }
                    else
                        m_alreadyCharged.insert(pPlayer->GetGUID());
                }
            }
            m_uiCharge_Timer = urand(18000, 22000);
            m_uiSayCharge_Timer = m_uiCharge_Timer - 3000;
            m_chargeTarget = 0;
        }
        else
            m_uiCharge_Timer -= diff;
        
        if (m_chargeTarget != 0) 
        {
            m_creature->StopMoving();
            m_creature->AttackStop();
            m_creature->SetTargetGuid(m_chargeTarget);
            m_creature->SetFacingToObject(m_creature->GetMap()->GetUnit(m_chargeTarget));
        }
        else
            DoMeleeAttackIfReady();
    }
    
    Unit* GetFinalTarget()
    {        
        Unit *chargeTarget = m_creature->GetMap()->GetUnit(m_chargeTarget);
        if (!chargeTarget || !chargeTarget->isAlive())
            return NULL;
        
        float chargeAngle = m_creature->GetAngle(chargeTarget);
        float chargeDistance = m_creature->GetDistance2d(chargeTarget);
        
        ThreatList const& tList = m_creature->getThreatManager().getThreatList();
        for (ThreatList::const_iterator i = tList.begin(); i != tList.end(); ++i)
        {
            Unit* potentialBlocker = m_creature->GetMap()->GetUnit((*i)->getUnitGuid());
            if (!potentialBlocker || potentialBlocker->GetGUID() == chargeTarget->GetGUID())
                continue;

            float t_angle = m_creature->GetAngle(potentialBlocker);
            float t_distance = m_creature->GetDistance2d(potentialBlocker);
            
            if (t_distance < chargeDistance && abs(t_angle - chargeAngle) <= 0.2)
                return potentialBlocker;
        }
        
        return chargeTarget;
    }
};

CreatureAI* GetAI_boss_rhahkzor(Creature* pCreature)
{
    return new boss_rhahkzorAI(pCreature);
}

void AddSC_boss_rhahkzor()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_rhahkzor";
    newscript->GetAI = &GetAI_boss_rhahkzor;
    newscript->RegisterSelf();
}
