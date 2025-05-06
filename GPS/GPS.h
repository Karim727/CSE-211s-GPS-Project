#ifndef GPS
#define GPS

#define MAX_LENGTH 45
#define CR 0x0D								//Carridge Return \r
#define LF 0x0A								//Line Feed \n
void Gps_parsing(char* string);
void Gps_out_string(char* string);
extern float current_longitude;
extern float current_latitude;
extern float longi_min,lati_min; // Longitude and Latitude Minutes
extern short int longi_deg, lati_deg; // Longitude and Latitude Degrees

#endif
