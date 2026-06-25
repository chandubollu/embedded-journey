#include<stdio.h>
int Add(int a,int b)
{
return a+b;}
int main()
{
int c;
//pointer to function that should take
//(int,int) as argument/parameter and return int
int (*p)(int,int);//function pointer p
p=&Add;//function name will return us pointer
c=(*p)(2,3);//de referencing and executing the function
printf("%d",c);
}
