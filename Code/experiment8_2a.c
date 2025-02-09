#include <regx52.h>
void init_uart( ); //declare UART function
char recivevalue; //receive data
void check_id(int);

char id[9] = {'e','9','4','1','0','6','1','5','1'};
char correct[11] = {'\r','\n','c','o','r','r','e','c','t','\r','\n'};
char wrong[9] = {'\r','\n','w','r','o','n','g','\r','\n'};
int counter = 0;
int point = 0;

void main( )
{
	init_uart( );
	while (1);
}

void init_uart( )
{
	SCON = 0x50; //Mode1
	TMOD = 0x20; //Timer1 Mode2
	TH1 = 0xe6; //set Baud=1200
	TR1 = 1; //enable TCON Timer1
	IE = 0x90; //enable UART
}

void UART_Isr(void) interrupt 4 //UART
{
	while (RI == 0); //wait recieve flag == 1
	RI = 0; //clear flag
	recivevalue = SBUF;
	P2 = recivevalue; //LED display data
	
	check_id(recivevalue);
	
	if (counter == 9)
	{
		if (point == 9)
		{
			int i=0;
			for (; i<11; i++)
			{
				SBUF = correct[i]; //load data
				while (TI == 0); //wait transmit flag == 1
				TI=0; //clear flag
				counter = 0;
				point = 0;
			}
		}
		else
		{
			int i=0;
			for (; i<9; i++)
			{
				SBUF = wrong[i]; //load data
				while (TI == 0); //wait transmit flag == 1
				TI=0; //clear flag
				counter = 0;
				point = 0;
			}
		}
	}
}

void check_id(int id_num)
{
	if (id_num == id[counter])
	{
		point++;
	}
	counter++;
}