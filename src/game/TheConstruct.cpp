
#include "TheConstruct.h"

#include "Guild/Guild.h"
#include "Guild/GuildMgr.h"
#include "ReputationMgr.h"

enum WEAPONS {
    AXE	    = 196,
    AXE2    = 197,
    BOW	    = 264,
    GUN	    = 266,
    MACE    = 198,
    MACE2   = 199,
    POLEARM = 200,
    SWORD   = 201,
    SWORD2  = 202,
    STAFF   = 227,
    DAGGER  = 1180,
    THROWN  = 2567,
    SPEAR   = 3386,
    CROSSBOW= 5011,
    WAND    = 5009,
    FIST    = 15590
};

enum ARMOR {
    CLOTH   = 9078,
    LEATHER = 9077,
    MAIL    = 8737,
    PLATE   = 750,
    SHIELD  = 9116
};

void DoAtLogin(Player *player) {
    /*
    Darkspear Trolls ID#530
    Orgrimmar - ID#76
    Thunder Bluff - ID#81
    Undercity - ID#68
    */
    std::vector<int> factions = {530, 76, 81, 68};
    InsertFactions(player, factions);

    std::vector<int> skills = {};
    std::vector<int> armors = {};
    std::vector<int> spells = {};
    std::vector<int> disabled_spells = {};
    switch (player->getClass()) {
	case CLASS_DRUID:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_MACES, SKILL_2H_MACES, SKILL_POLEARMS, SKILL_STAVES, SKILL_DAGGERS, SKILL_FIST_WEAPONS};
	    armors = {SKILL_LEATHER, SKILL_CLOTH};
	    spells = {
		MACE, MACE2, POLEARM, STAFF, DAGGER, FIST,
		CLOTH, LEATHER,
		1066, // Aquatic form
		9634, // Dire bear form
		6795, // Growl
		6807, // Maul
		18960 // Teleport moonglade
	    };
	    break;
	case CLASS_HUNTER:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_AXES, SKILL_2H_AXES, SKILL_SWORDS, SKILL_2H_SWORDS, SKILL_POLEARMS, SKILL_STAVES, SKILL_DAGGERS, SKILL_FIST_WEAPONS, SKILL_BOWS, SKILL_CROSSBOWS, SKILL_GUNS, SKILL_DUAL_WIELD};
	    armors = {SKILL_MAIL, SKILL_LEATHER, SKILL_CLOTH};
	    spells = {
		AXE, AXE2, SWORD, SWORD2, POLEARM, STAFF, DAGGER, FIST, BOW, CROSSBOW, GUN,
		CLOTH, LEATHER, MAIL,
		5149, // Tame beast
		1515, // Beast training
		6991, // Feed pet
		982, // Revive pet
		883, // Call pet
		2641, // Dismiss pet
                // Pet Skills
                7370, 26184, 26185, 26186, 26202, 28343, // Charge
                17254, 17262, 17263, 17264, 17265, 17266, 17267, 17268, // Bite
 	 	2980, 2981, 2982, 3667, 2975, 2976, 2977, 3666, // Claw
                24609, 24608, 24607, 24599, // Furious Howl
 	 	24845, 25013, 25014, 25015, 25016, 25017, // Lightning Breath
                24451, 24454, 24455, // Prowl
                24641, 24584, 24588, 24589, // Scorpid Poison
 	 	24424, 24580, 24581, 24582, // Screech
                26065, // Shell shield
                26094, 26189, 26190, // Thunderstomp
                23100, 23111, 23112, // Dash
                23146, 23149, 23150, // Dive
                1747, 1748, 1749, 1750, 1751, 16698 // Cower
	    };
	    break;
	case CLASS_MAGE:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_SWORDS, SKILL_STAVES, SKILL_DAGGERS, SKILL_WANDS};
	    armors = {SKILL_CLOTH};
	    spells = {
		SWORD, STAFF, DAGGER, WAND,
		CLOTH
	    };
	    break;
	case CLASS_PALADIN:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_AXES, SKILL_2H_AXES, SKILL_SWORDS, SKILL_2H_SWORDS, SKILL_MACES, SKILL_2H_MACES, SKILL_POLEARMS};
	    armors = {SKILL_PLATE_MAIL, SKILL_MAIL, SKILL_LEATHER, SKILL_CLOTH, SKILL_SHIELD};
	    spells = {
		AXE, AXE2, MACE, MACE2, POLEARM,
		CLOTH, LEATHER, MAIL, PLATE, SHIELD
	    };
	    break;
	case CLASS_PRIEST:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_MACES, SKILL_STAVES, SKILL_DAGGERS, SKILL_WANDS};
	    armors = {SKILL_CLOTH};
	    spells = {
		MACE, STAFF, DAGGER, WAND,
		CLOTH
	    };
	    break;
	case CLASS_ROGUE:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_AXES, SKILL_SWORDS, SKILL_MACES, SKILL_DAGGERS, SKILL_FIST_WEAPONS, SKILL_BOWS, SKILL_CROSSBOWS, SKILL_GUNS, SKILL_THROWN, SKILL_DUAL_WIELD};
	    armors = {SKILL_LEATHER, SKILL_CLOTH};
	    spells = {
		AXE, SWORD, MACE, DAGGER, FIST, BOW, CROSSBOW, GUN, THROWN,
		CLOTH, LEATHER
	    };
	    break;
	case CLASS_SHAMAN:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_AXES, SKILL_2H_AXES, SKILL_MACES, SKILL_2H_MACES, SKILL_POLEARMS, SKILL_STAVES, SKILL_DAGGERS, SKILL_FIST_WEAPONS};
	    armors = {SKILL_MAIL, SKILL_LEATHER, SKILL_CLOTH, SKILL_SHIELD};
	    spells = {
		AXE, MACE, POLEARM, STAFF, DAGGER, FIST,
		CLOTH, LEATHER, MAIL, SHIELD,
		3599, // Searing totem rank 1
		8071, // Stoneskin totem rank 1
		5394 // Healing Stream totem rank 1
	    };
	    disabled_spells = {AXE2, MACE2};
	    break;
	case CLASS_WARLOCK:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_SWORDS, SKILL_STAVES, SKILL_DAGGERS, SKILL_WANDS};
	    armors = {SKILL_CLOTH};
	    spells = {
		SWORD, STAFF, DAGGER, WAND,
		CLOTH,
		688, // Summon imp
		697, // Summon succubus
		712, // Summon voidwalker
		691 // Summon felhunter
	    };
	    break;
	case CLASS_WARRIOR:
	    skills = {SKILL_DEFENSE, SKILL_UNARMED, SKILL_AXES, SKILL_2H_AXES, SKILL_SWORDS, SKILL_2H_SWORDS, SKILL_MACES, SKILL_2H_MACES, SKILL_POLEARMS, SKILL_STAVES, SKILL_DAGGERS, SKILL_FIST_WEAPONS, SKILL_BOWS, SKILL_CROSSBOWS, SKILL_GUNS, SKILL_THROWN, SKILL_DUAL_WIELD};
	    armors = {SKILL_PLATE_MAIL, SKILL_MAIL, SKILL_LEATHER, SKILL_CLOTH, SKILL_SHIELD};
	    spells = {
		AXE, AXE2, SWORD, SWORD2, MACE, MACE2, POLEARM, STAFF, DAGGER, FIST, BOW, CROSSBOW, GUN, THROWN,
		CLOTH, LEATHER, MAIL, PLATE, SHIELD,
		71, // Defensive stance
		2458, // Berserker stance
		355, // Taunt
		7386, // Sunder Armor
		20611 // Intercept
	    };
	    break;
    }
    InsertSkills(player, skills);
    InsertArmors(player, armors);
    InsertSpells(player, spells);
    InsertSpells(player, disabled_spells, true);
    InsertRiding(player);
    InsertHomebind(player);
}

