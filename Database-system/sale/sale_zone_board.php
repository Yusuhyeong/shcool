<?php
include '../sql/session.php';
include '../db.php';

$num = $_REQUEST["num"];

$row = mysqli_fetch_array(mq("select * from sale s, state t where s.state_num = t.state_num AND s.state_num ='".$num."'"));
$num = $row["state_num"];
$title = $row["title"];
$contents = $row["contents"];
$date = $row["date"];
$viewer = $row["viewers"] + 1;
$good = $row["goods"];
$area = $row["area"];
$price = $row["price"];
$tel = $row["tel"];

$fet = mq("update sale s INNER JOIN state t ON s.state_num = t.state_num set t.viewers = '".$viewer."' where s.state_num = '".$num."'");

if(isset($_SESSION['user_id'])) $id = $_SESSION['user_id'];
else unset($id);
if(isset($_SESSION['user_name'])) $name = $_SESSION['user_name'];
else unset($name);
?>

<!doctype html>
<html>
   <head>
      <meta charset="utf-8">
      <title>정보</title>
      <link href="/css/basic.css" type="text/css" rel="stylesheet" />      <!--스타일 시트 적용-->
	  <link href="../css/zone_board.css" type="text/css" rel="stylesheet" />
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
				<div class = "main">
            <div class="contents">
               <div class="title">
                  <a class="name">
                     <?="<h2>[자취빵] <span>".$title."</span<</h2>";?>
                     <a class="more"><?=$date?></a> <br>
                     <hr>
                     <?="<h3>조회수 : ".$viewer.  "  추천수 : ".$good."</h3>";?>
                  </a>
               </div>
               <hr>
               <table class="table_" border = "1" cellspacing="0">
                  <tr>
                     <td>상권명</td>
                     <td><?=$title?></td>
                  <tr>
                  <tr>
                     <td>연락처</td>
                     <td><?=$tel?></td>
                  <tr>
                  <tr>
                     <td>방세</td>
                     <td><?=$price?></td>
                  <tr>
                  <tr>
                     <td>옵션</td>
                     <td><?=$contents?></td>
                  <tr>
               </table><br>
					<div class="image_map"><img src="../img/zone_<?=$area?>/<?=$title."위치"?>.PNG" alt="img"><br></div>
					<div class="image_">
						<img src="../img/zone_<?=$area?>/<?=$title."_1"?>.jpg" alt="img">
						<img src="../img/zone_<?=$area?>/<?=$title."_2"?>.jpg" alt="img">
					</div>
				<hr>
				<div class="button">
					<button type="button" onclick="location.href='sale_zone_<?=$area?>.php'">목록</button>
				</div>
			</div>
         </div>
         <footer>
	<div class="top">
		<div class="clear"></div>
	</div>
	<div class="btm">
		<div class="btm_bottom">
			<ul>
			<li>충북대학교</li>
			<li>Tel 010-4993-6984</li>
			<li>관리자 18팀</li>
			<li>E-mail rwalrwala@gmail.com</li>
			</ul>
			<address>Copyright 2020 14팀 All rights reserved.</address>
		</div>
	</div>
		</footer>
      </div>
   </body>
</html>