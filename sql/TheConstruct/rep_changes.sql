
-- add AV rep to MC mobs at same rate
UPDATE `creature_onkill_reputation` SET `RewOnKillRepFaction2` = '729', `MaxStanding2` = '7', `RewOnKillRepValue2` = `RewOnKillRepValue1` WHERE `creature_id` IN ('11502', '11658', '11659', '11666', '11667', '11668', '11673', '11982', '11988', '12056', '12057', '12076', '12098', '12100', '12101', '12118', '12259', '12264');

-- add AB rep to ZG mobs at the same rate
UPDATE `creature_onkill_reputation` SET `RewOnKillRepFaction2` = '510', `MaxStanding2` = '7', `RewOnKillRepValue2` = `RewOnKillRepValue1` WHERE `creature_id` IN ('11338', '11339', '11340', '11350', '11351', '11352', '11353', '11356', '11359', '11361', '11365', '11370', '11371', '11372', '11373', '11374', '11380', '11382', '11387', '11388', '11391', '11830', '11831', '14507', '14509', '14510', '14515', '14517', '14532', '14750', '14821', '14825', '14834', '14880', '14882', '14883', '15043', '15082', '15083', '15084', '15085', '15111');

-- add 3rd rep gain on kill
ALTER TABLE `creature_onkill_reputation`   
  ADD COLUMN `RewOnKillRepFaction3` SMALLINT(6) DEFAULT 0  NOT NULL AFTER `RewOnKillRepFaction2`,
  ADD COLUMN `MaxStanding3` TINYINT(4) DEFAULT 0  NOT NULL AFTER `RewOnKillRepValue2`,
  ADD COLUMN `IsTeamAward3` TINYINT(4) DEFAULT 0  NOT NULL AFTER `MaxStanding3`,
  ADD COLUMN `RewOnKillRepValue3` MEDIUMINT(9) DEFAULT 0  NOT NULL AFTER `IsTeamAward3`;

-- add WSG rep to some stuff in AQ20/40
UPDATE `creature_onkill_reputation` SET `RewOnKillRepFaction3` = '889', `MaxStanding2` = '7', `MaxStanding3` = '7', `RewOnKillRepValue3` = `RewOnKillRepValue1` WHERE `creature_id` IN ('15229', '15230', '15235', '15236', '15240', '15246', '15249', '15250', '15252', '15262', '15264', '15275', '15276', '15277', '15311', '15312', '15339', '15340', '15341', '15348', '15369', '15370', '15727', '15741');
