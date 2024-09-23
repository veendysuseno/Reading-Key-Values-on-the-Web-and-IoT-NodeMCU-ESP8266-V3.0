<?php 	

//Simpan dengan nama file koneksidb.php

$server       = "localhost";
$user         = "root";
$password     = "";
$database     = "demo"; //Nama Database di phpMyAdmin

$koneksi      = mysqli_connect($server, $user, $password, $database);

function query($query) {
    global $koneksi;
    $result = mysqli_query($koneksi, $query );
    $box = [];
    while( $sql = mysqli_fetch_assoc($result) ){
    $box[] = $sql;
    }
    return $box;
}

  

 ?>