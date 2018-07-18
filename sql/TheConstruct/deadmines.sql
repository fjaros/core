
UPDATE map_template SET maxplayers=15,LevelMin=60,LevelMax=60 WHERE entry=36 AND patch=1;

-- Create mooncloth & arcanite bar ref group
DELETE FROM reference_loot_template WHERE entry IN (31001, 31002);
INSERT INTO reference_loot_template (entry,item,ChanceOrQuestChance,groupid,mincountOrRef,maxcount,condition_id,patch_min,patch_max)
VALUES
    (31001, 14342, 0, 1, 1, 1, 0, 0, 10), -- mooncloth
    (31001, 12360, 0, 1, 1, 1, 0, 0, 10), -- arcanite bar

    (31002, 3387, 0, 1, 1, 1, 0, 0, 10), -- Limited Invulnerability Potion
    (31002, 3824, 0, 1, 1, 1, 0, 0, 10), -- Shadow Oil
    (31002, 3829, 0, 1, 1, 1, 0, 0, 10), -- Frost Oil
    (31002, 5634, 0, 1, 1, 1, 0, 0, 10), -- Free Action Potion
    (31002, 9036, 0, 1, 1, 1, 0, 0, 10), -- Magic Resistance Potion
    (31002, 9088, 0, 1, 1, 1, 0, 0, 10), -- Gift of Arthas
    (31002, 9179, 0, 1, 1, 1, 0, 0, 10), -- Elixir of Greater Intellect
    (31002, 9187, 0, 1, 1, 1, 0, 0, 10), -- Elixir of Greater Agility
    (31002, 9206, 0, 1, 1, 1, 0, 0, 10), -- Elixir of Giants
    (31002, 9224, 0, 1, 1, 1, 0, 0, 10), -- Elixir of Demonslaying
    (31002, 9264, 0, 1, 1, 1, 0, 0, 10), -- Elixir of Shadow Power
    (31002, 12218, 0, 1, 1, 1, 0, 0, 10), -- Monster Omelet
    (31002, 13442, 0, 1, 1, 1, 0, 0, 10), -- Mighty Rage Potion
    (31002, 13444, 0, 1, 1, 1, 0, 0, 10), -- Major Mana Potion
    (31002, 13446, 0, 1, 1, 1, 0, 0, 10), -- Major Healing Potion
    (31002, 13447, 0, 1, 1, 1, 0, 0, 10), -- Elixir of the Sages
    (31002, 13452, 0, 1, 1, 1, 0, 0, 10), -- Elixir of the Mongoose
    (31002, 13453, 0, 1, 1, 1, 0, 0, 10), -- Elixir of Brute Force
    (31002, 13454, 0, 1, 1, 1, 0, 0, 10), -- Greater Arcane Elixir
    (31002, 13455, 0, 1, 1, 1, 0, 0, 10), -- Greater Stoneshield Potion
    (31002, 13457, 0, 1, 1, 1, 0, 0, 10), -- Greater Fire Protection Potion
    (31002, 13458, 0, 1, 1, 1, 0, 0, 10), -- Greater Nature Protection Potion
    (31002, 13459, 0, 1, 1, 1, 0, 0, 10), -- Greater Shadow Protection Potion
    (31002, 13461, 0, 1, 1, 1, 0, 0, 10), -- Greater Arcane Protection Potion
    (31002, 13462, 0, 1, 1, 1, 0, 0, 10), -- Purification Potion
    (31002, 13510, 0, 1, 1, 2, 0, 0, 10), -- Flask of the Titans
    (31002, 13511, 0, 1, 1, 2, 0, 0, 10), -- Flask of Distilled Wisdom
    (31002, 13512, 0, 1, 1, 2, 0, 0, 10), -- Flask of Supreme Power
    (31002, 18045, 0, 1, 1, 1, 0, 0, 10), -- Tender Wolf Steak
    (31002, 18254, 0, 1, 1, 1, 0, 0, 10), -- Runn Tum Tuber Surprise
    (31002, 20004, 0, 1, 1, 1, 0, 0, 10), -- Major Troll's Blood Potion
    (31002, 20007, 0, 1, 1, 1, 0, 0, 10), -- Mageblood Potion
    (31002, 20452, 0, 1, 1, 1, 0, 0, 10), -- Smoked Desert Dumplings
    (31002, 20748, 0, 1, 1, 1, 0, 0, 10), -- Brilliant Mana Oil
    (31002, 20749, 0, 1, 1, 1, 0, 0, 10), -- Brilliant Wizard Oil
    (31002, 21023, 0, 1, 1, 1, 0, 0, 10), -- Dirge's Kickin' Chimaerok Chops
    (31002, 21546, 0, 1, 1, 1, 0, 0, 10) -- Elixir of Greater Firepower
;

DELETE FROM creature_loot_template WHERE mincountOrRef IN (-31001, -31002);

-- Defias Miner
UPDATE creature_template SET minlevel=56,maxlevel=58,minhealth=6694,maxhealth=6891,armor=3498,dmg_multiplier=13 WHERE entry=598;

-- Defias Evoker
UPDATE creature_template SET minlevel=59,maxlevel=60,minhealth=8696,maxhealth=8912,armor=3211,dmg_multiplier=13 WHERE entry=1729;

-- Defias Strip Miner
UPDATE creature_template SET minlevel=58,maxlevel=59,minhealth=7534,maxhealth=7706,armor=3600,dmg_multiplier=13 WHERE entry=4416;

