$(document).ready(function(){
		

		//real time halaman dashboard.php
				setInterval(function() {
            		$('.data').load('data.php');
          							}, 100);

	

  });