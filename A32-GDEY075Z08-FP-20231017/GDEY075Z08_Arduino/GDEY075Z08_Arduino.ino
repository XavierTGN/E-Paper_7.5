#include <SPI.h>
//EPD
#include "Display_EPD_W21_spi.h"
#include "Display_EPD_W21.h"
#include "Ap_29demo.h"  



void setup() {
  Serial.begin(115200);
   pinMode(A14, INPUT);  //BUSY
   pinMode(A15, OUTPUT); //RES 
   pinMode(A16, OUTPUT); //DC   
   pinMode(A17, OUTPUT); //CS   



   //pinMode(BUSY_PIN, INPUT); A14 //BUSY
   //pinMode(RST_PIN, OUTPUT); //RES 
   //pinMode(DC_PIN, OUTPUT); //DC   
   //pinMode(CS_PIN, OUTPUT); //CS   
   //SPI
   SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0)); 
   SPI.begin ();  
	 	Serial.print("SPI.begin");
}

//Tips//
/*
1.Flickering is normal when EPD is performing a full screen update to clear ghosting from the previous image so to ensure better clarity and legibility for the new image.
2.There will be no flicker when EPD performs a partial refresh.
3.Please make sue that EPD enters sleep mode when refresh is completed and always leave the sleep mode command. Otherwise, this may result in a reduced lifespan of EPD.
4.Please refrain from inserting EPD to the FPC socket or unplugging it when the MCU is being powered to prevent potential damage.)
5.Re-initialization is required for every full screen update.
6.When porting the program, set the BUSY pin to input mode and other pins to output mode.
*/
void loop() {
  unsigned char i;
		 	Serial.print("loop...");
#if 1 //Full screen refresh, fast refresh, and partial refresh demostration.
			EPD_Init(); //Full screen refresh initialization.
			EPD_WhiteScreen_ALL(gImage_BW1,gImage_RW1); //To Display one image using full screen refresh.
			EPD_DeepSleep(); //Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
			delay(3000); //Delay for 3s.
			
			/************Fast refresh mode(16s)*******************/
	#if 1 //Fast refresh demostration.	
			EPD_Init_Fast(); //Fast refresh initialization.
			EPD_WhiteScreen_ALL(gImage_BW1,gImage_RW1); //To Display one image using full screen refresh.
			EPD_DeepSleep(); //Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
			delay(3000); //Delay for 3s.
	#endif				
	#if 1 //Partial refresh demostration.
	//Partial refresh demo support displaying a clock at 5 locations with 00:00.  
	//After 5 partial refreshes, implement a full screen refresh to clear the ghosting caused by partial refreshes.
	//////////////////////Partial refresh time demo/////////////////////////////////////
			EPD_Init(); //Electronic paper initialization.	
			EPD_SetRAMValue_BaseMap(gImage_BW1,gImage_RW1); //Please do not delete the background color function, otherwise it will cause unstable display during partial refresh.
			EPD_Init_Part(); //Pa refresh initialization.
			for(i=0;i<6;i++)
			{
				EPD_Dis_Part_Time(376,24,Num[1],Num[0],gImage_numdot,Num[0],Num[i],5,104,48); //x,y,DATA-A~E,Resolution 48*104              		
			}				
			EPD_DeepSleep();  //Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
			delay(2000); //Delay for 2s.
			EPD_Init(); //Full screen refresh initialization.
			EPD_WhiteScreen_White(); //Clear screen function.
			EPD_DeepSleep(); //Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
			delay(2000); //Delay for 2s.
	#endif	
	
	#if 0 //Demonstration of full screen refresh with 180-degree rotation, to enable this feature, please change 0 to 1.
			/************Full display(2s)*******************/
			EPD_Init_180(); //Full screen refresh initialization.
		  EPD_WhiteScreen_ALL(gImage_BW1,gImage_RW1); //To Display one image using full screen refresh.
		  EPD_DeepSleep(); //Enter the sleep mode and please do not delete it, otherwise it will reduce the lifespan of the screen.
			delay(3000); //Delay for 3s.
	#endif			
	
#endif
  while(1); // The program stops here   
	delay(3000);
	//Serial.println"helllo");
	Serial.print("Connecting to WiFi network ");
}




//////////////////////////////////END//////////////////////////////////////////////////
