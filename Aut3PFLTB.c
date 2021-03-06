
//Denne macroen styrer GPO til DHD for Aut3 fra Mandozzi TS. 
//Den avhenger av at det allerede finnes to tomme EventOut: GPIO_AUT3_PFLTB_ON og GPIO_AUT3_PFLTB_OFF. Disse må refereres til i TPIO-innstillingene (Se Confluence)

if($Aut3PFLState == 0 && $Aut3OnAirState == 0 && $Aut4OnAirState == 0 && $WinOnAirState == 0) //Sjekker hva status er. Variabel settes til 0 ved oppstart. 
            {
                TP_ShowError(*, Aut3 PFL/TB going active!)
                $Aut3PFLState = 1;
                TP_ChangeUserButtonProp(*, * Aut3PFL *, ColorBkgnd, 255, 255, 0 )

                // Kall GPO-eventet. 
                
                GPIO_AUT3_PFLTB_ON()
                

            }   else if( $Aut3PFLState == 1)  {
                                                TP_ShowError(*, Aut3 PFL/TB is switching off!)
                                                $Aut3PFLState = 0;
                                                TP_ChangeUserButtonProp(*, * Aut3PFL *, ColorBkgnd, 192, 192, 192 )
                                                GPIO_AUT3_PFLTB_OFF()

                                            } 
                                                else 
                                                        {
                                                            TP_ShowError(*, One or more ext lines are OnAir! PFL forbidden in this mode.)
                                                                    
                                                        }
