

<?php
	include '../db.php';

    $num = $_GET["num"];
    $page=$_GET["page"];

   

    $sql="delete from board where num=$num";
    mysqli_query($conn,$sql);
 
   
    if($conn->query($sql)){
        echo "<script> alert(\"게시글이 삭제 되었습니다.\");</script>";
        echo "<script> location.href = '../board/board_list.php'</script>";
    }else {
        echo "<script>alert(\"게시글 삭제 실패\");</script>";
        echo "<script>history.back();</script>";
     }

     mysqli_close($conn);

     echo"
     <script>
      location.href ='board_list.php?page=$page';
      </script>
 ";
?>