#include <math.h>
#include "Bit_Utilities.h"

#include "distance.h"
#include "GPS.h"
const double  EARTH_RADIUS = 6371000;


/*void coord_conversion(void)
{
   current_longitude = longi_min/60 + longi_deg;
	 current_longitude = lati_min/60 + lati_deg;

}*/

float ToRad(float angle){
    float rad = (float)angle *PI/180;
    return rad;
}

extern float GPS_getDistance(float currentLong, float currentLat, float destLong, float destLat){

float currentLongRad = ToRad(currentLong);
float currentLatRad = ToRad(destLat);
float destLongRad = ToRad(destLong);
float destLatRad = ToRad(destLat);
	


float longDiff = destLongRad - currentLongRad;
float latDiff = destLatRad - currentLatRad;

float a = pow(sin(latDiff/2),2)+cos(currentLatRad)*cos(destLatRad)*pow(sin(longDiff/2),2);
double c = 2*atan2(sqrt(a),sqrt(1-a));
return EARTH_RADIUS*c;
}
