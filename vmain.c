#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tm4c123gh6pm.h"
#include "UART.h"
#include "GPS.h"
#include "gpio.h"
#include "LCD.h"
#include "distance.h"
#include "Bit_Utilities.h"
#include "bluetooth.h"
//#define MAX_LENGTH 45
  //char i=0;
	//int min=10000;
	//float d[6]={0,0,0,0,0,0};	
	//char min_index=4;
float d[5]={0,0,0,0,0};	

float GATE2_LAT = 30.06471733333;
float GATE2_LONG = 31.2775783333;
//float LUBAN_LAT=30.06329183333;
//float LUBAN_LONG=31.27896033333;   // 30.063431°N 31.279529°E
float LUBAN_LAT=30.063431;
float LUBAN_LONG=31.2795;

float HALL_A_LAT=30.06438516667	;
float HALL_A_LONG=31.28003716667;
float HALL_C_LAT=30.06387833333;
float HALL_C_LONG=31.28039583333;
float LIBRARY_LAT=30.06509483333;
float LIBRARY_LONG=31.27998783333;
float CREDIT_LAT=30.06362016667;
float CREDIT_LONG=31.278225;





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////GPS




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Distance







///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////main


//FROM GOOGLE MAPS
//	Student's Hostpital					30.066120, 31.279812 //
//  Vertex of Credit Building   30.062575, 31.278232 //  3003.7545, 03116.69392
//Note: the Deg within the faculty is constant as well as the first two digits in minutes,
// so you can only focus on the numbers after the decimal point.   3003.7545, 03116.69392 Can also be represented by integers
//																																		  ||||        |||||
// COORDINATES AT MODRGAT 							LAT30.064058	LONG31.279260       //$GPRMC,101612.00,A,3003.84349,N,03116.75562
//	modrgat	from google earth	  						30.06423  31.279188
// COORDINATES AT ARCHITECTURE BUILDING	LAT30.063983  LONG31.280597     	//$GPRMC,101612.00,A,3003.83901,N,03116.83587

int main()
{
        char bt_msg[32];
	char i ;
	volatile int min ;
	//char cc;				//Out char from gps
	char NMEA[45];	//Out string from gps
	//volatile int d1;
	volatile char min_index = 4 ;
	const char *names[5] = {
      " LUBAN", " GATE2", " Hall C", " Library", " Credit"
    };
	char Longitude[14]="";
	char Latitude[14]="";
	 float lati_float;
	 float longi_float;
	 GPIO_init();
		LCD_init();
	UART3_Init(); 

	UART4_Init();
	//UART0_Init();
	while(1)
	{
		min = 10000;
	//	strcpy(NMEA , "$GPRMC,101612.00,A,3003.83901,N,03116.83587"); //USE THIS FOR TESTING WITHOUT GPS
	memset(NMEA, '\0', sizeof(NMEA)); 
	memset(Latitude, '\0', sizeof(Latitude)); 
	memset(Longitude, '\0', sizeof(Longitude)); 

	//cc = UART4_Tx();
	//UART0_Rx(cc); //Send gps output to pc
	
	Gps_out_string(NMEA); //Store Output of Gps in NMEA
	Gps_parsing(NMEA,&lati_float,&longi_float); // Get the Longitude and Latitude// They're now stored in main.
	d[0] = (int)GPS_getDistance(longi_float, lati_float,LUBAN_LONG,LUBAN_LAT); //d1 should be 128
	d[1] = (int)GPS_getDistance(longi_float, lati_float,GATE2_LONG,GATE2_LAT); //d1 should be 128
	//d[2] = (int)GPS_getDistance(longi_float, lati_float,HALL_A_LONG,HALL_A_LAT); //d1 should be 128
	d[2] = (int)GPS_getDistance(longi_float, lati_float,HALL_C_LONG,HALL_C_LAT); //d1 should be 128
	d[3] = (int)GPS_getDistance(longi_float, lati_float,LIBRARY_LONG,LIBRARY_LAT); //d1 should be 128
	d[4] = (int)GPS_getDistance(longi_float, lati_float,CREDIT_LONG,CREDIT_LAT); //d1 should be 128	
//UART5_SendS("mosque");
	
	
		

	for(i=0;i<5; i++ )     //TO GET THE INDEX OF THE MINIMUM ELEMENT
{
	 if(d[i]<min){ 
	 min = d[i];
		        min_index = i;
		   }	     
}	
	//LCD_print_location(" Mosque",7,d[0]); 
LCD_instructions(0x01); //clear screen
LCD_instructions(0x80); //cursor to initial position
switch(min_index){
	case 0:
	LCD_print_location(" LUBAN",6,d[0]); break;
	case 1:
	LCD_print_location(" GATE2",6,d[1]); break;
	
	case 2:
	LCD_print_location(" Hall C",7,d[2]); break;
	case 3:
	LCD_print_location(" Library",8,d[3]); break;
	case 4:
	LCD_print_location(" Credit",7,d[4]); break;
	default:
		break;

}	

  

            // build: " place:128m\r\n"
            snprintf(bt_msg, sizeof(bt_msg),
                     "%s:%dm\r\n",
                     names[min_index],
                     (int)(d[min_index]));
            UART3_SendS(bt_msg);   // transmit via bluetooth
        	

          for (volatile int delay = 0; delay < 2000000; delay++);  //i added some delay
		
		
		
		
		
}
	



}
