//function pointrs and call backs
#include<stdio.h>
void A()
{
printf("Hello");
}
void B(void (*ptr)())//function pointer as arguent
{ptr();}
int main()
{void (*p)()=A;
B(p);}

