<?php 

//Simpan dengan nama file proses.php
require "koneksidb.php";

  $data = query("SELECT * FROM tabel_kontrol_2")[0];

	 if(isset($_GET['channel']) AND isset($_GET['CH_1'])){
		  $channel = $_GET['channel'];
		  $CH_1   = $_GET['CH_1'];
				if ($channel == 'CH_1') {
				    $sql = "UPDATE tabel_kontrol_2 SET CH_1 = '$CH_1'";
				  }	
				
			  $koneksi->query($sql);
			  header('Location:index.php');
	 }
        
        $result  = json_encode($data);
        echo $result;
        
 ?>