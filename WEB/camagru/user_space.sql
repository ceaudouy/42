-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Nov 25, 2019 at 06:12 AM
-- Server version: 5.6.43
-- PHP Version: 5.6.40

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `user_space`
--

-- --------------------------------------------------------

--
-- Table structure for table `commentaire`
--

CREATE TABLE `commentaire` (
  `id` int(11) NOT NULL,
  `id_user` int(11) NOT NULL,
  `login` varchar(255) NOT NULL,
  `photo` varchar(255) NOT NULL,
  `commentaire` text NOT NULL,
  `id_user_photo` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `commentaire`
--

INSERT INTO `commentaire` (`id`, `id_user`, `login`, `photo`, `commentaire`, `id_user_photo`) VALUES
(161, 25, 'qwerty', '25_435155926626.png', 'whoaw', 25),
(162, 26, 'qazwsx', '25_435155926626.png', 'sisi', 25),
(163, 27, 'bvftfg', '26_089622928429.png', 'ah !', 26),
(164, 27, 'bvftfg', '25_435155926626.png', 'ok', 25),
(165, 28, 'okij', '27_344058622110.png', 'mouais', 27);

-- --------------------------------------------------------

--
-- Table structure for table `likes`
--

CREATE TABLE `likes` (
  `id` int(11) NOT NULL,
  `photo` varchar(255) NOT NULL,
  `id_user` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `likes`
--

INSERT INTO `likes` (`id`, `photo`, `id_user`) VALUES
(15, '25_435155926626.png', 25),
(16, '25_955184711292.png', 25),
(17, '25_435155926626.png', 26),
(18, '26_089622928429.png', 27),
(19, '25_435155926626.png', 27),
(20, '25_955184711292.png', 27),
(21, '27_344058622110.png', 27),
(22, '26_049548971943.png', 27),
(23, '26_049548971943.png', 28);

-- --------------------------------------------------------

--
-- Table structure for table `membres`
--

CREATE TABLE `membres` (
  `id` int(11) NOT NULL,
  `login` varchar(255) NOT NULL,
  `mail` varchar(255) NOT NULL,
  `avatar` varchar(255) NOT NULL,
  `notif` int(11) NOT NULL,
  `confirme` int(1) NOT NULL,
  `confirmkey` varchar(255) NOT NULL,
  `passwd` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `membres`
--

INSERT INTO `membres` (`id`, `login`, `mail`, `avatar`, `notif`, `confirme`, `confirmkey`, `passwd`) VALUES
(25, 'qwerty', 'camagru.ceaudouy@gmail.com', '25.jpeg', 1, 1, '36041401598', '39c919cbd57b5e841ca2dd77bd9b4fb8'),
(26, 'qazwsx', 'qazwsx@qwerty.fr', '26.jpeg', 1, 1, '61020987989', 'a25d0b28019e5ba5be9d564e52a5b38c'),
(27, 'bvftfg', 'uybg@efed.f', 'default.jpeg', 1, 1, '01115772339', 'a25d0b28019e5ba5be9d564e52a5b38c'),
(28, 'okij', 'qwe@tfrvd.f', 'default.jpeg', 1, 1, '19920514034', 'a25d0b28019e5ba5be9d564e52a5b38c');

-- --------------------------------------------------------

--
-- Table structure for table `photos`
--

CREATE TABLE `photos` (
  `id` int(11) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `path` text NOT NULL,
  `id_user` int(11) NOT NULL,
  `date` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `photos`
--

INSERT INTO `photos` (`id`, `nom`, `path`, `id_user`, `date`) VALUES
(47, '25_955184711292.png', 'membres/photo/25_955184711292.png', 25, '25112019060605'),
(48, '25_435155926626.png', 'membres/photo/25_435155926626.png', 25, '25112019060614'),
(49, '26_049548971943.png', 'membres/photo/26_049548971943.png', 26, '25112019060754'),
(50, '26_089622928429.png', 'membres/photo/26_089622928429.png', 26, '25112019060829'),
(51, '27_195238687577.png', 'membres/photo/27_195238687577.png', 27, '25112019061004'),
(52, '27_344058622110.png', 'membres/photo/27_344058622110.png', 27, '25112019061020');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `commentaire`
--
ALTER TABLE `commentaire`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `likes`
--
ALTER TABLE `likes`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `membres`
--
ALTER TABLE `membres`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `photos`
--
ALTER TABLE `photos`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `commentaire`
--
ALTER TABLE `commentaire`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=166;

--
-- AUTO_INCREMENT for table `likes`
--
ALTER TABLE `likes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;

--
-- AUTO_INCREMENT for table `membres`
--
ALTER TABLE `membres`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=29;

--
-- AUTO_INCREMENT for table `photos`
--
ALTER TABLE `photos`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=53;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
