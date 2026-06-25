#include<stdio.h>
#pragma pack(1)
struct abc{
char a;
int b;
char c;
};
int main()
{
struct abc var;
printf("%lu",sizeof(var));
}
