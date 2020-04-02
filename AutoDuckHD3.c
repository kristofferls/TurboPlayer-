TP_ShowError(*, DataOfChannel(3,PlayState))

									
if ( DataOfChannel(3,PlayState) == Free)						//hvis spiller 3 ikke spiller, start neste element med demping
										{
											TP_ShowError(*, Player 3 is free! Ducking next element!)
											TP_Start(Line, 3)
											TP_Fade (Line, 3, 0000, -9)
											$DuckingChannel3=Active
											TP_ChangeUserButtonProp(*,* Duck 3 *,Text,Fade Inn HD3)
											TP_ChangeUserButtonProp(*,* Duck 3 *, ColorBkgnd, 255, 131, 193)
											TP_ChangeUserButtonProp (*,* Duck 3 *, ColorText, 0, 0, 0)
											TP_ActivateTimer(Duck3_Blink, 1)
											terminate
										}





if ( ( DataOfChannel(3,PlayState) == Playing) && ($DuckingChannel3 == Active) ) //hvis spiller 3 spiller og ducking allerede er satt, fade inn. 

																			{
																				TP_ShowError(*, Player 3 is ducked! Fading up!)
																				TP_Fade(Channel,3,1500,0)
																				$DuckingChannel3=None
																				TP_ActivateTimer(Duck3_Blink, 0)
																				TP_ChangeUserButtonProp(*,* Duck 3 *,Text,Demp HD3)
																				TP_ChangeUserButtonProp(*,* Duck 3 *, ColorBkgnd, 187, 0, 94)
																				TP_ChangeUserButtonProp (*,* Duck 3 *, ColorText, 255, 255, 255)
																				
																				terminate
																			}

																			
if ( ( DataOfChannel(3,PlayState) == Playing) && ($DuckingChannel3 == None) ) //hvis spiller 3 spiller og ducking ikke er aktiv, duck spilleren. 

																			
																			{
																				TP_ShowError(*, Player 3 is not ducked! Ducking!)
																				TP_Fade(Channel,3,1500,-9)
																				$DuckingChannel3=Active
																				TP_ChangeUserButtonProp(*,* Duck 3 *,Text,Fade Inn HD 3)
																				TP_ChangeUserButtonProp(*,* Duck 3 *, ColorBkgnd, 255, 131, 193)
																				TP_ChangeUserButtonProp (*,* Duck 3 *, ColorText, 0, 0, 0)
																				TP_ActivateTimer(Duck3_Blink, 1)
																				terminate
																			}