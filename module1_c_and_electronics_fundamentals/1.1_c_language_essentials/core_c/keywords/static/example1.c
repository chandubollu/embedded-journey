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
