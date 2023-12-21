#include <stdio.h>
#include <stdint.h>

uint64_t fibonacci_sum(uint8_t count);

int main()
{
    uint16_t count;

    while (1)
    {
        fputs("Enter the number of terms: ", stdout);
        scanf("%hu", &count);

        printf("Sum of Fibonacci terms up to %hu: %llu\n", count, fibonacci_sum(count));
    }

    return 0;
}

uint64_t fibonacci_sum(uint8_t count)
{
    uint64_t sum, term1, term2, tmp;

    sum = 1;
    term1 = 1;
    term2 = 2;
    while (--count)
    {
        sum += term1;

        tmp = term1;
        term1 = term2;
        term2 += tmp;
    }

    return sum;
}
