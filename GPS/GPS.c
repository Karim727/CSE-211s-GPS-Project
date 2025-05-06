#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "GPS.h"
#include "distance.h"
#include "UART.h"

float longi_min,lati_min; // Longitude and Latitude Minutes
short int longi_deg, lati_deg; // Longitude and Latitude Degrees


void extract_deg_min(float coord, short int *deg, float* min, short int len)
{
	len--;
	*min = remainder(coord, (float)pow(10,len));
	*deg = coord/pow(10,len);
}


void Gps_parsing(char* string)
{
	char Longitude[14]="";
	char Latitude[14]="";
	
	float longi_float;
	float lati_float;
	char *myPtr = strtok(string, ",");
	char flag = 1;
	char counter = 0;
	
	while (myPtr != NULL) {
		if( strcmp(myPtr, "GPRMC") && flag == 1) // if true then else statement is executed
			break;		// Break outside the loop if the Token isn't $GPRMC
			
			else
			{
				myPtr = strtok(NULL, ",");  // Splits the string to the desired Tokens
				flag =0;
				counter++;

				switch (counter){
					
					case 3: // Third Token A = Valid data, V = InValid data
						if(strcmp(myPtr,"A")) // The Condition returns 0 if myPtr == A
							goto exit;
						break;
						
					case 4: // Fourth Token // Longitude 
					strcat(Longitude,myPtr); // store langitude in a char[]
					longi_float = atof(Longitude); // Convert string to float
					extract_deg_min(longi_float,&longi_deg,&longi_min, 3);	// take first three decimals for longi_deg and the rest for longi_float
					break;
					case 6: // Sixth Token // Latitude
						strcat(Latitude,myPtr); // store latitude in a char[]
					 lati_float = atof(Latitude); // Convert string to float
						extract_deg_min(lati_float,&lati_deg, &lati_min,2);	// take two decimals for lati_deg and the rest for lati_float
						

				}
				
		}
			
	}
	exit: ;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// THE COORDINATES ARE NOW STORED INSIDE lati_deg/min & longi_deg/min
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Gps_out_string(char* string)
{
	int i=0;
	char c4;
	c4 = UART4_Tx();
	while(c4 != CR)
	{
		c4 = UART4_Tx();
		string[i]=c4;
		i++;
	}
string[i]='\0';


}




