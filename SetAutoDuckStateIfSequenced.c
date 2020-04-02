//Dersom neste element i kjøreplanen starter i sequenced, vil ikke "Start HDx Dempet" endre seg, da den ikke er trykket på av brukeren. Denne funksjonen setter riktig mode hvis knappen ikke blir trykket inn. 

//TP Kernel skriver ut variablen TheCause som "Timer" dersom neste element er startet av Stinger eller en annen fixed start. Variabelen %TheChannel indikerer hvilken kanal Timer ble aktivert for, gitt at Event = ElementStarting


if ( ( %TheCause == Timer ) && ( %TheChannel == 1 ) )	{
	
															TP_ShowError(*, Player 1 started by timed event - setting button properties accordingly)
															$DuckingChannel1=None //Setter global variabel slik at ducking-knappene vet at spilleren spiller, selv om den ikke var startet av StartNeste eller AutoDuckHDx
															TP_ChangeUserButtonProp(*,* Duck 1 *,Text,Demp HD1)
															TP_ChangeUserButtonProp(*,* Duck 1 *, ColorBkgnd, 187, 0, 94)
															TP_ChangeUserButtonProp (*,* Duck 1 *, ColorText, 255, 255, 255)
														}

if ( ( %TheCause == Timer ) && ( %TheChannel == 2 ) )	{
	
															TP_ShowError(*, Player 2 started by timed event - setting button properties accordingly)
															$DuckingChannel2=None //Setter global variabel slik at ducking-knappene vet at spilleren spiller, selv om den ikke var startet av StartNeste eller AutoDuckHDx
															TP_ChangeUserButtonProp(*,* Duck 2 *,Text,Demp HD2)
															TP_ChangeUserButtonProp(*,* Duck 2 *, ColorBkgnd, 187, 0, 94)
															TP_ChangeUserButtonProp (*,* Duck 2 *, ColorText, 255, 255, 255)
									
														}
																										
if ( ( %TheCause == Timer ) && ( %TheChannel == 3 ) )	{
	
															TP_ShowError(*, Player 3 started by timed event - setting button properties accordingly)
															$DuckingChannel3=None //Setter global variabel slik at ducking-knappene vet at spilleren spiller, selv om den ikke var startet av StartNeste eller AutoDuckHDx
															TP_ChangeUserButtonProp(*,* Duck 3 *,Text,Demp HD3)
															TP_ChangeUserButtonProp(*,* Duck 3 *, ColorBkgnd, 187, 0, 94)
															TP_ChangeUserButtonProp (*,* Duck 3 *, ColorText, 255, 255, 255)
									
														}		


//KLS 2019																										