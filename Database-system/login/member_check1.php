
<html>
	<head>
		<?php
			include '../db.php';
			//session_start();
		?>
		<meta charset="utf-8">
	</head>
	<body>
	<?php


		$id=$_post['id'];
		$pass=md5($_post['pass']);

		//echo $id;
		
		$sql="SELECT *from member WHERE id='{$id}' AND pass = '{$pass}'";
		$result=mysqli_query($conn,$sql);
		
		$row=mysqli_fetch_assoc($result);
		
		
		/*echo("
				<script>
					window.alert('{$id}')
					history.go(-1)
				</script>
			");*/
		if($row != NULL)
		{
			//$_SESSION['userid'] = $row['id'];
			echo "<script>alert(\"환영합니다.\")</script>";
			echo "<script>location.replace('/index.php')</script>";
		}
		
		if($row ==NULL) {
			echo "<script>alert(\"아이디와 비밀번호를 확인하세요.\");</script>";
			echo "<script>history.back();</script>";
		}
			/*
			echo("
				<script>
					window.alert('등록되지 않은 아이디입니다.')
					history.go(-1)
				</script>
			");
		}
		else{
			$row=mysqli_fetch_array($result);
			$db_pass=$row["pass"];

			mysqli_close($con);

			if($pass !=$db_pass)
			{
				echo("
					<script>
						window.alert('비밀번호가 틀립니다.')
						history.go(-1)
					</script>
		
				");
			exit;
			}
			else
			{
				$_SESSION["userid"]=$row["id"];
				$_SESSION["username"]=$row["name"];
		
				echo("
					<script>
						location.href='../index.php';
					</script>
				");
			}
		}*/

	?>
	</body>
</html>