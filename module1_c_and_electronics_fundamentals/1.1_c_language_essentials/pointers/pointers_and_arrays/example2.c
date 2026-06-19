#include<stdio.h>
int main()
{int A[]={0,1,2,3,4};
int i;
for(i=0;i<5;i++)
{
printf("%p\n",A+i);
printf("%p\n",&A[i]);
printf("%d\n",*(A+i));
printf("%d\n",A[i]);
}
}
