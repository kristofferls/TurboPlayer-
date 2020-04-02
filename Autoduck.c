TP_ShowError(*, DataOfChannel(1,PlayState))
//$i=0
if ( DataOfChannel(1,PlayState)==Playing)

{
if($DuckingChannel1==Active)		//sjekker om kanalen allerede er ducked

							{
							TP_ShowError(*, Ducking is not active!) 
							TP_ActivateTimer (Blink1, 0)
							TP_Fade(Channel,1,1500,0)
							$DuckingChannel1=None
							TP_ChangeUserButtonProp(*,* Duck 1 *,Text,Demp HD1)
							//TP_ChangeUserButtonProp(*,* Duck 1 *, ColorBkgnd, 187, 0, 94)
							//TP_ChangeUserButtonProp (*,* Duck 1 *, ColorText, 255, 255, 255)
							
							}else{
									TP_ShowError(*, Fading down Channel 1)
									TP_ActivateTimer (Blink1, 1)
									TP_Fade(Channel,1,1500,-9)
									$DuckingChannel1=Active
									TP_ShowError(*, Channel 1 is now -9dB!) 
									TP_ChangeUserButtonProp(*,* Duck 1 *,Text,Fade Inn HD 1)
									//TP_ChangeUserButtonProp(*,* Duck 1 *, ColorBkgnd, 255, 132, 193)
									//TP_ChangeUserButtonProp (*,* Duck 1 *, ColorText, 0, 0, 0)
							
							}
}
if ( DataOfChannel(1,PlayState)==Free)
							
							{
							  TP_SetDataOfElement(Show,Next,Fade_Amplification,-9)
							  TP_Start(Line, 1)
							  $DuckingChannel1=Active
							  TP_ChangeUserButtonProp(*,* Duck 1 *,Text,Fade Inn HD1)
							  TP_ChangeUserButtonProp(*,* Duck 1 *, ColorBkgnd, 255, 132, 193)
							  TP_ChangeUserButtonProp (*,* Duck 1 *, ColorText, 0, 0, 0)
							}
