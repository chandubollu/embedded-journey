#include<stdio.h>
struct abc
{
    int x;
    int y;
};
int main()
{
    struct abc a={0,1};
    struct abc *ptr=&a;
    //ptr is pointer to some variable of type struct abc.
    printf("%d %d",ptr->x,ptr->y);
    //ptr->x is equvalent to (*ptr).x 
    //ptr->x is equvalent to (*&a).x
    //* and & cancel out we lft with a.x
    //a.x=0 and similarly a.y =1

    return 0;
}
