<?php
unset($_SESSION["userid"]);
unset($_SESSION["username"]);

echo("
<script>
  location.href='index.php';
  </script>
  ");
  ?>