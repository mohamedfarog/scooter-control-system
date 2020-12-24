-- phpMyAdmin SQL Dump
-- version 4.6.6deb5ubuntu0.5
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Dec 24, 2020 at 12:30 PM
-- Server version: 5.7.32-0ubuntu0.18.04.1
-- PHP Version: 7.2.24-0ubuntu0.18.04.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `gunseldb1`
--

-- --------------------------------------------------------

--
-- Table structure for table `employee_iot`
--

CREATE TABLE `employee_iot` (
  `id` int(11) NOT NULL,
  `registry` int(10) UNSIGNED DEFAULT NULL,
  `rfid` varchar(191) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin DEFAULT NULL,
  `name` varchar(45) CHARACTER SET utf8mb4 COLLATE utf8mb4_bin DEFAULT NULL,
  `category` int(11) NOT NULL,
  `created_at` timestamp NULL DEFAULT NULL,
  `updated_at` timestamp NULL DEFAULT NULL,
  `deleted_at` timestamp NULL DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Dumping data for table `employee_iot`
--

INSERT INTO `employee_iot` (`id`, `registry`, `rfid`, `name`, `category`, `created_at`, `updated_at`, `deleted_at`) VALUES
(2, 53159, '391754129070', 'A.Adewumi', 0, '2019-02-14 08:18:58', '2019-09-21 14:43:04', NULL),
(8, 96227, '599315291494', 'A.Gökalp', 0, '2019-02-14 08:18:58', '2019-09-27 07:30:52', NULL),
(9, 99479, '876114917897', 'A.Alçı', 0, '2019-02-14 08:18:58', '2019-09-16 07:42:49', NULL),
(10, 65484, '117608127770', 'A.Yıldırım', 0, '2019-02-14 08:18:58', '2019-09-14 07:56:15', NULL),
(11, 18307, '461715648289', 'A.Kazmacı', 0, '2019-02-14 08:18:58', '2019-09-20 11:36:10', NULL),
(12, 21962, '47990742721', 'A.Aydoğdu', 0, '2019-02-14 08:18:58', '2019-09-16 07:42:46', NULL),
(13, 17343, '392634867056', 'B.Güzelışık', 0, '2019-02-14 08:18:58', '2019-10-01 08:32:55', NULL),
(24, 34461, '392173559511	\n', 'E.Yakut', 0, '2019-02-14 08:18:58', '2019-09-14 07:56:25', NULL),
(25, 36365, '50154945131', 'E.Soylu', 0, '2019-02-14 08:18:58', '2019-09-14 07:56:26', NULL),
(26, 99179, '984685611899', 'E.Atmaca', 0, '2019-02-14 08:18:58', '2019-09-14 07:56:29', NULL),
(27, 55923, '	1009778073112', 'E.Çukur', 0, '2019-02-14 08:18:58', '2019-09-16 07:42:33', NULL),
(30, 53270, '256522890968', 'F.Turgut', 0, '2019-02-14 08:18:58', '2019-09-16 07:45:30', NULL),
(31, 64626, '731045292487', 'G.Tanta', 0, '2019-02-14 08:18:58', '2019-04-30 14:34:13', '2019-04-30 14:34:13'),
(32, 22370, NULL, 'H.Kayıkçı', 0, '2019-02-14 08:18:58', '2019-10-10 14:58:14', NULL),
(33, 99719, '	774157503972', 'H.Yakar', 0, '2019-02-14 08:18:58', '2019-08-26 16:47:01', NULL),
(35, 93235, '535599180025214', 'H.Sürer', 0, '2019-02-14 08:18:58', '2019-09-12 14:49:12', NULL),
(37, 12530, '119156219512', 'H.Erarslan', 0, '2019-02-14 08:18:58', '2019-10-07 05:37:41', NULL),
(39, 12588, '535919953857208', 'İ.Güreli', 0, '2019-02-14 08:18:58', '2019-08-29 07:29:20', '2019-08-29 07:29:20'),
(42, 46015, '666040442380', 'K.Bayrak', 0, '2019-02-14 08:18:58', '2019-10-24 16:31:38', NULL),
(43, 88464, NULL, 'K.Deniz', 0, '2019-02-14 08:18:58', '2019-09-14 07:56:42', NULL),
(44, 93947, '	531417767339', 'M.Eze', 0, '2019-02-14 08:18:58', '2019-09-17 05:43:16', NULL),
(45, 97774, '1057643289119', 'M.Durmuş', 0, '2019-02-14 08:18:58', '2019-09-14 07:56:47', NULL),
(46, 66242, '1078489161098	\n', 'M.Aykut', 0, '2019-02-14 08:18:58', '2019-08-26 16:47:11', NULL),
(48, 41401, '600188493486', 'M.Kibarer', 0, '2019-02-14 08:18:58', '2019-10-14 09:04:43', NULL),
(49, 69846, '734925331932', 'M.Tekdemir', 0, '2019-02-14 08:18:58', '2019-09-19 04:26:57', NULL),
(50, 53294, '461857660322', 'M.Akçakaya', 0, '2019-02-14 08:18:58', '2019-09-23 06:23:09', NULL),
(51, 24788, '116465577547	\n', 'M.Şahin', 0, '2019-02-14 08:18:58', '2019-09-14 07:56:54', NULL),
(54, 91329, '155883081017', 'M.Bilir', 0, '2019-02-14 08:18:58', '2019-03-08 13:49:00', NULL),
(56, 84323, '813206522563', 'M.Özdemir', 0, '2019-02-14 08:18:58', '2019-10-18 11:54:34', NULL),
(57, 97040, '667613896085', 'N.Elmas', 0, '2019-02-14 08:18:58', '2019-09-14 07:56:58', NULL),
(58, 86498, '600205270703	\n', 'N.Koşak', 0, '2019-02-14 08:18:58', '2019-09-16 07:48:29', NULL),
(59, 82840, '1082148232863', 'O.Akan', 0, '2019-02-14 08:18:58', '2019-09-16 07:48:52', NULL),
(61, 88752, '461408607875', 'O.Genç', 0, '2019-02-14 08:18:58', '2019-09-14 07:57:00', NULL),
(65, 28305, '942099439260	\n', 'Ö.Kalaycı', 0, '2019-02-14 08:18:58', '2019-09-16 07:53:59', NULL),
(66, 79918, '598148816419', 'Ö.Tan', 0, '2019-02-14 08:18:58', '2019-08-26 16:47:28', NULL),
(67, 72691, '394749189580', 'P.Adsız', 0, '2019-02-14 08:18:58', '2019-09-18 17:45:38', NULL),
(68, 20885, '1011606665901', 'P.Denizol', 0, '2019-02-14 08:18:58', '2019-09-14 07:57:08', NULL),
(71, 90630, '118338592399', 'S.Öztürk', 0, '2019-02-14 08:18:58', '2019-10-08 05:46:29', NULL),
(72, 31118, '324101385826', 'S.Kudak', 0, '2019-02-14 08:18:58', '2019-09-16 07:49:36', NULL),
(73, 23373, '806368157395', 'S.Eker', 0, '2019-02-14 08:18:58', '2019-10-17 09:06:42', NULL),
(74, 99549, '295755124212', 'S.Zurnacı', 0, '2019-02-14 08:18:58', '2019-08-26 16:47:33', NULL),
(76, 99969, '666164371042', 'S.Tanta', 0, '2019-02-14 08:18:58', '2019-08-26 16:47:37', NULL),
(78, 27345, '119947238913', 'S.Mustapha', 0, '2019-02-14 08:18:58', '2019-10-05 14:53:46', NULL),
(80, 98604, '185034054977', 'S.Polat', 0, '2019-02-14 08:18:58', '2019-10-17 07:21:16', NULL),
(81, 18282, '944235785851	\n', 'S.Erçetin', 0, '2019-02-14 08:18:58', '2019-09-20 11:59:27', NULL),
(82, 99589, '19870715338	\n', 'T.Güven Zurnacı', 0, '2019-02-14 08:18:58', '2019-09-16 11:09:58', NULL),
(83, 89555, '875922763653', 'T.Üngör', 0, '2019-02-14 08:18:58', '2019-09-14 07:57:13', NULL),
(86, 95632, '	598216384036', 'V.Kıvrak', 0, '2019-02-14 08:18:58', '2019-09-24 05:22:58', NULL),
(88, 99349, '706662239611', 'Y.Akgün', 0, '2019-02-14 08:18:58', '2019-10-15 08:58:05', NULL),
(89, 28480, '472265575532', 'Y.Arıcan', 0, '2019-02-14 08:18:58', '2019-10-02 08:17:40', NULL),
(93, 60598, '737641536852', 'C.Cengiz', 0, '2019-02-21 05:16:53', '2019-09-16 07:42:38', NULL),
(95, 67343, '322608471356', 'A.Sağlam', 0, '2019-03-21 10:08:48', '2019-09-16 08:10:19', NULL),
(96, 68672, '528629280259', 'M.Alaca', 0, '2019-03-28 10:47:21', '2019-09-14 07:57:17', NULL),
(101, 89133, '300873931498', 'A.Azzam', 1, '2019-05-28 06:45:27', '2019-09-05 13:46:36', '2019-09-05 13:46:36'),
(103, 25814, '188229988150', 'O.Eldeş', 0, '2019-06-13 13:13:34', '2019-09-14 07:57:18', NULL),
(106, 36663, '292281847071', 'M.Alaca', 0, '2019-07-08 08:23:29', '2019-10-05 15:02:17', NULL),
(107, 41347, '1080930319002', 'F.Horozoğlu', 0, '2019-07-11 05:28:26', '2019-10-18 06:38:44', NULL),
(109, 84150, '1056586783319', 'K.Durukan', 0, '2019-07-15 05:22:40', '2019-09-23 08:24:00', '2019-09-23 08:24:00'),
(112, 87731, '874533723790', 'M.Korkmaz', 0, '2019-07-15 11:36:56', '2019-10-19 06:49:04', NULL),
(113, 94150, '599581503083', 'S.Dalgıç', 0, '2019-07-15 14:44:28', '2019-10-05 14:59:42', NULL),
(114, 29800, '530863926968	\n', 'F.Karataş', 0, '2019-07-19 14:49:15', '2019-10-16 13:16:12', NULL),
(115, 82887, '	394412732149', 'A.Kilimci', 0, '2019-07-29 13:41:43', '2019-07-29 13:41:43', NULL),
(116, 45835, '1080326142653	\n', 'M.Fallaha', 0, '2019-08-05 07:20:31', '2019-10-05 15:01:49', NULL),
(117, 55475, '	882387700756', 'K.Demircioğlu	', 0, '2019-08-08 13:06:58', '2019-10-10 06:17:17', '2019-10-10 06:17:17'),
(125, 13190, '942025584440', 'İ.Beceren', 3, '2019-09-23 11:22:08', '2019-10-16 13:13:58', NULL),
(126, 97006, '804067520266', 'M.Mohamed', 0, '2019-09-27 05:25:54', '2019-10-16 13:10:22', '2020-05-27 21:00:00'),
(128, 46926, '	667705850377', 'S.Elgammudi', 0, '2019-10-02 05:22:42', '2019-10-16 13:17:14', NULL),
(129, 91064, '	1052750449459', 'S.Kırlı', 0, '2019-10-14 11:31:19', '2019-10-24 07:49:49', NULL),
(130, 54988, '738346573116', 'N.Işık', 0, '2019-10-18 15:43:56', '2019-10-25 10:42:42', NULL),
(131, 19584, '738550849231', 'S,Kaymakçıoğlu', 0, '2020-09-06 21:00:00', '2020-09-01 21:00:00', '2020-09-07 21:00:00'),
(132, 84331, '117178343058', 'A.Uskuri', 0, NULL, NULL, NULL),
(133, 39362, '461205511530', 'A.Özkan', 0, NULL, NULL, NULL),
(134, 99264, '254731071484', 'E.Özden', 0, NULL, NULL, NULL),
(135, 54921, '1079913979370', 'U.Çekmegül', 0, NULL, NULL, NULL),
(136, 92199, '597609324155', 'M.Şimşek', 0, NULL, NULL, NULL),
(137, 77993, '592713768104', 'M.Tecimen', 0, NULL, NULL, NULL),
(138, 68660, '942793010720', 'E.Açış', 0, NULL, NULL, NULL),
(139, 22831, '736424140303', 'C.Özberkmen	', 0, NULL, NULL, NULL),
(140, 30740, '50401292094', 'O.Karabay', 0, NULL, NULL, NULL),
(141, 73009, '735430155779', 'MD.Patoari', 0, NULL, NULL, NULL),
(142, 72720, '390901119591', 'Y.Hossain', 0, NULL, NULL, NULL),
(143, 39811, '50977684206', 'F.Ali', 0, NULL, NULL, NULL),
(144, 28483, '1011164421635', 'J.Tarif', 0, NULL, NULL, NULL),
(145, 61510, '806975814243', 'M.Mamrul	', 0, NULL, NULL, NULL),
(146, 16349, '47268732667', 'G.Mert	', 0, NULL, NULL, NULL),
(147, 66538, '188370497183', 'S.Doğu', 0, NULL, NULL, NULL),
(148, 25964, '324016512325', 'A.Buçaklı', 0, NULL, NULL, NULL),
(149, 28285, '800838642069', 'D.Abdullina', 0, NULL, NULL, NULL),
(150, 22718, '529261836941', 'M.Yüzer	', 0, NULL, NULL, NULL),
(151, 96009, '943785877246', 'B.Alşan	', 0, NULL, NULL, NULL),
(152, 44943, '737104342604', 'M.Eker', 0, NULL, NULL, NULL),
(153, 89969, '804498742709', 'S.Osmanbuba', 0, NULL, NULL, NULL),
(154, 46149, '912938896688', 'Y.Beyoğlu', 0, NULL, NULL, NULL),
(155, 70068, '598417317426', 'M.Ayan', 0, NULL, NULL, NULL),
(156, 80338, '365011471812	\r\n', 'G.Çırak', 0, NULL, NULL, NULL),
(157, 62247, '49668209237', 'S.Fakir	', 0, NULL, NULL, NULL),
(158, 86987, '535535323462405445	\r\n', 'R.Güngör	', 0, NULL, NULL, NULL),
(159, 58205, '535535116786896574', ' S.Doğan	', 0, NULL, NULL, NULL),
(160, 89634, '535535463805455871', 'M.Çobanoğlu	', 0, NULL, NULL, NULL),
(161, 38145, '535535535805052849589', 'M.Çobanoğlu', 0, NULL, NULL, NULL),
(162, 24366, '535535324033289540', 'S.Demir	', 0, NULL, NULL, NULL),
(163, 22981, '528574619252', 'G.Kuvvet	', 0, NULL, NULL, NULL),
(164, 97524, '255684287961', 'G.Tunçel', 0, NULL, NULL, NULL),
(165, 46131, '942011424336', 'E.Parmaksız', 0, NULL, NULL, NULL),
(166, 79232, '186023451941', 'H.ÇELEBİ	', 0, NULL, NULL, NULL),
(167, 29220, '804537216865', 'Ö.Askaroglu	', 0, NULL, NULL, NULL),
(168, 19813, '804537216865', 'Ö.Uysal	', 0, NULL, NULL, NULL),
(169, 45695, '805005991507', 'D.Şeker', 0, NULL, NULL, NULL),
(170, 69237, '322498764463', 'A.Balcı	', 0, NULL, NULL, NULL),
(171, 80031, '532404088545', 'M.Celik', 0, NULL, NULL, NULL),
(172, 90693, '1081481535226', 'L.Kılıç	', 0, NULL, NULL, NULL),
(173, 95000, '51125132857', 'E.Ağustos	', 0, NULL, NULL, NULL),
(174, 75775, '918342271091', 'T.Kılınç	', 0, NULL, NULL, NULL),
(175, 87785, '50323758757', 'F.Alkan	', 0, NULL, NULL, NULL),
(176, 93126, '875289030629', 'C.Eze	', 0, NULL, NULL, NULL),
(177, 94541, '460089241519', 'A.Aligüllü	', 0, NULL, NULL, NULL),
(178, 37253, '460047424796', 'E.Uyar', 0, NULL, NULL, NULL),
(179, 26878, '872364285372', 'İ.Çelikkol	', 0, NULL, NULL, NULL),
(180, 26115, '49533991501', 'B.Copur	', 0, NULL, NULL, NULL),
(181, 73226, '1080309365426', 'Y.Hurmuz', 0, NULL, NULL, NULL),
(182, 64115, '48897374801', 'E.Ercan	', 0, NULL, NULL, NULL),
(183, 96793, '535531812760209	\r\n', 'A.Egrik	', 0, NULL, NULL, NULL),
(184, 66548, '462455028234	\r\n', 'F.Fırtına	', 0, NULL, NULL, NULL),
(185, 70952, '875022760609', 'M.Macit	', 0, NULL, NULL, NULL),
(186, 51505, '393131375133', 'M.AlShalabi	', 0, NULL, NULL, NULL),
(187, 40880, '530073820496', 'A.Miah	', 0, NULL, NULL, NULL),
(188, 97715, '325259337115', 'R.Amin	', 0, NULL, NULL, NULL),
(189, 88835, '393114597906', 'A.Hossen	', 0, NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `gonyeli_spots`
--

CREATE TABLE `gonyeli_spots` (
  `id` int(20) NOT NULL,
  `spot_id` varchar(45) NOT NULL,
  `spot_status` int(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `gonyeli_spots`
--

INSERT INTO `gonyeli_spots` (`id`, `spot_id`, `spot_status`) VALUES
(1, 'spot_1', 1),
(2, 'spot_2', 0),
(3, 'spot_3', 0),
(4, 'spot_4', 0),
(5, 'spot_5', 0),
(6, 'spot_6', 0),
(7, 'spot_7', 0),
(8, 'spot_8', 0),
(9, 'spot_9', 0),
(10, 'spot_10', 0);

-- --------------------------------------------------------

--
-- Table structure for table `lef_spots`
--

CREATE TABLE `lef_spots` (
  `id` int(20) NOT NULL,
  `spot_id` varchar(45) NOT NULL,
  `spot_status` int(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `lef_spots`
--

INSERT INTO `lef_spots` (`id`, `spot_id`, `spot_status`) VALUES
(1, 'spot_1', 1),
(2, 'spot_2', 0),
(3, 'spot_3', 0),
(4, 'spot_4', 1),
(5, 'spot_5', 0),
(6, 'spot_6', 0),
(7, 'spot_7', 1),
(8, 'spot_8', 1),
(9, 'spot_9', 1),
(10, 'spot_10', 1);

-- --------------------------------------------------------

--
-- Table structure for table `magusa_spots`
--

CREATE TABLE `magusa_spots` (
  `id` int(20) NOT NULL,
  `spot_id` varchar(45) NOT NULL,
  `spot_status` int(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `magusa_spots`
--

INSERT INTO `magusa_spots` (`id`, `spot_id`, `spot_status`) VALUES
(1, 'spot_1', 1),
(2, 'spot_2', 1),
(3, 'spot_3', 1),
(4, 'spot_4', 0),
(5, 'spot_5', 0),
(6, 'spot_6', 1),
(7, 'spot_7', 1),
(8, 'spot_8', 0),
(9, 'spot_9', 0),
(10, 'spot_10', 1);

-- --------------------------------------------------------

--
-- Table structure for table `scooters`
--

CREATE TABLE `scooters` (
  `id` int(11) NOT NULL,
  `scooter_id` varchar(45) COLLATE utf8_turkish_ci NOT NULL,
  `scooter_name` varchar(45) COLLATE utf8_turkish_ci NOT NULL,
  `status` int(11) NOT NULL,
  `employee_id` varchar(45) COLLATE utf8_turkish_ci DEFAULT 'Available',
  `emp_category` varchar(45) COLLATE utf8_turkish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Dumping data for table `scooters`
--

INSERT INTO `scooters` (`id`, `scooter_id`, `scooter_name`, `status`, `employee_id`, `emp_category`) VALUES
(1, 'scooter_1', 's1', 1, 'Available', '1'),
(2, 'scooter_2', 's2', 1, 'Available', '1'),
(3, 'scooter_3', 's3', 1, 'Available', '2'),
(4, 'scooter_4', 's4', 1, 'Available', '1'),
(5, 'scooter_5', 's5', 1, 'Available', '1'),
(6, 'scooter_6', 's6', 1, 'Available', '2'),
(7, 'scooter_7', 's7', 1, 'Available', '2'),
(8, 'scooter_8', 's8', 1, 'Available', '2'),
(9, 'scooter_9', 's9', 1, 'Available', '2'),
(10, 'scooter_10', 's10', 1, 'Available', '2'),
(11, 'scooter_11', 's11', 1, 'Available', '3'),
(12, 'scooter_12', 's12', 1, 'Available', '3'),
(13, 'scooter_13', 's13', 1, 'Available', '3'),
(14, 'scooter_14', 's14', 1, 'Available', '3'),
(15, 'scooter_15', 's15', 1, 'Available', '3'),
(16, 'scooter_16', 's16', 1, 'Available', '4'),
(17, 'scooter_17', 's17', 1, 'Available', '4'),
(18, 'scooter_18', 's18', 1, 'Available', '4'),
(19, 'scooter_19', 's19', 1, 'Available', '4'),
(20, 'scooter_20', 's20', 1, 'Available', '4');

-- --------------------------------------------------------

--
-- Table structure for table `scooter_log`
--

CREATE TABLE `scooter_log` (
  `id` int(11) NOT NULL,
  `employee_id` varchar(45) DEFAULT NULL,
  `scooter_name` varchar(45) DEFAULT NULL,
  `date` varchar(45) DEFAULT NULL,
  `hour` varchar(45) DEFAULT NULL,
  `operation` varchar(45) DEFAULT NULL,
  `location` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `scooter_log`
--

INSERT INTO `scooter_log` (`id`, `employee_id`, `scooter_name`, `date`, `hour`, `operation`, `location`) VALUES
(133, '97006', 'scooter_15', '08/09/2020', '09:38:48', 'Scooter Taken', 'Girne Station'),
(134, '82887', 'scooter_6', '08/09/2020', '11:40:03', 'Scooter Taken', 'Lefkosa Station'),
(135, '97006', 'scooter_15', '08/09/2020', '11:41:18', 'Scooter Returned', 'Lefkosa Station'),
(136, '82887', 'scooter_6', '08/09/2020', '09:42:04', 'Scooter Returned', 'Girne Station'),
(137, '97006', 'scooter_15', '09/09/2020', '13:36:57', 'Scooter Taken', 'Lefkosa Station'),
(138, '97006', 'scooter_15', '09/09/2020', '13:37:21', 'Scooter Returned', 'Lefkosa Station'),
(139, '97006', 'scooter_15', '09/09/2020', '13:44:50', 'Scooter Taken', 'Lefkosa Station'),
(140, '97006', 'scooter_15', '09/09/2020', '13:45:26', 'Scooter Returned', 'Lefkosa Station'),
(141, '97006', 'scooter_15', '09/09/2020', '14:30:20', 'Scooter Taken', 'Lefkosa Station'),
(142, '97006', 'scooter_15', '09/09/2020', '14:30:44', 'Scooter Returned', 'Lefkosa Station'),
(143, '82887', 'scooter_6', '09/09/2020', '14:31:19', 'Scooter Taken', 'Lefkosa Station'),
(144, '97006', 'scooter_15', '09/09/2020', '14:31:48', 'Scooter Taken', 'Lefkosa Station'),
(145, '97006', 'scooter_15', '09/09/2020', '14:32:14', 'Scooter Returned', 'Lefkosa Station'),
(146, '82887', 'scooter_6', '09/09/2020', '14:32:33', 'Scooter Returned', 'Lefkosa Station'),
(147, '82887', 'scooter_6', '10/09/2020', '10:49:18', 'Scooter Taken', 'Lefkosa Station'),
(148, '82887', 'scooter_6', '10/09/2020', '10:51:25', 'Scooter Returned', 'Lefkosa Station'),
(149, '82887', 'scooter_6', '10/09/2020', '10:54:16', 'Scooter Taken', 'Lefkosa Station'),
(150, '82887', 'scooter_6', '10/09/2020', '10:54:59', 'Scooter Returned', 'Lefkosa Station'),
(151, '82887', 'scooter_6', '10/09/2020', '11:02:37', 'Scooter Taken', 'Lefkosa Station'),
(152, '82887', 'scooter_6', '10/09/2020', '11:08:44', 'Scooter Returned', 'Lefkosa Station'),
(153, '82887', 'scooter_6', '10/09/2020', '11:29:17', 'Scooter Taken', 'Lefkosa Station'),
(154, '82887', 'scooter_6', '10/09/2020', '14:00:03', 'Scooter Returned', 'Lefkosa Station'),
(155, '82887', 'scooter_6', '10/09/2020', '14:08:20', 'Scooter Taken', 'Lefkosa Station'),
(156, '82887', 'scooter_6', '10/09/2020', '14:08:50', 'Scooter Returned', 'Lefkosa Station'),
(157, '82887', 'scooter_6', '10/09/2020', '14:09:28', 'Scooter Taken', 'Lefkosa Station'),
(158, '82887', 'scooter_6', '10/09/2020', '14:09:59', 'Scooter Returned', 'Lefkosa Station'),
(159, '82887', 'scooter_6', '10/09/2020', '14:10:27', 'Scooter Taken', 'Lefkosa Station'),
(160, '82887', 'scooter_6', '10/09/2020', '14:10:47', 'Scooter Returned', 'Lefkosa Station'),
(161, '82887', 'scooter_6', '10/09/2020', '14:13:02', 'Scooter Taken', 'Lefkosa Station'),
(162, '97006', 'scooter_8', '10/09/2020', '14:16:16', 'Scooter Returned', 'Lefkosa Station'),
(163, '82887', 'scooter_6', '10/09/2020', '14:16:49', 'Scooter Taken', 'Lefkosa Station'),
(164, '82887', 'scooter_6', '10/09/2020', '12:34:38', 'Scooter Returned', 'Lefkosa Station'),
(165, '82887', 'scooter_6', '11/09/2020', '19:49:01', 'Scooter Taken', 'Lefkosa Station'),
(166, '82887', 'scooter_6', '11/09/2020', '19:49:37', 'Scooter Returned', 'Lefkosa Station'),
(167, '82887', 'scooter_6', '11/09/2020', '19:52:06', 'Scooter Taken', 'Lefkosa Station'),
(168, '82887', 'scooter_6', '11/09/2020', '20:32:47', 'Scooter Returned', 'Lefkosa Station'),
(169, '97006', 'scooter_15', '14/09/2020', '12:39:57', 'Scooter Taken', 'Lefkosa Station'),
(170, '97006', 'scooter_15', '14/09/2020', '12:40:38', 'Scooter Returned', 'Lefkosa Station'),
(171, '97006', 'scooter_15', '14/09/2020', '12:35:08', 'Scooter Taken', 'Lefkosa Station'),
(172, '97006', 'scooter_15', '14/09/2020', '12:35:38', 'Scooter Returned', 'Lefkosa Station'),
(173, '97006', 'scooter_15', '14/09/2020', '15:40:41', 'Scooter Taken', 'Girne Station'),
(174, '97006', 'scooter_15', '14/09/2020', '15:41:06', 'Scooter Returned', 'Girne Station'),
(175, '97006', 'scooter_15', '14/09/2020', '15:41:46', 'Scooter Taken', 'Girne Station'),
(176, '97006', 'scooter_15', '14/09/2020', '15:42:14', 'Scooter Returned', 'Girne Station'),
(177, '97006', 'scooter_15', '14/09/2020', '16:45:56', 'Scooter Taken', 'Girne Station'),
(178, '97006', 'scooter_15', '14/09/2020', '16:48:16', 'Scooter Returned', 'Girne Station'),
(179, '97006', 'scooter_15', '14/09/2020', '16:49:43', 'Scooter Taken', 'Girne Station'),
(180, '97006', 'scooter_15', '14/09/2020', '16:53:14', 'Scooter Returned', 'Girne Station'),
(181, '97006', 'scooter_15', '14/09/2020', '16:54:29', 'Scooter Taken', 'Girne Station'),
(182, '97006', 'scooter_15', '14/09/2020', '17:03:29', 'Scooter Returned', 'Girne Station'),
(183, '97006', 'scooter_15', '14/09/2020', '17:05:00', 'Scooter Taken', 'Girne Station'),
(184, '97006', 'scooter_15', '14/09/2020', '17:07:38', 'Scooter Returned', 'Girne Station'),
(185, '97006', 'scooter_15', '14/09/2020', '17:09:13', 'Scooter Taken', 'Girne Station'),
(186, '97006', 'scooter_15', '14/09/2020', '17:10:12', 'Scooter Returned', 'Girne Station'),
(187, '97006', 'scooter_15', '14/09/2020', '17:14:18', 'Scooter Taken', 'Girne Station'),
(188, '97006', '', '14/09/2020', '17:17:48', 'Scooter Taken', 'Girne Station'),
(189, '82887', 'scooter_6', '14/09/2020', '17:20:11', 'Scooter Taken', 'Girne Station'),
(190, '82887', 'scooter_6', '14/09/2020', '17:32:57', 'Scooter Returned', 'Girne Station'),
(191, '82887', 'scooter_6', '14/09/2020', '17:33:04', 'Scooter Returned', 'Girne Station'),
(192, '97006', 'scooter_15', '14/09/2020', '17:33:36', 'Scooter Returned', 'Girne Station'),
(193, '97006', 'scooter_15', '14/09/2020', '17:34:53', 'Scooter Taken', 'Girne Station'),
(194, '82887', 'scooter_6', '14/09/2020', '17:43:47', 'Scooter Taken', 'Girne Station'),
(195, '82887', 'scooter_6', '14/09/2020', '17:45:33', 'Scooter Returned', 'Girne Station'),
(196, '82887', 'scooter_6', '14/09/2020', '17:45:39', 'Scooter Returned', 'Girne Station'),
(197, '82887', 'scooter_6', '14/09/2020', '17:47:29', 'Scooter Taken', 'Girne Station'),
(198, '82887', 'scooter_6', '14/09/2020', '17:48:13', 'Scooter Returned', 'Girne Station'),
(199, '82887', 'scooter_6', '14/09/2020', '18:00:26', 'Scooter Taken', 'Girne Station'),
(200, '97006', 'scooter_15', '14/09/2020', '18:02:12', 'Scooter Returned', 'Girne Station'),
(201, '82887', 'scooter_6', '16/09/2020', '15:51:59', 'Scooter Returned', 'Girne Station'),
(202, '82887', 'scooter_6', '16/09/2020', '15:54:13', 'Scooter Taken', 'Girne Station'),
(203, '82887', 'scooter_6', '16/09/2020', '15:54:59', 'Scooter Returned', 'Girne Station'),
(204, '97006', 'scooter_15', '17/09/2020', '18:40:39', 'Scooter Taken', 'Girne Station'),
(205, '97006', 'scooter_15', '17/09/2020', '18:41:10', 'Scooter Returned', 'Girne Station'),
(206, '97006', 'scooter_15', '17/09/2020', '18:45:53', 'Scooter Taken', 'Girne Station'),
(207, '97006', 'scooter_15', '17/09/2020', '18:46:55', 'Scooter Returned', 'Girne Station'),
(208, '97006', 'scooter_15', '17/09/2020', '18:47:46', 'Scooter Taken', 'Girne Station'),
(209, '97006', 'scooter_15', '17/09/2020', '18:49:12', 'Scooter Returned', 'Girne Station'),
(210, '97006', 'scooter_15', '17/09/2020', '18:53:25', 'Scooter Taken', 'Girne Station'),
(211, '97006', 'scooter_15', '17/09/2020', '18:56:16', 'Scooter Returned', 'Girne Station'),
(212, '97006', 'scooter_15', '17/09/2020', '19:01:50', 'Scooter Taken', 'Girne Station'),
(213, '97006', 'scooter_15', '17/09/2020', '19:20:41', 'Scooter Returned', 'Girne Station'),
(214, '97006', 'scooter_15', '17/09/2020', '19:24:14', 'Scooter Taken', 'Girne Station'),
(215, '97006', 'scooter_15', '17/09/2020', '19:24:38', 'Scooter Returned', 'Girne Station'),
(216, '97006', 'scooter_15', '17/09/2020', '19:25:56', 'Scooter Taken', 'Girne Station'),
(217, '97006', 'scooter_15', '17/09/2020', '19:28:20', 'Scooter Returned', 'Girne Station'),
(218, '97006', 'scooter_15', '17/09/2020', '19:29:12', 'Scooter Taken', 'Girne Station'),
(219, '97006', 'scooter_15', '17/09/2020', '19:37:40', 'Scooter Returned', 'Girne Station'),
(220, '97006', 'scooter_15', '17/09/2020', '19:38:47', 'Scooter Taken', 'Girne Station'),
(221, '97006', 'scooter_15', '17/09/2020', '19:39:49', 'Scooter Returned', 'Girne Station'),
(222, '97006', 'scooter_15', '17/09/2020', '19:41:38', 'Scooter Taken', 'Girne Station'),
(223, '97006', 'scooter_15', '17/09/2020', '19:44:59', 'Scooter Returned', 'Girne Station'),
(224, '97006', 'scooter_15', '17/09/2020', '19:54:04', 'Scooter Taken', 'Girne Station'),
(225, '97006', 'scooter_15', '18/09/2020', '08:22:13', 'Scooter Returned', 'Girne Station'),
(226, '97006', 'scooter_15', '18/09/2020', '08:24:38', 'Scooter Taken', 'Girne Station'),
(227, '97006', 'scooter_15', '18/09/2020', '08:26:52', 'Scooter Returned', 'Girne Station'),
(228, '97006', 'scooter_15', '18/09/2020', '08:28:31', 'Scooter Taken', 'Girne Station'),
(229, '97006', 'scooter_15', '18/09/2020', '08:29:00', 'Scooter Returned', 'Girne Station'),
(230, '97006', 'scooter_15', '18/09/2020', '08:39:05', 'Scooter Taken', 'Girne Station'),
(231, '97006', 'scooter_15', '18/09/2020', '08:40:43', 'Scooter Returned', 'Girne Station'),
(232, '97006', 'scooter_15', '18/09/2020', '08:41:50', 'Scooter Taken', 'Girne Station'),
(233, '97006', 'scooter_15', '18/09/2020', '08:44:17', 'Scooter Returned', 'Girne Station'),
(234, '97006', 'scooter_15', '18/09/2020', '08:45:16', 'Scooter Taken', 'Girne Station'),
(235, '97006', 'scooter_15', '18/09/2020', '08:46:17', 'Scooter Returned', 'Girne Station'),
(236, '97006', 'scooter_15', '18/09/2020', '08:47:47', 'Scooter Taken', 'Girne Station'),
(237, '97006', 'scooter_15', '18/09/2020', '08:48:25', 'Scooter Returned', 'Girne Station'),
(238, '97006', 'scooter_15', '18/09/2020', '08:50:02', 'Scooter Taken', 'Girne Station'),
(239, '97006', 'scooter_15', '18/09/2020', '08:50:35', 'Scooter Returned', 'Girne Station'),
(240, '97006', 'scooter_15', '18/09/2020', '08:53:43', 'Scooter Taken', 'Girne Station'),
(241, '97006', 'scooter_15', '18/09/2020', '09:06:15', 'Scooter Returned', 'Girne Station'),
(242, '97006', 'scooter_15', '18/09/2020', '09:07:44', 'Scooter Taken', 'Girne Station'),
(243, '97006', 'scooter_15', '18/09/2020', '09:08:21', 'Scooter Returned', 'Girne Station'),
(244, '97006', 'scooter_15', '18/09/2020', '09:09:25', 'Scooter Taken', 'Girne Station'),
(245, '97006', 'scooter_15', '18/09/2020', '09:09:58', 'Scooter Returned', 'Girne Station'),
(246, '97006', 'scooter_15', '18/09/2020', '09:11:25', 'Scooter Taken', 'Girne Station'),
(247, '97006', 'scooter_15', '18/09/2020', '09:12:14', 'Scooter Returned', 'Girne Station'),
(248, '97006', 'scooter_15', '18/09/2020', '09:13:35', 'Scooter Taken', 'Girne Station'),
(249, '97006', 'scooter_15', '18/09/2020', '09:14:04', 'Scooter Returned', 'Girne Station'),
(250, '97006', 'scooter_15', '18/09/2020', '09:15:07', 'Scooter Taken', 'Girne Station'),
(251, '97006', 'scooter_15', '18/09/2020', '09:15:35', 'Scooter Returned', 'Girne Station'),
(252, '97006', 'scooter_15', '18/09/2020', '09:25:59', 'Scooter Taken', 'Girne Station'),
(253, '97006', 'scooter_15', '18/09/2020', '09:26:56', 'Scooter Returned', 'Girne Station'),
(254, '97006', 'scooter_15', '18/09/2020', '09:34:48', 'Scooter Taken', 'Girne Station'),
(255, '97006', 'scooter_15', '18/09/2020', '09:35:45', 'Scooter Returned', 'Girne Station'),
(256, '97006', 'scooter_15', '18/09/2020', '09:36:38', 'Scooter Taken', 'Girne Station'),
(257, '97006', 'scooter_15', '18/09/2020', '09:44:32', 'Scooter Returned', 'Girne Station'),
(258, '97006', 'scooter_15', '18/09/2020', '09:44:48', 'Scooter Returned', 'Girne Station'),
(259, '97006', 'scooter_15', '18/09/2020', '09:45:04', 'Scooter Returned', 'Girne Station'),
(260, '97006', 'scooter_15', '18/09/2020', '09:47:05', 'Scooter Taken', 'Girne Station'),
(261, '97006', 'scooter_15', '18/09/2020', '09:48:05', 'Scooter Returned', 'Girne Station'),
(262, '97006', 'scooter_15', '18/09/2020', '09:49:01', 'Scooter Taken', 'Girne Station'),
(263, '97006', 'scooter_15', '18/09/2020', '09:49:19', 'Scooter Returned', 'Girne Station'),
(264, '97006', 'scooter_15', '18/09/2020', '09:51:36', 'Scooter Taken', 'Girne Station'),
(265, '97006', 'scooter_15', '18/09/2020', '09:53:13', 'Scooter Returned', 'Girne Station'),
(266, '97006', 'scooter_15', '18/09/2020', '09:53:58', 'Scooter Taken', 'Girne Station'),
(267, '97006', 'scooter_15', '18/09/2020', '09:57:08', 'Scooter Returned', 'Girne Station'),
(268, '97006', 'scooter_15', '18/09/2020', '09:57:56', 'Scooter Taken', 'Girne Station'),
(269, '97006', 'scooter_15', '18/09/2020', '09:58:50', 'Scooter Returned', 'Girne Station'),
(270, '97006', 'scooter_15', '18/09/2020', '09:59:57', 'Scooter Taken', 'Girne Station'),
(271, '97006', 'scooter_15', '18/09/2020', '10:00:23', 'Scooter Returned', 'Girne Station'),
(272, '97006', 'scooter_15', '18/09/2020', '10:04:52', 'Scooter Taken', 'Girne Station'),
(273, '97006', 'scooter_15', '18/09/2020', '10:05:24', 'Scooter Returned', 'Girne Station'),
(274, '97006', 'scooter_15', '18/09/2020', '10:07:01', 'Scooter Taken', 'Girne Station'),
(275, '97006', 'scooter_15', '18/09/2020', '10:11:29', 'Scooter Returned', 'Girne Station'),
(276, '97006', 'scooter_15', '18/09/2020', '10:15:44', 'Scooter Taken', 'Girne Station'),
(277, '97006', 'scooter_15', '18/09/2020', '10:17:09', 'Scooter Returned', 'Girne Station'),
(278, '97006', 'scooter_15', '18/09/2020', '10:20:05', 'Scooter Taken', 'Girne Station'),
(279, '97006', 'scooter_15', '18/09/2020', '10:21:38', 'Scooter Returned', 'Girne Station'),
(280, '97006', 'scooter_15', '18/09/2020', '10:23:10', 'Scooter Taken', 'Girne Station'),
(281, '97006', 'scooter_15', '18/09/2020', '10:24:43', 'Scooter Returned', 'Girne Station'),
(282, '97006', 'scooter_15', '18/09/2020', '10:25:50', 'Scooter Taken', 'Girne Station'),
(283, '97006', 'scooter_15', '18/09/2020', '10:27:20', 'Scooter Returned', 'Girne Station'),
(284, '97006', 'scooter_15', '18/09/2020', '10:28:38', 'Scooter Taken', 'Girne Station'),
(285, '97006', 'scooter_15', '18/09/2020', '10:49:11', 'Scooter Returned', 'Girne Station'),
(286, '97006', 'scooter_15', '18/09/2020', '11:07:59', 'Scooter Taken', 'Girne Station'),
(287, '97006', 'scooter_15', '18/09/2020', '11:09:19', 'Scooter Returned', 'Girne Station'),
(288, '97006', 'scooter_15', '18/09/2020', '17:16:32', 'Scooter Taken', 'Girne Station'),
(289, '97006', 'scooter_15', '18/09/2020', '17:17:41', 'Scooter Returned', 'Girne Station'),
(290, '97006', 'scooter_15', '18/09/2020', '17:18:47', 'Scooter Taken', 'Girne Station'),
(291, '97006', 'scooter_15', '18/09/2020', '17:33:22', 'Scooter Returned', 'Girne Station'),
(292, '97006', 'scooter_15', '18/09/2020', '17:34:02', 'Scooter Taken', 'Girne Station'),
(293, '97006', 'scooter_15', '18/09/2020', '17:37:44', 'Scooter Returned', 'Girne Station'),
(294, '97006', 'scooter_15', '18/09/2020', '17:41:22', 'Scooter Taken', 'Girne Station'),
(295, '97006', 'scooter_15', '18/09/2020', '17:45:37', 'Scooter Returned', 'Girne Station'),
(296, '97006', 'scooter_15', '18/09/2020', '17:48:52', 'Scooter Taken', 'Girne Station'),
(297, '97006', 'scooter_15', '18/09/2020', '18:57:37', 'Scooter Returned', 'Girne Station'),
(298, '97006', 'scooter_15', '18/09/2020', '18:58:31', 'Scooter Taken', 'Girne Station'),
(299, '97006', 'scooter_15', '18/09/2020', '18:59:32', 'Scooter Returned', 'Girne Station'),
(300, '97006', 'scooter_15', '18/09/2020', '19:00:19', 'Scooter Taken', 'Girne Station'),
(301, '97006', 'scooter_15', '18/09/2020', '19:04:23', 'Scooter Returned', 'Girne Station'),
(302, '97006', 'scooter_15', '18/09/2020', '19:05:09', 'Scooter Taken', 'Girne Station'),
(303, '97006', 'scooter_15', '18/09/2020', '19:06:16', 'Scooter Returned', 'Girne Station'),
(304, '97006', 'scooter_15', '18/09/2020', '19:07:22', 'Scooter Taken', 'Girne Station'),
(305, '97006', 'scooter_15', '18/09/2020', '19:16:33', 'Scooter Returned', 'Girne Station'),
(306, '97006', 'scooter_15', '18/09/2020', '19:17:25', 'Scooter Taken', 'Girne Station'),
(307, '97006', 'scooter_15', '18/09/2020', '19:30:34', 'Scooter Returned', 'Girne Station'),
(308, '97006', 'scooter_15', '18/09/2020', '19:32:11', 'Scooter Taken', 'Girne Station'),
(309, '97006', 'scooter_15', '18/09/2020', '19:33:52', 'Scooter Returned', 'Girne Station'),
(310, '97006', 'scooter_15', '18/09/2020', '19:35:15', 'Scooter Taken', 'Girne Station'),
(311, '97006', 'scooter_15', '18/09/2020', '19:37:05', 'Scooter Returned', 'Girne Station'),
(312, '97006', 'scooter_15', '18/09/2020', '19:38:26', 'Scooter Taken', 'Girne Station'),
(313, '97006', 'scooter_15', '18/09/2020', '19:41:07', 'Scooter Returned', 'Girne Station'),
(314, '97006', 'scooter_15', '18/09/2020', '19:44:32', 'Scooter Taken', 'Girne Station'),
(315, '97006', 'scooter_15', '18/09/2020', '19:44:48', 'Scooter Taken', 'Girne Station'),
(316, '97006', 'scooter_15', '18/09/2020', '19:51:11', 'Scooter Returned', 'Girne Station'),
(317, '97006', 'scooter_15', '18/09/2020', '19:51:33', 'Scooter Returned', 'Girne Station'),
(318, '97006', 'scooter_15', '18/09/2020', '19:52:13', 'Scooter Taken', 'Girne Station'),
(319, '97006', 'scooter_15', '18/09/2020', '19:59:01', 'Scooter Returned', 'Girne Station'),
(320, '97006', 'scooter_15', '18/09/2020', '20:01:24', 'Scooter Taken', 'Girne Station'),
(321, '97006', 'scooter_15', '18/09/2020', '20:03:08', 'Scooter Returned', 'Girne Station'),
(322, '97006', 'scooter_15', '18/09/2020', '20:04:37', 'Scooter Taken', 'Girne Station'),
(323, '97006', 'scooter_15', '18/09/2020', '20:10:35', 'Scooter Returned', 'Girne Station'),
(324, '97006', 'scooter_15', '18/09/2020', '20:11:22', 'Scooter Taken', 'Girne Station'),
(325, '97006', 'scooter_15', '18/09/2020', '20:15:08', 'Scooter Returned', 'Girne Station'),
(326, '97006', 'scooter_15', '18/09/2020', '20:15:53', 'Scooter Taken', 'Girne Station'),
(327, '97006', 'scooter_15', '18/09/2020', '20:19:29', 'Scooter Returned', 'Girne Station'),
(328, '97006', 'scooter_15', '18/09/2020', '20:19:45', 'Scooter Returned', 'Girne Station'),
(329, '97006', 'scooter_15', '18/09/2020', '20:20:38', 'Scooter Taken', 'Girne Station'),
(330, '97006', 'scooter_15', '18/09/2020', '20:23:18', 'Scooter Returned', 'Girne Station'),
(331, '97006', 'scooter_15', '18/09/2020', '20:24:11', 'Scooter Taken', 'Girne Station'),
(332, '97006', 'scooter_15', '18/09/2020', '20:26:41', 'Scooter Returned', 'Girne Station'),
(333, '97006', 'scooter_15', '18/09/2020', '20:28:04', 'Scooter Taken', 'Girne Station'),
(334, '97006', 'scooter_15', '18/09/2020', '20:31:07', 'Scooter Taken', 'Girne Station'),
(335, '97006', 'scooter_15', '18/09/2020', '20:33:05', 'Scooter Taken', 'Girne Station'),
(336, '97006', 'scooter_15', '18/09/2020', '20:42:02', 'Scooter Taken', 'Girne Station'),
(337, '97006', 'scooter_15', '18/09/2020', '20:52:46', 'Scooter Taken', 'Girne Station'),
(338, '97006', 'scooter_15', '18/09/2020', '20:58:56', 'Scooter Taken', 'Girne Station'),
(339, '97006', 'scooter_15', '18/09/2020', '21:02:20', 'Scooter Taken', 'Girne Station'),
(340, '97006', 'scooter_15', '18/09/2020', '21:04:47', 'Scooter Taken', 'Girne Station'),
(341, '97006', 'scooter_15', '18/09/2020', '21:07:17', 'Scooter Taken', 'Girne Station'),
(342, '97006', 'scooter_15', '18/09/2020', '21:14:53', 'Scooter Taken', 'Girne Station'),
(343, '97006', 'scooter_15', '18/09/2020', '21:20:14', 'Scooter Taken', 'Girne Station'),
(344, '97006', 'scooter_15', '18/09/2020', '21:21:53', 'Scooter Taken', 'Girne Station'),
(345, '97006', 'scooter_15', '18/09/2020', '21:25:09', 'Scooter Taken', 'Girne Station'),
(346, '97006', 'scooter_15', '18/09/2020', '21:29:26', 'Scooter Taken', 'Girne Station'),
(347, '97006', 'scooter_15', '18/09/2020', '21:31:15', 'Scooter Taken', 'Girne Station'),
(348, '97006', 'scooter_15', '18/09/2020', '21:31:31', 'Scooter Taken', 'Girne Station'),
(349, '97006', 'scooter_15', '18/09/2020', '21:32:48', 'Scooter Taken', 'Girne Station'),
(350, '97006', 'scooter_15', '18/09/2020', '21:36:31', 'Scooter Returned', 'Girne Station'),
(351, '97006', 'scooter_15', '18/09/2020', '22:15:46', 'Scooter Taken', 'Girne Station'),
(352, '97006', 'scooter_15', '18/09/2020', '22:39:33', 'Scooter Returned', 'Girne Station'),
(353, '97006', 'scooter_15', '18/09/2020', '22:40:49', 'Scooter Taken', 'Girne Station'),
(354, '97006', 'scooter_15', '18/09/2020', '22:41:26', 'Scooter Returned', 'Girne Station'),
(355, '97006', 'scooter_15', '18/09/2020', '22:42:25', 'Scooter Taken', 'Girne Station'),
(356, '97006', 'scooter_15', '18/09/2020', '22:43:46', 'Scooter Returned', 'Girne Station'),
(357, '97006', 'scooter_15', '18/09/2020', '22:44:58', 'Scooter Taken', 'Girne Station'),
(358, '97006', 'scooter_15', '18/09/2020', '22:46:52', 'Scooter Returned', 'Girne Station'),
(359, '97006', 'scooter_15', '18/09/2020', '22:48:46', 'Scooter Taken', 'Girne Station'),
(360, '97006', 'scooter_15', '19/09/2020', '14:48:41', 'Scooter Returned', 'Girne Station'),
(361, '97006', 'scooter_15', '19/09/2020', '14:50:30', 'Scooter Taken', 'Girne Station'),
(362, '97006', 'scooter_15', '19/09/2020', '14:52:58', 'Scooter Returned', 'Girne Station'),
(363, '97006', 'scooter_15', '19/09/2020', '14:53:43', 'Scooter Taken', 'Girne Station'),
(364, '97006', 'scooter_15', '19/09/2020', '14:54:26', 'Scooter Returned', 'Girne Station'),
(365, '97006', 'scooter_15', '19/09/2020', '14:55:09', 'Scooter Taken', 'Girne Station'),
(366, '97006', 'scooter_15', '19/09/2020', '14:56:59', 'Scooter Returned', 'Girne Station'),
(367, '97006', 'scooter_15', '19/09/2020', '14:59:03', 'Scooter Taken', 'Girne Station'),
(368, '97006', 'scooter_15', '19/09/2020', '15:00:39', 'Scooter Returned', 'Girne Station'),
(369, '97006', 'scooter_15', '19/09/2020', '15:04:45', 'Scooter Taken', 'Girne Station'),
(370, '97006', 'scooter_15', '19/09/2020', '15:07:07', 'Scooter Returned', 'Girne Station'),
(371, '97006', 'scooter_15', '19/09/2020', '15:12:29', 'Scooter Taken', 'Girne Station'),
(372, '97006', 'scooter_15', '19/09/2020', '15:15:58', 'Scooter Returned', 'Girne Station'),
(373, '97006', 'scooter_15', '19/09/2020', '15:21:32', 'Scooter Taken', 'Girne Station'),
(374, '97006', 'scooter_15', '19/09/2020', '15:27:31', 'Scooter Returned', 'Girne Station'),
(375, '97006', 'scooter_15', '19/09/2020', '15:30:52', 'Scooter Taken', 'Girne Station'),
(376, '97006', 'scooter_15', '19/09/2020', '15:31:49', 'Scooter Returned', 'Girne Station'),
(377, '97006', 'scooter_15', '19/09/2020', '15:32:49', 'Scooter Taken', 'Girne Station'),
(378, '97006', 'scooter_15', '19/09/2020', '15:35:35', 'Scooter Returned', 'Girne Station'),
(379, '97006', 'scooter_15', '19/09/2020', '15:36:36', 'Scooter Taken', 'Girne Station'),
(380, '97006', 'scooter_15', '19/09/2020', '15:39:33', 'Scooter Returned', 'Girne Station'),
(381, '97006', 'scooter_15', '19/09/2020', '15:40:50', 'Scooter Taken', 'Girne Station'),
(382, '97006', 'scooter_15', '19/09/2020', '15:43:04', 'Scooter Returned', 'Girne Station'),
(383, '97006', 'scooter_15', '19/09/2020', '15:46:44', 'Scooter Taken', 'Girne Station'),
(384, '97006', 'scooter_15', '19/09/2020', '15:51:52', 'Scooter Returned', 'Girne Station'),
(385, '97006', 'scooter_15', '19/09/2020', '15:53:59', 'Scooter Taken', 'Girne Station'),
(386, '97006', 'scooter_15', '19/09/2020', '15:57:02', 'Scooter Returned', 'Girne Station'),
(387, '97006', 'scooter_15', '19/09/2020', '15:57:45', 'Scooter Taken', 'Girne Station'),
(388, '97006', 'scooter_15', '19/09/2020', '15:58:53', 'Scooter Returned', 'Girne Station'),
(389, '97006', 'scooter_15', '19/09/2020', '16:00:13', 'Scooter Taken', 'Girne Station'),
(390, '97006', 'scooter_15', '19/09/2020', '16:03:30', 'Scooter Returned', 'Girne Station'),
(391, '97006', 'scooter_15', '19/09/2020', '16:04:43', 'Scooter Taken', 'Girne Station'),
(392, '97006', 'scooter_15', '19/09/2020', '16:05:18', 'Scooter Returned', 'Girne Station'),
(393, '97006', 'scooter_15', '19/09/2020', '16:06:13', 'Scooter Taken', 'Girne Station'),
(394, '97006', 'scooter_15', '19/09/2020', '16:07:06', 'Scooter Returned', 'Girne Station'),
(395, '97006', 'scooter_15', '19/09/2020', '16:10:41', 'Scooter Taken', 'Girne Station'),
(396, '97006', 'scooter_15', '19/09/2020', '16:15:59', 'Scooter Returned', 'Girne Station'),
(397, '97006', 'scooter_15', '19/09/2020', '16:17:34', 'Scooter Taken', 'Girne Station'),
(398, '97006', 'scooter_15', '19/09/2020', '16:18:57', 'Scooter Returned', 'Girne Station'),
(399, '97006', 'scooter_15', '19/09/2020', '16:25:17', 'Scooter Taken', 'Girne Station'),
(400, '97006', 'scooter_15', '19/09/2020', '16:27:24', 'Scooter Returned', 'Girne Station'),
(401, '97006', 'scooter_15', '19/09/2020', '16:31:27', 'Scooter Taken', 'Girne Station'),
(402, '97006', 'scooter_15', '19/09/2020', '16:56:49', 'Scooter Returned', 'Girne Station'),
(403, '97006', 'scooter_15', '19/09/2020', '16:58:01', 'Scooter Taken', 'Girne Station'),
(404, '97006', 'scooter_15', '19/09/2020', '16:59:39', 'Scooter Returned', 'Girne Station'),
(405, '97006', 'scooter_15', '21/09/2020', '09:14:15', 'Scooter Taken', 'Girne Station'),
(406, '97006', 'scooter_15', '21/09/2020', '09:16:44', 'Scooter Returned', 'Girne Station'),
(407, '97006', 'scooter_15', '21/09/2020', '09:24:58', 'Scooter Taken', 'Girne Station'),
(408, '97006', 'scooter_15', '21/09/2020', '09:38:49', 'Scooter Returned', 'Girne Station'),
(409, '97006', 'scooter_15', '21/09/2020', '10:16:05', 'Scooter Taken', 'Girne Station'),
(410, '97006', 'scooter_15', '21/09/2020', '10:18:30', 'Scooter Returned', 'Girne Station'),
(411, '97006', 'scooter_15', '21/09/2020', '10:20:24', 'Scooter Taken', 'Girne Station'),
(412, '97006', 'scooter_15', '21/09/2020', '10:22:32', 'Scooter Returned', 'Girne Station'),
(413, '97006', 'scooter_15', '21/09/2020', '10:25:55', 'Scooter Taken', 'Girne Station'),
(414, '97006', 'scooter_15', '21/09/2020', '10:26:53', 'Scooter Returned', 'Girne Station'),
(415, '97006', 'scooter_15', '21/09/2020', '10:28:14', 'Scooter Taken', 'Girne Station'),
(416, '97006', 'scooter_15', '21/09/2020', '10:36:12', 'Scooter Returned', 'Girne Station'),
(417, '97006', 'scooter_15', '21/09/2020', '10:40:35', 'Scooter Taken', 'Girne Station'),
(418, '97006', 'scooter_15', '21/09/2020', '10:45:21', 'Scooter Returned', 'Girne Station'),
(419, '97006', 'scooter_15', '21/09/2020', '11:09:34', 'Scooter Taken', 'Girne Station'),
(420, '97006', 'scooter_15', '21/09/2020', '11:11:04', 'Scooter Returned', 'Girne Station'),
(421, '97006', 'scooter_15', '21/09/2020', '11:12:44', 'Scooter Taken', 'Girne Station'),
(422, '97006', 'scooter_15', '21/09/2020', '11:14:12', 'Scooter Returned', 'Girne Station'),
(423, '97006', 'scooter_15', '21/09/2020', '11:15:38', 'Scooter Taken', 'Girne Station'),
(424, '97006', 'scooter_15', '21/09/2020', '11:16:18', 'Scooter Returned', 'Girne Station'),
(425, '97006', 'scooter_15', '21/09/2020', '11:17:20', 'Scooter Taken', 'Girne Station'),
(426, '97006', 'scooter_15', '21/09/2020', '11:18:02', 'Scooter Returned', 'Girne Station'),
(427, '97006', 'scooter_15', '21/09/2020', '11:18:49', 'Scooter Taken', 'Girne Station'),
(428, '97006', 'scooter_15', '21/09/2020', '11:19:29', 'Scooter Returned', 'Girne Station'),
(429, '97006', 'scooter_15', '21/09/2020', '11:20:16', 'Scooter Taken', 'Girne Station'),
(430, '97006', 'scooter_15', '21/09/2020', '11:21:44', 'Scooter Returned', 'Girne Station'),
(431, '97006', 'scooter_15', '21/09/2020', '11:23:03', 'Scooter Taken', 'Girne Station'),
(432, '97006', 'scooter_15', '21/09/2020', '11:25:38', 'Scooter Returned', 'Girne Station'),
(433, '97006', 'scooter_15', '21/09/2020', '11:29:36', 'Scooter Taken', 'Girne Station'),
(434, '97006', 'scooter_15', '21/09/2020', '11:31:10', 'Scooter Returned', 'Girne Station'),
(435, '97006', 'scooter_15', '21/09/2020', '11:35:18', 'Scooter Taken', 'Girne Station'),
(436, '97006', 'scooter_15', '21/09/2020', '11:38:18', 'Scooter Returned', 'Girne Station'),
(437, '97006', 'scooter_15', '21/09/2020', '11:39:30', 'Scooter Taken', 'Girne Station'),
(438, '97006', 'scooter_15', '21/09/2020', '11:42:33', 'Scooter Returned', 'Girne Station'),
(439, '97006', 'scooter_15', '21/09/2020', '11:43:28', 'Scooter Taken', 'Girne Station'),
(440, '97006', 'scooter_15', '21/09/2020', '11:45:04', 'Scooter Returned', 'Girne Station'),
(441, '97006', 'scooter_15', '21/09/2020', '11:47:35', 'Scooter Taken', 'Girne Station'),
(442, '97006', 'scooter_15', '21/09/2020', '11:52:05', 'Scooter Returned', 'Girne Station'),
(443, '97006', 'scooter_15', '21/09/2020', '11:52:58', 'Scooter Taken', 'Girne Station'),
(444, '97006', 'scooter_15', '21/09/2020', '11:53:37', 'Scooter Returned', 'Girne Station'),
(445, '97006', 'scooter_15', '21/09/2020', '11:55:53', 'Scooter Taken', 'Girne Station'),
(446, '97006', 'scooter_15', '21/09/2020', '11:56:51', 'Scooter Returned', 'Girne Station'),
(447, '97006', 'scooter_15', '21/09/2020', '11:57:31', 'Scooter Taken', 'Girne Station'),
(448, '97006', 'scooter_15', '21/09/2020', '11:58:10', 'Scooter Returned', 'Girne Station'),
(449, '97006', 'scooter_1', '22/09/2020', '11:17:42', 'Scooter Taken', 'Lefkosa Station'),
(450, '97006', 'scooter_6', '22/09/2020', '11:24:00', 'Scooter Taken', 'Lefkosa Station'),
(451, '97006', 'scooter_6', '22/09/2020', '11:56:23', 'Scooter Taken', 'Lefkosa Station'),
(452, '97006', 'scooter_6', '22/09/2020', '12:01:26', 'Scooter Returned', 'Lefkosa Station'),
(453, '97006', 'scooter_6', '22/09/2020', '10:40:52', 'Scooter Taken', 'Girne Station'),
(454, '97006', 'scooter_6', '22/09/2020', '10:42:16', 'Scooter Returned', 'Girne Station'),
(455, '97006', 'scooter_6', '22/09/2020', '10:46:12', 'Scooter Taken', 'Girne Station'),
(456, '97006', 'scooter_6', '22/09/2020', '10:46:51', 'Scooter Returned', 'Girne Station'),
(457, '97006', 'scooter_6', '22/09/2020', '15:13:35', 'Scooter Taken', 'Lefkosa Station'),
(458, '97006', 'scooter_6', '22/09/2020', '15:16:58', 'Scooter Returned', 'Lefkosa Station'),
(459, '97006', 'scooter_6', '22/09/2020', '15:18:00', 'Scooter Taken', 'Lefkosa Station'),
(460, '97006', 'scooter_6', '22/09/2020', '15:18:52', 'Scooter Returned', 'Lefkosa Station'),
(461, '97006', 'scooter_6', '22/09/2020', '15:20:52', 'Scooter Taken', 'Lefkosa Station'),
(462, '97006', 'scooter_6', '22/09/2020', '15:44:50', 'Scooter Returned', 'Lefkosa Station'),
(463, '97006', '', '22/09/2020', '15:47:36', 'Scooter Taken', 'Lefkosa Station'),
(464, '97006', 'scooter_6', '22/09/2020', '15:48:21', 'Scooter Returned', 'Lefkosa Station'),
(465, '97006', 'scooter_6', '22/09/2020', '16:53:45', 'Scooter Taken', 'Lefkosa Station'),
(466, '97006', 'scooter_6', '22/09/2020', '16:54:13', 'Scooter Returned', 'Lefkosa Station'),
(467, '97006', '', '22/09/2020', '16:43:15', 'Scooter Taken', 'Girne Station'),
(468, '97006', '', '22/09/2020', '17:17:19', 'Scooter Taken', 'Girne Station'),
(469, '97006', '', '22/09/2020', '17:18:03', 'Scooter Taken', 'Girne Station'),
(470, '97006', '', '22/09/2020', '17:25:14', 'Scooter Taken', 'Girne Station'),
(471, '97006', '', '22/09/2020', '17:25:29', 'Scooter Taken', 'Girne Station'),
(472, '97006', '', '22/09/2020', '17:25:30', 'Scooter Taken', 'Girne Station'),
(473, '97006', '', '22/09/2020', '17:29:31', 'Scooter Taken', 'Girne Station'),
(474, '97006', '', '22/09/2020', '17:34:12', 'Scooter Taken', 'Girne Station'),
(475, '97006', '', '22/09/2020', '17:39:17', 'Scooter Taken', 'Girne Station'),
(476, '97006', '', '22/09/2020', '17:45:22', 'Scooter Taken', 'Girne Station'),
(477, '97006', '', '22/09/2020', '17:47:16', 'Scooter Taken', 'Girne Station'),
(478, '97006', '', '22/09/2020', '17:48:00', 'Scooter Taken', 'Girne Station'),
(479, '97006', '', '22/09/2020', '17:51:14', 'Scooter Taken', 'Girne Station'),
(480, '97006', '', '22/09/2020', '17:52:18', 'Scooter Taken', 'Girne Station'),
(481, '97006', '', '22/09/2020', '17:53:01', 'Scooter Taken', 'Girne Station'),
(482, '97006', '', '22/09/2020', '17:53:52', 'Scooter Taken', 'Girne Station'),
(483, '97006', 'scooter_6', '22/09/2020', '17:58:25', 'Scooter Taken', 'Girne Station'),
(484, '97006', 'scooter_6', '22/09/2020', '17:58:57', 'Scooter Returned', 'Girne Station'),
(485, '97006', 'scooter_6', '22/09/2020', '18:00:00', 'Scooter Taken', 'Girne Station'),
(486, '97006', 'scooter_6', '22/09/2020', '18:00:39', 'Scooter Returned', 'Girne Station'),
(487, '97006', 'scooter_6', '22/09/2020', '18:01:21', 'Scooter Taken', 'Girne Station'),
(488, '97006', 'scooter_6', '22/09/2020', '18:01:56', 'Scooter Returned', 'Girne Station'),
(489, '97006', 'scooter_6', '22/09/2020', '18:04:25', 'Scooter Taken', 'Girne Station'),
(490, '97006', 'scooter_6', '22/09/2020', '18:04:58', 'Scooter Returned', 'Girne Station'),
(491, '97006', 'scooter_1', '23/09/2020', '13:20:18', 'Scooter Taken', 'Girne Station'),
(492, '97006', 'scooter_1', '23/09/2020', '13:20:52', 'Scooter Returned', 'Girne Station'),
(493, '97006', 'scooter_1', '23/09/2020', '13:34:22', 'Scooter Taken', 'Girne Station'),
(494, '97006', 'scooter_1', '23/09/2020', '13:35:09', 'Scooter Returned', 'Girne Station'),
(495, '97006', 'scooter_1', '23/09/2020', '16:02:51', 'Scooter Taken', 'Girne Station'),
(496, '97006', 'scooter_1', '23/09/2020', '16:04:22', 'Scooter Returned', 'Girne Station'),
(497, '97006', 'scooter_1', '23/09/2020', '16:04:55', 'Scooter Taken', 'Girne Station'),
(498, '97006', 'scooter_1', '23/09/2020', '16:05:11', 'Scooter Taken', 'Girne Station'),
(499, '97006', 'scooter_1', '23/09/2020', '16:06:28', 'Scooter Returned', 'Girne Station'),
(500, '97006', 'scooter_2', '23/09/2020', '16:07:01', 'Scooter Returned', 'Girne Station'),
(501, '97006', 'scooter_1', '23/09/2020', '16:07:28', 'Scooter Taken', 'Girne Station'),
(502, '97006', 'scooter_1', '23/09/2020', '16:09:15', 'Scooter Returned', 'Girne Station'),
(503, '97006', 'scooter_1', '23/09/2020', '16:09:40', 'Scooter Taken', 'Girne Station'),
(504, '97006', 'scooter_1', '23/09/2020', '16:12:04', 'Scooter Returned', 'Girne Station'),
(505, '97006', 'scooter_1', '23/09/2020', '16:12:44', 'Scooter Taken', 'Girne Station'),
(506, '97006', 'scooter_1', '23/09/2020', '16:17:16', 'Scooter Returned', 'Girne Station'),
(507, '97006', 'scooter_1', '23/09/2020', '16:17:32', 'Scooter Returned', 'Girne Station'),
(508, '97006', 'scooter_1', '23/09/2020', '16:18:01', 'Scooter Taken', 'Girne Station'),
(509, '97006', 'scooter_1', '23/09/2020', '16:19:33', 'Scooter Returned', 'Girne Station'),
(510, '97006', 'scooter_1', '23/09/2020', '16:20:08', 'Scooter Taken', 'Girne Station'),
(511, '97006', 'scooter_1', '23/09/2020', '16:23:59', 'Scooter Returned', 'Girne Station'),
(512, '97006', 'scooter_1', '23/09/2020', '16:24:26', 'Scooter Taken', 'Girne Station'),
(513, '97006', 'scooter_1', '23/09/2020', '16:24:43', 'Scooter Taken', 'Girne Station'),
(514, '97006', 'scooter_1', '23/09/2020', '16:28:35', 'Scooter Returned', 'Girne Station'),
(515, '97006', 'scooter_2', '23/09/2020', '16:29:09', 'Scooter Returned', 'Girne Station'),
(516, '97006', 'scooter_1', '23/09/2020', '16:29:37', 'Scooter Taken', 'Girne Station'),
(517, '97006', 'scooter_1', '23/09/2020', '16:32:16', 'Scooter Returned', 'Girne Station'),
(518, '97006', 'scooter_1', '23/09/2020', '16:32:42', 'Scooter Taken', 'Girne Station'),
(519, '97006', 'scooter_1', '23/09/2020', '16:33:31', 'Scooter Returned', 'Girne Station'),
(520, '97006', 'scooter_1', '23/09/2020', '16:37:31', 'Scooter Taken', 'Girne Station'),
(521, '97006', 'scooter_1', '23/09/2020', '16:38:03', 'Scooter Returned', 'Girne Station'),
(522, '97006', 'scooter_1', '23/09/2020', '16:38:27', 'Scooter Taken', 'Girne Station'),
(523, '97006', 'scooter_1', '23/09/2020', '16:38:42', 'Scooter Taken', 'Girne Station'),
(524, '97006', 'scooter_1', '23/09/2020', '16:39:07', 'Scooter Returned', 'Girne Station'),
(525, '97006', 'scooter_2', '23/09/2020', '16:39:31', 'Scooter Returned', 'Girne Station'),
(526, '97006', 'scooter_1', '23/09/2020', '16:39:58', 'Scooter Taken', 'Girne Station'),
(527, '97006', 'scooter_1', '23/09/2020', '16:40:19', 'Scooter Returned', 'Girne Station'),
(528, '97006', 'scooter_1', '23/09/2020', '16:44:46', 'Scooter Taken', 'Girne Station'),
(529, '97006', 'scooter_1', '23/09/2020', '16:46:24', 'Scooter Returned', 'Girne Station'),
(530, '97006', 'scooter_1', '23/09/2020', '16:47:00', 'Scooter Taken', 'Girne Station'),
(531, '97006', 'scooter_1', '23/09/2020', '16:47:30', 'Scooter Returned', 'Girne Station'),
(532, '97006', 'scooter_1', '24/09/2020', '13:23:24', 'Scooter Taken', 'Girne Station'),
(533, '97006', 'scooter_1', '24/09/2020', '15:45:21', 'Scooter Returned', 'Girne Station'),
(534, '97006', 'scooter_1', '25/09/2020', '09:00:23', 'Scooter Taken', 'Girne Station'),
(535, '97006', 'scooter_1', '25/09/2020', '09:01:36', 'Scooter Returned', 'Girne Station'),
(536, '97006', 'scooter_1', '25/09/2020', '09:03:16', 'Scooter Taken', 'Girne Station'),
(537, '97006', 'scooter_1', '25/09/2020', '09:05:58', 'Scooter Returned', 'Girne Station'),
(538, '97006', 'scooter_1', '25/09/2020', '09:15:32', 'Scooter Taken', 'Girne Station'),
(539, '97006', 'scooter_1', '25/09/2020', '09:16:07', 'Scooter Returned', 'Girne Station'),
(540, '97006', 'scooter_1', '25/09/2020', '09:16:54', 'Scooter Taken', 'Girne Station'),
(541, '97006', 'scooter_1', '25/09/2020', '09:17:30', 'Scooter Returned', 'Girne Station'),
(542, '97006', 'scooter_1', '25/09/2020', '09:18:07', 'Scooter Taken', 'Girne Station'),
(543, '97006', 'scooter_1', '25/09/2020', '09:20:21', 'Scooter Returned', 'Girne Station'),
(544, '97006', 'scooter_1', '25/09/2020', '09:21:14', 'Scooter Taken', 'Girne Station'),
(545, '97006', 'scooter_1', '25/09/2020', '09:22:08', 'Scooter Returned', 'Girne Station'),
(546, '97006', 'scooter_1', '25/09/2020', '09:31:00', 'Scooter Taken', 'Girne Station'),
(547, '97006', 'scooter_1', '25/09/2020', '09:34:42', 'Scooter Returned', 'Girne Station'),
(548, '97006', 'scooter_1', '25/09/2020', '09:45:36', 'Scooter Taken', 'Girne Station'),
(549, '97006', 'scooter_1', '25/09/2020', '09:47:04', 'Scooter Returned', 'Girne Station'),
(550, '97006', 'scooter_1', '25/09/2020', '09:47:37', 'Scooter Taken', 'Girne Station'),
(551, '97006', 'scooter_1', '25/09/2020', '09:48:24', 'Scooter Returned', 'Girne Station'),
(552, '97006', 'scooter_1', '25/09/2020', '10:03:51', 'Scooter Taken', 'Girne Station'),
(553, '97006', 'scooter_1', '25/09/2020', '10:04:33', 'Scooter Returned', 'Girne Station'),
(554, '97006', 'scooter_1', '25/09/2020', '10:04:48', 'Scooter Returned', 'Girne Station'),
(555, '97006', 'scooter_1', '25/09/2020', '10:05:32', 'Scooter Taken', 'Girne Station'),
(556, '97006', 'scooter_1', '25/09/2020', '10:07:12', 'Scooter Returned', 'Girne Station'),
(557, '97006', 'scooter_1', '25/09/2020', '10:08:05', 'Scooter Taken', 'Girne Station'),
(558, '97006', 'scooter_1', '25/09/2020', '10:09:01', 'Scooter Returned', 'Girne Station'),
(559, '97006', 'scooter_1', '25/09/2020', '10:09:51', 'Scooter Taken', 'Girne Station'),
(560, '97006', 'scooter_1', '25/09/2020', '10:10:36', 'Scooter Returned', 'Girne Station'),
(561, '97006', 'scooter_1', '25/09/2020', '10:12:27', 'Scooter Taken', 'Girne Station'),
(562, '97006', 'scooter_1', '25/09/2020', '10:15:55', 'Scooter Returned', 'Girne Station'),
(563, '97006', 'scooter_1', '25/09/2020', '10:16:49', 'Scooter Taken', 'Girne Station'),
(564, '97006', 'scooter_1', '25/09/2020', '10:17:56', 'Scooter Returned', 'Girne Station'),
(565, '97006', 'scooter_1', '25/09/2020', '10:19:12', 'Scooter Taken', 'Girne Station'),
(566, '97006', 'scooter_1', '25/09/2020', '10:20:51', 'Scooter Returned', 'Girne Station'),
(567, '97006', 'scooter_1', '25/09/2020', '10:22:11', 'Scooter Taken', 'Girne Station'),
(568, '97006', 'scooter_1', '25/09/2020', '10:23:25', 'Scooter Returned', 'Girne Station'),
(569, '97006', 'scooter_1', '25/09/2020', '10:27:03', 'Scooter Taken', 'Girne Station'),
(570, '97006', 'scooter_1', '25/09/2020', '10:51:03', 'Scooter Returned', 'Girne Station'),
(571, '97006', 'scooter_1', '25/09/2020', '10:51:32', 'Scooter Taken', 'Girne Station'),
(572, '97006', 'scooter_1', '25/09/2020', '11:10:34', 'Scooter Returned', 'Girne Station'),
(573, '97006', 'scooter_1', '25/09/2020', '12:07:33', 'Scooter Taken', 'Girne Station'),
(574, '97006', 'scooter_1', '25/09/2020', '13:58:53', 'Scooter Returned', 'Girne Station'),
(575, '97006', 'scooter_1', '25/09/2020', '13:58:53', 'Scooter Returned', 'Girne Station'),
(576, '97006', 'scooter_1', '25/09/2020', '13:58:53', 'Scooter Returned', 'Girne Station'),
(577, '97006', 'scooter_1', '25/09/2020', '14:32:12', 'Scooter Taken', 'Girne Station'),
(578, '97006', 'scooter_1', '25/09/2020', '14:32:35', 'Scooter Returned', 'Girne Station'),
(579, '97006', 'scooter_1', '25/09/2020', '14:33:03', 'Scooter Taken', 'Girne Station'),
(580, '97006', 'scooter_1', '25/09/2020', '14:33:25', 'Scooter Returned', 'Girne Station'),
(581, '97006', 'scooter_1', '25/09/2020', '15:18:30', 'Scooter Taken', 'Girne Station'),
(582, '97006', 'scooter_1', '25/09/2020', '15:18:45', 'Scooter Taken', 'Girne Station'),
(583, '97006', 'scooter_1', '25/09/2020', '15:33:41', 'Scooter Returned', 'Girne Station'),
(584, '97006', 'scooter_2', '25/09/2020', '18:20:14', 'Scooter Returned', 'Girne Station'),
(585, '97006', 'scooter_1', '25/09/2020', '18:26:07', 'Scooter Taken', 'Girne Station'),
(586, '97006', 'scooter_1', '25/09/2020', '18:26:57', 'Scooter Returned', 'Girne Station'),
(587, '97006', 'scooter_1', '25/09/2020', '18:28:02', 'Scooter Taken', 'Girne Station'),
(588, '97006', 'scooter_1', '25/09/2020', '18:28:32', 'Scooter Returned', 'Girne Station'),
(589, '97006', 'scooter_1', '25/09/2020', '18:48:27', 'Scooter Taken', 'Girne Station'),
(590, '97006', 'scooter_1', '25/09/2020', '16:50:33', 'Scooter Returned', 'Lefkosa Station'),
(591, '97006', 'scooter_2', '25/09/2020', '19:08:08', 'Scooter Taken', 'Girne Station'),
(592, '97006', 'scooter_2', '25/09/2020', '19:32:04', 'Scooter Returned', 'Girne Station'),
(593, '97006', 'scooter_2', '25/09/2020', '19:32:19', 'Scooter Returned', 'Girne Station'),
(594, '97006', 'scooter_2', '25/09/2020', '19:32:34', 'Scooter Returned', 'Girne Station'),
(595, '97006', 'scooter_2', '25/09/2020', '19:33:00', 'Scooter Taken', 'Girne Station'),
(596, '97006', 'scooter_2', '25/09/2020', '19:36:52', 'Scooter Returned', 'Girne Station'),
(597, '97006', 'scooter_2', '28/09/2020', '11:09:07', 'Scooter Taken', 'Girne Station'),
(598, '97006', 'scooter_2', '28/09/2020', '11:09:36', 'Scooter Returned', 'Girne Station'),
(599, '97006', 'scooter_2', '28/09/2020', '11:10:58', 'Scooter Taken', 'Girne Station'),
(600, '97006', 'scooter_2', '28/09/2020', '11:11:45', 'Scooter Returned', 'Girne Station'),
(601, '97006', 'scooter_2', '28/09/2020', '11:12:13', 'Scooter Taken', 'Girne Station'),
(602, '97006', 'scooter_2', '28/09/2020', '11:12:37', 'Scooter Returned', 'Girne Station'),
(603, '97006', 'scooter_2', '28/09/2020', '11:19:53', 'Scooter Taken', 'Girne Station'),
(604, '97006', 'scooter_2', '28/09/2020', '11:20:17', 'Scooter Returned', 'Girne Station'),
(605, '97006', 'scooter_2', '28/09/2020', '11:28:37', 'Scooter Taken', 'Girne Station'),
(606, '97006', 'scooter_2', '28/09/2020', '11:29:26', 'Scooter Returned', 'Girne Station'),
(607, '97006', 'scooter_2', '28/09/2020', '11:30:13', 'Scooter Taken', 'Girne Station'),
(608, '97006', 'scooter_2', '28/09/2020', '11:30:53', 'Scooter Returned', 'Girne Station'),
(609, '97006', 'scooter_2', '28/09/2020', '11:31:27', 'Scooter Taken', 'Girne Station'),
(610, '97006', 'scooter_2', '28/09/2020', '11:32:04', 'Scooter Returned', 'Girne Station'),
(611, '97006', 'scooter_2', '28/09/2020', '11:35:31', 'Scooter Taken', 'Girne Station'),
(612, '97006', 'scooter_2', '28/09/2020', '11:36:40', 'Scooter Returned', 'Girne Station'),
(613, '97006', 'scooter_2', '28/09/2020', '11:37:32', 'Scooter Taken', 'Girne Station'),
(614, '97006', 'scooter_2', '28/09/2020', '11:41:31', 'Scooter Returned', 'Girne Station'),
(615, '97006', 'scooter_2', '28/09/2020', '11:47:54', 'Scooter Taken', 'Girne Station'),
(616, '97006', 'scooter_2', '28/09/2020', '11:49:21', 'Scooter Returned', 'Girne Station'),
(617, '97006', 'scooter_2', '28/09/2020', '11:50:26', 'Scooter Taken', 'Girne Station'),
(618, '97006', 'scooter_2', '28/09/2020', '11:50:56', 'Scooter Returned', 'Girne Station'),
(619, '97006', 'scooter_2', '28/09/2020', '11:51:34', 'Scooter Taken', 'Girne Station'),
(620, '97006', 'scooter_2', '28/09/2020', '11:52:07', 'Scooter Returned', 'Girne Station'),
(621, '97006', 'scooter_2', '28/09/2020', '11:53:15', 'Scooter Taken', 'Girne Station'),
(622, '97006', 'scooter_2', '28/09/2020', '11:54:16', 'Scooter Returned', 'Girne Station'),
(623, '97006', 'scooter_2', '28/09/2020', '12:09:17', 'Scooter Taken', 'Girne Station'),
(624, '97006', 'scooter_2', '28/09/2020', '12:09:56', 'Scooter Returned', 'Girne Station'),
(625, '97006', 'scooter_2', '28/09/2020', '12:10:48', 'Scooter Taken', 'Girne Station'),
(626, '97006', 'scooter_2', '28/09/2020', '12:11:45', 'Scooter Returned', 'Girne Station'),
(627, '97006', 'scooter_2', '28/09/2020', '12:13:56', 'Scooter Taken', 'Girne Station'),
(628, '97006', 'scooter_2', '28/09/2020', '12:15:31', 'Scooter Returned', 'Girne Station'),
(629, '97006', 'scooter_2', '28/09/2020', '12:17:13', 'Scooter Taken', 'Girne Station'),
(630, '97006', 'scooter_2', '28/09/2020', '12:24:00', 'Scooter Returned', 'Girne Station'),
(631, '97006', 'scooter_2', '28/09/2020', '12:26:03', 'Scooter Taken', 'Girne Station'),
(632, '97006', 'scooter_2', '28/09/2020', '12:26:45', 'Scooter Returned', 'Girne Station'),
(633, '97006', 'scooter_2', '28/09/2020', '12:27:09', 'Scooter Taken', 'Girne Station'),
(634, '97006', 'scooter_2', '28/09/2020', '12:28:40', 'Scooter Returned', 'Girne Station'),
(635, '97006', 'scooter_2', '28/09/2020', '12:30:27', 'Scooter Taken', 'Girne Station'),
(636, '97006', 'scooter_2', '28/09/2020', '12:30:51', 'Scooter Returned', 'Girne Station'),
(637, '97006', 'scooter_2', '28/09/2020', '13:35:27', 'Scooter Taken', 'Girne Station'),
(638, '97006', 'scooter_2', '28/09/2020', '13:35:50', 'Scooter Returned', 'Girne Station'),
(639, '97006', 'scooter_2', '28/09/2020', '13:37:34', 'Scooter Taken', 'Girne Station'),
(640, '97006', 'scooter_2', '28/09/2020', '13:37:57', 'Scooter Returned', 'Girne Station'),
(641, '97006', 'scooter_2', '28/09/2020', '14:01:58', 'Scooter Taken', 'Girne Station'),
(642, '97006', 'scooter_2', '28/09/2020', '14:04:57', 'Scooter Returned', 'Girne Station'),
(643, '97006', 'scooter_2', '28/09/2020', '14:31:09', 'Scooter Taken', 'Girne Station'),
(644, '97006', 'scooter_2', '28/09/2020', '14:31:32', 'Scooter Returned', 'Girne Station'),
(645, '97006', 'scooter_1', '28/09/2020', '15:15:04', 'Scooter Taken', 'Lefkosa Station'),
(646, '97006', 'scooter_1', '28/09/2020', '15:15:24', 'Scooter Returned', 'Lefkosa Station'),
(647, '97006', 'scooter_1', '28/09/2020', '15:18:32', 'Scooter Taken', 'Lefkosa Station'),
(648, '97006', 'scooter_1', '28/09/2020', '15:20:41', 'Scooter Returned', 'Lefkosa Station'),
(649, '97006', 'scooter_3', '29/09/2020', '07:49:01', 'Scooter Taken', 'Lefkosa Station'),
(650, '97006', 'scooter_3', '29/09/2020', '07:50:30', 'Scooter Taken', 'Lefkosa Station'),
(651, '97006', 'scooter_3', '29/09/2020', '07:55:25', 'Scooter Taken', 'Lefkosa Station'),
(652, '97006', 'scooter_3', '29/09/2020', '08:04:20', 'Scooter Taken', 'Lefkosa Station'),
(653, '97006', 'scooter_1', '29/09/2020', '12:06:17', 'Scooter Taken', 'Lefkosa Station'),
(654, '97006', 'scooter_3', '29/09/2020', '08:16:00', 'Scooter Taken', 'Lefkosa Station'),
(655, '97006', 'scooter_3', '29/09/2020', '08:17:50', 'Scooter Taken', 'Lefkosa Station'),
(656, '97006', 'scooter_3', '29/09/2020', '08:18:19', 'Scooter Returned', 'Lefkosa Station'),
(657, '97006', 'scooter_3', '29/09/2020', '08:25:35', 'Scooter Taken', 'Lefkosa Station'),
(658, '97006', 'scooter_3', '29/09/2020', '08:25:51', 'Scooter Returned', 'Lefkosa Station'),
(659, '97006', 'scooter_3', '30/09/2020', '06:25:19', 'Scooter Taken', 'Lefkosa Station'),
(660, '97006', 'scooter_3', '30/09/2020', '06:25:31', 'Scooter Returned', 'Lefkosa Station'),
(661, '97006', 'scooter_3', '30/09/2020', '06:28:53', 'Scooter Taken', 'Lefkosa Station'),
(662, '97006', 'scooter_3', '30/09/2020', '06:29:18', 'Scooter Returned', 'Lefkosa Station'),
(663, '97006', 'scooter_3', '30/09/2020', '07:27:04', 'Scooter Taken', 'Lefkosa Station'),
(664, '97006', 'scooter_3', '30/09/2020', '07:27:27', 'Scooter Returned', 'Lefkosa Station'),
(665, '97006', 'scooter_3', '30/09/2020', '07:27:55', 'Scooter Taken', 'Lefkosa Station'),
(666, '97006', 'scooter_3', '30/09/2020', '07:30:57', 'Scooter Returned', 'Lefkosa Station'),
(667, '97006', 'scooter_3', '30/09/2020', '07:31:24', 'Scooter Taken', 'Lefkosa Station'),
(668, '97006', 'scooter_3', '30/09/2020', '07:31:47', 'Scooter Returned', 'Lefkosa Station'),
(669, '97006', 'scooter_3', '30/09/2020', '07:35:21', 'Scooter Taken', 'Lefkosa Station'),
(670, '97006', 'scooter_3', '30/09/2020', '07:36:49', 'Scooter Returned', 'Lefkosa Station'),
(671, '97006', 'scooter_3', '30/09/2020', '07:41:26', 'Scooter Taken', 'Lefkosa Station'),
(672, '97006', 'scooter_3', '30/09/2020', '07:42:25', 'Scooter Returned', 'Lefkosa Station'),
(673, '97006', 'scooter_3', '30/09/2020', '07:46:01', 'Scooter Taken', 'Lefkosa Station'),
(674, '97006', 'scooter_3', '30/09/2020', '07:47:06', 'Scooter Returned', 'Lefkosa Station'),
(675, '97006', 'scooter_3', '30/09/2020', '07:47:42', 'Scooter Taken', 'Lefkosa Station'),
(676, '97006', 'scooter_3', '30/09/2020', '07:48:34', 'Scooter Returned', 'Lefkosa Station'),
(677, '97006', 'scooter_3', '30/09/2020', '07:51:41', 'Scooter Taken', 'Lefkosa Station'),
(678, '97006', 'scooter_3', '30/09/2020', '07:52:04', 'Scooter Returned', 'Lefkosa Station'),
(679, '97006', 'scooter_3', '30/09/2020', '07:53:32', 'Scooter Taken', 'Lefkosa Station'),
(680, '97006', 'scooter_3', '30/09/2020', '07:53:57', 'Scooter Returned', 'Lefkosa Station'),
(681, '97006', 'scooter_3', '30/09/2020', '07:57:42', 'Scooter Taken', 'Lefkosa Station'),
(682, '97006', 'scooter_3', '30/09/2020', '07:58:26', 'Scooter Returned', 'Lefkosa Station'),
(683, '97006', 'scooter_3', '30/09/2020', '07:59:13', 'Scooter Taken', 'Lefkosa Station'),
(684, '97006', 'scooter_3', '30/09/2020', '07:59:58', 'Scooter Returned', 'Lefkosa Station'),
(685, '97006', 'scooter_3', '30/09/2020', '08:01:30', 'Scooter Taken', 'Lefkosa Station'),
(686, '97006', 'scooter_3', '30/09/2020', '08:38:31', 'Scooter Returned', 'Lefkosa Station'),
(687, '97006', 'scooter_3', '30/09/2020', '08:47:59', 'Scooter Taken', 'Lefkosa Station'),
(688, '97006', 'scooter_3', '30/09/2020', '08:48:40', 'Scooter Returned', 'Lefkosa Station'),
(689, '97006', 'scooter_3', '30/09/2020', '09:16:11', 'Scooter Taken', 'Lefkosa Station'),
(690, '97006', 'scooter_3', '30/09/2020', '09:17:48', 'Scooter Returned', 'Lefkosa Station'),
(691, '97006', 'scooter_3', '30/09/2020', '09:19:38', 'Scooter Taken', 'Lefkosa Station'),
(692, '97006', 'scooter_3', '30/09/2020', '09:23:26', 'Scooter Returned', 'Lefkosa Station');
INSERT INTO `scooter_log` (`id`, `employee_id`, `scooter_name`, `date`, `hour`, `operation`, `location`) VALUES
(693, '97006', 'scooter_3', '30/09/2020', '09:24:11', 'Scooter Taken', 'Lefkosa Station'),
(694, '97006', 'scooter_3', '30/09/2020', '09:25:27', 'Scooter Returned', 'Lefkosa Station'),
(695, '97006', 'scooter_3', '30/09/2020', '09:25:43', 'Scooter Returned', 'Lefkosa Station'),
(696, '97006', 'scooter_3', '30/09/2020', '09:26:39', 'Scooter Taken', 'Lefkosa Station'),
(697, '97006', 'scooter_3', '30/09/2020', '09:36:42', 'Scooter Returned', 'Lefkosa Station'),
(698, '97006', 'scooter_3', '30/09/2020', '09:37:33', 'Scooter Taken', 'Lefkosa Station'),
(699, '97006', 'scooter_3', '30/09/2020', '09:43:46', 'Scooter Returned', 'Lefkosa Station'),
(700, '97006', 'scooter_3', '30/09/2020', '09:53:19', 'Scooter Taken', 'Lefkosa Station'),
(701, '97006', 'scooter_3', '30/09/2020', '09:54:57', 'Scooter Returned', 'Lefkosa Station'),
(702, '97006', 'scooter_1', '30/09/2020', '12:03:08', 'Scooter Taken', 'Girne Station'),
(703, '97006', 'scooter_1', '30/09/2020', '12:04:14', 'Scooter Returned', 'Girne Station'),
(704, '97006', 'scooter_1', '30/09/2020', '12:05:12', 'Scooter Taken', 'Girne Station'),
(705, '97006', 'scooter_1', '30/09/2020', '12:05:57', 'Scooter Returned', 'Girne Station'),
(706, '97006', 'scooter_1', '30/09/2020', '10:22:40', 'Scooter Taken', 'Girne Station'),
(707, '97006', 'scooter_1', '30/09/2020', '10:23:03', 'Scooter Returned', 'Girne Station'),
(708, '97006', 'scooter_1', '30/09/2020', '11:11:36', 'Scooter Taken', 'Girne Station'),
(709, '97006', 'scooter_1', '30/09/2020', '11:29:11', 'Scooter Taken', 'Girne Station'),
(710, '97006', 'scooter_1', '30/09/2020', '11:41:58', 'Scooter Returned', 'Girne Station'),
(711, '97006', 'scooter_1', '30/09/2020', '11:45:11', 'Scooter Taken', 'Girne Station'),
(712, '97006', 'scooter_1', '30/09/2020', '11:45:37', 'Scooter Returned', 'Girne Station'),
(713, '97006', 'scooter_1', '30/09/2020', '11:46:56', 'Scooter Taken', 'Girne Station'),
(714, '97006', 'scooter_1', '30/09/2020', '11:47:19', 'Scooter Returned', 'Girne Station'),
(715, '97006', 'scooter_1', '30/09/2020', '11:47:46', 'Scooter Taken', 'Girne Station'),
(716, '97006', 'scooter_1', '30/09/2020', '11:48:12', 'Scooter Returned', 'Girne Station'),
(717, '97006', 'scooter_1', '30/09/2020', '11:51:36', 'Scooter Taken', 'Girne Station'),
(718, '97006', 'scooter_1', '30/09/2020', '11:52:06', 'Scooter Returned', 'Girne Station'),
(719, '97006', 'scooter_1', '30/09/2020', '11:57:50', 'Scooter Taken', 'Girne Station'),
(720, '97006', 'scooter_1', '30/09/2020', '12:00:53', 'Scooter Returned', 'Girne Station'),
(721, '97006', 'scooter_1', '30/09/2020', '12:02:27', 'Scooter Taken', 'Girne Station'),
(722, '97006', 'scooter_1', '30/09/2020', '12:03:59', 'Scooter Returned', 'Girne Station'),
(723, '97006', 'scooter_1', '30/09/2020', '12:04:14', 'Scooter Returned', 'Girne Station'),
(724, '97006', 'scooter_1', '30/09/2020', '12:06:17', 'Scooter Taken', 'Girne Station'),
(725, '97006', 'scooter_1', '30/09/2020', '12:06:40', 'Scooter Returned', 'Girne Station'),
(726, '97006', 'scooter_1', '30/09/2020', '12:14:30', 'Scooter Taken', 'Girne Station'),
(727, '97006', 'scooter_1', '30/09/2020', '12:14:52', 'Scooter Returned', 'Girne Station'),
(728, '97006', 'scooter_1', '30/09/2020', '12:19:59', 'Scooter Taken', 'Girne Station'),
(729, '97006', 'scooter_1', '30/09/2020', '12:21:34', 'Scooter Returned', 'Girne Station'),
(730, '97006', 'scooter_1', '30/09/2020', '12:25:16', 'Scooter Taken', 'Girne Station'),
(731, '97006', 'scooter_1', '30/09/2020', '12:27:08', 'Scooter Returned', 'Girne Station'),
(732, '97006', 'scooter_1', '30/09/2020', '12:27:23', 'Scooter Returned', 'Girne Station'),
(733, '97006', 'scooter_1', '30/09/2020', '12:46:43', 'Scooter Taken', 'Girne Station'),
(734, '97006', 'scooter_1', '30/09/2020', '12:48:45', 'Scooter Returned', 'Girne Station'),
(735, '97006', 'scooter_1', '30/09/2020', '12:50:04', 'Scooter Taken', 'Girne Station'),
(736, '97006', 'scooter_1', '30/09/2020', '12:50:46', 'Scooter Returned', 'Girne Station'),
(737, '97006', 'scooter_1', '30/09/2020', '12:51:26', 'Scooter Taken', 'Girne Station'),
(738, '97006', 'scooter_1', '30/09/2020', '12:52:01', 'Scooter Returned', 'Girne Station'),
(739, '97006', 'scooter_1', '30/09/2020', '13:02:11', 'Scooter Taken', 'Girne Station'),
(740, '97006', 'scooter_1', '30/09/2020', '13:04:04', 'Scooter Returned', 'Girne Station'),
(741, '99479', 'scooter_1', '30/09/2020', '13:06:38', 'Scooter Taken', 'Girne Station'),
(742, '99479', 'scooter_1', '30/09/2020', '13:08:15', 'Scooter Returned', 'Girne Station'),
(743, '99479', 'scooter_1', '30/09/2020', '13:09:10', 'Scooter Taken', 'Girne Station'),
(744, '99479', 'scooter_1', '30/09/2020', '13:10:04', 'Scooter Returned', 'Girne Station'),
(745, '99479', 'scooter_1', '30/09/2020', '13:14:37', 'Scooter Taken', 'Girne Station'),
(746, '99479', 'scooter_1', '30/09/2020', '13:17:11', 'Scooter Returned', 'Girne Station'),
(747, '97006', 'scooter_1', '30/09/2020', '14:21:10', 'Scooter Taken', 'Girne Station'),
(748, '97006', 'scooter_1', '30/09/2020', '14:21:42', 'Scooter Returned', 'Girne Station'),
(749, '97006', 'scooter_1', '30/09/2020', '16:55:30', 'Scooter Taken', 'Girne Station'),
(750, '97006', 'scooter_1', '30/09/2020', '16:56:03', 'Scooter Returned', 'Girne Station'),
(751, '97006', 'scooter_1', '30/09/2020', '16:59:01', 'Scooter Taken', 'Girne Station'),
(752, '97006', 'scooter_1', '30/09/2020', '16:59:24', 'Scooter Returned', 'Girne Station'),
(753, '97006', 'scooter_1', '30/09/2020', '15:43:21', 'Scooter Taken', 'Girne Station'),
(754, '97006', 'scooter_1', '30/09/2020', '15:43:46', 'Scooter Returned', 'Girne Station'),
(755, '97006', 'scooter_1', '30/09/2020', '15:45:34', 'Scooter Taken', 'Girne Station'),
(756, '97006', 'scooter_1', '01/10/2020', '13:29:51', 'Scooter Returned', 'Girne Station'),
(757, '97006', 'scooter_1', '01/10/2020', '13:40:46', 'Scooter Taken', 'Girne Station'),
(758, '97006', 'scooter_1', '01/10/2020', '13:41:31', 'Scooter Returned', 'Girne Station'),
(759, '97006', 'scooter_1', '01/10/2020', '13:43:06', 'Scooter Taken', 'Girne Station'),
(760, '97006', 'scooter_1', '01/10/2020', '13:43:51', 'Scooter Returned', 'Girne Station'),
(761, '97006', 'scooter_1', '01/10/2020', '13:45:00', 'Scooter Taken', 'Girne Station'),
(762, '97006', 'scooter_1', '01/10/2020', '13:45:53', 'Scooter Returned', 'Girne Station'),
(763, '97006', 'scooter_1', '01/10/2020', '13:46:56', 'Scooter Taken', 'Girne Station'),
(764, '97006', 'scooter_1', '01/10/2020', '13:47:27', 'Scooter Returned', 'Girne Station'),
(765, '97006', 'scooter_1', '01/10/2020', '13:50:01', 'Scooter Taken', 'Girne Station'),
(766, '97006', 'scooter_1', '01/10/2020', '13:50:14', 'Scooter Taken', 'Girne Station'),
(767, '97006', 'scooter_1', '01/10/2020', '13:51:12', 'Scooter Returned', 'Girne Station'),
(768, '97006', 'scooter_2', '01/10/2020', '13:53:26', 'Scooter Returned', 'Girne Station'),
(769, '46149', 'scooter_1', '06/10/2020', '10:07:26', 'Scooter Taken', 'Girne Station'),
(770, '46149', 'scooter_1', '06/10/2020', '10:08:08', 'Scooter Returned', 'Girne Station'),
(771, '46149', 'scooter_1', '06/10/2020', '10:08:24', 'Scooter Returned', 'Girne Station'),
(772, '97006', 'scooter_1', '06/10/2020', '15:42:50', 'Scooter Taken', 'Girne Station'),
(773, '97006', 'scooter_1', '06/10/2020', '15:43:26', 'Scooter Returned', 'Girne Station'),
(774, '97006', 'scooter_1', '30/10/2020', '16:47:19', 'Scooter Taken', 'Girne Station'),
(775, '97006', 'scooter_1', '30/10/2020', '16:48:50', 'Scooter Returned', 'Girne Station'),
(776, '97006', 'scooter_1', '02/11/2020', '14:35:01', 'Scooter Taken', 'Girne Station'),
(777, '97006', 'scooter_1', '02/11/2020', '14:37:44', 'Scooter Returned', 'Girne Station'),
(778, '97006', 'scooter_1', '02/11/2020', '14:45:04', 'Scooter Taken', 'Girne Station'),
(779, '97006', 'scooter_1', '02/11/2020', '14:47:48', 'Scooter Returned', 'Girne Station'),
(780, '97006', 'scooter_1', '02/11/2020', '14:50:20', 'Scooter Taken', 'Girne Station'),
(781, '97006', 'scooter_1', '02/11/2020', '15:14:21', 'Scooter Returned', 'Girne Station'),
(782, '97006', 'scooter_1', '02/11/2020', '15:52:19', 'Scooter Taken', 'Girne Station'),
(783, '97006', 'scooter_1', '02/11/2020', '15:52:50', 'Scooter Returned', 'Girne Station'),
(784, '97006', 'scooter_1', '10/11/2020', '09:29:07', 'Scooter Taken', 'Girne Station'),
(785, '97006', 'scooter_1', '10/11/2020', '09:41:18', 'Scooter Returned', 'Girne Station'),
(786, '97006', 'scooter_1', '10/11/2020', '09:42:59', 'Scooter Taken', 'Girne Station'),
(787, '97006', 'scooter_1', '10/11/2020', '09:48:09', 'Scooter Returned', 'Girne Station'),
(788, '97006', 'scooter_1', '10/11/2020', '10:07:32', 'Scooter Taken', 'Girne Station'),
(789, '97006', 'scooter_1', '10/11/2020', '10:07:55', 'Scooter Returned', 'Girne Station'),
(790, '97006', 'scooter_1', '10/11/2020', '10:08:20', 'Scooter Taken', 'Girne Station'),
(791, '97006', 'scooter_1', '10/11/2020', '10:08:41', 'Scooter Returned', 'Girne Station'),
(792, '97006', 'scooter_1', '10/11/2020', '12:41:00', 'Scooter Taken', 'Girne Station'),
(793, '97006', 'scooter_1', '10/11/2020', '12:41:25', 'Scooter Returned', 'Girne Station'),
(794, '97006', 'scooter_1', '12/11/2020', '15:36:43', 'Scooter Taken', 'Girne Station'),
(795, '97006', 'scooter_1', '12/11/2020', '15:37:04', 'Scooter Returned', 'Girne Station'),
(796, '97006', 'scooter_1', '13/11/2020', '08:21:47', 'Scooter Taken', 'Girne Station'),
(797, '97006', 'scooter_1', '13/11/2020', '08:22:12', 'Scooter Returned', 'Girne Station'),
(798, '97006', 'scooter_1', '13/11/2020', '08:35:15', 'Scooter Taken', 'Girne Station'),
(799, '97006', 'scooter_1', '13/11/2020', '08:35:37', 'Scooter Returned', 'Girne Station');

-- --------------------------------------------------------

--
-- Table structure for table `spots`
--

CREATE TABLE `spots` (
  `id` int(20) NOT NULL,
  `spot_id` varchar(45) NOT NULL,
  `spot_status` int(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `spots`
--

INSERT INTO `spots` (`id`, `spot_id`, `spot_status`) VALUES
(1, 'spot_1', 1),
(2, 'spot_2', 1),
(3, 'spot_3', 0),
(4, 'spot_4', 0),
(5, 'spot_5', 0),
(6, 'spot_6', 0),
(7, 'spot_7', 0),
(8, 'spot_8', 0),
(9, 'spot_9', 0),
(10, 'spot_10', 1);

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
  `name` varchar(45) COLLATE utf8_turkish_ci NOT NULL DEFAULT 'user',
  `id` varchar(45) COLLATE utf8_turkish_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`name`, `id`) VALUES
('user', '463682449040');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `employee_iot`
--
ALTER TABLE `employee_iot`
  ADD PRIMARY KEY (`id`),
  ADD KEY `employee_iot_registry_foreign` (`registry`);

--
-- Indexes for table `gonyeli_spots`
--
ALTER TABLE `gonyeli_spots`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `lef_spots`
--
ALTER TABLE `lef_spots`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `magusa_spots`
--
ALTER TABLE `magusa_spots`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `scooters`
--
ALTER TABLE `scooters`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `scooter_log`
--
ALTER TABLE `scooter_log`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `spots`
--
ALTER TABLE `spots`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`name`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `employee_iot`
--
ALTER TABLE `employee_iot`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=190;
--
-- AUTO_INCREMENT for table `gonyeli_spots`
--
ALTER TABLE `gonyeli_spots`
  MODIFY `id` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
--
-- AUTO_INCREMENT for table `lef_spots`
--
ALTER TABLE `lef_spots`
  MODIFY `id` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
--
-- AUTO_INCREMENT for table `magusa_spots`
--
ALTER TABLE `magusa_spots`
  MODIFY `id` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
--
-- AUTO_INCREMENT for table `scooters`
--
ALTER TABLE `scooters`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;
--
-- AUTO_INCREMENT for table `scooter_log`
--
ALTER TABLE `scooter_log`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=800;
--
-- AUTO_INCREMENT for table `spots`
--
ALTER TABLE `spots`
  MODIFY `id` int(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
