//Setter RemoteTP PGM2 aka Namsos/Steinkjer OnAir på P1TR.
// Kristoffer L-S Sept 2020.

//Krever at TCPSender-applikasjon er installert i C:\Data\TCPSender. 
//Krever eventet OnAirBlink i /EventsTimed for at blinking skal fungere. Denne macroen må ligge i /EventsOut. Kan hete hva som helst. 
//Komentarer er skrevet kun for switch 1 vei, da den andre veien fungerer identisk, bare motsatt. 




//Sjekk at OnAirToggle-switch og SafetySwitch variable finnes i TP minnet. Finnes den ikke, anta at man er OffAir, og sett modus til det:

if (! varexist ( $OnAirToggle ) ) { 
                                    $OnAirToggle = 0
                                    
                                    } 

if (! varexist ( $SafetySwitch ) ) { 
                                    $SafetySwitch = 0
                                    
                                    } 


//Sjekk om OnAirToggle allerede er trykket på, og sjekk om SafetySwitch (aka "Take" i GUI) er aktiv. Hvis ikke, skriv en feilmelding til skjerm.

if ($OnAirToggle == 0 && $SafetySwitch == 0)    {
                                                    TP_ShowError(*, SafetySwitch is not pressed! OnAirSwitch not allowed!!)
                                                    
                                                }
//Sjekk om OnAirToggle allerede er trykket, og at SafetySwitch er aktivert. Dersom man ikke allerede er OnAir, men SafetySwitch er skrudd på: Gå på lufta! 

if ($OnAirToggle == 0 && $SafetySwitch == 1) {
                                                TP_ShowError(*, Switching to OnAir!)  //Skriv til skjermen. 
                                                TP_ChangeUserButtonProp ( *, * OnAirToggle *, ColorBkgnd, 255, 0, 0 ) //Skift bakgrunnsfarge til rød
                                                TP_ChangeUserButtonProp ( *, * OnAirToogle *, ColorText, 0, 0, 0 )  

                                                TP_ActivateTimer(OnAirBlink, 1) //Aktiver blinking av knappen, for å visuelt informere om at man er på lufta. 
                                                TP_ChangeUserButtonProp(*,* OnAirToggle *,Text,Snu av!!) //Skift tekst i knappen for å illustrere status. 

                                                // Kjør kommando mot Mandozzi. Disse variablene er VELDIG skumle å endre på, og MÅ kvalitetssjekkes før bruk!!!!!

                                                
                                                TP_StartApp ( \{{ "C:\Data\TCPSender\TCPSender.exe" "IP_OF_FIREWALL"	"8080" "CONNCHAN|HEXStr" \}}, "", "NoWindow" ) // Se Confluence.
                                                
                                                $OnAirToggle = 1 //Sett intern switch-variabel til 1, slik at TP vet at den ved neste klikk går inn i neste kodeblokk. 
                                                
                                                TP_ShowError(*, OnAir command sent to router!)
                                                
                                                return // skitten programmering, for å unngå at TP switcher OffAir med en gang etter den har satt seg selv on air.
                                            }   

//Dersom OnAirToggle er aktivert, er man allerede på lufta. Derfor: Gå av lufta, og pass på å reset SafetySwitch tilbake til 0. 
if ($OnAirToggle == 1) {
                            TP_ShowError(*, Is OnAir - switching to OffAir!)
                            TP_ActivateTimer(OnAirBlink, 0)

                            TP_ChangeUserButtonProp ( *, * OnAirToggle *, ColorBkgnd, 0, 255, 0 )
                            TP_ChangeUserButtonProp ( *, * OnAirToogle *, ColorText, 255, 255, 255 )

                            
							TP_ChangeUserButtonProp(*,* OnAirToggle *,Text,  !! Snu På )

                              // do some more Mandozzi magic

                             TP_StartApp ( \{{ "C:\Data\TCPSender\TCPSender.exe" "IP_OF_FIREWALL"	"8080" "DISCCHAN|HEXStr" \}}, "", "NoWindow" ) //Se Confluence

                            $OnAirToggle = 0
                            $SafetySwitch = 0 //Re-arm SafetySwitch.
                            
                            TP_ChangeUserButtonProp(*, * SafetySwitch *, ColorBkgnd, 192,192,192)
                            TP_ShowError(*, OffAir command sent to router.)
                            return

                        }                     
