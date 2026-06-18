#include <stdio.h>
#include <limits.h>

int main()
{
    signed char sc = -1;
    unsigned char uc = 255;

    signed int si = -10;
    unsigned int ui = 10;

    printf("=== Sizes ===\n");
    printf("sizeof(signed char)   = %zu\n", sizeof(sc));
    printf("sizeof(unsigned char) = %zu\n", sizeof(uc));
    printf("sizeof(signed int)    = %zu\n", sizeof(si));
    printf("sizeof(unsigned int)  = %zu\n", sizeof(ui));

    printf("\n=== Ranges ===\n");
    printf("SCHAR_MIN = %d\n", SCHAR_MIN);
    printf("SCHAR_MAX = %d\n", SCHAR_MAX);
    printf("UCHAR_MAX = %u\n", UCHAR_MAX);

    printf("\n=== Signed vs Unsigned ===\n");
    printf("sc = %d\n", sc);
    printf("uc = %u\n", uc);

    printf("\n=== Comparison ===\n");
    if (si < ui)
        printf("-10 < 10 : TRUE\n");
    else
        printf("-10 < 10 : FALSE\n");

    printf("\n=== Signed Overflow ===\n");
    signed char a = 127;
    printf("Before = %d\n", a);
    a++;
    printf("After  = %d\n", a);

    printf("\n=== Unsigned Underflow ===\n");
    unsigned char b = 0;
    printf("Before = %u\n", b);
    b--;
    printf("After  = %u\n", b);

    printf("\n=== Conversion ===\n");
    unsigned int x = -1;
    printf("unsigned int x = -1 --> %u\n", x);

    return 0;
}
