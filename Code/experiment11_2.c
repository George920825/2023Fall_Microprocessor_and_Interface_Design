#include <regx52.h>

void delay(int);
void turn( );
code char one_phase[ ] = {0x01,0x02,0x04,0x08};
code char two_phase[ ] = {0x0c,0x06,0x03,0x09};
int dir , delay_time;

void main( )
{
	dir = 0;
	
	// ADC to set the delay time
	while (1)
	{
		if (P2 > (256 * 8 / 9)) {
			delay_time = 20000;
		}
		else if (P2 > (256 * 7 / 9)) {
			delay_time = 16000;
		}
		else if (P2 > (256 * 6 / 9)) {
			delay_time = 12000;
		}
		else if (P2 > (256 * 5 / 9)) {
			delay_time = 8000;
		}
		else if (P2 > (256 * 4 / 9)) {
			delay_time = 4000;
		}
		else if (P2 > (256 * 3 / 9)) {
			delay_time = 1000;
		}
		else if (P2 > (256 * 2 / 9)) {
			delay_time = 800;
		}
		else if (P2 > (256 * 1 / 9)) {
			delay_time = 600;
		}
		else {
			delay_time = 500;
		}
		turn();
	}

// 11_1
//	delay_time = 5000;
//	dir = 0;
//	while (1)
//	{
//		turn( );
//	}
}

void turn( )
{
	int x;
	if (dir == 1) //one phase, turn right
	{
		for (x = 0; x < 4; x++)
		{
			P1 = one_phase[x];
			delay(delay_time);
		}
	}
	else //two phase, turn left
	{
		for(x = 0; x < 4; x++)
		{
			P1 = two_phase[x];
			delay(delay_time);
		}
	}
}

void delay(int t)
{
	while(t--);
}