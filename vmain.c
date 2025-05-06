#include <stdint.h>
#include <string.h>
#include "tm4c123gh6pm.h"
#include "UART.h"
#include "GPS.h"
#include "gpio.h"
#include "LCD.h"
#include "distance.h"
#include "testttttttt.h"
#include "Bit_Utilities.h"

float MOSQUE_LAT=30.07;
float MOSQUE_LONG=31.4;
float HALL_A_LAT=30.08;
float HALL_A_LONG=31.5;
float HALL_C_LAT=30.09;
float HALL_C_LONG=31.6;
float LIBRARY_LAT=30.1;
float LIBRARY_LONG=31.7;
float CREDIT_LAT=30.2;
float CREDIT_LONG=31.8;


float current_longitude = 30.069;
float current_latitude = 31.3; //arbitrary coordinates

int main()
{
	float d1;
	float d2;
	float d3;
	float d4;
	float d5;
	char cc;				//Out char from gps
	//char NMEA[MAX_LENGTH]="";	//Out string from gps


	GPIO_init();
	UART4_Init();
	UART0_Init();
	while(1)
	{
	//memset(NMEA, '\0', sizeof(NMEA)); 

	cc = UART4_Tx();
	UART0_Rx(cc); //Send gps output to pc
	//Gps_out_string(NMEA); //Store Output of Gps in NMEA
	//Gps_parsing(NMEA); // Get the Longitude and Latitude 
	//coord_conversion();
	//d1 = GPS_getDistance(current_longitude, current_latitude,MOSQUE_LONG,MOSQUE_LAT);
	//d2 = GPS_getDistance(current_longitude, current_latitude,HALL_A_LONG,HALL_A_LAT);
	//d3 = GPS_getDistance(current_longitude, current_latitude,HALL_C_LONG,HALL_C_LAT);
	//d4 = GPS_getDistance(current_longitude, current_latitude,LIBRARY_LONG,LIBRARY_LAT);
	//d5 = GPS_getDistance(current_longitude, current_latitude,CREDIT_LONG,CREDIT_LAT);
	}
	

}

