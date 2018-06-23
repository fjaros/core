
#ifndef THECONSTRUCT_H
#define THECONSTRUCT_H

#include <vector>
#include "Player.h"

void DoAtLogin(Player *player);
void DoPostLogin(Player *player);
void InsertFactions(Player *player, std::vector<int> factions);
void InsertSkills(Player *player, std::vector<int> skills);
void InsertArmors(Player *player, std::vector<int> armors);
void InsertSpells(Player *player, std::vector<int> spells, bool disabled = false);
void InsertRiding(Player *player);
void InsertHomebind(Player *player);
void AddToGuild(Player *player);

#endif /* THECONSTRUCT_H */
