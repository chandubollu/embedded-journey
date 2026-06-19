#include<stdio.h>
void increment (int a)
{
a=a+1;//here a is local variable to this function(formal argument)
printf("address of variable a in increment=%p\n",&a);}
int main()
{
int a;
a=10;//here a is local variable to this function(actual argument)
increment(a);
printf("a=%d",a);
printf("address of variable a in increment=%p\n",&a);
}
//output is 10 .
//it is also known as call by value
