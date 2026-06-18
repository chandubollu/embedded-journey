/*
print sizes of all basic types*/
#include<stdio.h>
int main()
{
printf("char:%zu\n",sizeof(char));
printf("int:%zu\n",sizeof(int));
printf("float:%zu\n",sizeof(float));
printf("double:%zu\n",sizeof(double));
printf("short:%zu\n",sizeof(short));
printf("long:%zu\n",sizeof(long));
printf("long long:%zu\n",sizeof(long long));
printf("void:%zu\n",sizeof(void));
int a=10;
int * p=&a;
printf("p:%zu",sizeof(p));
return 0;
}
