Action()
{
	lr_start_transaction("UC_02_buy_ticket");

	
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
	
	lr_think_time(1);
	
	lr_start_transaction("open_search_page");

		web_revert_auto_header("Sec-Fetch-User");
	
		web_add_auto_header("Upgrade-Insecure-Requests", 
			"1");
	
		web_reg_save_param_ex("ParamName=cities", "LB=\<option value\=\"", "RB=\">", "Ordinal=ALL", LAST);
		
		web_reg_find("Text=<title>Flight Selections</title>", LAST);
		web_url("Search Flights Button", 
			"URL=http://127.0.0.1:8090/WebTours/welcome.pl?page=search", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://127.0.0.1:8090/WebTours/nav.pl?page=menu&in=home", 
			"Snapshot=t5.inf", 
			"Mode=HTML", 
			LAST);
		
		lr_save_string(lr_paramarr_random("cities"),"depart");
		lr_save_string(lr_paramarr_random("cities"),"arrive");
		while (strcmp(lr_eval_string("{depart}"), lr_eval_string("{arrive}")) == 0) {
			lr_save_string(lr_paramarr_random("cities"),"arrive");
		}

	lr_end_transaction("open_search_page",LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("search_tickets");

		web_add_auto_header("Origin", 
			"http://127.0.0.1:8090");
	
		web_add_auto_header("Sec-Fetch-User", 
			"?1");
	
		web_reg_save_param_regexp("ParamName=outboundFlightList",
	                          "Regexp=outboundFlight value\=(\\d+;\\d+;\\d{2}/\\d{2}/\\d{4})",
	                          "Ordinal=all",
	                          LAST);
		
		web_reg_find("Text=<title>Flight Selections</title>", LAST);
		web_reg_find("Text=Flight departing from <B>{depart}</B> to <B>{arrive}</B> on <B>{departDate}</B>", LAST);
		
		web_submit_data("reservations.pl", 
				"Action=http://127.0.0.1:8090/WebTours/reservations.pl", 
				"Method=POST",
				"TargetFrame=", 
				"RecContentType=text/html", 
				"Referer=http://127.0.0.1:8090/WebTours/reservations.pl?page=welcome", 
				"Snapshot=t6.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=advanceDiscount", "Value=0", ENDITEM, 
				"Name=depart", "Value={depart}", ENDITEM, 
				"Name=departDate", "Value={departDate}", ENDITEM, 
				"Name=arrive", "Value={arrive}", ENDITEM, 
				"Name=returnDate", "Value={returnDate}", ENDITEM, 
				"Name=numPassengers", "Value=1", ENDITEM, 
				"Name=seatPref", "Value={seatPref}", ENDITEM, 
				"Name=seatType", "Value={seatType}", ENDITEM, 
				"Name=findFlights.x", "Value=58", ENDITEM, 
				"Name=findFlights.y", "Value=7", ENDITEM, 
				"Name=.cgifields", "Value=roundtrip", ENDITEM, 
				"Name=.cgifields", "Value=seatType", ENDITEM, 
				"Name=.cgifields", "Value=seatPref", ENDITEM, 
				LAST);
		
		lr_save_string(lr_paramarr_random("outboundFlightList"),"outboundFlight");
		
	lr_end_transaction("search_tickets",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("select_ticket");
	
		web_reg_find("Text=<title>Flight Reservation</title>", LAST);
		
		web_submit_data("reservations.pl_2",
			"Action=http://127.0.0.1:8090/WebTours/reservations.pl",
			"Method=POST",
			"TargetFrame=",
			"RecContentType=text/html",
			"Referer=http://127.0.0.1:8090/WebTours/reservations.pl",
			"Snapshot=t7.inf",
			"Mode=HTML",
			ITEMDATA,
			"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
			"Name=numPassengers", "Value=1", ENDITEM,
			"Name=advanceDiscount", "Value=0", ENDITEM,
			"Name=seatType", "Value={seatType}", ENDITEM,
			"Name=seatPref", "Value={seatPref}", ENDITEM,
			"Name=reserveFlights.x", "Value=61", ENDITEM,
			"Name=reserveFlights.y", "Value=4", ENDITEM,
			LAST);

	lr_end_transaction("select_ticket",LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("buy_ticket");
	
		web_reg_find("Text=Reservation Made!", LAST);
		web_reg_find("Text=A {seatType} Class ticket\n from {depart} to {arrive}.", LAST);
		
		web_submit_data("reservations.pl_3",
			"Action=http://127.0.0.1:8090/WebTours/reservations.pl",
			"Method=POST",
			"TargetFrame=",
			"RecContentType=text/html",
			"Referer=http://127.0.0.1:8090/WebTours/reservations.pl",
			"Snapshot=t8.inf",
			"Mode=HTML",
			ITEMDATA,
			"Name=firstName", "Value={firstName}", ENDITEM,
			"Name=lastName", "Value={lastName}", ENDITEM,
			"Name=address1", "Value={address1}", ENDITEM,
			"Name=address2", "Value={address2}", ENDITEM,
			"Name=pass1", "Value={firstName} {lastName}", ENDITEM,
			"Name=creditCard", "Value={creditCard}", ENDITEM,
			"Name=expDate", "Value={expDate}", ENDITEM,
			"Name=oldCCOption", "Value=", ENDITEM,
			"Name=numPassengers", "Value=1", ENDITEM,
			"Name=seatType", "Value={seatType}", ENDITEM,
			"Name=seatPref", "Value={seatPref}", ENDITEM,
			"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
			"Name=advanceDiscount", "Value=0", ENDITEM,
			"Name=returnFlight", "Value=", ENDITEM,
			"Name=JSFormSubmit", "Value=off", ENDITEM,
			"Name=buyFlights.x", "Value=45", ENDITEM,
			"Name=buyFlights.y", "Value=9", ENDITEM,
			"Name=.cgifields", "Value=saveCC", ENDITEM,
			LAST);

	lr_end_transaction("buy_ticket",LR_AUTO);
	
	lr_think_time(5);
	
	lr_start_transaction("open_itinerary_page");

		web_revert_auto_header("Sec-Fetch-User");
	
		web_add_auto_header("Upgrade-Insecure-Requests", 
			"1");
	
		web_reg_find("Text=<title>Flights List</title>", LAST);
		
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

	lr_think_time(5);
	
	lr_start_transaction("logout");

		web_revert_auto_header("Sec-Fetch-User");
	
		web_add_header("Upgrade-Insecure-Requests", 
			"1");
	
		web_reg_find("Text=<title>Web Tours</title>", LAST);
		web_reg_find("Text=A Session ID has been created and loaded into a cookie called MSO", LAST);
		web_url("SignOff Button", 
			"URL=http://127.0.0.1:8090/WebTours/welcome.pl?signOff=1", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://127.0.0.1:8090/WebTours/nav.pl?page=menu&in=home", 
			"Snapshot=t3.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("logout",LR_AUTO);
	
	
	lr_end_transaction("UC_02_buy_ticket", LR_AUTO);

	return 0;
}