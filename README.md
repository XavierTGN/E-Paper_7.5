Para usar el ESP32-S3 WROOM-1 (por ejemplo, con chip ESP32-S3-MON16R8 que tiene 16 MB Flash y 8 MB PSRAM)
en el Arduino IDE, sigue estos pasos para configurarlo correctamente y evitar errores de memoria como el que viste.

✅ Configuración recomendada para el ESP32-S3 WROOM-1 (MON16R8) en Arduino IDE
1.-Placa
ESP32S3 Dev Module
USB CDC On Boot
Enabled (para usar puerto USB nativo)
PSRAM
✅ Enabled → esto es muy importante ya que tienes 8 MB de PSRAM y debes activarla
Flash Size
16MB (128Mb)
Flash Mode
QIO o DIO (por lo general QIO funciona bien)
Flash Frequency
80MHz o 40MHz (usa 80 MHz si tu módulo lo soporta sin errores)
Partition Scheme
Default 4MB with spiffs (1.2MB APP/1.5MB SPIFFS)
O usa Huge APP si necesitas más espacio para código: 16MB (3MB APP/9MB FATFS)
Upload Speed
921600 (si falla, baja a 460800 o 115200)
Port
Selecciona el puerto USB correspondiente (el chip tiene USB nativo, así que aparece como “ESP32S3 USB JTAG” o similar)
