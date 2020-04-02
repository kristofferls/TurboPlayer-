//Denne macroen deklarerer variabler brukt til styring av relekort for GPO mot DHD.

TP_ShowError(*, Creating GPIO state vars!)

//PFL-state variabler: 
$Aut3PFLState = 0
$Aut4PFLState = 0
$WinPFLState = 0
//OnAir-state variabler
$Aut3OnAirState = 0
$Aut4OnAirState = 0
$WinOnAirState = 0

TP_ShowError(*, Done!)
//Sett relekort til 0
TP_ShowError(*, Setting all GPOs to off)

GPIO_AUT3_ONAIR_OFF()
GPIO_AUT4_ONAIR_OFF()
GPIO_WIN_ONAIR_OFF()
GPIO_AUT3_PFLTB_OFF()
GPIO_AUT4_PFLTB_OFF()
GPIO_WIN_PFLTB_OFF()

TP_ShowError(*, Done! Continuing..)