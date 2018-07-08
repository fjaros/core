
-- Defias Miner
UPDATE creature_template SET minlevel=56,maxlevel=58,minhealth=6694,maxhealth=6891,armor=3498,dmg_multiplier=12 WHERE entry=598;

-- Defias Evoker
UPDATE creature_template SET minlevel=59,maxlevel=60,minhealth=8696,maxhealth=8912,armor=3211,dmg_multiplier=12 WHERE entry=1729;

-- Defias Strip Miner
UPDATE creature_template SET minlevel=58,maxlevel=59,minhealth=7534,maxhealth=7706,armor=3600,dmg_multiplier=12 WHERE entry=4416;

-- Defias Overseer
UPDATE creature_template SET minlevel=59,maxlevel=60,minhealth=9540,maxhealth=9780,armor=3840,dmg_multiplier=13 WHERE entry=634;

-- Defias Watchman
UPDATE creature_template SET minlevel=59,maxlevel=60,minhealth=7534,maxhealth=7706,armor=3600,dmg_multiplier=13 WHERE entry=1725;

-- Rhahk'Zor
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=94539,maxhealth=94539,armor=4391,dmg_multiplier=14,MovementType=1,AIName='',ScriptName='boss_rhahkzor' WHERE entry=644;
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000001, '$N is making me ANGRY!', 1);

-- Sneed's Shredder
UPDATE creature_template SET minlevel=63,maxlevel=63,minhealth=81977,maxhealth=81977,armor=4100,dmg_multiplier=14,MovementType=1,AIName='',ScriptName='boss_sneeds_shredder' WHERE entry=642;
REPLACE INTO custom_texts (entry, content_default, `type`) VALUES (-2000002, 'TERMINATING... TERMINATING...', 1);