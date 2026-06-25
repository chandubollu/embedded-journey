#include<stdio.h>
struct car{
    int fuel_tank_cap;}c1,c2;
int main()
{
    c1.fuel_tank_cap  =45;
    c2.fuel_tank_cap =30;
    printf("%d %d",c1.fuel_tank_cap,c2.fuel_tank_cap);
    return 0;
}
