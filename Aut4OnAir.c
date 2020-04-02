// Denne macroen setter OnAir-status for Aut4 fra Mandozzi. 

// Sett Aut4 On Air! 
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

if ($Aut4OnAirState == 0 && $Aut4PFLState == 0) 
                {
                    TP_ShowError(*,Aut 4 is ON AIR!)
                    GPIO_AUT4_ONAIR_ON()
                    $Aut4OnAirState = 1

                    //Oppdater knappen

                    
                    //Endre utseende på knappen Aut3 On 

                    TP_ChangeUserButtonProp(*,* Aut4ON *,Text,  Aut 4 ON AIR!)
                    TP_ChangeUserButtonProp(*,* Aut4ON *, ColorBkgnd, 255, 0, 0) //Rød
                    TP_ChangeUserButtonProp(*,* Aut4ON *, ColorText, 255, 255, 255) //Hvit

                } else if ($Aut4OnAirState == 1)
                
                {
                    
                    TP_ShowError(*, Aut 4 is OFF AIR!)
                    GPIO_AUT4_ONAIR_OFF()
                    $Aut4OnAirState = 0
                    
                    //Endre utseende på knappen Aut3 On tilbake til default. 

                    TP_ChangeUserButtonProp(*,* Aut4ON *,Text,  Aut 4 ON)
                    TP_ChangeUserButtonProp(*,* Aut4ON *, ColorBkgnd, 192, 192, 192) //Grå
                    TP_ChangeUserButtonProp(*,* Aut4ON *, ColorText, 0, 0, 0) //Sort


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

