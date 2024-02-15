Action()
{

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("welcome.pl", 
		"URL=http://127.0.0.1:8090/WebTours/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8090/WebTours/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_cookie("MSO=SID&1706774978&MSO_Comments&on&MSO_ServerErrorsProb&50&MSO_ServerLoadProb&50; DOMAIN=127.0.0.1");

	web_add_header("Origin", 
		"http://127.0.0.1:8090");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:8090/WebTours/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8090/WebTours/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=138256.377318753HVVVfzcptAiDDDDDtczzQpDHttf", ENDITEM, 
		"Name=username", "Value=007", ENDITEM, 
		"Name=password", "Value=&#1079;&#1092;&#1099;&#1099;&#1094;&#1097;&#1082;&#1074;", ENDITEM, 
		"Name=login.x", "Value=73", ENDITEM, 
		"Name=login.y", "Value=7", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	web_url("nav.pl", 
		"URL=http://127.0.0.1:8090/WebTours/nav.pl?username=007&password=%26%231079%3B%26%231092%3B%26%231099%3B%26%231099%3B%26%231094%3B%26%231097%3B%26%231082%3B%26%231074%3B", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8090/WebTours/login.pl", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://127.0.0.1:8090");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_submit_data("login.pl_2", 
		"Action=http://127.0.0.1:8090/WebTours/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8090/WebTours/nav.pl?username=007&password=%26%231079%3B%26%231092%3B%26%231099%3B%26%231099%3B%26%231094%3B%26%231097%3B%26%231082%3B%26%231074%3B", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=138256.377318753HVVVfzcptAiDDDDDtczzQpDHttf", ENDITEM, 
		"Name=username", "Value=007", ENDITEM, 
		"Name=password", "Value=password", ENDITEM, 
		"Name=login.x", "Value=42", ENDITEM, 
		"Name=login.y", "Value=5", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_start_transaction("open");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("Search Flights Button", 
		"URL=http://127.0.0.1:8090/WebTours/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8090/WebTours/nav.pl?page=menu&in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("open",LR_AUTO);

	lr_start_transaction("seacr");

	web_add_auto_header("Origin", 
		"http://127.0.0.1:8090");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

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
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=02/02/2024", ENDITEM, 
		"Name=arrive", "Value=Frankfurt", ENDITEM, 
		"Name=returnDate", "Value=02/03/2024", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=58", ENDITEM, 
		"Name=findFlights.y", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("seacr",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("1_transaction sel");

	web_submit_data("reservations.pl_2", 
		"Action=http://127.0.0.1:8090/WebTours/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8090/WebTours/reservations.pl", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=010;386;02/02/2024", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=reserveFlights.x", "Value=61", ENDITEM, 
		"Name=reserveFlights.y", "Value=4", ENDITEM, 
		LAST);

	lr_end_transaction("1_transaction sel",LR_AUTO);

	lr_start_transaction("by");

	web_submit_data("reservations.pl_3", 
		"Action=http://127.0.0.1:8090/WebTours/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:8090/WebTours/reservations.pl", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=James", ENDITEM, 
		"Name=lastName", "Value=Bond", ENDITEM, 
		"Name=address1", "Value=45 Wellington St, London, United Kingdom", ENDITEM, 
		"Name=address2", "Value=WC2E7BN", ENDITEM, 
		"Name=pass1", "Value=James Bond", ENDITEM, 
		"Name=creditCard", "Value=1", ENDITEM, 
		"Name=expDate", "Value=1", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=outboundFlight", "Value=010;386;02/02/2024", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=buyFlights.x", "Value=45", ENDITEM, 
		"Name=buyFlights.y", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);

	lr_end_transaction("by",LR_AUTO);

	return 0;
}