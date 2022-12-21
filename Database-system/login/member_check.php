<?php
	include '../sql/session.php';
	include '../db.php';
	
	$temp_id=$_POST["id"];
	$temp_pass=md5($temp = $_POST['pass']);
	
	$sql = mq("SELECT * FROM member WHERE id = '{$temp_id}' AND pass = '{$temp_pass}'");
	$logincount = $sql->fetch_array();
	
	if($logincount!=null) {
		$_SESSION['user_id'] = $logincount['id'];
        $_SESSION['user_name'] = $logincount['name'];
		echo "<script>alert(\"".$_SESSION['user_id']." 환영합니다.\");</script>";
		echo "<script>location.replace('../index.php')</script>";
		exit();
	}
	
	if($logincount==null) {
		echo "<script>alert(\"아이디와 비밀번호를 확인하세요.\");</script>";
		echo "<script>history.back();</script>";
		exit();
	}
	
	/*$row = $res->fetch_array(MYSQLI_ASSOC);
	
	echo "$row";
	
	if($row != NULL) {
		echo "<script>alert(\"환영합니다.\");</script>";
		echo "<script>location.replace('../index.php')";
	}
	
	if($row == NULL) {
		echo "<script>alert(\"아이디와 비밀번호를 확인하세요.\"_);</script>";
		echo "<script>history.back();</script>";
	}*/
?>




