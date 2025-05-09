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
//#define MAX_LENGTH 45
char i=0;
float min=10000;
float d[6]={0,0,0,0,0,0};	
char min_index=4;

float ARCH_LAT = 30.063983;
float ARCH_LONG = 31.280597;
float MOSQUE_LAT=30.06463;
float MOSQUE_LONG=31.28044;
float HALL_A_LAT=30.06417;
float HALL_A_LONG=31.28020;
float HALL_C_LAT=30.06366;
float HALL_C_LONG=31.28045;
float LIBRARY_LAT=30.06523;
float LIBRARY_LONG=31.28019;
float CREDIT_LAT=30.06348;
float CREDIT_LONG=31.27842;

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
	
	//char cc;				//Out char from gps
	char NMEA[45];	//Out string from gps
	 float lati_float;
	 float longi_float;
	GPIO_init();
		LCD_init();

	//UART4_Init();
	//UART0_Init();
	while(1)
	{
		strcpy(NMEA , "$GPRMC,101612.00,A,3003.83901,N,03116.83587"); //USE THIS FOR TESTING WITHOUT GPS
	//memset(NMEA, '\0', sizeof(NMEA)); 
	//memset(Latitude, '\0', sizeof(Latitude)); 
	//memset(Longitude, '\0', sizeof(Longitude)); 

	//cc = UART4_Tx();
//	UART0_Rx(cc); //Send gps output to pc
	//Gps_out_string(NMEA); //Store Output of Gps in NMEA
	Gps_parsing(NMEA,&lati_float,&longi_float); // Get the Longitude and Latitude// They're now stored in main.
	d[0] = (int)GPS_getDistance(longi_float, lati_float,MOSQUE_LONG,MOSQUE_LAT); //d1 should be 128
	d[1] = (int)GPS_getDistance(longi_float, lati_float,ARCH_LONG,ARCH_LAT); //d1 should be 128

	d[2] = (int)GPS_getDistance(longi_float, lati_float,HALL_A_LONG,HALL_A_LAT); //d1 should be 128
	d[3] = (int)GPS_getDistance(longi_float, lati_float,HALL_C_LONG,HALL_C_LAT); //d1 should be 128
	d[4] = (int)GPS_getDistance(longi_float, lati_float,LIBRARY_LONG,LIBRARY_LAT); //d1 should be 128
	d[5] = (int)GPS_getDistance(longi_float, lati_float,CREDIT_LONG,CREDIT_LAT); //d1 should be 128	
	
	
		

		for(i=0;i<6; i++ )     //TO GET THE INDEX OF THE MINIMUM ELEMENT
	{
		 if(d[i]<min){ 
		 min = d[i];
							min_index = i;
				 }	     
	}	
LCD_instructions(0x80);
	//LCD_print_location(" Mosque",7,d[0]); 

	switch(min_index)
		{
		case 0:
		LCD_print_location(" Mosque",7,d[0]); break;
		case 1:
		LCD_print_location(" Arch",5,d[1]); break;
		case 2:
		LCD_print_location(" Hall A",7,d[2]); break;
		case 3:
		LCD_print_location(" Hall C",7,d[3]); break;
		case 4:
		LCD_print_location(" Library",8,d[4]); break;
		case 5:
		LCD_print_location(" Credit",7,d[5]); break;
		default:
			break;

			}		
		
		
		
		
		
		
		
	}
	



}