void DoPostLogin(Player *player) {
    AddToGuild(player);
}

void InsertFactions(Player *player, std::vector<int> factions) {
    static SqlStatementID insFaction;
    for (int faction : factions) {
	SqlStatement insert = CharacterDatabase.CreateStatement(insFaction, "REPLACE INTO character_reputation"
		"(guid, faction, standing, flags)"
		"VALUES (?,?,?,?)");

	insert.addUInt32(player->GetGUIDLow());
	insert.addUInt32(faction);
	insert.addUInt32(42999);
	insert.addUInt32(FACTION_FLAG_VISIBLE);

	insert.Execute();
    }
}

void InsertSkills(Player *player, std::vector<int> skills) {
    static SqlStatementID insSkill;
    for (int skill : skills) {
	SqlStatement insert = CharacterDatabase.CreateStatement(insSkill, "REPLACE INTO character_skills"
		"(guid, skill, value, max)"
		"VALUES (?,?,?,?)");

	insert.addUInt32(player->GetGUIDLow());
	insert.addUInt32(skill);
	insert.addUInt32(300);
	insert.addUInt32(300);

	insert.Execute();
    }
}

void InsertArmors(Player *player, std::vector<int> armors) {
    static SqlStatementID insArmor;
    for (int armor : armors) {
	SqlStatement insert = CharacterDatabase.CreateStatement(insArmor, "REPLACE INTO character_skills"
		"(guid, skill, value, max)"
		"VALUES (?,?,?,?)");

	insert.addUInt32(player->GetGUIDLow());
	insert.addUInt32(armor);
	insert.addUInt32(1);
	insert.addUInt32(1);

	insert.Execute();
    }
}

void InsertSpells(Player *player, std::vector<int> spells, bool disabled) {
    static SqlStatementID insSpell;
    for (int spell : spells) {
	SqlStatement insert = CharacterDatabase.CreateStatement(insSpell, "REPLACE INTO character_spell"
		"(guid, spell, active, disabled)"
		"VALUES (?,?,?,?)");

	insert.addUInt32(player->GetGUIDLow());
	insert.addUInt32(spell);
	insert.addUInt8(1);
	if (disabled) {
	    insert.addUInt8(1);
	} else {
	    insert.addUInt8(0);
	}

	insert.Execute();
    }
}

