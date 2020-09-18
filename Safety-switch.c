//Sikkerhetsvariabel for å unngå at man kan snu seg på lufta uten to trykk. 
//v.1.1 : PREPCHAN kommando sendes til Mandozzi - ala slik det fungerer med tradisjonell velger. 
//v.1.1 : Dersom SafetySwitch trykkes mens man er på lufta, vil den ta studio av lufta. 
//Kristoffer L-S Sept 2020

if (! varexist ( $SafetySwitch ) ) { 
                                    $SafetySwitch = 0

                                    } 

//Sjekk om SafetySwitch er trykket. Hvis variabel ikke er satt, anta at man skal OnAir. Skift farge på knapper, og send en PREPCHAN til router
if ($SafetySwitch == 0) {
                            TP_ShowError(*, SafetySwitch pressed! OnAirSwitch unlocked)
                            TP_ChangeUserButtonProp(*, * SafetySwitch *, ColorBkgnd, 255,255,0)
                            TP_ChangeUserButtonProp(*, * OnAirToggle *, ColorBkgnd, 0,255,0)
                            
                            TP_StartApp ( \{{ "C:\Data\TCPSender\TCPSender.exe" "IP"	"PORT" "PREPCHAN|String" \}}, "", "NoWindow" ) // 6E00 = Mandozzi input RemoteTP PGM2 0700 = Mandozzi stasjon 8. Input-nummer er reversert, dvs de to siste numrene er de to første. 6E00 = 006E i routeren. 
                            TP_StartApp ( \{{ "C:\Data\TCPSender\TCPSender.exe" "IP"	"PORT" "PREPCHAN|String" \}}, "", "NoWindow" )
                            $SafetySwitch = 1
                            return
                        
                        }
if ($SafetySwitch == 1 && $OnAirToggle == 0) 
                                                {

                                                    TP_ShowError(*, SafetySwitch pressed! OnAirSwitch locked)
                                                    TP_ChangeUserButtonProp(*, * SafetySwitch *, ColorBkgnd, 192,192,192)
                                                    TP_StartApp ( \{{ "C:\Data\TCPSender\TCPSender.exe" "IP"	"PORT" "UNPRCHAN|String" \}}, "", "NoWindow" ) // 6E00 = Mandozzi input RemoteTP PGM2 0700 = Mandozzi stasjon 8.
                                                    TP_StartApp ( \{{ "C:\Data\TCPSender\TCPSender.exe" "IP"	"PORT" "UNPRCHAN|String" \}}, "", "NoWindow" )
                                                    TP_ChangeUserButtonProp(*, * SafetySwitch *, ColorBkgnd, 192,192,192)
                                                    TP_ChangeUserButtonProp ( *, * OnAirToggle *, ColorBkgnd, 192, 192, 192 )
                                                    $SafetySwitch = 0
                                                    return


                                                }

if($SafetySwitch == 1 && $OnAirToggle == 1)     {

                                                    TP_ShowError(*, SafetySwitch button pressed while OnAir! Switching to OffAir!)
                                                    TP_ChangeUserButtonProp(*, * SafetySwitch *, ColorBkgnd, 192,192,192)
                                                    TP_ChangeUserButtonProp ( *, * OnAirToggle *, ColorBkgnd, 192, 192, 192 )
                                                    TP_ChangeUserButtonProp ( *, * OnAirToogle *, ColorText, 255, 255, 255 )

                                                    TP_StartApp ( \{{ "C:\Data\TCPSender\TCPSender.exe" "IP"	"PORT" "DISCCHAN|String" \}}, "", "NoWindow" ) // 6E00 = Mandozzi input RemoteTP PGM2 0700 = Mandozzi stasjon 8.
                                                    TP_StartApp ( \{{ "C:\Data\TCPSender\TCPSender.exe" "IP"	"PORT" "DISCCHAN|String" \}}, "", "NoWindow" )

                                                    TP_ShowError(*, OffAir command sent to router.)
                                                    $OnAirToggle = 0
                                                    $SafetySwitch = 0 //Re-arm SafetySwitch.
                                                    TP_ActivateTimer(OnAirBlink, 0)
                                                    return

                                                }                                                                        
