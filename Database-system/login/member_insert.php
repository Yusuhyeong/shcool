<?php
   include '../db.php';

   $name=$_POST["name"];
   $id=$_POST["id"];
   $pass=$_POST["pass"];
   $pass_check=$_POST["pass_check"];
   $num=$_POST["num"];
   $email=$_POST["email"];
   $sex=$_POST["sex"];
      
   if($pass != $pass_check) {            //비밀번호 일치 확인
      echo "<script>alert(\"비밀번호가 일치하지 않습니다.\");</script>";
      echo "<script>history.back();</script>";
      exit;
      }else {
      $pass = md5($pass);         //비밀번호 암호화
   }
   
   $sql = mysqli_query($conn, "SELECT EXISTS (SELECT * from member WHERE id='{$id}') as success"); 
   $usernamecount = $sql->fetch_array(); 
   if($usernamecount['success']==1) {
      echo "<script>alert(\"중복된 아이디입니다!\");</script>";
      echo "<script>history.back();</script>";
      exit;
   }
   
   
   $checkemail = filter_var($email, FILTER_VALIDATE_EMAIL);      //이메일 형식 체크
   
   if($checkemail != true) {
      echo "<script>alert(\"이메일 형식이 잘못되었습니다.\");</script>";//
      echo "<script>history.back();</script>";
        exit;
    }
   
   //$result = mysqli_query($conn, "INSERT INTO member(name,id,pass,num,email) VALUES('".$name."','".$id."','".$pass."','".$num."','".$email."')");
   
   $sql = "INSERT INTO member(name,id,pass,num,email,sex) VALUES('$name','$id','$pass','$num','$email','$sex')";
   
   if($conn->query($sql)) {   
      echo "<script>alert(\"회원가입이 완료되었습니다!\");</script>";
      echo "<script>location.href='../index.php'</script>";
   }else {
      echo "<script>alert(\"회원가입 실패\");</script>";
      echo "<script>history.back();</script>";
   }
?>