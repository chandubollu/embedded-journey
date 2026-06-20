//arrays and pointers are differnt types that are used in similar manner
#include<stdio.h>
int main()
{
char c1[6]="Hello";
char* c2;//pointer pointing to character data type
c2=c1;
printf("%p/n",c2);
printf("%p/n",c1[1]);
}