void InsertRiding(Player *player) {
    std::vector<int> ridings_special = {SKILL_RIDING_HORSE, SKILL_RIDING_WOLF, SKILL_RIDING_TIGER, SKILL_RIDING_RAM, SKILL_RIDING_RAPTOR, SKILL_RIDING_KODO};
    for (int riding : ridings_special) {
	static SqlStatementID insRidingSpecial;
	SqlStatement insert = CharacterDatabase.CreateStatement(insRidingSpecial, "REPLACE INTO character_skills"
		"(guid, skill, value, max)"
		"VALUES (?,?,?,?)");

	insert.addUInt32(player->GetGUIDLow());
	insert.addUInt32(riding);
	insert.addUInt32(75);
	insert.addUInt32(75);

	insert.Execute();
    }

    std::vector<int> ridings = {SKILL_RIDING};
    for (int riding : ridings) {
	static SqlStatementID insRiding;
	SqlStatement insert = CharacterDatabase.CreateStatement(insRiding, "REPLACE INTO character_skills"
		"(guid, skill, value, max)"
		"VALUES (?,?,?,?)");

	insert.addUInt32(player->GetGUIDLow());
	insert.addUInt32(riding);
	insert.addUInt32(150);
	insert.addUInt32(150);

	insert.Execute();
    }

    // spells
    std::vector<int> all_spells = {
	//33388, // apprentice riding
	33391 // journeyman riding
    };
    for (int spell : all_spells) {
	static SqlStatementID insSpell;
	SqlStatement insert = CharacterDatabase.CreateStatement(insSpell, "REPLACE INTO character_spell"
		"(guid, spell, active, disabled)"
		"VALUES (?,?,?,?)");

	insert.addUInt32(player->GetGUIDLow());
	insert.addUInt32(spell);
	insert.addUInt8(1);
	insert.addUInt8(0);

	insert.Execute();
    }
}

void InsertHomebind(Player *player) {
    if (player->GetTeam() != HORDE) {
	return;
    }
    
    static SqlStatementID insHomebind;
    SqlStatement insert = CharacterDatabase.CreateStatement(insHomebind, "REPLACE INTO character_homebind"
	    "(guid, map, zone, position_x, position_y, position_z)"
	    "VALUES (?,?,?,?,?,?)");

    insert.addUInt32(player->GetGUIDLow());
    insert.addUInt32(1);
    insert.addUInt32(1637);
    insert.addFloat(1633.27);
    insert.addFloat(-4439.64);
    insert.addFloat(15.4805);

    insert.Execute();
}

void AddToGuild(Player *player) {
    if (player->GetTeam() != HORDE) {
	return;
    }

    uint32_t guildId = 1;
    Guild *guild = sGuildMgr.GetGuildById(guildId);
    GuildAddStatus status = guild->AddMember(player->GetGUIDLow(), guild->GetLowestRank());
    switch (status) {
	case GuildAddStatus::ALREADY_IN_GUILD:
	    BASIC_LOG("AddToGuild FAILED, player %s ALREADY_IN_GUILD", player->GetName());
	    break;
	case GuildAddStatus::GUILD_FULL:
	    BASIC_LOG("AddToGuild FAILED, player %s GUILD_FULL", player->GetName());
	    break;
	case GuildAddStatus::PLAYER_DATA_ERROR:
	    BASIC_LOG("AddToGuild FAILED, player %s PLAYER_DATA_ERROR", player->GetName());
	    break;
	case GuildAddStatus::UNKNOWN_PLAYER:
	    BASIC_LOG("AddToGuild FAILED, player %s UNKNOWN_PLAYER", player->GetName());
	    break;
    }
}

const SpellEntry* ChangeSpellEffect(const SpellEntry* pSpell, Unit* pCaster)
{
    SpellEntry* newSpell = (SpellEntry*)pSpell;

    switch (pCaster->GetGUIDLow()) {
        case 79168: // rhahk'zor
            switch (newSpell->Id) {
                case 15284: //cleave
                    newSpell->EffectBasePoints[0] = 5000;
                    break;
                case 24408: //charge
                    newSpell->EffectBasePoints[1] = 2000;
                    break;
            }
            break;
        case 79223: // sneed's shredder
            switch (newSpell->Id) {
                case 20475: // living bomb
                    newSpell->EffectAmplitude[0] = 5000;
                    break;
            }
            break;
        case 79344: // cookie
            switch (newSpell->Id) {
                case 6306: //acid splash
                    newSpell->EffectBasePoints[0] = 300;
                    break;
            }
            break;
        case 79206: // gilnid
            switch (newSpell->Id) {
                case 5213: // molten metal
                    newSpell->EffectBasePoints[0] = 250;
                    break;
                case 23970: // liquid fire
                    newSpell->EffectBasePoints[0] = 1350;
                    break;
            }
        case 79336: // vancleef
            switch (newSpell->Id) {
                case 17501: // cannon fire
                    newSpell->EffectBasePoints[0] = 1500;
                    break;
            }
            break;
    }

    return newSpell;
}
