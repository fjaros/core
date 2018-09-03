
UPDATE map_template SET maxplayers=15,LevelMin=60,LevelMax=60 WHERE entry=36 AND patch=1;

-- Create mooncloth & arcanite bar ref group
DELETE FROM reference_loot_template WHERE entry IN (31001, 31002);
INSERT INTO reference_loot_template (entry,item,ChanceOrQuestChance,groupid,mincountOrRef,maxcount,condition_id,patch_min,patch_max)
VALUES
    (31001, 14342, 0, 1, 1, 2, 0, 0, 10), -- mooncloth
    (31001, 12360, 0, 1, 1, 2, 0, 0, 10) -- arcanite bar

--     (31002, 3387, 0, 1, 1, 1, 0, 0, 10), -- Limited Invulnerability Potion
--     (31002, 3824, 0, 1, 1, 1, 0, 0, 10), -- Shadow Oil
--     (31002, 3829, 0, 1, 1, 1, 0, 0, 10), -- Frost Oil
--     (31002, 5634, 0, 1, 1, 1, 0, 0, 10), -- Free Action Potion
--     (31002, 9036, 0, 1, 1, 1, 0, 0, 10), -- Magic Resistance Potion
--     (31002, 9088, 0, 1, 1, 1, 0, 0, 10), -- Gift of Arthas
--     (31002, 9179, 0, 1, 1, 1, 0, 0, 10), -- Elixir of Greater Intellect
--     (31002, 9187, 0, 1, 1, 1, 0, 0, 10), -- Elixir of Greater Agility
--     (31002, 9206, 0, 1, 1, 1, 0, 0, 10), -- Elixir of Giants
--     (31002, 9224, 0, 1, 1, 1, 0, 0, 10), -- Elixir of Demonslaying
--     (31002, 9264, 0, 1, 1, 1, 0, 0, 10), -- Elixir of Shadow Power
--     (31002, 12218, 0, 1, 1, 1, 0, 0, 10), -- Monster Omelet
--     (31002, 13442, 0, 1, 1, 1, 0, 0, 10), -- Mighty Rage Potion
--     (31002, 13444, 0, 1, 1, 1, 0, 0, 10), -- Major Mana Potion
--     (31002, 13446, 0, 1, 1, 1, 0, 0, 10), -- Major Healing Potion
--     (31002, 13447, 0, 1, 1, 1, 0, 0, 10), -- Elixir of the Sages
--     (31002, 13452, 0, 1, 1, 1, 0, 0, 10), -- Elixir of the Mongoose
--     (31002, 13453, 0, 1, 1, 1, 0, 0, 10), -- Elixir of Brute Force
--     (31002, 13454, 0, 1, 1, 1, 0, 0, 10), -- Greater Arcane Elixir
--     (31002, 13455, 0, 1, 1, 1, 0, 0, 10), -- Greater Stoneshield Potion
--     (31002, 13457, 0, 1, 1, 1, 0, 0, 10), -- Greater Fire Protection Potion
--     (31002, 13458, 0, 1, 1, 1, 0, 0, 10), -- Greater Nature Protection Potion
--     (31002, 13459, 0, 1, 1, 1, 0, 0, 10), -- Greater Shadow Protection Potion
--     (31002, 13461, 0, 1, 1, 1, 0, 0, 10), -- Greater Arcane Protection Potion
--     (31002, 13462, 0, 1, 1, 1, 0, 0, 10), -- Purification Potion
--     (31002, 13510, 0, 1, 1, 2, 0, 0, 10), -- Flask of the Titans
--     (31002, 13511, 0, 1, 1, 2, 0, 0, 10), -- Flask of Distilled Wisdom
--     (31002, 13512, 0, 1, 1, 2, 0, 0, 10), -- Flask of Supreme Power
--     (31002, 18045, 0, 1, 1, 1, 0, 0, 10), -- Tender Wolf Steak
--     (31002, 18254, 0, 1, 1, 1, 0, 0, 10), -- Runn Tum Tuber Surprise
--     (31002, 20004, 0, 1, 1, 1, 0, 0, 10), -- Major Troll's Blood Potion
--     (31002, 20007, 0, 1, 1, 1, 0, 0, 10), -- Mageblood Potion
--     (31002, 20452, 0, 1, 1, 1, 0, 0, 10), -- Smoked Desert Dumplings
--     (31002, 20748, 0, 1, 1, 1, 0, 0, 10), -- Brilliant Mana Oil
--     (31002, 20749, 0, 1, 1, 1, 0, 0, 10), -- Brilliant Wizard Oil
--     (31002, 21023, 0, 1, 1, 1, 0, 0, 10), -- Dirge's Kickin' Chimaerok Chops
--     (31002, 21546, 0, 1, 1, 1, 0, 0, 10) -- Elixir of Greater Firepower
;

