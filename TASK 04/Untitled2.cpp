#include <stdio.h>

#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define RUPEES_TO_PAISE(x) ((x) * 100)

int main(void)
{
    int a = 5;
    int b = 8;

    printf("Square of %d = %d\n", a, SQUARE(a));
    printf("Maximum of %d and %d = %d\n", a, b, MAX(a, b));
    printf("10 rupees in paise = %d\n", RUPEES_TO_PAISE(10));
    printf("Square of (a + 1) = %d\n", SQUARE(a + 1));

    return 0;
}


