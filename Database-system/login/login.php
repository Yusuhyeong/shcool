<!doctype html>
<html>
	<head>
		<meta charset="utf-8">
		<title>로그인</title>
		<link href="../css/login.css" type="text/css" rel="stylesheet" />
	</head>
	<body>
		<div class="logo">
			<a href="../index.php"><img src="../img/logoimage.png" alt="logo" width="100%" height="100%"></a>
		</div>
		<form method="post" action="member_check.php">
			<div class="login">
				<p>
					<input id="id" type="text" class="LoginTextBox" placeholder="아이디" name="id">
				</p>
				<p>
					<input id="pass" type="password" class="LoginTextBox" placeholder="비밀번호" maxlength="15" name="pass">
				</p>
				<input type="submit" value="로그인" class="LoginButton">
			</div>
		</form>
	</body>
</html>
