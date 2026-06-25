#include<stdio.h>
int main()
{
printf("%zu\n", sizeof('A'));
char c = 25;

printf("%d\n", c);
printf("%zu\n", sizeof(10));
printf("%zu\n", sizeof(10.0));
printf("%zu\n", sizeof(10.0f));
short x = 10;
short y = 20;

printf("%zu\n", sizeof(x + y));
char a = -1;

if(a < 0)
    printf("Negative");
else
    printf("Positive");
unsigned int d = 1;
int b = -2;

printf("%d\n", d + b);
return 0;}
