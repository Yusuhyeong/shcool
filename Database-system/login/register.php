<!doctype html>
<html lang="ko">
	<head>
		<meta charset="utf-8">
		<title>자취빵::회원가입</title>
		<link href="../css/login.css" type="text/css" rel="stylesheet" />
	</head>
	<body>
		<form method="post" action="member_insert.php">
			<div class="logo">
				<a href="../index.php"><img src="../img/logoimage.png" alt="logo" width="100%" height="100%"></a>
			<div class="login">
				<p>
					<input id="name" type="text" class="LoginTextBox" placeholder="이름" name="name">
				</p>
				<p>
					<input id="sex" type="text" class="LoginTextBox" placeholder="성별" name="sex">
				</p>
				<p>
					<input id="id" type="text" class="LoginTextBox" placeholder="아이디" name="id">
				</p>
				<p>
					<input id="password" type="password" class="LoginTextBox" placeholder="비밀번호" maxlength="15" name="pass">
				</p>
				<p>
					<input id="password2" type="password" class="LoginTextBox" placeholder="비밀번호확인" name="pass_check">
				</p>
				<p>
					<input id="number" type="text" class="LoginTextBox" placeholder="전화번호" name="num">
				</p>
				<p>
					<input id="email" type="email" class="LoginTextBox" placeholder="이메일" name="email">
				</p>
				<p>
					<input type="submit" value="회원가입" class="LoginButton">
				</p>
			</div>
		</form> 
	</body>
</html>
  