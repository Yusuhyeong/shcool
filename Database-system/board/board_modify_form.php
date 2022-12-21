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

<script>
  function check_input() {
      if (!document.board_form.title.value)
      {
          alert("제목을 입력하세요!");
          document.board_form.title.focus();
          return;
      }
      if (!document.board_form.contents.value)
      {
          alert("내용을 입력하세요!");    
          document.board_form.contents.focus();
          return;
      }
      document.board_form.submit();
   }
</script>
</head>
<body>
<header>
	<?php include './board_header.php'; ?>
</header>
<section>
   	<div id="board_box">
	    <h3 id="board_title">
	    		게시판 > 글 쓰기
		</h3>

        <?php
	$num  = $_GET["num"];
	$page = $_GET["page"];
	
	
	$sql = "select * from board where num=$num";
	$result = mysqli_query($conn, $sql);
	$row = mysqli_fetch_array($result);
	$id       = $row["id"];
	$title    = $row["title"];
	$contents    = $row["contents"];		
?>

<form  name="board_form" method="post" action="board_modify.php?num=<?=$num?>&page=<?=$page?>" enctype="multipart/form-data">
	    	 <ul id="board_form">
				<li>
					<span class="col1">이름 : </span>
					<span class="col2"><?=$id?></span>
				</li>		
	    		<li>
	    			<span class="col1">제목 : </span>
	    			<span class="col2"><input name="title" type="text" value="<?=$title?>"></span>
	    		</li>	    	
	    		<li id="text_area">	
	    			<span class="col1">내용 : </span>
	    			<span class="col2">
	    				<textarea name="contents"><?=$contents?></textarea>
	    			</span>
	    		</li>
	    	    </ul>
	    	<ul class="buttons">
				<li><button type="button" onclick="check_input()">수정하기</button></li>
				<li><button type="button" onclick="location.href='board_list.php'">목록</button></li>
			</ul>
	    </form>
        </div> <!-- board_box -->
</section> 
<footer>
	<?php include './board_footer.php'; ?>
</footer>
</body>
</html>