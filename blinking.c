if ( ! varexist ( $Duck1IsHigh ) )
{
$Duck1IsHigh = 0
}
if (( $Duck1IsHigh ) && $DuckingChannel1 == None)) 
{
TP_ChangeUserButtonProp ( *, * Duck 1 *, ColorBkgnd, 255, 0, 0 )
TP_ChangeUserButtonProp ( *, * Duck 1 *, ColorText, 0, 0, 0 )
$Duck1IsHigh = 0
}
else
{
TP_ChangeUserButtonProp ( *,* Duck 1 *, ColorBkgnd, 255, 255, 255 )
TP_ChangeUserButtonProp ( *,* Duck 1 *, ColorText, 128, 0, 0 )
$Duck1IsHigh = 1
}