-- Defias Overseer
UPDATE creature_template SET minlevel=59,maxlevel=60,minhealth=9540,maxhealth=9780,armor=3840,dmg_multiplier=14 WHERE entry=634;

-- Defias Watchman
UPDATE creature_template SET minlevel=59,maxlevel=60,minhealth=7534,maxhealth=7706,armor=3600,dmg_multiplier=14 WHERE entry=1725;

-- Defias Taskmaster
UPDATE creature_template SET minlevel=58,maxlevel=59,minhealth=7534,maxhealth=8706,armor=4600,dmg_multiplier=17 WHERE entry=4417;

-- Defias Wizard
UPDATE creature_template SET minlevel=58,maxlevel=59,minhealth=7534,maxhealth=8706,armor=2600,dmg_multiplier=17 WHERE entry=4418;


-- Rhahk'Zor
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=94539,maxhealth=94539,armor=4391,dmg_multiplier=16,MovementType=1,AIName='',ScriptName='boss_rhahkzor' WHERE entry=644;
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000001, '$N is making me ANGRY!', 1);
DELETE FROM creature_loot_template WHERE entry=644 AND item=14342;
INSERT INTO creature_loot_template (entry, item, ChanceOrQuestChance, groupid, mincountOrRef, maxcount, condition_id, patch_min, patch_max) 
VALUES
    (644, 31001, 25, 0, -31001, 1, 0, 0, 10),
    (644, 31002, 100, 1, -31002, 10, 0, 0, 10)
;

-- Goblin Woodcarver
UPDATE creature_template SET minlevel=57,maxlevel=59,minhealth=9700,maxhealth=11000,armor=3514,dmg_multiplier=13 WHERE entry=641;

-- Goblin Engineer
UPDATE creature_template SET minlevel=57,maxlevel=59,minhealth=9700,maxhealth=12000,armor=3614,dmg_multiplier=13 WHERE entry=622;

-- Goblin Craftsman
UPDATE creature_template SET minlevel=57,maxlevel=59,minhealth=10700,maxhealth=10900,armor=3414,dmg_multiplier=13 WHERE entry=1731;

-- Goblin Shipbuilder
UPDATE creature_template SET minlevel=59,maxlevel=60,minhealth=9700,maxhealth=10900,armor=4414,dmg_multiplier=15 WHERE entry=3947;

-- Sneed's Shredder
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=81977,maxhealth=81977,armor=4100,dmg_multiplier=16,MovementType=1,AIName='',ScriptName='boss_sneeds_shredder' WHERE entry=642;
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000002, 'TERMINATING... TERMINATING...', 1);

-- Sneed
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=41001,maxhealth=41001,armor=2100,dmg_multiplier=16,MovementType=1,AIName='EventAI',ScriptName='' WHERE entry=643;
INSERT INTO creature_loot_template (entry, item, ChanceOrQuestChance, groupid, mincountOrRef, maxcount, condition_id, patch_min, patch_max) 
VALUES
    (643, 31001, 35, 0, -31001, 1, 0, 0, 10),
    (643, 31002, 100, 1, -31002, 10, 0, 0, 10)
;

-- Remote-Controlled Golem
UPDATE creature_template SET minlevel=58,maxlevel=58,minhealth=7404,maxhealth=7404,armor=1200,dmg_multiplier=16 WHERE entry=2520;

-- Gilnid
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=92001,maxhealth=92001,armor=4734,dmg_multiplier=17,MovementType=1,AIName='',ScriptName='boss_gilnid' WHERE entry=1763;
UPDATE spell_template SET baseLevel=63,spellLevel=63 WHERE ID=5213;
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000003, 'No intruder will steal the Cookie!', 1);
INSERT INTO creature_loot_template (entry, item, ChanceOrQuestChance, groupid, mincountOrRef, maxcount, condition_id, patch_min, patch_max) 
VALUES
    (1763, 31001, 55, 0, -31001, 1, 0, 0, 10),
    (1763, 31002, 100, 1, -31002, 10, 0, 0, 10)
;

-- Defias blackguard
UPDATE creature_template SET minlevel=58,maxlevel=59,minhealth=9140,maxhealth=9260,armor=4640,dmg_multiplier=14 WHERE entry=636;

-- Defias Pirate
UPDATE creature_template SET minlevel=58,maxlevel=59,minhealth=9740,maxhealth=10260,armor=4840,dmg_multiplier=15 WHERE entry=657;

-- Defias Squallshaper
UPDATE creature_template SET minlevel=58,maxlevel=59,minhealth=8750,maxhealth=9222,armor=3420,dmg_multiplier=15 WHERE entry=1732;

-- Mr. Smite
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=95995,maxhealth=95995,armor=4934,dmg_multiplier=19,MovementType=1,AIName='',ScriptName='boss_mr_smite' WHERE entry=646;

-- Cookie
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=106594,maxhealth=110345,armor=5533,dmg_multiplier=19,MovementType=1,AIName='',ScriptName='boss_cookie' WHERE entry=645;
UPDATE spell_template SET baseLevel=63,spellLevel=63 WHERE ID=6306;
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000003, 'No intruder will steal the Cookie!', 1);
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000004, 'Intruder eliminated. The Cookie is safe.', 1);
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000005, 'The Cookie... is... devoured.', 1);
INSERT INTO creature_loot_template (entry, item, ChanceOrQuestChance, groupid, mincountOrRef, maxcount, condition_id, patch_min, patch_max) 
VALUES
    (645, 31001, 65, 0, -31001, 1, 0, 0, 10),
    (645, 31002, 100, 1, -31002, 10, 0, 0, 10)
;
