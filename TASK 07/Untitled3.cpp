#include <stdio.h>

int main(void)
{
    int a = 5, b = 2;
    double x = 0.1, y = 0.2;
    double result = 0.0;
    int i;

   
    printf("Integer division: %d / %d = %d\n",
           a, b, a / b);

    
    printf("0.1 + 0.2 = %.17f\n", x + y);

    
    printf("Integer + double = %.1f\n", a + 2.5);

    
    for (i = 0; i < 10; i++)
    {
        result += 0.1;
    }

    printf("Sum of 0.1 repeated 10 times = %.17f\n",
           result);

    return 0;
}