DELETE FROM creature_loot_template WHERE mincountOrRef IN (-31001, -31002);

-- Defias Miner
UPDATE creature_template SET minlevel=61,maxlevel=62,minhealth=16694,maxhealth=17891,armor=3498,mindmg=2400,maxdmg=3400,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=598;

-- Defias Evoker
UPDATE creature_template SET minlevel=61,maxlevel=63,minhealth=14696,maxhealth=16912,armor=3111,mindmg=2200,maxdmg=3000,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=1729;

-- Defias Strip Miner
UPDATE creature_template SET minlevel=61,maxlevel=62,minhealth=17534,maxhealth=17706,armor=3600,mindmg=2700,maxdmg=3600,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=4416;

-- Defias Overseer
UPDATE creature_template SET minlevel=62,maxlevel=63,minhealth=19540,maxhealth=19780,armor=3840,mindmg=3000,maxdmg=3400,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=634;

-- Defias Watchman
UPDATE creature_template SET minlevel=62,maxlevel=63,minhealth=17534,maxhealth=17706,armor=3600,mindmg=2700,maxdmg=3600,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=1725;

-- Defias Taskmaster
UPDATE creature_template SET minlevel=61,maxlevel=62,minhealth=17534,maxhealth=18706,armor=4600,mindmg=2800,maxdmg=3400,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=4417;

-- Defias Wizard
UPDATE creature_template SET minlevel=61,maxlevel=62,minhealth=17534,maxhealth=18706,armor=2600,mindmg=2200,maxdmg=3200,baseattacktime=2000,rangeattacktime=2000,dmg_multiplier=1 WHERE entry=4418;


-- Rhahk'Zor
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=224539,maxhealth=224539,armor=4391,mindmg=5000,maxdmg=5400,baseattacktime=2000,rangeattacktime=2000,dmg_multiplier=1,MovementType=1,AIName='',ScriptName='boss_rhahkzor' WHERE entry=644;
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES
    (-2000001, '$N is making me ANGRY!', 1),
    (-2000006, 'Me likey you like Toad', 0)
;
DELETE FROM creature_loot_template WHERE entry=644 AND item=14342;
INSERT INTO creature_loot_template (entry, item, ChanceOrQuestChance, groupid, mincountOrRef, maxcount, condition_id, patch_min, patch_max) 
VALUES
    (644, 31001, 25, 0, -31001, 1, 0, 0, 10)
--    (644, 31002, 100, 1, -31002, 10, 0, 0, 10)
;

-- Goblin Woodcarver
UPDATE creature_template SET minlevel=57,maxlevel=59,minhealth=19700,maxhealth=21000,armor=4514,mindmg=2400,maxdmg=3000,baseattacktime=1200,rangeattacktime=1200,dmg_multiplier=1 WHERE entry=641;

-- Goblin Engineer
UPDATE creature_template SET minlevel=57,maxlevel=59,minhealth=19700,maxhealth=22000,armor=4614,mindmg=2400,maxdmg=3000,baseattacktime=1200,rangeattacktime=1200,dmg_multiplier=1 WHERE entry=622;

-- Goblin Craftsman
UPDATE creature_template SET minlevel=57,maxlevel=59,minhealth=20700,maxhealth=20900,armor=4414,mindmg=2400,maxdmg=3000,baseattacktime=1200,rangeattacktime=1200,dmg_multiplier=1 WHERE entry=1731;

-- Goblin Shipbuilder
UPDATE creature_template SET minlevel=59,maxlevel=60,minhealth=19700,maxhealth=20900,armor=5414,mindmg=2400,maxdmg=3000,baseattacktime=1200,rangeattacktime=1200,dmg_multiplier=1 WHERE entry=3947;

