#include<stdio.h>
int a=10;
void fun1();
void fun2();
int main()
{
    printf("%d\n",a);
    fun1();
    fun2();
}
void  fun1()
{
    int a=2;
    a++;
    printf("a=%d\n",a);
}
void  fun2()
{
    printf("hello from fun2");
}
