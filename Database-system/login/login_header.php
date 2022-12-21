<?php  
    if(isset($_SESSION['user_id'])) $id = $_SESSION['user_id'];
    if(isset($_SESSION['user_name'])) $name = $_SESSION['user_name'];
?>
<!DOCTYPE html>
<html lang="ko">
	<head>
		<link href="../css/basic.css" type="text/css" rel="stylesheet" />
	</head>
	<body>
    <div class=nav>
		<div class="logo">
			<a href="../index.php"><img src="../img/logoimage.png" alt="logo" width="120" height="50"></a>	<!--로고 띄우기-->
		</div>
		<div class="lnb">
        	<ul>
        		<li><a href="./sale/sale_best.php"><span>BEST</span></a></li>
        		<li><a href="./sale/sale_zone_1.php"><span>1구역</span></a></li>
        		<li><a href="./sale/sale_zone_2.php"><span>2구역</span></a></li>
        		<li><a href="./sale/sale_zone_3.php"><span>3구역</span></a></li>
        		<li><a href="./sale/sale_zone_4.php"><span>4구역</span></a></li>
        	</ul>
        </div>
		<div class="top-l">
		<?php
			if(!isset($id)) {
				echo '<div class="login">
				<a href="./login/login.php">로그인</a>
				&nbsp│&nbsp
				<a href="./login/register.php">회원가입</a>
				</div>';
			}
			else {
				echo '<div class="logout">
				<a>'; echo $id;
				echo '</a>님 환영합니다.
				&nbsp│&nbsp
				<a href="./sql/logout.php">로그아웃</a>
				</div>';
			}
		?>
	</div>
	</body>
</html>