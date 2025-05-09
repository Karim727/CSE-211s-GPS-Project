#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "GPS.h"
#include "distance.h"
#include "UART.h"

float longi_min,lati_min; // Longitude and Latitude Minutes
short int longi_deg, lati_deg; // Longitude and Latitude Degrees


//$GPRMC,101612.00,A,3003.84349,N,03116.75562,E,0.105,,070525,,,A*70<CR><LF>

void Gps_parsing(char* string,float* lati,float* longi)

{
	
	char Longitude[14]="";
	char Latitude[14]="";
	//int len	;
	volatile float temp;
	

	char *myPtr = strtok(string, ",");
	//char flag = 1;
	char counter = 0;
	char * z;
	string[6] = ',';
	
	while (myPtr != NULL) {
		
				myPtr = strtok(NULL, ",");  // Splits the string to the desired Tokens
				//flag =0;
				counter++;

				switch (counter){
					
					case 2: // Third Token A = Valid data, V = InValid data
						if(strcmp(myPtr,"A")) // The Condition returns 0 if myPtr == A
							goto exit;
						break;
						
					case 3: // Fourth Token // latitude 
						strcat(Latitude,myPtr); // store latitude in a char[]
						temp = strtod(Latitude,&z); // Convert string to float
						*lati = (float)(remainder(temp,100))/60 + ((int)temp/100);
					//lati_min = (float)remainder(templati,100);
					  //lati_deg = lati_float/100;
						break;
					case 5: // Sixth Token // Longitude
					
						strcat(Longitude,myPtr); // store longitude in a char[]
						temp = strtod(Longitude,&z); // Convert string to float
						*longi = (float)(remainder(temp,100))/60 + ((int)temp/100);
						
					break;

				}
				
		
			
	}
	exit: ;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// THE COORDINATES ARE NOW STORED INSIDE lati_deg/min & longi_deg/min
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Gps_out_string(char* string)
{
	char *myPtr;
	int i=0;
	char flag = 1;
	char c4;
	loop: ;
	flag=1;
	i=0;
	do
	{
		c4 = UART4_Tx();
		if(c4 != '$' && flag == 1)
		{
			continue;
		}
		
		string[i] = c4;
		i++;
		flag = 0;
	}
	while(c4 != '*');
	string[i]='\0';

	myPtr = strtok(string, ",");

	while (myPtr != NULL) {
		if( strcmp(myPtr, "$GPRMC") ) // if true then else statement is executed

					goto loop;
		else
			break;		// Break outside the loop if the Token isn't $GPRMC
	
	}
	 
}
//Gps_parsing(NMEA); // Get the Longitude and Latitude 


