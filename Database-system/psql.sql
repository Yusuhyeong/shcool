CREATE SCHEMA `test` ;

use test;

CREATE TABLE board (
	num			INT				NOT NULL,
    id			VARCHAR(30)		NOT NULL,
    title		VARCHAR(30)		NOT NULL,
    contents	VARCHAR(255)	NOT NULL,
    date		DATE			DEFAULT NULL,
    viewer		INT				DEFAULT NULL,
    good		int				DEFAULT NULL,
    CONSTRAINT PK_BOARD PRIMARY KEY (num)
);

CREATE TABLE state (
	state_num	INT				NOT NULL,
    viewers		INT				DEFAULT '0',
    goods		INT				DEFAULT '0',
    CONSTRAINT PK_STATE PRIMARY KEY (state_num)
);

CREATE TABLE MAP (
	map_id	    char(10)		NOT NULL,
    map_num		INT				NOT NULL,
    lat			DOUBLE			DEFAULT NULL,
    lng			DOUBLE			DEFAULT NULL,
    CONSTRAINT PK_MAP PRIMARY KEY (map_id)
);

CREATE TABLE MEMBER (
	name		CHAR(20)		NOT NULL,
    id			CHAR(20)		NOT NULL,
    pass		CHAR(255)		NOT NULL,
    num			CHAR(20)		NOT NULL,
    email		CHAR(20)		NOT NULL,
    sex			VARCHAR(10)		DEFAULT NULL,
    CONSTRAINT PK_MEMBER PRIMARY KEY (id)
);

CREATE TABLE SALE (
	num			INT				NOT NULL,
    id			VARCHAR(30)		NOT NULL,
    title		VARCHAR(50)		NOT NULL,
    contents	VARCHAR(255)	NOT NULL,
    date		date			NOT NULL,
    area		INT				NOT NULL,
    price		VARCHAR(255)	NOT NULL,
    tel			CHAR(20)		NOT NULL,
    state_num	int				DEFAULT NULL,
    CONSTRAINT PK_SALE PRIMARY KEY (num)
);


INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_1', '1', '36.628425', '127.448724');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_2', '2', '36.627203', '127.448338');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_3', '3', '36.629356', '127.448746');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_4', '4', '36.631732', '127.451482');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_5', '5', '36.631199', '127.451074');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_6', '6', '36.630949', '127.450774');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_7', '7', '36.626437', '127.448819');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_8', '8', '36.627002', '127.464141');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_9', '9', '36.626089', '127.466201');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_10', '10', '36.625882', '127.46368');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_11', '11', '36.625003', '127.465064');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_12', '12', '36.626097', '127.466191');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_13', '13', '36.625985', '127.466212');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_14', '14', '36.631006', '127.46093');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_15', '15', '36.630897', '127.461266');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_16', '16', '36.630006', '127.462269');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_17', '17', '36.629847', '127.46287');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_18', '18', '36.628754', '127.463315');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_19', '19', '36.618772', '127.459746');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_20', '20', '36.618504', '127.459292');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_21', '21', '36.618048', '127.458916');
INSERT INTO `test`.`map` (`map_id`, `map_num`, `lat`, `lng`) VALUES ('m_22', '22', '36.618754', '127.459216');

INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('1', 'admin', '금강하우스', '풀옵션, 공용정수기 이용, 침대 설치', '2014-01-14', '1', '보증금 200 / 월세 25, 관리비 7', '010-3397-0566', '1');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('2', 'admin', '금성빌리지', '풀옵션, CCTV 설치, 승강기, 디지털 도어락, 주차 가능', '2015-03-21', '1', '보증금 200 / 월세 25, 관리비 6', '010-5322-8565', '2');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('3', 'admin', '몽마르뜨', '풀옵션, CCTV 설치, 침대, 주차 가능', '2008-12-11', '1', '보증금 100 / 월세 26, 관리비 5', '010-5431-7241', '3');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('4', 'admin', '스타빌', '풀옵션, 침대, 디지털 도어락, 주차 가능', '2015-11-03', '1', '보증금 200 / 월세 26, 관리비 5', '011-311-3563', '4');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('5', 'admin', '은하수빌라', '풀옵션, CCTV 설치, 공용 정수기, 침대, 주차 가능', '2018-05-07', '1', '보증금 200 / 월세 28, 관리비 5', '010-2438-0904', '5');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('6', 'admin', '축복의집', '풀옵션, 침대', '2018-04-27', '1', '보증금 400 / 월세 25, 관리비 5', '010-8824-3840', '6');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('7', 'admin', '하버드빌라', '풀옵션, CCTV 설치, 승강기 설치', '2019-05-03', '1', '보증금 100 / 월세 25, 관리비 5', '010-4311-1421', '7');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('8', 'admin', '그린빌', '풀옵션, 공용 정수기, 침대, 공과금 포함, 디지털 도어락, 주차 가능', '2017-08-19', '2', '전세 2000, 관리비 8', '010-9420-7766', '8');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('9', 'admin', '베로니카하우스', '풀옵션, 침대', '2018-04-22', '2', '보증금 200 / 월세 25, 관리비 5', '010-3200-7457', '9');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('10', 'admin', '블루힐', '풀옵션, 침대', '2012-06-03', '2', '보증금 200 / 월세 25, 관리비 5', '010-3261-6882', '10');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('11', 'admin', '상촌빌라', '풀옵션, 침대, 디지털 도어락, 주차 가능', '2013-01-07', '2', '보증금 100 / 월세 28, 관리비 6', '010-3650-9417', '11');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('12', 'admin', '안젤라하우스', '풀옵션, 침대', '2011-05-13', '2', '전세 2500, 관리비 5', '010-4140-5705', '12');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('13', 'admin', '즐거운빌', '풀옵션, 침대', '2017-10-11', '2', '보증금 200 / 월세 25, 관리비 7', '010-9455-6969', '13');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('14', 'admin', '나라찬빌라', '풀옵션, 공용 정수기, 침대, 공용 세탁기, 주차 가능', '2010-11-23', '3', '보증금 500 / 월세 30, 관리비 5', '043-542-6992', '14');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('15', 'admin', '대경빌', '공용 정수기, 침대, 공용 세탁기', '2015-03-17', '3', '보증금 300 / 월세 28, 관리비 5', '010-8826-9848', '15');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('16', 'admin', '아띠하우스빌라', '공용 정수기, 침대, 주차 가능', '2014-04-19', '3', '보증금 200 / 월세 28, 관리비 5', '010-2594-8571', '16');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('17', 'admin', '연수빌', '풀옵션, 침대', '2018-02-21', '3', '보증금 200 / 월세 25, 관리비 7', '011-426-8914', '17');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('18', 'admin', '예인빌', '풀옵션, CCTV 설치, 승강기, 침대, 디지털 도어락', '2011-12-03', '3', '보증금 500 / 월세 26, 관리비 5', '010-8480-4431', '18');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('19', 'admin', '다올빌', '풀옵션, 침대', '2013-04-11', '4', '전세 5000, 관리비 6', '\'010-8746-6910', '19');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('20', 'admin', '송원빌', '풀옵션, 침대, 디지털 도어락', '2015-07-03', '4', '전세 4000, 관리비 8', '010-5414-5428', '20');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('21', 'admin', '시온빌', '풀옵션, 침대', '2008-03-02', '4', '보증금 500 / 월세 30, 관리비 5', '010-7315-1961', '21');
INSERT INTO `test`.`sale` (`num`, `id`, `title`, `contents`, `date`, `area`, `price`, `tel`, `state_num`) VALUES ('22', 'admin', '에코브리지', '풀옵션, 공용 정수기, 침대', '2007-10-20', '4', '전세 3000, 관리비 8', '010-8996-7953', '22');

INSERT INTO `test`.`state` (`state_num`) VALUES ('1');
INSERT INTO `test`.`state` (`state_num`) VALUES ('2');
INSERT INTO `test`.`state` (`state_num`) VALUES ('3');
INSERT INTO `test`.`state` (`state_num`) VALUES ('4');
INSERT INTO `test`.`state` (`state_num`) VALUES ('5');
INSERT INTO `test`.`state` (`state_num`) VALUES ('6');
INSERT INTO `test`.`state` (`state_num`) VALUES ('7');
INSERT INTO `test`.`state` (`state_num`) VALUES ('8');
INSERT INTO `test`.`state` (`state_num`) VALUES ('9');
INSERT INTO `test`.`state` (`state_num`) VALUES ('10');
INSERT INTO `test`.`state` (`state_num`) VALUES ('11');
INSERT INTO `test`.`state` (`state_num`) VALUES ('12');
INSERT INTO `test`.`state` (`state_num`) VALUES ('13');
INSERT INTO `test`.`state` (`state_num`) VALUES ('14');
INSERT INTO `test`.`state` (`state_num`) VALUES ('15');
INSERT INTO `test`.`state` (`state_num`) VALUES ('16');
INSERT INTO `test`.`state` (`state_num`) VALUES ('17');
INSERT INTO `test`.`state` (`state_num`) VALUES ('18');
INSERT INTO `test`.`state` (`state_num`) VALUES ('19');
INSERT INTO `test`.`state` (`state_num`) VALUES ('20');
INSERT INTO `test`.`state` (`state_num`) VALUES ('21');
INSERT INTO `test`.`state` (`state_num`) VALUES ('22');

