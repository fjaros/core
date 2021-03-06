
-- hearthstone 30 minutes
UPDATE spell_template SET categoryRecoveryTime=1800000 WHERE id=8690;

-- change stackable 5 items & soul shard to stackable 20 items
UPDATE item_template SET stackable=20 WHERE entry IN (
118,537,556,755,771,779,783,858,887,929,954,955,1074,1180,1181,1212,1288,1464,1475,
1476,1477,1478,1520,1630,1687,1688,1696,1701,1702,1710,1711,1712,2085,2289,2290,2295,
2454,2455,2456,2457,2458,2459,2590,2591,2608,2940,3010,3012,3013,3171,3180,3181,3300,
3382,3383,3384,3385,3386,3387,3388,3389,3390,3391,3399,3401,3402,3403,3669,3670,3671,
3674,3722,3723,3724,3725,3767,3769,3823,3824,3825,3826,3827,3828,3829,3928,3931,4092,
4093,4099,4232,4235,4384,4391,4402,4405,4406,4407,4419,4421,4422,4424,4425,4426,4428,
4553,4554,4555,4556,4581,4582,4583,4584,4585,4586,4588,4590,4591,4596,4623,4627,4757,
4775,4780,4784,4787,4814,4852,4860,4865,4867,4872,4873,4874,4875,4876,4877,4879,4880,
5113,5114,5115,5120,5121,5123,5125,5128,5133,5134,5135,5136,5137,5268,5269,5362,5363,
5364,5367,5368,5369,5370,5371,5373,5374,5375,5376,5377,5427,5428,5429,5430,5431,5432,
5433,5435,5506,5565,5566,5567,5569,5631,5633,5634,5635,5637,5740,5829,5871,5996,5997,
6041,6042,6043,6048,6049,6050,6051,6052,6149,6265,6302,6372,6373,6438,6439,6444,6445,
6455,6457,6662,7071,7073,7074,7096,7098,7099,7100,7101,7191,7287,7296,7392,7967,8146,
8169,8171,8508,8949,8951,8956,9030,9036,9088,9144,9154,9155,9172,9179,9187,9197,9206,
9224,9233,9264,9312,9313,9314,9315,9317,9318,9335,9336,9356,10305,10306,10307,10308,
10309,10310,10457,10546,10548,10592,11387,11388,11389,11392,11406,11417,11418,11509,
11590,11751,11752,12190,12645,12924,13442,13443,13444,13445,13446,13447,13452,13453,
13454,13455,13456,13457,13458,13459,13460,13461,13462,13506,13510,13511,13512,13513,
15407,16583,17030,17033,17708,17747,18225,18226,18227,18230,18233,18234,18253,18283,
18294,18297,18512,18604,18662,18802,18839,18841,19441,19911,19971,20002,20004,20007,
20008,20017,20516,20620,20763,21038,21254,21546,22192,22193,24281,24282
);

-- Set higher drop rate for crusader pattern according to classicdb
REPLACE INTO creature_loot_template VALUES (4494, 16252, 0.75, 0, 1, 1, 0, 0, 10);
REPLACE INTO creature_loot_template VALUES (9451, 16252, 0.75, 0, 1, 1, 0, 0, 10);

-- Set D2 sets to be usable by corresponding class only
UPDATE item_template SET AllowableClass=1 WHERE entry IN (21994, 21995, 21996, 21997, 21998, 21999, 22000, 22001); -- warrior
UPDATE item_template SET AllowableClass=2 WHERE entry IN (22086, 22087, 22088, 22089, 22090, 22091, 22092, 22093); -- paladin
UPDATE item_template SET AllowableClass=4 WHERE entry IN (22010, 22011, 22013, 22015, 22016, 22017, 22060, 22061); -- hunter
UPDATE item_template SET AllowableClass=8 WHERE entry IN (22002, 22003, 22004, 22005, 22006, 22007, 22008, 22009); -- rogue
UPDATE item_template SET AllowableClass=16 WHERE entry IN (22078, 22079, 22080, 22081, 22082, 22083, 22084, 22085); -- priest
UPDATE item_template SET AllowableClass=64 WHERE entry IN (22095, 22096, 22097, 22098, 22099, 22100, 22101, 22102); -- shaman
UPDATE item_template SET AllowableClass=128 WHERE entry IN (22062, 22063, 22064, 22065, 22066, 22067, 22068, 22069); -- mage
UPDATE item_template SET AllowableClass=256 WHERE entry IN (22070, 22071, 22072, 22073, 22074, 22075, 22076, 22077); -- warlock
UPDATE item_template SET AllowableClass=1024 WHERE entry IN (22106, 22107, 22108, 22109, 22110, 22111, 22112, 22113); -- druid

-- Make following items unique equipped
UPDATE item_template SET Flags=Flags | 0x80000,maxcount=1 WHERE entry=13965; -- Blackhand's Breadth
UPDATE item_template SET Flags=Flags | 0x80000,maxcount=1 WHERE entry=13966; -- Mark of Tyranny
UPDATE item_template SET Flags=Flags | 0x80000,maxcount=1 WHERE entry=13968; -- Eye of the Beast

-- set mageblood potion to 3 second cooldown
update `item_template` set `spellcooldown_1` = '0' ,`spellcategorycooldown_1` = '3000' where `entry` = '20007';

-- set ace of * to drop from MC bosses
INSERT INTO `creature_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `groupid`, `mincountOrRef`, `maxcount`, `condition_id`, `patch_min`, `patch_max`) VALUES
('12118', '36000', '100', '1', '-36000', '1', '0', '0', '10'),
('11982', '36000', '100', '1', '-36000', '1', '0', '0', '10'),
('12057', '36000', '100', '1', '-36000', '1', '0', '0', '10'),
('12264', '36000', '100', '1', '-36000', '1', '0', '0', '10'),
('12056', '36000', '100', '1', '-36000', '1', '0', '0', '10'),
('11988', '36000', '100', '1', '-36000', '1', '0', '0', '10'),
('12098', '36000', '100', '1', '-36000', '1', '0', '0', '10'),
('11502', '36000', '100', '1', '-36000', '1', '0', '0', '10'),
('12259', '36000', '100', '1', '-36000', '1', '0', '0', '10');

INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `groupid`, `mincountOrRef`, `maxcount`, `condition_id`, `patch_min`, `patch_max`) VALUES
('16719', '36000', '100', '1', '-36000', '1', '0', '0', '10');

INSERT INTO `reference_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `groupid`, `mincountOrRef`, `maxcount`, `condition_id`, `patch_min`, `patch_max`) VALUES
('36000', '19227', '0', '1', '1', '1', '0', '0', '10'),
('36000', '19268', '0', '1', '1', '1', '0', '0', '10'),
('36000', '19276', '0', '1', '1', '1', '0', '0', '10'),
('36000', '19258', '0', '1', '1', '1', '0', '0', '10');

-- remove script from Annora master enchanter
UPDATE creature_template SET ScriptName='' WHERE entry=11073;
