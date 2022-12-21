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
  
        <link href="/css/basic.css" type="text/css" rel="stylesheet" /> 
		<link href="../css/board.css" type="text/css" rel="stylesheet" />		<!스타일 시트 적용>
		<link href="../css/common.css" type="text/css" rel="stylesheet" />
</head>
<body>
    <header>
		<?php include './board_header.php'; ?>
	</header>
<section>
<div id="board_box">
	    <h3 class="title">
			게시판 > 내용보기
        </h3>
        
<?php
    $num = $_GET["num"];
    $page = $_GET["page"];
    

     $sql="select *from board where num=$num";
     $result=mysqli_query($conn,$sql);

     $row = mysqli_fetch_array($result);
	$id  = $row["id"];
	$title = $row["title"];
    $contents = $row["contents"];
    $day = $row["date"];
    $viewer=$row["viewer"];
    
    //공백과 줄 바꿈 코드 변경
    $contents = str_replace(" ", "&nbsp;", $contents);
    $contents = str_replace("\n", "<br>", $contents);
    
    $new_viewer = $viewer + 1;
	$sql = "update board set viewer=$new_viewer where num=$num";   
    mysqli_query($conn, $sql);
    ?>

<ul id="view_contents">
			<li>
				<span class="col1"><b>제목 :</b> <?=$title?></span>
				<span class="col2"><?=$id?> | <?=$day?></span>
				<p></p>
				<?=$contents?>
            		</li>
</ul>

<ul class="buttons">
				<li><button onclick="location.href='board_list.php?page=<?=$page?>'">목록</button></li>
				<li><button onclick="location.href='board_modify_form.php?num=<?=$num?>&page=<?=$page?>'">수정</button></li>
				<li><button onclick="location.href='board_delete.php?num=<?=$num?>&page=<?=$page?>'">삭제</button></li>
				<li><button onclick="location.href='board_form.php'">글쓰기</button></li>
		</ul>
        </div> <!-- board_box -->
</section>
<footer>
	<?php include './board_footer.php'; ?>
</footer>
</body>
</html>
    
