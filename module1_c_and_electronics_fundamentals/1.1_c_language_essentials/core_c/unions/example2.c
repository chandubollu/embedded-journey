#include<stdio.h>
union abc{
    int a;
    char b;
    double c;
    float d;
};
int main()
{printf("%ld",sizeof(union abc));
return 0;}
