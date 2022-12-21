<!doctype html>

<?php
	include '../db.php';
	if(isset($_SESSION['user_id'])) $id = $_SESSION['user_id'];
	else unset($id);
	if(isset($_SESSION['user_name'])) $name = $_SESSION['user_name'];
	else unset($name);
	?>
<html>
	<head>
		<meta charset="utf-8">
		<title>자유게시판</title>
		<link href="/css/basic.css" type="text/css" rel="stylesheet" />		<!스타일 시트 적용>
		<link href="/css/table.css" type="text/css" rel="stylesheet" />
	</head>
	<body>
	<section>
		<header>
			<?php include '../header.php'; ?>
		</header>
		<div class="top-l">
		</div>
		<div class="clear"></div>
		</div>
			<div class="home">
				<div class="main">
					<div class="contents">
						<!-- page -->	    	
						<ul class="buttons">
							<center>
								<font size="10em">
								자유게시판
								</font>
							</center>
							<table class="table">
								<thead>
									<tr>
										<th width="70">번호</th>
										<th width="500">제목</th>
										<th width="120">글쓴이</th>
										<th width="100">작성일</th>
										<th width="100">조회수</th>
										<th width="50">추천수</th>
									</tr>
								</thead>
								<tbody>
<?php
$res=mq("SELECT * FROM board order by num desc");
if(isset($_GET["page"]))
	$page = $_GET["page"];
else
	$page = 1;

$count = mysqli_num_rows($res);
	
$scale = 10;
					
//페이지 수 계산
if($count % $scale == 0)
	$total_page = floor($count /$scale);
else
	$total_page = floor($count/$scale)+1;

$start = ($page - 1) * $scale;
$number = $count - $start;

for($i=$start; $i<$start+$scale && $i < $count; $i++){
	mysqli_data_seek($res, $i);
	//가져올 레코드로 위치(포인터) 이동
	$row = mysqli_fetch_array($res);
	//하나의 레코드 가져오기
	$num = $row["num"];
	$id = $row["id"];
	$title = $row["title"];
	$contents = $row["contents"];
	$date = $row["date"];
	$viewer = $row["viewer"];
	$good = $row["good"];
							
?>
									<tr>
										<td width="70"> <?=$num?></td>
										<td width="500"> <?=$title?></td>
										<td width="120"> <?=$id?></td>
										<td width="100"> <?=$date?></td>
										<td width="100"> <?=$viewer?></td>
										<td width="50"> <?=$good?></td>
									</tr>
<?php
}
?>
								</tbody>
							</table>
						</ul>
						<div id="write_btn">
							<p style="text-align:right; margin-right:35px;">
							<a href="board_form.php"><button>글쓰기</button></a>
						</div>
						</p>
					</div>
			</div>
			<footer>
				<?php include '../footer.php'; ?>
			</footer>	
		</section>
	</body>
</html>