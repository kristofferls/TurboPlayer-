//Sikkerhetsvariabel for å unngå at man kan snu seg på lufta uten to trykk. 
//Opprett 

if (! varexist ( $SafetySwitch ) ) { 
                                    $SafetySwitch = 0

                                    } 

if ($SafetySwitch == 0) {
                            TP_ShowError(*, SafetySwitch pressed! OnAirSwitch unlocked)
                            TP_ChangeUserButtonProp(*, * SafetySwitch *, ColorBkgnd, 255,255,0)
                            $SafetySwitch = 1
                            return
                        
                        }
if ($SafetySwitch == 1) 
                        {

                            TP_ShowError(*, SafetySwitch pressed! OnAirSwitch locked)
                            TP_ChangeUserButtonProp(*, * SafetySwitch *, ColorBkgnd, 192,192,192)
                            $SafetySwitch = 0
                            return


                        }                        
