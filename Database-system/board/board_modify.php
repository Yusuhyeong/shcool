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
</head>
<?php
    $num = $_GET["num"];
    $page = $_GET["page"];

    $title = $_POST["title"];
    $contents = $_POST["contents"];
          
   
    $sql = "update board set title='$title', contents='$contents' ";
    $sql .= " where num=$num";
    mysqli_query($conn, $sql);

    mysqli_close($conn);     

    echo "
	      <script>
	          location.href = 'board_list.php?page=$page';
	      </script>
	  ";
?>
</html>