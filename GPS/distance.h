#ifndef distance
#define distance

#define PI 3.14159265358979323846

float ToDegree(float angle);
float ToRad(float angle);
float GPS_getDistance(float currentLong, float currentLat, float destLong, float destLat);

//void current_coord(void);
//long int coord_conversion(char* coord, int len);

#endif 
