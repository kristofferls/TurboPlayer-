//Mandozzi-styring av RemoteTP-linjer i Mandozzi mellom Namsos og Steinkjer. 

//Kristoffer L-S Sept 2020. 

//Krever at TCPSender-applikasjon er installert i C:\Data\TCPSender. 

//Komentarer er skrevet kun for switch 1 vei, da den andre veien fungerer identisk, bare motsatt. 

//Sjekk at Steinkjer_toggle-switch-variable finnes i TP minnet. Finnes den ikke, anta at man er i Namsos, og sett modus til det:

if (! varexist ( $Steinkjer_toggle ) ) { 
                                        $Steinkjer_toggle = 0
                                    
                                     } 



if ($Steinkjer_toggle == 0) { //Sett sending til Steinkjer.

                                TP_ShowError(*, Setter retur til Steinkjer.)  //Skriv til skjermen. 
                                TP_ChangeUserButtonProp ( *, * Steinkjer *, ColorBkgnd, 255, 170, 255 ) //Skift bakgrunnsfarge til rød
                                TP_ChangeUserButtonProp ( *, * Steinkjer *, ColorText, 0, 0, 0 )  

                                
                                TP_ChangeUserButtonProp( *, * Steinkjer *, Text, Bytt til Namsos (Nå: Steinkjer)) //Skift tekst i knappen for å illustrere status. 

                                // Kjør kommando mot Mandozzi. Disse variablene er VELDIG skumle å endre på, og MÅ kvalitetssjekkes før bruk!!!!!

                                
                                TP_StartApp ( \{{ "C:\Data\TCPSender\TCPSender.exe" "160.67.28.205"	"8080" "CONN|00D780FFFFFF8801FF9B00FFE901FF6E00FFE901FF6F00" \}}, "", "NoWindow" ) //Se confluence.
                                
                                TP_ShowError(*, Sending Mandozzi-routing commands)                                
                                $Steinkjer_toggle = 1 //Sett intern switch-variabel til 1, slik at TP vet at den ved neste klikk går inn i neste kodeblokk. 
                                
                                TP_ShowError(*, Mandozzi commands sent. Audio should now be present at Steinkjer.)
                                
                                return // skitten programmering, for å unngå at TP switcher OffAir med en gang etter den har satt seg selv on air.
                            }   


if ($Steinkjer_toggle == 1) { //Sett sending til Namsos

                                TP_ShowError(*, Setter retur til Namsos.)  //Skriv til skjermen. 
                                TP_ChangeUserButtonProp ( *, * Steinkjer *, ColorBkgnd, 0, 128, 255 ) //Skift bakgrunnsfarge til rød
                                TP_ChangeUserButtonProp ( *, * Steinkjer *, ColorText, 0, 0, 0 )  

                                
                                TP_ChangeUserButtonProp(*,* Steinkjer *,Text, Bytt til Steinkjer (Nå:Namsos)) //Skift tekst i knappen for å illustrere status. 

                                // Kjør kommando mot Mandozzi. Disse variablene er VELDIG skumle å endre på, og MÅ kvalitetssjekkes før bruk!!!!!

                                
                                TP_StartApp ( \{{ "C:\Data\TCPSender\TCPSender.exe" "160.67.28.205"	"8080" "DISC|00D780FFFFFFE901FF6E00FF6F00FF9B00" \}}, "", "NoWindow" ) //Se confluence.
                                
                                TP_ShowError(*, Sending Mandozzi-routing commands)                                
                                $Steinkjer_toggle = 0 //Sett intern switch-variabel til 1, slik at TP vet at den ved neste klikk går inn i neste kodeblokk. 
                                
                                TP_ShowError(*, Mandozzi commands sent. Audio should now be present at Namsos.)
                                
                                return // skitten programmering, for å unngå at TP switcher OffAir med en gang etter den har satt seg selv on air.
                        }                     