
#include "scriptPCH.h"
#include "deadmines.h"

enum
{
    AGGRO_YELL = 5619,
    SAY_CHARGE = -2000001,
    SAY_TOAD = -2000006,
    SPELL_CHARGE = 24408,
    SPELL_CLEAVE = 16044,
    SPELL_HEX = 24053
};

struct boss_rhahkzorAI : public ScriptedAI
{
    uint32 m_uiCleave_Timer;
    uint32 m_uiSayCharge_Timer;
    uint32 m_uiCharge_Timer;
    uint32 m_uiHex_Timer;
    uint64 m_chargeTarget;
    std::set<uint64> m_alreadyCharged;
    
    boss_rhahkzorAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }
    
    void Reset()
    {
        m_uiCharge_Timer = 16000;
        m_uiCleave_Timer = 6000;
        m_uiSayCharge_Timer = 13000;
        m_uiHex_Timer = 9000;
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
            if (DoCastSpellIfCan(m_creature->getVictim(), SPELL_CLEAVE) == CAST_OK)
            m_uiCleave_Timer = urand(4000, 6000);
        }
        else
            m_uiCleave_Timer -= diff;

        if (m_uiHex_Timer < diff)
        {
            Unit *pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, nullptr, SELECT_FLAG_PLAYER);
            if (DoCastSpellIfCan(pTarget, SPELL_HEX, CF_FORCE_CAST) == CAST_OK)
            {
                DoScriptText(SAY_TOAD, m_creature);
                m_uiHex_Timer = urand(8000, 11000);
            }
        }
        else
            m_uiHex_Timer -= diff;
        
        if (m_uiSayCharge_Timer < diff) 
        {
            if (Unit* pTarget = GetRandomFarthestPlayerInRange(0.0f, 40.0f, 3))
            {
                DoScriptText(SAY_CHARGE, m_creature, pTarget);
                m_chargeTarget = pTarget->GetGUID();
                m_uiSayCharge_Timer = 16000;
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
                    if (DoCastSpellIfCan(pPlayer, SPELL_CHARGE) == CAST_OK)
                    {
                        if (m_alreadyCharged.find(pPlayer->GetGUID()) != m_alreadyCharged.end())
                        {
                            m_creature->DoKillUnit(pPlayer);
                            m_alreadyCharged.erase(pPlayer->GetGUID());
                        }
                        else
                            m_alreadyCharged.insert(pPlayer->GetGUID());
                        m_uiSayCharge_Timer = urand(16000, 19000);
                        m_uiCharge_Timer = m_uiSayCharge_Timer + 3000;
                        m_chargeTarget = 0;
                    }
                }
            }
        }
        else
            m_uiCharge_Timer -= diff;

        if (m_chargeTarget != 0) 
        {
            if (m_creature->IsMoving())
                m_creature->StopMoving();
            if (m_creature->isAttackingPlayer())
                m_creature->AttackStop();
            m_creature->SetTargetGuid(m_chargeTarget);
            m_creature->SetFacingToObject(m_creature->GetMap()->GetUnit(m_chargeTarget));
        }
        else
            DoMeleeAttackIfReady();
    }

    Unit* GetRandomFarthestPlayerInRange(float min, float max, int randomCount)
    {
        float bestRange = min;
        std::vector<Unit*> units;

        ThreatList const& tList = m_creature->getThreatManager().getThreatList();
        for (ThreatList::const_iterator i = tList.begin(); i != tList.end(); ++i)
        {
            Unit* pTarget = m_creature->GetMap()->GetUnit((*i)->getUnitGuid());
            if (!pTarget || !pTarget->IsPlayer())
                continue;

            units.push_back(pTarget);
        }
        std::sort(units.begin(), units.end(), [this](Unit *i, Unit *j)
            {
                return m_creature->GetDistance(i) > m_creature->GetDistance(j);
            }
        );
        if (randomCount > units.size())
            randomCount = units.size();

        return units[rand() % randomCount];
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
            if (!potentialBlocker || !potentialBlocker->IsPlayer() ||
                    potentialBlocker->GetGUID() == chargeTarget->GetGUID())
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
