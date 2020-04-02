TP_ShowError(*, DataOfChannel(1,PlayState)) 										//oppdaterer error-skjermen i GUI om status ifm. feil. 

If ( DataOfElement ( Show, Next, Class ) $= "Live" ) 	{							//sjekker hvilken type/class neste element er. Dersom det er "Live" start bøtteballeten. 

															TP_Start (Show, Next)	// Starter live-element-spiller dersom neste element er av klassen "Live"
														}	Else{ 					//dersom elementet ikke er live, start en ledig spiller. 
														
														
																	If (DataOfChannel(1,PlayState) ==Free)		{	//sjekker om channel 1 er ledig 
																												TP_Start(Line,1)
																												TP_ShowError(*, Player 1 is free! Juhu) 
																												$DuckingChannel1=None //Deklarerer / setter variabelen brukt av duck/fade-knappene ved TP boot. 
																												TP_ChangeUserButtonProp (*,* Duck 1 *,Text,Demp HD1)
																												TP_ChangeUserButtonProp (*,* Duck 1 *, ColorBkgnd, 187, 0, 94)
																												TP_ChangeUserButtonProp (*,* Duck 1 *, ColorText, 255, 255, 255)
																												
																												} else {
																	
																	If ( (DataOfChannel (1, PlayState) ==Playing) && (DataOfChannel (2, PlayState) ==Free)) {	//hvis channel 1 er opptatt - bruk channel 2
																												TP_ShowError(*, Player 1 is not free, but 2 is!) 
																												TP_Start(Line,2)
																												$DuckingChannel2=None //Deklarerer / setter variabelen brukt av duck/fade-knappene ved TP boot.
																												TP_ChangeUserButtonProp (*,* Duck 2 *,Text,Demp HD2)
																												TP_ChangeUserButtonProp (*,* Duck 2 *, ColorBkgnd, 187, 0, 94)
																												TP_ChangeUserButtonProp (*,* Duck 2 *, ColorText, 255, 255, 255)
																												terminate
																												}
																	
																	If ( (DataOfChannel (1, PlayState) ==Playing) && (DataOfChannel (2, PlayState) ==Playing) ) //hvis channel 1 og 2 er opptatt - bruk channel 3!                
																												{
																												TP_ShowError(*, Player 1 or 2 is not free, but 3 is!) 
																												TP_Start(Line,3)
																												$DuckingChannel3=None //Deklarerer / setter variabelen brukt av duck/fade-knappene ved TP boot.
																												TP_ChangeUserButtonProp (*,* Duck 3 *,Text,Demp HD3)
																												TP_ChangeUserButtonProp (*,* Duck 3 *, ColorBkgnd, 187, 0, 94)
																												TP_ChangeUserButtonProp (*,* Duck 3 *, ColorText, 255, 255, 255)
																												terminate
																												}
															
															
																} //end of check 
																
																
																
																
																
																
																
																
TP_ShowError(*, DataOfChannel(1,PlayState)) 										//oppdaterer error-skjermen i GUI om status ifm. feil. 

if ( DataOfElement ( Show, Next, Class ) $= "Live" ) 	{	

															TP_Start (Show, Next) 
														
														}else { if	(DataOfChannel(1,PlayState) ==Free)		//sjekker om channel 1 er ledig 
														
														
																	
																												{	
																												TP_Start(Line,1)
																												TP_ShowError(*, Player 1 is free! Juhu) 
																												$DuckingChannel1=None //Deklarerer / setter variabelen brukt av duck/fade-knappene ved TP boot. 
																												TP_ChangeUserButtonProp (*,* Duck 1 *,Text,Demp HD1)
																												TP_ChangeUserButtonProp (*,* Duck 1 *, ColorBkgnd, 187, 0, 94)
																												TP_ChangeUserButtonProp (*,* Duck 1 *, ColorText, 255, 255, 255)
																												}
																
																else if ( (DataOfChannel (1, PlayState) ==Playing) && (DataOfChannel (2, PlayState) ==Free)) 
																												
																												{	
																												TP_ShowError(*, Player 1 is not free, but 2 is!) 
																												TP_Start(Line,2)
																												$DuckingChannel2=None //Deklarerer / setter variabelen brukt av duck/fade-knappene ved TP boot.
																												TP_ChangeUserButtonProp (*,* Duck 2 *,Text,Demp HD2)
																												TP_ChangeUserButtonProp (*,* Duck 2 *, ColorBkgnd, 187, 0, 94)
																												TP_ChangeUserButtonProp (*,* Duck 2 *, ColorText, 255, 255, 255)
																												
																												}
																else if ( (DataOfChannel (1, PlayState) ==Playing) && (DataOfChannel (2, PlayState) ==Playing) ) //hvis channel 1 og 2 er opptatt - bruk channel 3!                
																												{
																												TP_ShowError(*, Player 1 or 2 is not free, but 3 is!) 
																												TP_Start(Line,3)
																												$DuckingChannel3=None //Deklarerer / setter variabelen brukt av duck/fade-knappene ved TP boot.
																												TP_ChangeUserButtonProp (*,* Duck 3 *,Text,Demp HD3)
																												TP_ChangeUserButtonProp (*,* Duck 3 *, ColorBkgnd, 187, 0, 94)
																												TP_ChangeUserButtonProp (*,* Duck 3 *, ColorText, 255, 255, 255)
																												
																												}
																}
															
																} //end of check 