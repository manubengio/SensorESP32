@echo off

rem Ir a la carpeta de Mosquitto
cd /d "C:\Program Files\mosquitto"

rem Abrir otro CMD y suscribirse a "Distance"
start cmd /k "mosquitto_sub -h localhost -t Parking
"