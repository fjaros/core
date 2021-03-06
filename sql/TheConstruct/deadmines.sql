
-- add vancleef teleporter
REPLACE INTO creature_template VALUES (1000017,0,0,0,2029,0,0,0,'Edwin VanCleef','Deadmines Connoisseur',0,21,21,4138,4138,0,0,852,35,35,1,1,1.14286,0,1,89,116,0,94,1,2000,2000,1,33536,0,0,0,0,0,0,29.6792,40.8089,100,7,8,639,639,0,0,0,0,0,0,0,3417,0,0,0,6390,0,318,421,'',0,3,0,0,1,286,0,0,608908883,0,0,'npc_vancleef_gossip');

REPLACE INTO broadcast_text (ID,MaleText,FemaleText) VALUES
(200001, 
'I have an unusual request of sorts. In my old home, the mines of Westfall where I grew old and tired, the endless intimate engagements with my captains no longer exciting the erogenous crevices that once when massaged made me...',
'I have an unusual request of sorts. In my old home, the mines of Westfall where I grew old and tired, the endless intimate engagements with my captains no longer exciting the erogenous crevices that once when massaged made me...'),
(200002,
'Nevertheless! I started to experiment with dark magic to rekindle the exhausted flame. Alas I managed to spawn a doppelgänger, so strong and powerful that he was soon the preferred object of my captains\' deepest fantasies.',
'Nevertheless! I started to experiment with dark magic to rekindle the exhausted flame. Alas I managed to spawn a doppelgänger, so strong and powerful that he was soon the preferred object of my captains\' deepest fantasies.'),
(200003,
'My begging and pleading proved no match to the filthy powers he spread inside of my captains. I had no choice but to, alike a weathered cuckold, retreat across the world and ask you for assistance. Will you restore my dungeon to its former glory?',
'My begging and pleading proved no match to the filthy powers he spread inside of my captains. I had no choice but to, alike a weathered cuckold, retreat across the world and ask you for assistance. Will you restore my dungeon to its former glory?');

REPLACE INTO npc_text (ID,BroadcastTextID0,Probability0) VALUES
(16777214, 200001, 1),
(16777213, 200002, 1),
(16777212, 200003, 1);


UPDATE map_template SET maxplayers=15,LevelMin=60,LevelMax=60 WHERE entry=36 AND patch=1;

-- Defias Miner
UPDATE creature_template SET minlevel=61,maxlevel=62,minhealth=16694,maxhealth=17891,armor=3498,mindmg=2400,maxdmg=3400,minrangedmg=1800,maxrangedmg=2400,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=598;

-- Defias Evoker
UPDATE creature_template SET minlevel=61,maxlevel=63,minhealth=14696,maxhealth=16912,armor=3111,mindmg=2200,maxdmg=3000,minrangedmg=1600,maxrangedmg=2200,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=1729;

-- Defias Strip Miner
UPDATE creature_template SET minlevel=61,maxlevel=62,minhealth=17534,maxhealth=17706,armor=3600,mindmg=2700,maxdmg=3600,minrangedmg=2000,maxrangedmg=2600,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=4416;

-- Defias Overseer
UPDATE creature_template SET minlevel=62,maxlevel=63,minhealth=19540,maxhealth=19780,armor=3840,mindmg=3000,maxdmg=3400,minrangedmg=2400,maxrangedmg=2600,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=634;

-- Defias Watchman
UPDATE creature_template SET minlevel=62,maxlevel=63,minhealth=17534,maxhealth=17706,armor=3600,mindmg=2700,maxdmg=3600,minrangedmg=2000,maxrangedmg=2800,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=1725;

-- Defias Taskmaster
UPDATE creature_template SET minlevel=61,maxlevel=62,minhealth=17534,maxhealth=18706,armor=4600,mindmg=2800,maxdmg=3400,minrangedmg=2200,maxrangedmg=2600,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=4417;

-- Defias Wizard
UPDATE creature_template SET minlevel=61,maxlevel=62,minhealth=17534,maxhealth=18706,armor=2600,mindmg=2200,maxdmg=3200,minrangedmg=1800,maxrangedmg=3000,baseattacktime=2000,rangeattacktime=2000,dmg_multiplier=1 WHERE entry=4418;


-- Rhahk'Zor
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=224539,maxhealth=224539,armor=4391,mindmg=5000,maxdmg=5400,baseattacktime=2000,rangeattacktime=2000,dmg_multiplier=1,MovementType=1,AIName='',ScriptName='boss_rhahkzor',MechanicImmuneMask=2793635679,flags_extra=256 WHERE entry=644;
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES
    (-2000001, '$N is making me ANGRY!', 1),
    (-2000006, 'Me likey you like Toad', 0)
;

-- Goblin Woodcarver
UPDATE creature_template SET minlevel=59,maxlevel=63,minhealth=19700,maxhealth=21000,armor=4514,mindmg=2400,maxdmg=3000,minrangedmg=1600,maxrangedmg=2400,baseattacktime=1200,rangeattacktime=1200,dmg_multiplier=1 WHERE entry=641;

-- Goblin Engineer
UPDATE creature_template SET minlevel=59,maxlevel=63,minhealth=19700,maxhealth=22000,armor=4614,mindmg=2400,maxdmg=3000,minrangedmg=1600,maxrangedmg=2400,baseattacktime=1200,rangeattacktime=1200,dmg_multiplier=1 WHERE entry=622;

