<!DOCTYPE html>
<html lang="ko">
	<head>
	<?php
		include '../db.php';
	?>
	</head>
	
	<body>
	<?php
		$sql = mysqli_query($conn, "SELECT * FROM sale");
		$row = $sql->fetch_array();
		
		while($row) {
			<script>
				var marker_pos = 
			</script>
		}
	?>
	</body>
</html>