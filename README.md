Para usar el ESP32-S3 WROOM-1 (por ejemplo, con chip ESP32-S3-MON16R8 que tiene 16 MB Flash y 8 MB PSRAM)\
en el Arduino IDE, sigue estos pasos para configurarlo correctamente y evitar errores de memoria como el que viste.\
✅ Configuración recomendada para el ESP32-S3 WROOM-1 (MON16R8) en Arduino IDE\
1.-Placa\
ESP32S3 Dev Module\
USB CDC On Boot\
Enabled (para usar puerto USB nativo)\
PSRAM\
✅ Enabled → esto es muy importante ya que tienes 8 MB de PSRAM y debes activarla\
Flash Size\
16MB (128Mb)\
Flash Mode\
QIO o DIO (por lo general QIO funciona bien)\
Flash Frequency\
80MHz o 40MHz (usa 80 MHz si tu módulo lo soporta sin errores)\
Partition Scheme\
Default 4MB with spiffs (1.2MB APP/1.5MB SPIFFS)\
O usa Huge APP si necesitas más espacio para código: 16MB (3MB APP/9MB FATFS)\
Upload Speed\
921600 (si falla, baja a 460800 o 115200)\
Port\
Selecciona el puerto USB correspondiente (el chip tiene USB nativo, así que aparece como “ESP32S3 USB JTAG” o similar)\

const unsigned char gImage_white[624] = { /* 0X80,0X01,0X68,0X00,0X30,0X00, */   Surt amb Vermell, inversa el blanc es vermell  /*
<img width="918" height="562" alt="image" src="https://github.com/user-attachments/assets/7988d1bf-ce37-47d4-a488-7eb16a93d3e5" />

const unsigned char gImage_RW1[48000]={/*red and white picture*/   Ssurt amb Negre es la inversa el negre sera blanc/*
<img width="919" height="557" alt="image" src="https://github.com/user-attachments/assets/28c4c1ab-f97a-4fe3-80ad-827fe85dcaae" />


Funcions llibreria  graficas: \
 ```EPD_Init()```             Inicialitza la pantalla, posar abans de fer quelcom al la pantalla. I sempre despres de EPD_DeepSleep().\
 ```EPD_DeepSleep()```        entra en modo durmir , utilizar per duri mes la pantalla, diu el fabrican. Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen. \
```EPD_WhiteScreen_White```  Borra la pantalla a blanc\
  aaaaa\
