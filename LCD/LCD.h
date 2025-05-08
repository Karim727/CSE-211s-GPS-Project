#ifndef LCD
#define LCD


void LCD_delay(long delay);
void data_lines (unsigned char data);
void LCD_data (unsigned char data);
void LCD_instructions (unsigned char data);
void LCD_init(void);
void LCD_word (char *word,char length);
void LCD_print_location (char* uu,char size,float min_distance);

#endif
