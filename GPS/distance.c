#include <math.h>
#include "Bit_Utilities.h"
#include "tm4c123gh6pm.h"
#include "GPIO.h"

const double  EARTH_RADIUS = 6371000;
#define PI 3.14159265358979323846

float ToDegree(float angle){
	int degree = (int)angle/100;
	float minutes = angle - (float)degree*100;
	return(degree+ (minutes/60));
}

float ToRad(float angle){
	float rad = angle *PI/180;
	return rad;
}

float GPS_getDistance(float currentLong, float currentLat, float destLong, float destLat){

float currentLongRad = ToRad(ToDegree(currentLong));
float currentLatRad = ToRad(ToDegree(currentLat));
float destLongRad = ToRad(ToDegree(destLong));
float destLatRad = ToRad(ToDegree(destLat));


float longDiff = destLongRad - currentLongRad;
float latDiff = destLatRad - currentLatRad;

float a = pow(sin(latDiff/2),2)+cos(currentLatRad)*cos(destLatRad)*pow(sin(longDiff/2),2);
double c = 2*atan2(sqrt(a),sqrt(1-a));
return EARTH_RADIUS*c;
}