<?php

	if( extension_loaded('steamclient') ) {
		print_r("Steamclient found!\n");
		
		print_r(steamclient_hello_world());
		print_r("\n");
		
		if( steamclient_init() ) {
			echo "Steam Init!\n";
			
			if( steamclient_is_login() ) {
				echo "Steam User is Login!\n";
			}
			else {
				echo "Steam is Logout!\n";
			}
			
			if( steamclient_shutdown() ) {
				echo "Steam Shutdown!\n";
			}
			else {
				echo "Steam Shutdown faild!\n";
			}
		}
		else {
			echo "Steam faild!\n";
		}
	}
	else {
		print_r("Steamclient not found!\n");
	}