if ( ! varexist ( $OnAirToggleIsHIGH ) ) { $OnAirToggleIsHIGH = 0}


if ( $OnAirToggleIsHIGH )
                    {
                        TP_ChangeUserButtonProp ( *, * OnAirToggle *, ColorBkgnd, 255, 0, 0 )
                        TP_ChangeUserButtonProp ( *, * OnAirToggle *, ColorText, 0, 0, 0 )
                        $OnAirToggleIsHIGH = 0

                    }  else{

                                TP_ChangeUserButtonProp ( *,* OnAirToggle *, ColorBkgnd, 255, 255, 255 )
                                TP_ChangeUserButtonProp ( *,* OnAirToggle *, ColorText, 0, 0, 0 )
                                $OnAirToggleIsHIGH = 1

                            }