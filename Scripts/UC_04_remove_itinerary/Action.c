Action()
{
	int i = 0;
	int randInt = 0;
	
	lr_start_transaction("UC_04_remove_itinerary");

	
	lr_start_transaction("open_main_page");
	
		web_add_auto_header("Sec-Fetch-Dest", 
			"frame");
	
		web_add_auto_header("Sec-Fetch-Mode", 
			"navigate");
	
		web_add_auto_header("Sec-Fetch-Site", 
			"same-origin");
	
		web_add_auto_header("Upgrade-Insecure-Requests", 
			"1");
	
	/*Correlation comment - Do not change!  Original value='138253.002754151HVVVDiipicQVzzzHtczzipDDcQHf' Name ='userSession' Type ='ResponseBased'*/
		web_reg_save_param_regexp(
			"ParamName=userSession",
			"RegExp=userSession\\ value=(.*?)>",
			"Ordinal=3",
			SEARCH_FILTERS,
			"Scope=Body",
			"RequestUrl=*/nav.pl*",
			LAST);
	
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

	lr_start_transaction("login");

		web_revert_auto_header("Upgrade-Insecure-Requests");
	
		web_add_header("Origin", 
			"http://127.0.0.1:8090");
	
		web_add_auto_header("Sec-Fetch-User", 
			"?1");
	
		web_reg_find("Text=User password was correct", LAST);
		web_submit_data("login.pl",
			"Action=http://127.0.0.1:8090/WebTours/login.pl",
			"Method=POST",
			"TargetFrame=body",
			"RecContentType=text/html",
			"Referer=http://127.0.0.1:8090/WebTours/nav.pl?in=home",
			"Snapshot=t2.inf",
			"Mode=HTML",
			ITEMDATA,
			"Name=userSession", "Value={userSession}", ENDITEM,
			"Name=username", "Value={login}", ENDITEM,
			"Name=password", "Value={password}", ENDITEM,
			"Name=login.x", "Value=29", ENDITEM,
			"Name=login.y", "Value=11", ENDITEM,
			"Name=JSFormSubmit", "Value=off", ENDITEM,
			LAST);

	lr_end_transaction("login",LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("open_itinerary_page");

		web_revert_auto_header("Sec-Fetch-User");
	
		web_add_auto_header("Upgrade-Insecure-Requests", 
			"1");
	
		web_reg_find("Text=<title>Flights List</title>", LAST);
		
		web_reg_save_param_regexp("ParamName=flightIds", 
		                          "Regexp=\"hidden\" name=\"flightID\" value=\"(.*?)\"  />",
		                          "ordinal=all", 
		                          LAST);

		web_reg_save_param_regexp("ParamName=cgifields", 
		                          "Regexp=<input type=\"hidden\" name=\".cgifields\" value=\"(.*?)\"  />",
		                          "ordinal=all", 
		                          LAST);
					
		web_url("Itinerary Button", 
			"URL=http://127.0.0.1:8090/WebTours/welcome.pl?page=itinerary", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://127.0.0.1:8090/WebTours/nav.pl?page=menu&in=home", 
			"Snapshot=t3.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("open_itinerary_page",LR_AUTO);
	
	lr_think_time(10);

	lr_start_transaction("remove_itinerary");
		
		randInt = rand() % 3 % atoi(lr_eval_string("{flightIds_count}"))+ 1;
	
		lr_save_string("", "cBuffer");
		
		for (i=1; i<= randInt; i++) {
	 		lr_param_sprintf("cBuffer", "%s%d=on&", lr_eval_string("{cBuffer}"), i);
		}
		 
		for (i=1;i<= atoi(lr_eval_string("{flightIds_count}"));i++) {
			lr_param_sprintf("cBuffer", 
			                 "%sflightID=%s&", 
			                 lr_eval_string("{cBuffer}"),
			                 lr_paramarr_idx("flightIds", i));
			 lr_param_sprintf("cBuffer", 
			                 "%s.cgifields=%s&",
			                 lr_eval_string("{cBuffer}"),
			                 lr_paramarr_idx("cgifields", i));
		}
		 
		lr_save_string(lr_eval_string("{cBuffer}removeFlights.x=36&removeFlights.y=4"), "request");
		
		web_add_header("Origin", 
			"http://127.0.0.1:8090");
	
		web_add_auto_header("Sec-Fetch-User", 
			"?1");
		
		web_reg_find("Text=name=\"flightID\" value=\"{flightIds_1}\"", "Fail=Found", LAST);
		if (randInt == 2) {
			web_reg_find("Text=name=\"flightID\" value=\"{flightIds_2}\"", "Fail=Found", LAST);
		} 
		if (randInt == 3) {
			web_reg_find("Text=name=\"flightID\" value=\"{flightIds_3}\"", "Fail=Found", LAST);
		} 
		
	 	web_custom_request("itinerary.pl",
	      "URL=http://127.0.0.1:8090/WebTours/itinerary.pl",
	      "Method=POST",
	      "Resource=0",
	      "RecContentType=text/html",
	      "Referer=http://127.0.0.1:8090/WebTours/itinerary.pl",
	      "Snapshot=t4.inf",
	      "Mode=HTTP",
	      "Body={request}",
	      LAST);

 	
	lr_end_transaction("remove_itinerary",LR_AUTO);
	
	
	lr_end_transaction("UC_04_remove_itinerary", LR_AUTO);

	
	return 0;
}