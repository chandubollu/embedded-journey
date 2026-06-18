 #include<stdio.h>
int main()
{
int a;
a=5;
int * p;
p=&a;
printf("%p\n",p);
printf("%p\n",&a);
printf("%p\n",&p);
printf("%d\n",*p);//* dereferencing operator
*p=8;
printf("%d\n",*p);
//pointer arithmetic
printf("address p is %p\n",p);
printf("value at address p is %d\n",*p);
printf("size of integer is %zu bytes\n",sizeof(int));
printf("address p+1 is %p\n",p+1);
printf("value at address p+1 is %d\n",*(p+1));
return 0;}
