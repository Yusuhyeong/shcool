<?php
	include '../sql/session.php';
	
	if(isset($_SESSION['user_id'])) $id = $_SESSION['user_id'];
	if(isset($_SESSION['user_name'])) $name = $_SESSION['user_name'];
	
	if(!isset($id)) {
		echo "<script> alert('로그인 후 이용해주세요.');
		location.replace('../login/login.php');
		</script>";
	}
?>

<script>
  function check_input(){
      if(!document.board_form.title.value)
      {
            alert("제목을 입력하세요!");
            document.board_form.title.focus();
            return;
      }
      if(!document.board_form.contents.value)
      {
            alert("내용을 입력하세요!");
            document.board_form.contents.focus();
            return;
      }
      document.board_form.submit();
  }
</script>
<html>
	<head>
		<meta charset="utf-8">
		<link href="../css/basic.css" type="text/css" rel="stylesheet" /> 
		<link rel="stylesheet" type="text/css" href="./css/common.css">
        <link rel="stylesheet" type="text/css" href="./css/board.css">
	</head>
	<body>
	<section>
      <header>
         <?php include './board_header.php'; ?>
      </header>
      <div class="clear"></div>
	<section>
		<div id="board_box">
			<h3 id="board_title">
				게시판>글쓰기
			</h3>
			<form name="board_form" method="post" action="board_insert.php" >
				<ul id="board_form">
					<li>
						<span class="col1">아이디:</span>
						<span class="col2"><?=$id?></span>
					</li>
					<li>
						<span class="col1">제목: </span>
						<span class="col2"><input name="title" type="text" ></span>
					</li>
					<li id="text_area">
						<span class="col1">내용: </span>
						<span class="col2">
							<textarea name="contents" rows="10" cols="200"></textarea>
						</span>
					</li>
				</ul>
				<ul class="buttons">
					<li><button type="button" onclick="check_input()">완료</button></li>
					<li><button type="button" onclick="location.href='board_list.php'">
					목록</button></li>
                </ul>

			</form>
		</div><!--board_box-->
    </section>
    <footer>
	   <?php include './board_footer.php'; ?>
   </footer>
	</body>
</html>