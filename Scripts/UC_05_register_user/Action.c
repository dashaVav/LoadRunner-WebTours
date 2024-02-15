Action()
{
	char login[10];
	int i = 0;
	
	lr_start_transaction("UC_05_register_user");

	
	lr_start_transaction("open_main_page");
	
		web_add_auto_header("Sec-Fetch-Dest", 
			"frame");
	
		web_add_auto_header("Sec-Fetch-Mode", 
			"navigate");
	
		web_add_auto_header("Sec-Fetch-Site", 
			"same-origin");
	
		web_add_auto_header("Upgrade-Insecure-Requests", 
			"1");
	
		web_reg_save_param("SID",
			"LB=MSO=SID&",
			"RB=&MSO",
			LAST);
	
		web_reg_find("Text=<title>Web Tours Navigation Bar</title>", LAST);
		web_url("welcome.pl", 
			"URL=http://127.0.0.1:8090/WebTours/welcome.pl?signOff=true", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://127.0.0.1:8090/WebTours/", 
			"Snapshot=t1.inf", 
			"Mode=HTML", 
			LAST);
	
		web_add_cookie("MSO=SID&{SID}&MSO_Comments&on&MSO_ServerErrorsProb&50&MSO_ServerLoadProb&50; DOMAIN=127.0.0.1");
	
		web_set_sockets_option("SSL_VERSION", "AUTO");
		
	lr_end_transaction("open_main_page", LR_AUTO);

	lr_think_time(2);
	
	lr_start_transaction("open_sign_up_page");
	
		web_add_auto_header("Sec-Fetch-User", 
			"?1");
	
		web_url("login.pl", 
			"URL=http://127.0.0.1:8090/WebTours/login.pl?username=&password=&getInfo=true", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://127.0.0.1:8090/WebTours/home.html", 
			"Snapshot=t2.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("open_sign_up_page",LR_AUTO);
	
	lr_think_time(20);

	lr_start_transaction("complete_form_and_register");

		web_add_header("Origin", 
			"http://127.0.0.1:8090");
	
		
		for (i = 0; i < 9; i++) {
    		login[i] = 'a' + rand() % 26;
		}
		login[9] = '\0';
		
		lr_save_string(login, "login");

		web_reg_find("Text=Thank you, <b>{login}</b>, for registering and welcome to the Web Tours", LAST);
		web_submit_data("login.pl_2", 
			"Action=http://127.0.0.1:8090/WebTours/login.pl", 
			"Method=POST", 
			"TargetFrame=info", 
			"RecContentType=text/html", 
			"Referer=http://127.0.0.1:8090/WebTours/login.pl?username=&password=&getInfo=true", 
			"Snapshot=t3.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=username", "Value={login}", ENDITEM, 
			"Name=password", "Value={password}", ENDITEM, 
			"Name=passwordConfirm", "Value={password}", ENDITEM, 
			"Name=firstName", "Value={firstName}", ENDITEM, 
			"Name=lastName", "Value={lastName}", ENDITEM, 
			"Name=address1", "Value={address1}", ENDITEM, 
			"Name=address2", "Value={address2}", ENDITEM, 
			"Name=register.x", "Value=68", ENDITEM, 
			"Name=register.y", "Value=9", ENDITEM, 
			LAST);

	lr_end_transaction("complete_form_and_register",LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("open_menu");

		web_revert_auto_header("Sec-Fetch-User");
	
		web_revert_auto_header("Upgrade-Insecure-Requests");
	
		web_add_header("Sec-Fetch-User", 
			"?1");
	
		web_reg_find("Text=User has returned to the home page.", LAST);
		web_url("button_next.gif", 
			"URL=http://127.0.0.1:8090/WebTours/welcome.pl?page=menus", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://127.0.0.1:8090/WebTours/login.pl", 
			"Snapshot=t4.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("open_menu",LR_AUTO);
	
	lr_end_transaction("UC_05_register_user", LR_AUTO);

	return 0;
}