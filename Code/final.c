#include <regx52.h>

#define TH0_init 0x06 //TH0_init= 256 - 250
#define TL0_init 0x06 //TL0_init = 256 - 250
#define Timer0_int_exetime 2000 //the parameter can be changed
void print_msg(char *);
void write(char, int);
void delay(unsigned int);
void mode2();
void mode3();
void mode4();
int mode=0;
int time=0;
int counter=0;
int percent=0;
int percent1=-1;

void main()
{
	IT0 = 0; 
	IT1 = 1;
	EX0 = 0; 
	EX1 = 1;
	ET0 = 1;
	EA = 1;
	TMOD = 0x0A;
	TL0 = TL0_init; TH0 = TH0_init; //set TH0 & TL0
	TCON = 0x10; //enable timer0
	P3_2 = 0;
	write(0x38, 0);
	write(0x08, 0);
	delay(100000000);
	write(0x0F, 0);
	write(0x06, 0);
	write(0x01, 0);

	while(1)
	{
		if(P0>=0 && P0<=65)
		{
			if(percent!=percent1)
			{
				mode2();
				percent1=percent;
			}
		}
		else if(P0>=75 && P0<=165)
		{
			if(mode!=3)
			{
				mode3();
				mode=3;
				percent=0;
				percent1=-1;				
			}
		}
		else if(P0>=175 && P0<=255)
		{
			time=time+1;
			if(mode!=4)
			{
				mode4();
				mode=4;	
				percent=0;
				percent1=-1;
			}
			if(time==10000)
			{
				write(0x18, 0);
				time=0;
			}
		}
	}
}

void mode2(void)
{
	P2=254;
	write(0x38, 0);
	write(0x0F, 0);
	write(0x06, 0);
	write(0x01, 0);
	write(0x80, 0);
	if(percent==0)
	{
		print_msg("0%");
		write(0xC0, 0);
		print_msg(">");
	}
	else if(percent==1)
	{
		print_msg("6.25%");
		write(0xC0, 0);
		print_msg("=>");
	}
	else if(percent==2)
	{
		print_msg("12.5%");
		write(0xC0, 0);
		print_msg("==>");
	}
	else if(percent==3)
	{
		print_msg("18.75%");
		write(0xC0, 0);
		print_msg("===>");
	}
	else if(percent==4)
	{
		print_msg("25%");
		write(0xC0, 0);
		print_msg("====>");
	}
	else if(percent==5)
	{
		print_msg("31.25%");
		write(0xC0, 0);
		print_msg("=====>");
	}
	else if(percent==6)
	{
		print_msg("37.5%");
		write(0xC0, 0);
		print_msg("======>");
	}
	else if(percent==7)
	{
		print_msg("43.75%");
		write(0xC0, 0);
		print_msg("=======>");
	}
	else if(percent==8)
	{
		print_msg("50%");
		write(0xC0, 0);
		print_msg("========>");
	}
	else if(percent==9)
	{
		print_msg("56.25%");
		write(0xC0, 0);
		print_msg("=========>");
	}
	else if(percent==10)
	{
		print_msg("62.5%");
		write(0xC0, 0);
		print_msg("==========>");
	}
	else if(percent==11)
	{
		print_msg("68.75%");
		write(0xC0, 0);
		print_msg("===========>");
	}
	else if(percent==12)
	{
		print_msg("75%");
		write(0xC0, 0);
		print_msg("============>");
	}
	else if(percent==13)
	{
		print_msg("81.25%");
		write(0xC0, 0);
		print_msg("=============>");
	}
	else if(percent==14)
	{
		print_msg("87.5%");
		write(0xC0, 0);
		print_msg("==============>");
	}
	else if(percent==15)
	{
		print_msg("93.75%");
		write(0xC0, 0);
		print_msg("===============>");
	}
	else if(percent==16)
	{
		print_msg("100%");
		write(0xC0, 0);
		print_msg("================");
	}
}

void mode3(void)
{
	P2=253;
	write(0x38, 0);
	write(0x0F, 0);
	write(0x06, 0);
	write(0x01, 0);
	write(0x80, 0);
	print_msg("E94106151");
	
	write(0x40,0);//BONE
	write(0x00,1);
	write(0x0A,1);
	write(0x0A,1);
	write(0x00,1);
	write(0x11,1);
	write(0x0E,1);
	write(0x00,1);
	write(0x00,1);

	write(0x8E,0);
	write(0x00,1);
		
	write(0x48,0);//smile
	write(0x00,1);
	write(0x0E,1);
	write(0x1F,1);
	write(0x15,1);
	write(0x0E,1);
	write(0x0E,1);
	write(0x00,1);
		
	write(0x8F,0);
	write(0x01,1);
	
	write(0xC0, 0);
	print_msg("Final exam");
}

void mode4(void)
{
	P2=251;
	write(0x38, 0);
	write(0x0F, 0);
	write(0x06, 0);
	write(0x01, 0);
	write(0x80, 0);
	print_msg("I love embedded system.");
}

void print_msg(char *msg)
{
	for (; *msg!='\0'; msg++) 
	write(*msg,1); 
}
void write(char cmd, int rs_value)
{
	P1= cmd;
	P3_6= rs_value; //RS
	P3_7=1; //E
	delay(100);
	P3_7=0;
}
void delay(unsigned int i)
{
	while (i--);
}

void int_1(void)interrupt 2
{
	write(0x38, 0);
	write(0x0F, 0);
	write(0x06, 0);
	write(0x01, 0);
	write(0x80, 0);
	print_msg("Best(1)");
	write(0xC0, 0);
	print_msg("Worst(1)");
	while(1);
}

void timer0_interrupt(void) interrupt 1 // ?Iinterrupt 1' is int vector of INT0
{
		counter++;
		if (counter == Timer0_int_exetime) //250clock cycle * 2000 = 0.5 second
		{
			if(percent<=17)
			{
				percent++;
			}
			counter=0;
		}
}