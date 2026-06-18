/*Find how many elements are in an array using sizeof().*/
#include<stdio.h>
int main()
{
int a[10];
printf("a:%zu bytes\n",sizeof(a));
printf("elements:%zu\n",sizeof(a)/sizeof(a[0]));
return 0;
}
