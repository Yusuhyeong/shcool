<!DOCTYPE html>
<html lang="ko">
   <body>
   <script type="text/javascript" src="https://maps.googleapis.com/maps/api/js?key=AIzaSyCDs9R2GpmN8bdGDx3xI6oqjks9yfnqHXc&sensor=false&language=ko" ></script>
      <script> 
         function initialize() { 

         var center = new google.maps.LatLng(36.628, 127.4541504); // 좌표값
         var mapOptions = { 
            zoom: 17, // 지도 확대레벨 조정
            center: center, 
            mapTypeId: google.maps.MapTypeId.ROADMAP 

            
         } 
         var map = new google.maps.Map(document.getElementById('map_canvas'), mapOptions); 
<?php
$res = mq("select m.map_num, m.lat, m.lng, s.title from sale s, map m where s.num = m.map_num");
while($row = mysqli_fetch_array($res)) {
   $lat = $row['lat'];
   $lng = $row['lng'];
   $title = $row['title'];
   $num = $row['map_num'];
?>
         var point<?=$num?> = new google.maps.LatLng(<?=$lat?>, <?=$lng?>); // 좌표값

         infowindow<?=$num?> = new google.maps.InfoWindow({                  //인포윈도우 선언
            position: point<?=$num?>,
              content: '<div style = "padding:15px;"><a href="./sale/sale_zone_board.php?num=<?=$num?>"><?=$title?></a></div>'      //인포윈도우 링크 걸기
            
            //removable : true
           });

         var marker<?=$num?> = new google.maps.Marker({ 
            position: point<?=$num?>, 
            map: map, 
            
            title: "<?=$title?>" // 마커에 마우스를 올렸을때 간략하게 표기될 설명글
         }); 

         marker<?=$num?>.addListener("click", () => {
               infowindow<?=$num?>.open(map,marker<?=$num?>);
            });

<?php }?>
      } 
      window.onload = initialize;
      </script>
   </body>
</html>