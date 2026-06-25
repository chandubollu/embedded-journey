#include<stdio.h>
struct student
{
char grade;
int age;
float percentage;
};
int main()
{
//basic data types
printf("===data types===");
printf("char :%zu bytes\n",sizeof(char));
printf("short :%zu bytes\n",sizeof(short));
printf("int :%zu bytes\n",sizeof(int));
printf("long :%zu bytes\n",sizeof(long));
printf("long long :%zu bytes\n",sizeof(long long));
printf("float :%zu bytes\n",sizeof(float));
printf("double :%zu bytes\n",sizeof(double));
//variables
char c ='A';
int age=25;
float temp=36.5;
printf("\n===variables===\n");
printf("c :%zu bytes\n",sizeof(c));
printf("age :%zu bytes\n",sizeof(age));
printf("temp :%zu bytes\n",sizeof(temp));
//arrays
int arr[10];
printf("\n===arrays===\n");
printf("arr :%zu bytes\n",sizeof(arr));
printf("elements :%zu bytes\n",sizeof(arr)/sizeof(arr[0]));
//pointers
int *p=&age;
printf("\n===pointers===\n");
printf("p:%zu bytes\n",sizeof(p));
//structure
struct student s;
printf("\n===structures===\n");
printf("student:%zu bytes" ,sizeof(struct student));
printf("s:%zu bytes",sizeof(s));
return 0;
}
