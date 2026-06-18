/*
problem:student management system
store information about a student and display it.
Requirements:
Student ID
Name initial
Age
Marks
Percentage
Phone number
Pass/Fail status*/
#include<stdio.h>
#include<stdbool.h>
int main()
{
char initial ='A';
unsigned int rollNo = 101;
int age = 22;
short marks =485;
float percentage = 97.0f;
double cgpa = 9.87654321;
long long phone=9876543210LL;
bool isPass = true;
printf("initial:%c\n",initial);
printf("Roll No:%u\n",rollNo);
printf("Age : %d\n",age);
printf("Marks      : %hd\n", marks);
printf("Percentage : %.2f\n", percentage);
printf("CGPA       : %.8lf\n", cgpa);
printf("Phone      : %lld\n", phone);
printf("Pass       : %s\n", isPass ? "Yes" : "No");
return 0;
}
