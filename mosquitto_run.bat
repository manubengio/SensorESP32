@echo off

rem Ir a la carpeta de Mosquitto
cd /d "C:\Program Files\mosquitto"

rem Ejecutar Mosquitto en un CMD separado
start cmd /k "mosquitto -c "C:\Program Files\mosquitto\mosquitto.conf" -v"

