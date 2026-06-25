#include<stdio.h>
#pragma pack(1)
struct store{
    double price;
    union{
        struct{
            char *title;
            char *author;
            int num_pages;
        }book;
        struct{
            int color;
            int size;
            char *design;
        }shirt;
    }item;
};
int main()
{
    struct store s;
    s.item.book.title="the alchemist";
    s.item.book.author="paulo coelho";
    s.item.book.num_pages=197;
    printf("%s\n",s.item.book.title);
    printf("%ld",sizeof(s));
    return 0;
}
