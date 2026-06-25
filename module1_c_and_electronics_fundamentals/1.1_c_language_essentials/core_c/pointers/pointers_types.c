#include<stdio.h>
int main()
{
int a=1025;
int *p;
p=&a;
printf("size of integer is %zu\n",sizeof(int));
printf("address=%p,value=%d\n",p,*p);//value=1025
printf("address=%p,value=%d\n",p+1,*(p+1));//value=garbage value
char *p0;
p0=(char*)p;//typecasting
printf("size of char is %zu\n",sizeof(char));
printf("address=%p,value=%d\n",p0,*p0);//value=1
//1025= 00000000 00000000 00000100 00000001
printf("address=%p,value=%d\n",p0+1,*(p0+1));//value=4
//void pointer - generic pointer
void *p1;
p1=p;//no need of type casting here
printf("addressof p1=%p",p1);
return 0;}
