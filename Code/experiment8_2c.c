#include<regx51.h>

void init_uart();
void switch_ele();
void check();

char recivevalue;
char N[9] = {'\0'};
char ref[9] = {'1','5','1','6','0','1','4','9','e'};
//'E','9','4','1','0','6','1','5','1'

int flag = 0;
int counter = 0;

void main( ){
	init_uart();
	while(1);
}


void init_uart(void)
{
	SCON=0x50;
	TMOD=0x20;
	TH1=0xe6;
	TR1=1;
	IE=0x90;
}	

void UART_Isr(void) interrupt 4
{	
	while(RI == 0);
	RI=0;
	counter++;

	recivevalue=SBUF;
	P2 = recivevalue;

	switch_ele();
	N[0] = recivevalue;
	
	check();
	
	if(counter == 9 && flag == 9)
	{
		SBUF='\n';
		while(TI==0);
		TI=0;
		SBUF='c';
		while(TI==0);
		TI=0;
		SBUF='o';
		while(TI==0);
		TI=0;
		SBUF='r';
		while(TI==0);
		TI=0;
		SBUF='r';
		while(TI==0);
		TI=0;
		SBUF='e';
		while(TI==0);
		TI=0;
		SBUF='c';
		while(TI==0);
		TI=0;
		SBUF='t';
		while(TI==0);
		TI=0;
		SBUF='\n';
		while(TI==0);
		TI=0;
		counter = counter - 9;
	}

	else if(counter == 9 && flag != 9)
	{
		SBUF='\n';
		while(TI==0);
		TI=0;
		SBUF='w';
		while(TI==0);
		TI=0;
		SBUF='r';
		while(TI==0);
		TI=0;
		SBUF='o';
		while(TI==0);
		TI=0;
		SBUF='n';
		while(TI==0);
		TI=0;
		SBUF='g';
		while(TI==0);
		TI=0;
		SBUF='\n';
		while(TI==0);
		TI=0;
		counter = counter - 9;
	}
	
	flag = 0;
	
}

void switch_ele(void)
{
	int i = 8;
	for(; i>0; i--)
	{
		N[i] = N[i-1];
	}
}

void check(void)
{
	int j = 8;
	for(; j>=0;j--)
	{
		if(N[j] == ref[j])
			flag += 1;
	}
}