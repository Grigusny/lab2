echo off
cls
echo Podaj nazw© katalogu do utworzenia :
SET /P katalog=""
md %katalog%
cd %katalog%
echo Podaj ile plikow chcesz utworzy† w katalogu %katalog%:
SET /P ilo†=""
SET licznik=1
goto :petla
:petla
if %licznik% leq %ilo†% (
echo %date% %time% > plik%licznik%.txt 
goto :warunek)
if %licznik% gtr %licznik%(
goto :koniec)
:warunek
set /a licznik=%licznik%+1
goto :petla
:koniec
pause