-- Goblin Craftsman
UPDATE creature_template SET minlevel=59,maxlevel=63,minhealth=20700,maxhealth=20900,armor=4414,mindmg=2400,maxdmg=3000,minrangedmg=1600,maxrangedmg=2400,baseattacktime=1200,rangeattacktime=1200,dmg_multiplier=1 WHERE entry=1731;

-- Goblin Shipbuilder
UPDATE creature_template SET minlevel=59,maxlevel=63,minhealth=19700,maxhealth=20900,armor=5414,mindmg=2400,maxdmg=3000,minrangedmg=1600,maxrangedmg=2400,baseattacktime=1200,rangeattacktime=1200,dmg_multiplier=1 WHERE entry=3947;

-- Sneed's Shredder
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=281977,maxhealth=281977,armor=5100,mindmg=2400,maxdmg=3200,baseattacktime=1500,rangeattacktime=1500,dmg_multiplier=1,MovementType=1,AIName='',ScriptName='boss_sneeds_shredder',MechanicImmuneMask=2793635679 WHERE entry=642;
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000002, 'TERMINATING... TERMINATING...', 1);

-- Sneed
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=149318,maxhealth=149318,armor=4100,mindmg=2700,maxdmg=3200,baseattacktime=1600,rangeattacktime=1600,dmg_multiplier=1,MovementType=1,AIName='',ScriptName='boss_sneed',MechanicImmuneMask=2793635679,flags_extra=0 WHERE entry=643;
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000008, 'Weaklings! Time to go repair my shredder.', 0);

-- Remote-Controlled Golem
UPDATE creature_template SET minlevel=58,maxlevel=58,minhealth=5404,maxhealth=5404,armor=1200,mindmg=3600,maxdmg=3600,baseattacktime=1000,rangeattacktime=1000,dmg_multiplier=1 WHERE entry=2520;

-- Gilnid
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=292001,maxhealth=292001,armor=4734,mindmg=2400,maxdmg=3000,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1,MovementType=1,AIName='',ScriptName='boss_gilnid',MechanicImmuneMask=2793635679 WHERE entry=1763;
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000007, 'These intruders are quite resistant. Perhaps we can change things up a bit!', 1);
UPDATE spell_template SET baseLevel=63,spellLevel=63 WHERE ID=5213;

-- Defias blackguard
UPDATE creature_template SET minlevel=58,maxlevel=59,minhealth=29140,maxhealth=29260,armor=4640,mindmg=2400,maxdmg=3100,minrangedmg=1600,maxrangedmg=2300,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1,spell1=9080,spell2=6016,spell3=1427 WHERE entry=636;

-- Defias Pirate
UPDATE creature_template SET minlevel=58,maxlevel=59,minhealth=29740,maxhealth=30260,armor=4840,mindmg=2400,maxdmg=3100,minrangedmg=1600,maxrangedmg=2300,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=657;

-- Defias Squallshaper
UPDATE creature_template SET minlevel=58,maxlevel=59,minhealth=28750,maxhealth=29222,armor=3420,mindmg=2400,maxdmg=3100,minrangedmg=1600,maxrangedmg=2300,baseattacktime=1400,rangeattacktime=1400,dmg_multiplier=1 WHERE entry=1732;

-- Mr. Smite
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=295995,maxhealth=295995,armor=4934,dmg_multiplier=19,MovementType=1,AIName='',ScriptName='boss_mr_smite',MechanicImmuneMask=608908883,flags_extra=256 WHERE entry=646;

-- Cookie
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=310345,maxhealth=310345,armor=4513,mindmg=2000,maxdmg=3000,baseattacktime=1250,rangeattacktime=1250,dmg_multiplier=1,speed_walk=1.4,speed_run=1.84286,MovementType=1,AIName='',ScriptName='boss_cookie',MechanicImmuneMask=2793635679 WHERE entry=645;
UPDATE spell_template SET baseLevel=63,spellLevel=63 WHERE ID=6306;
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000003, 'No intruder will steal the Cookie!', 1);
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000004, 'Intruder eliminated. The Cookie is safe.', 1);
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000005, 'The Cookie... is... devoured.', 1);

-- Edwin VanCleef
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=316594,maxhealth=316594,armor=4633,mindmg=3000,maxdmg=3500,baseattacktime=1550,rangeattacktime=1550,dmg_multiplier=1,MovementType=1,AIName='',ScriptName='boss_vancleef',MechanicImmuneMask=2793635679 WHERE entry=639;

-- Update greenskin
UPDATE `creature_template` SET `minlevel` = '63', `maxlevel` = '63', `minhealth` = '271135', `maxhealth` = '271135', `minmana` = '10000', `maxmana` = '10000', `armor` = '4000', `mindmg` = '1500', `maxdmg` = '2500', `attackpower` = '600', `rangeattacktime` = '1500', `minrangedmg` = '1000', `maxrangedmg` = '1500', `rangedattackpower` = '500', `spell2` = '0', `spells_template` = '0', `ScriptName` = 'boss_greenskin',MechanicImmuneMask=608908883 WHERE `entry` = '647';

-- Update johnson
UPDATE `creature_template` SET `minlevel` = '63', `maxlevel` = '63', `minhealth` = '210493', `maxhealth` = '210493', `minmana` = '10000', `maxmana` = '10000', `armor` = '3500', `rank` = '2', `mindmg` = '1500', `maxdmg` = '2000', `dmgschool` = '5', `attackpower` = '500', `unit_class` = '1', `spells_template` = '0', `ScriptName` = 'boss_johnson',MechanicImmuneMask=608908883 WHERE `entry` = '3586';

-- Remove gilnid goblin
DELETE FROM creature WHERE guid=79211;