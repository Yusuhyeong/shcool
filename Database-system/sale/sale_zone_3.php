<?php
	include '../sql/session.php';
	include '../db.php';
	if(isset($_SESSION['user_id'])) $id = $_SESSION['user_id'];
	else unset($id);
	if(isset($_SESSION['user_name'])) $name = $_SESSION['user_name'];
	else unset($name);
?>

<!doctype html>
<html>
	<head>
		<meta charset="utf-8">
		<title>사창동</title>
		<link href="/css/basic.css" type="text/css" rel="stylesheet" />			<!--스타일 시트 적용-->
		<link href="../css/sale_hover.css" type="text/css" rel="stylesheet" />
		<link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.13.0/css/all.min.css" rel="stylesheet"> <!--CDN 링크 -->
		<style type="text/css">
			A:link {text-decoration:none}
			A:visited {text-decoration:none}
			A:hover {text-decoration:none}	
		</style>		
	</head>
	<body>
		<header>
			<?php include './sale_header.php'; ?>
		</header>
		<div class="clear"></div>
		</div>
		<div class="home">
			<div class="main">
					
					
				<div class="contents">
					<main>
						<section class="info_box">
							<h2>사창동 <span>분양정보</span></h2>
							<ul style="list-style-type: none;">
<?php
// area - 3
$area = 3;

$res = mq("select * from sale s, state t where s.state_num = t.state_num AND s.area ='".$area."'");

while($row = mysqli_fetch_array($res)) {
	$num = $row["state_num"];
	$title = $row["title"];
	$contents = $row["contents"];
	$date = $row["date"];
	$viewer = $row["viewers"];
	$good = $row["goods"];
	$price = $row["price"];

?>
								<li>
									<a href="sale_zone_board.php?num=<?=$num?>">
										<em><img src="../img/zone_3/<?=$title?>.jpg" alt="img"></em>
										<div class="temp">
											<?="<h3>".$title."</h3>";?>
											<p><?=$contents?></p>
											<span class="ico no3">사창동</span>
										</div>
								
									<div class="container">
										<div class="text_">
											<?="<p>조회수 : ".$viewer."</p>";?>
											<?="<p>추천 : ".$good."</p>";?>
										</div>
									</div>
									</a>
									<div>
									<a href="sale_good.php?num=<?=$num?>">
										<span style="color:#FF0000"><i class="fas fa-heart fa-lg fa-fw"></i></span>
									</a>
									
									</div>
								</li>
<?php }?>
							</ul>
						</section>
					</main>
					
					<div style="cleaer: both;"> </div>
				</div>					
			</div>
		</div>
		<footer>
			<?php include './sale_footer.php'; ?>
		</footer>
		</body>
	</html>