##### static
##### syntax: static data_type variable_name
- default value would be zero.
- stored in RAM
- scope is within block
- lifetime is till the end of the program
##### example 1
```c
#include<stdio.h>
static char ch;
void display();
int main()
{
    display();
    display();
    printf("\n ch=%c",ch);
}
void display()
{
    static int x=0;
    int y=10;
    x+=10;
    printf("\nx=%d",x);
    printf("\nx=%d",y);
}
```
##### example2
```c
#include<stdio.h>
void display();
int main()
{
    int i;
    for(i=0;i<3;i++)
  {  display();
}}
void display()
{
    static int x=5;
    int y=5;
    x++;
    y++;
    printf("X=%d",x);
    printf("y=%d",y);
    }
    ```