-- Sneed's Shredder
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=281977,maxhealth=281977,armor=5100,mindmg=2400,maxdmg=3200,baseattacktime=1500,rangeattacktime=1500,dmg_multiplier=1,MovementType=1,AIName='',ScriptName='boss_sneeds_shredder' WHERE entry=642;
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000002, 'TERMINATING... TERMINATING...', 1);

-- Sneed
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=149318,maxhealth=149318,armor=4100,mindmg=2700,maxdmg=3200,baseattacktime=1600,rangeattacktime=1600,dmg_multiplier=1,MovementType=1,AIName='',ScriptName='boss_sneed' WHERE entry=643;
INSERT INTO creature_loot_template (entry, item, ChanceOrQuestChance, groupid, mincountOrRef, maxcount, condition_id, patch_min, patch_max) 
VALUES
    (643, 31001, 35, 0, -31001, 1, 0, 0, 10)
--    (643, 31002, 100, 1, -31002, 10, 0, 0, 10)
;

-- Remote-Controlled Golem
UPDATE creature_template SET minlevel=58,maxlevel=58,minhealth=5404,maxhealth=5404,armor=1200,mindmg=3500,maxdmg=3500,baseattacktime=1500,rangeattacktime=1500,dmg_multiplier=1 WHERE entry=2520;

-- Gilnid
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=292001,maxhealth=292001,armor=4734,mindmg=2400,maxdmg=3000,baseattacktime=1200,rangeattacktime=1200,dmg_multiplier=1,MovementType=1,AIName='',ScriptName='boss_gilnid' WHERE entry=1763;
UPDATE spell_template SET baseLevel=63,spellLevel=63 WHERE ID=5213;
INSERT INTO creature_loot_template (entry, item, ChanceOrQuestChance, groupid, mincountOrRef, maxcount, condition_id, patch_min, patch_max) 
VALUES
    (1763, 31001, 55, 0, -31001, 1, 0, 0, 10)
--    (1763, 31002, 100, 1, -31002, 10, 0, 0, 10)
;

-- Defias blackguard
UPDATE creature_template SET minlevel=58,maxlevel=59,minhealth=29140,maxhealth=29260,armor=4640,mindmg=2400,maxdmg=3100,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1,spell1=9080,spell2=6016,spell3=1427 WHERE entry=636;

-- Defias Pirate
UPDATE creature_template SET minlevel=58,maxlevel=59,minhealth=29740,maxhealth=30260,armor=4840,mindmg=2400,maxdmg=3100,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=657;

-- Defias Squallshaper
UPDATE creature_template SET minlevel=58,maxlevel=59,minhealth=28750,maxhealth=29222,armor=3420,mindmg=2400,maxdmg=3100,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=1732;

-- Mr. Smite
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=295995,maxhealth=295995,armor=4934,dmg_multiplier=19,MovementType=1,AIName='',ScriptName='boss_mr_smite' WHERE entry=646;

-- Cookie
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=310345,maxhealth=310345,armor=4513,mindmg=2000,maxdmg=3000,baseattacktime=1250,rangeattacktime=1250,dmg_multiplier=1,speed_walk=1.4,speed_run=1.84286,MovementType=1,AIName='',ScriptName='boss_cookie' WHERE entry=645;
UPDATE spell_template SET baseLevel=63,spellLevel=63 WHERE ID=6306;
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000003, 'No intruder will steal the Cookie!', 1);
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000004, 'Intruder eliminated. The Cookie is safe.', 1);
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000005, 'The Cookie... is... devoured.', 1);
INSERT INTO creature_loot_template (entry, item, ChanceOrQuestChance, groupid, mincountOrRef, maxcount, condition_id, patch_min, patch_max) 
VALUES
    (645, 31001, 65, 0, -31001, 1, 0, 0, 10)
--    (645, 31002, 100, 1, -31002, 10, 0, 0, 10)
;

-- Edwin VanCleef
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=316594,maxhealth=316594,armor=4633,mindmg=3000,maxdmg=3500,baseattacktime=1550,rangeattacktime=1550,dmg_multiplier=1,MovementType=1,AIName='',ScriptName='boss_vancleef' WHERE entry=639;
