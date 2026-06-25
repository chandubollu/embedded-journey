##### extern
- default value is 0.
- stored in RAM
- scope is global
- lifetime is till the end of the program.
- it is used to declare a global variable or function.
##### example1:
```c
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
void fun1()
{
    int a=2;
    a++;
    printf("a=%d\n",a);
}
void fun2()
{
    printf("hello from fun2");
}
```
##### example2:
```c
#include<stdio.h>
void fun1();
void fun2();
int main()
{
    printf("%d\n",a);
    fun1();
    fun2();
}
void fun1()
{
    int a=2;
    a++;
    printf("a=%d\n",a);
}
void fun2()
{
    printf("hello from fun2");
}
int a=10;
```
##### example3:
```c
#include<stdio.h>
void fun1();
void fun2();
int main()
{   extern int a;
    printf("%d\n",a);
    fun1();
    fun2();
}
void fun1()
{
    int a=2;
    a++;
    printf("a=%d\n",a);
}
void fun2()
{
    printf("hello from fun2");
}
int a=10;
```
#### example4:
```c
#include<stdio.h>
void fun1();
void fun2();
int main()
{
    extern int x;
    printf("x=%d",x);
    fun1();
    fun2();
}
void fun1()
{
    int x=1;
    x+=5;
    printf("\nx=%d",x);
}
void fun2()
{
int y=4;
y++;
printf("\nin fun2 y=%d",y);
}
int x=10;
```
#### example5:
- create two files 
1.support.c
```c
#include<stdio.h>
void display()
{
    extern int x;
    printf("hello from support class");
    printf("\nx=%d",x);
}
```
2. file.c
```c
#include<stdio.h>
#include "support.c"
extern void display();
int x=10;
int main()
{
    display();
}
```