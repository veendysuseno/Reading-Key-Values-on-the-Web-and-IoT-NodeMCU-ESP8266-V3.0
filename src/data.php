<?php 
    
    require "koneksidb.php";

    $data = query("SELECT * FROM tabel_kontrol_2")[0];

 ?>


<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>

	   <div class="row mt-5">	
   <div class="col">
		<div class="card" style="max-width:18rem;">
		  <h5 class="card-header bg-dark text-white">Channel 1</h5>
		  <div class="card-body">
		    <h5 class="card-title">STATUS :</h5>
		       <?php if($data["CH_1"] == "0") { ?>
		       	    <h1 class="text-danger">OFF</h1>
		       <?php }
		         else { ?>
		       	     <h1 class="text-primary">ON</h1>
		       <?php } ?>
		  </div>
		</div>
	</div>
</div>		

</body>
</html>