<!doctype html>

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
	</head>

	<?php
	if(!$id )
	{
		echo("
		<script>
			alert(' 게시판 글쓰기는 로그인 후 이용해 주세요!');
			history.go(-1)
			</script>
			");
		exit;
	}
	
	
	$title=$_POST["title"];
	$contents=$_POST["contents"];

	$title=htmlspecialchars($title,ENT_QUOTES);
	$contents=htmlspecialchars($contents,ENT_QUOTES);

	$day=date("Y-m-d");

  
	if($id && $title && $contents){
		$sql= "insert into board(id, title, contents, date) values('$id','$title', '$contents', '$day')";
		//$sql="values('$id','$title', '$contents', date)";
  }
	 //$result=$db->query($sql);
	 if($conn->query($sql)){
		echo "<script>alert(\"글쓰기 완료!\");</script>";
		echo "<script>location.href='../board/board_list.php'</script>";
	 }else{
	 echo "<script>alert(\"글쓰기 실패\");</script>";
	 echo "<script>history.back();</script>";
	 }
  
	 mysqli_close($conn);
  
	 echo "
	 <script>
	  location.href = \'board_list.php\';
	 </script>
   ";
	  ?>