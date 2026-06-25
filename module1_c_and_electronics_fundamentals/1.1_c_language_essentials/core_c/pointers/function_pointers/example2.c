#include<stdio.h>
void PrintHello()
{
printf("Hello\n");
}
int Add(int a,int b)
{
return a+b;
}
int main()
{
void (*ptr)();
ptr = PrintHello;
ptr();
}

