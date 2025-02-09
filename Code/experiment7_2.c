#include <regx51.h> // include header file for 8051
#define TH0_init 0x06 //TH0_init= 256 - 250
#define TL0_init 0x06 //TL0_init = 256 - 250
#define Timer0_int_exetime 2000 //the parameter can be changed
void delay(int t);
int counter;
unsigned char LED;

void main( )
{
		TMOD = 0x0a; //set timer0 to mode 2(8-bits and auto-reload)  1010
		IP = 0x02; //timer0 interrupt has high priority
		IE = 0x82; //enable timer0 interrupt
		LED = 0xfe;
	  	P3_2 = 0;
		TL0 = TL0_init; TH0 = TH0_init; //set TH0 & TL0
		TCON = 0x10; //enable timer0
		while (1)
		{
				P2=LED;
		}
}


void timer0_interrupt(void) interrupt 1 // �Iinterrupt 1' is int vector of INT0
{
		counter++;
		if (counter == Timer0_int_exetime) //250clock cycle * 2000 = 0.5 second
		{
				LED=LED<<1;
				LED++;
				if(LED==0XFF)
				{
						LED=0XFE;
		    }
				P2=LED;
				counter = 0;
		}
}