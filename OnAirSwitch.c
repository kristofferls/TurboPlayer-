//Setter RemoteTP PGM2 aka Namsos/Steinkjer OnAir på P1TR.
// Kristoffer L-S Sept 2020.

//Krever at TCPSender-applikasjon er installert i C:\Data\TCPSender. 
//Krever eventet OnAirBlink i /EventsTimed for at blinking skal fungere. Denne macroen må ligge i /EventsOut. Kan hete hva som helst. 
//Komentarer er skrevet kun for switch 1 vei, da den andre veien fungerer identisk, bare motsatt. 




//Sjekk at OnAirToggle-switch-variable finnes i TP minnet. Finnes den ikke, anta at man er OffAir, og sett modus til det:

if (! varexist ( $OnAirToggle ) ) { 
                                    $OnAirToggle = 0
                                    
                                    } 


//Dersom OnAirSwitch ikke er satt til 1, anta at man skal OnAir. 

if ($OnAirToggle == 0) {
                            TP_ShowError(*, Switching to OnAir!)  //Skriv til skjermen. 
                            TP_ChangeUserButtonProp ( *, * OnAirToggle *, ColorBkgnd, 255, 0, 0 ) //Skift bakgrunnsfarge til rød
                            TP_ChangeUserButtonProp ( *, * OnAirToogle *, ColorText, 0, 0, 0 )  

                            TP_ActivateTimer(OnAirBlink, 1) //Aktiver blinking av knappen, for å visuelt informere om at man er på lufta. 
							TP_ChangeUserButtonProp(*,* OnAirToggle *,Text,Snu av!!) //Skift tekst i knappen for å illustrere status. 

                            // Kjør kommando mot Mandozzi. Disse variablene er VELDIG skumle å endre på, og MÅ kvalitetssjekkes før bruk!!!!!

                            
                            TP_StartApp ( \{{ "C:\Data\TCPSender\TCPSender.exe" "160.67.28.205"	"8080" "CONNCHAN|00D780FFFFFF6E00FF0700" \}}, "", "NoWindow" ) // 6E00 = Mandozzi input RemoteTP PGM2 0700 = Mandozzi stasjon 8. Input-nummer er reversert, dvs de to siste numrene er de to første. 6E00 = 006E i routeren. 
                            
                            $OnAirToggle = 1 //Sett intern switch-variabel til 1, slik at TP vet at den ved neste klikk går inn i neste kodeblokk. 
                            
                            TP_ShowError(*, OnAir command sent to router!)
                            
                            return // skitten programmering, for å unngå at TP switcher OffAir med en gang etter den har satt seg selv on air.
                        }   


if ($OnAirToggle == 1) {
                            TP_ShowError(*, Is OnAir - switching to OffAir!)
                            TP_ActivateTimer(OnAirBlink, 0)

                            TP_ChangeUserButtonProp ( *, * OnAirToggle *, ColorBkgnd, 0, 255, 0 )
                            TP_ChangeUserButtonProp ( *, * OnAirToogle *, ColorText, 255, 255, 255 )

                            
							TP_ChangeUserButtonProp(*,* OnAirToggle *,Text,  !! Snu På )

                              // do some more Mandozzi magic

                             TP_StartApp ( \{{ "C:\Data\TCPSender\TCPSender.exe" "160.67.28.205"	"8080" "DISCCHAN|FF6E00FF0700" \}}, "", "NoWindow" ) // 6E00 = Mandozzi input RemoteTP PGM2 0700 = Mandozzi stasjon 8.

                            $OnAirToggle = 0
                            TP_ShowError(*, OffAir command sent to router.)
                            return

                        }                     