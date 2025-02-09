#include <regx52.h>
void print_msg(char *);
void write(char, int);
void delay(unsigned int);
void main()
{
	write(0x38, 0);
	write(0x0F, 0);
	write(0x06, 0);
	write(0x01, 0);
	write(0xC0, 0);
	print_msg("E94096152");
	
//	write(0x40,0);
//	write(0x00,1);
//	
//	write(0x41,0);
//	write(0x0E,1);
//	
//	write(0x42,0);
//	write(0x1F,1);
//	
//	write(0x43,0);
//	write(0x15,1);
//	
//	write(0x44,0);
//	write(0x0E,1);
//	
//	write(0x45,0);
//	write(0x0E,1);
//	
//	write(0x46,0);
//	write(0x00,1);
//	
//	write(0x47,0);
//	write(0x00,1);
//	
//	write(0x80,0);
//	write(0x00,1);
	
	write(0x48,0);//cg ram  smile
	write(0x00,1);
	write(0x0A,1);
	write(0x0A,1);
	write(0x00,1);
	write(0x11,1);
	write(0x0E,1);
	write(0x00,1);
//	write(0x8F,0);
	write(0x00,1);
	while (1);
}
void print_msg(char *msg)
{
	for (; *msg!='\0'; msg++) 
	write(*msg,1); 
}
void write(char cmd, int rs_value)
{
	P1= cmd;
	P3_4= rs_value; //RS
	P3_5=1; //E
	delay(100);
	P3_5=0;
}


void delay(unsigned int i)
{
	while (i--);
}