//=======================================================================
// File:                oled.cpp
// Author:              Marcelo Castello (https://github.com/mcastellogh)
// Editor:              Manuel Bengio    (https://github.com/manubengio)
// Version:             1.0.1
// Date:                Mayo 2024 (Original) Febrero 2025 (Edition)
// Info:                Proyect template for Electrónica II
//--REFS:
//--https://github.com/olikraus/u8g2/wiki/
//--ICONS https://github.com/olikraus/u8g2/wiki/fntgrpiconic#open_iconic_mime_6x
//=======================================================================

#include "oled.h"

//--Instances
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, SCL_PIN, SDA_PIN);
uint8_t u8log_buffer[U8LOG_WIDTH*U8LOG_HEIGHT];
U8X8LOG u8x8log;

//--Local variables
uint32_t start_clock=millis();

//--extern variables
extern int distance;


//-Definitions screen area tittle
areaScreen areaTittle = {
  0,8,128,20
};

//-Definitions screen area values
areaScreen areaV = {
0,20,128,70
};


void oled88_init(void){
  Wire.begin(SDA_PIN,SCL_PIN);
  u8g2.begin();
  u8x8log.begin(U8LOG_WIDTH, U8LOG_HEIGHT, u8log_buffer);
  u8x8log.setRedrawMode(1);		//--  0: Update screen with newline, 1: Update screen for every char  
  u8g2.setFlipMode(1);        //--  rotate screen 180 degrees

}

void oled88_test(void){
  u8g2.setDrawColor(1);
  u8g2.drawBox(0,0,128,64);
  u8g2.sendBuffer();
  u8g2.setDrawColor(0);
  for(int r=0; r<128; r++){
    u8g2.drawBox(r,0,r+1,64);
    u8g2.sendBuffer();
  }
  u8g2.setDrawColor(1);
}

void oled88_clear(void){
  u8g2.clearBuffer();
  u8g2.sendBuffer();
}

void oled88_bienvenida(void){
  u8g2.setMaxClipWindow();
  u8g2.setFont(u8g2_font_spleen6x12_mf);
  u8g2.setCursor(10,35);
  u8g2.print("UTN Electronica II");
  u8g2.setFont(u8g2_font_streamline_all_t); //see https://github.com/olikraus/u8g2/wiki/fntgrpstreamline#streamline_all
  u8g2.sendBuffer();
  delay(3000);
}

void oled88_update(int distance){
if ((millis()-start_clock)>=1000){
      start_clock=millis();
      oled88_printTit(" Medicion:        ");
      oled88_printV(distance);      
    }
    delay(10);
}

//--Print message in tittle area
void oled88_printTit(const char * tittle){
  u8g2.setClipWindow(areaTittle.xorg,areaTittle.yorg,areaTittle.xend,areaTittle.yend);
  u8g2.setFont(u8g2_font_spleen6x12_mf);//u8g2_font_helvB08_tr);
  u8g2.setCursor(0, 18);
  u8g2.print(tittle);
  u8g2.sendBuffer();
}

//--Print 3 values in value area
void oled88_printV(int distance){
    //u8x8.setFont(u8g2_font_9x15_t_cyrillic);
    u8g2.setClipWindow(areaV.xorg,areaV.yorg,areaV.xend,areaV.yend);
    u8g2.setFont(u8g2_font_spleen6x12_mf);
    u8g2.setCursor(0, 30);
    u8g2.printf(" Distancia: %d cm ",distance);
    u8g2.sendBuffer();
}


void oled88_connected_wifi(IPAddress ip) {
  u8g2.setFont(u8g2_font_spleen6x12_mf); 
  u8g2.setCursor(10, 20);  
  u8g2.print("Conectado a WiFi");
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.setCursor(10, 50);  
  u8g2.printf("IP: %d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
  u8g2.sendBuffer();
  delay(200);
}

void oled88_info(const char * info) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_spleen6x12_mf); 
  u8g2.setCursor(10, 30);  
  u8g2.print(info);
  u8g2.sendBuffer();
  delay(2000);
}