<!DOCTYPE html>
<!DOCTYPE html>
<?php
	include '../db.php';
	include '../sql/session.php';

	if(isset($_SESSION['user_id'])) $id = $_SESSION['user_id'];
	else unset($id);
	if(isset($_SESSION['user_name'])) $name = $_SESSION['user_name'];
	else unset($name);
	
?>
<html>
<head> 
<meta charset="utf-8">
<title>자유게시판</title>
        <link href="../css/basic.css" type="text/css" rel="stylesheet" />    
		<link href="../css/board.css" type="text/css" rel="stylesheet" />		<!스타일 시트 적용>
		<link href="../css/common.css" type="text/css" rel="stylesheet" />
	</head>
<body>
		<header>
			<?php include './board_header.php'; ?>
		</header>

      	<div class="clear"></div>
		<div id="board_box">
	    	<h3>
	    		게시판 > 목록보기
			</h3>
	    	<ul id="board_list">
				<li>
					<span class="col1">번호</span>
					<span class="col2">제목</span>
					<span class="col3">글쓴이</span>
					<span class="col5">등록일</span>
					<span class="col6">조회</span>
				</li>
<?php
	if (isset($_GET["page"]))
		$page = $_GET["page"];
	else
        $page = 1;
        
        $sql = "select * from board order by num desc";
	$result = mysqli_query($conn, $sql);
	$total_record = mysqli_num_rows($result); // 전체 글 수

	$scale = 10;

	// 전체 페이지 수($total_page) 계산 
	if ($total_record % $scale == 0)     
		$total_page = floor($total_record/$scale);      
	else
		$total_page = floor($total_record/$scale) + 1; 
 
	// 표시할 페이지($page)에 따라 $start 계산  
	$start = ($page - 1) * $scale;      

	$number = $total_record - $start;

   for ($i=$start; $i<$start+$scale && $i < $total_record; $i++)
   {
      mysqli_data_seek($result, $i);
      // 가져올 레코드로 위치(포인터) 이동
      $row = mysqli_fetch_array($result);
      // 하나의 레코드 가져오기
	  $num         = $row["num"];
	  $id          = $row["id"];
	  $title     = $row["title"];
      $day  = $row["date"];
      $viewer         = $row["viewer"];
      
?>
				<li>
					<span class="col1"><?=$num?></span>
					<span class="col2"><a href="board_view.php?num=<?=$num?>&page=<?=$page?>"><?=$title?></a></span>
					<span class="col3"><?=$id?></span>
					<span class="col5"><?=$day?></span>
					<span class="col6"><?=$viewer?></span>
				</li>	

<?php
   	   $num--;
   }
   mysqli_close($conn);

?>
	    	</ul>
			<ul id="page_num"> 	
<?php
	if ($total_page>=2 && $page >= 2)	
	{
		$new_page = $page-1;
		echo "<li><a href='board_list.php?page=$new_page'>◀ 이전</a> </li>";
	}		
	else 
		echo "<li>&nbsp;</li>";

   	// 게시판 목록 하단에 페이지 링크 번호 출력
   	for ($i=1; $i<=$total_page; $i++)
   	{
		if ($page == $i)     // 현재 페이지 번호 링크 안함
		{
			echo "<li><b> $i </b></li>";
		}
		else
		{
			echo "<li><a href='board_list.php?page=$i'> $i </a><li>";
		}
   	}
   	if ($total_page>=2 && $page != $total_page)		
   	{
		$new_page = $page+1;	
		echo "<li> <a href='board_list.php?page=$new_page'>다음 ▶</a> </li>";
	}
	else 
		echo "<li>&nbsp;</li>";
?>
			</ul> <!-- page -->	    	
			<ul class="buttons">
				<li><button onclick="location.href='board_list.php'">목록</button></li>
				<li>
<?php 
    if($id) {
?>
					<button onclick="location.href='board_form.php'">글쓰기</button>
<?php
	} else {
?>
					<a href="javascript:alert('로그인 후 이용해 주세요!')"><button>글쓰기</button></a>
<?php
	}
?>
				</li>
			</ul>
	</div> <!-- board_box -->

		<footer>
			<?php include './board_footer.php'; ?>
		</footer>
</body>
</html>