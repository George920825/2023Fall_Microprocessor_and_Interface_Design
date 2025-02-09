#include <regx52.h>
#include <string.h>
void print_msg(char[]);
void write(char, int);
void delay(unsigned int);

void main( )
{
write(0x38, 0); // use 2 lines and 5x7 matrix (00111000)p.22
write(0x0F, 0); // LCD ON, cursor ON, cursor blinking ON (00001111)p.20
write(0x06, 0); // increment cursor (00000110)p.19
write(0x01, 0); // clear screen (00000001)p.18
write(0x80, 0); // DDRAM 1st row 1st column (00H) (10000000)p.25
print_msg("Hello, world!"); // display "Hello world!"
while (1);
}

void print_msg(char msg[])
{
int i;
for (i=0; i<strlen(msg); i++) // for every character
write(msg[i], 1); // monitor displays character (RS=1, data in)p.16
}

void write(char cmd, int rs_value)
{
P1 = cmd; // P1=cmd (send data)
P3_0 = rs_value; // RS=rs (1 or 0)p.16
P3_1 = 1; // ENABLE high p.15
delay(100);
P3_1 = 0; // ENABLE low
}

void delay(unsigned int i)
{
while (i--);
}