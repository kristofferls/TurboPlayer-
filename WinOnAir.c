// Denne macroen setter OnAir-status for Win aka RME 4+5 fra TP-maskinen. 

// Sett Win On Air! 
// Sjekk status på PFL på alle kanaler. Alle PFL-GPOs må gå lave for at returene fra DHD skal bli riktig! 
// Når kanalen går OffAir - slett alle PFL-states, slik at de ikke forhindrer programleder å høre PGM når en automatlinjer går av lufta. 


//Sett alle PFL-kanaler til OFF: 

    $Aut3PFLState = 0
    $Aut4PFLState = 0
    $WinPFLState = 0

// Sett alle PFL-GPOs til 0: 

    GPIO_AUT3_PFLTB_OFF()
    GPIO_AUT4_PFLTB_OFF()
    GPIO_WIN_PFLTB_OFF()

//Endre utseende på knappen Aut3PFL 


    TP_ChangeUserButtonProp(*,* Aut3PFL *,Text, PFL/TB Deaktivert!)
    TP_ChangeUserButtonProp(*,* Aut3PFL *, ColorBkgnd, 192, 192, 192) //Grå
    TP_ChangeUserButtonProp(*,* Aut3PFL *, ColorText, 0, 0, 0) //Sort


//Endre utseende på knappen Aut4PFL 

    TP_ChangeUserButtonProp(*,* Aut4PFL *,Text, PFL/TB Deaktivert!)
    TP_ChangeUserButtonProp(*,* Aut4PFL *, ColorBkgnd, 192, 192, 192) //Grå
    TP_ChangeUserButtonProp(*,* Aut4PFL *, ColorText, 0, 0, 0) //Sort


//Endre utseende på knappen WinPFL 

    TP_ChangeUserButtonProp(*,* WinPFL *,Text, PFL/TB Deaktivert!)
    TP_ChangeUserButtonProp(*,* WinPFL *, ColorBkgnd, 192, 192, 192) //Grå
    TP_ChangeUserButtonProp(*,* WinPFL *, ColorText, 0, 0, 0) //Sort


// Sett Aut 4 On Air 

if ($WinOnAirState == 0 && $WinPFLState == 0) 
                {
                    TP_ShowError(*,Win is ON AIR!)
                    GPIO_WIN_ONAIR_ON()
                    $WinOnAirState = 1

                    //Oppdater knappen

                    
                    //Endre utseende på knappen Win On 

                    TP_ChangeUserButtonProp(*,* WinON *,Text,  Win ON AIR!)
                    TP_ChangeUserButtonProp(*,* WinON *, ColorBkgnd, 255, 0, 0) //Rød
                    TP_ChangeUserButtonProp(*,* WinON *, ColorText, 255, 255, 255) //Hvit

                } else if ($WinOnAirState == 1)
                
                {
                    
                    TP_ShowError(*, Win is OFF AIR!)
                    GPIO_Win_ONAIR_OFF()
                    $WinOnAirState = 0
                    
                    //Endre utseende på knappen Win On tilbake til default. 

                    TP_ChangeUserButtonProp(*,* WinON *,Text,  Win ON)
                    TP_ChangeUserButtonProp(*,* WinON *, ColorBkgnd, 192, 192, 192) //Grå
                    TP_ChangeUserButtonProp(*,* WinON *, ColorText, 0, 0, 0) //Sort

                   // Sjekk om alle andre knapper er off air før tilbakestilling av PFL-knappetekst: 
                    
                    if ($Aut3OnAirState == 0 && $Aut4OnAirState == 0 && $WinOnAirState == 0) 
                                    
                                    {

                                         //Endre utseende på knappen Aut3PFL 
                                        TP_ChangeUserButtonProp(*,* Aut3PFL *,Text, Aut 3 PFL/TB)
                                        //Endre utseende på knappen Aut4PFL 
                                        TP_ChangeUserButtonProp(*,* Aut4PFL *,Text, Aut 4 PFL/TB)
                                        //Endre utseende på knappen WinPFL 
                                        TP_ChangeUserButtonProp(*,* WinPFL *,Text, Win PFL/TB)    

                                    }


                }

