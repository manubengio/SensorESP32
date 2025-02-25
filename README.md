<h1>Catedra de Electrónica II - UTN FRRO </h1>
<h1>TP FINAL ESP32 - Sensor de estacionamiento trasero</h1>

# Sensor de Estacionamiento con ESP32

Este proyecto consiste en un sensor de estacionamiento basado en ESP32, utilizando un sensor de ultrasonido SR04 y una pantalla OLED para mostrar la distancia medida. Además, el ESP32 está conectado a Internet para enviar los datos a una computadora.

## Características
- Sensor de ultrasonido SR04 para medir distancias.
- Pantalla OLED para visualizar la distancia en tiempo real.
- Conectividad a Internet mediante WiFi para enviar datos.
- Desarrollo con PlatformIO.

## Requisitos
### Hardware
- ESP32
- Sensor de ultrasonido HC-SR04
- Pantalla OLED (SSD1306)
- Cables de conexión
- Fuente de alimentación adecuada

### Software
- [PlatformIO](https://platformio.org/) instalado en VS Code
- Dependencias necesarias (ver `platformio.ini`)

## Instalación y Configuración
1. Clonar el repositorio:
   ```sh
   git clone https://github.com/manubengio/SensorESP32.git
   cd SensorESP32
   ```
2. Abrir el proyecto con VS Code y PlatformIO.
3. Instalar las dependencias ejecutando:
   ```sh
   pio run --target init
   ```

## Compilación y Carga en la Placa
1. Conectar el ESP32 a la computadora mediante USB.
2. Seleccionar el puerto serie adecuado en PlatformIO.
3. Compilar y cargar el firmware ejecutando:
   ```sh
   pio run --target upload
   ```
4. Para ver la salida en serie:
   ```sh
   pio device monitor
   ```

## Diagrama de conexión 
![Diagrama de conexión](figures/Diagrama_Conexion.jpg)

## Uso
- Una vez cargado el firmware, la pantalla OLED mostrará la distancia medida por el sensor HC-SR04.

## Contribuciones
Si deseas contribuir, por favor abre un issue o envía un pull request.

## Licencia
Este proyecto está bajo la licencia MIT. Ver el archivo `LICENSE` para más detalles.

