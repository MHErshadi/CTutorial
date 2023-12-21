#include <stdio.h>
#include <stdint.h>

void print_narcissistic(uint32_t start, uint32_t end);
uint8_t num_length(uint32_t number);
uint32_t power(uint8_t base, uint8_t exp);

int main()
{
    uint32_t start, end;

    while (1)
    {
        fputs("Enter the left bound: ", stdout);
        scanf("%u", &start);
        fputs("Enter the right bound: ", stdout);
        scanf("%u", &end);

        print_narcissistic(start, end);
    }
}

void print_narcissistic(uint32_t start, uint32_t end)
{
    uint64_t sum;
    uint8_t slen, elen;
    uint32_t pow10, i, tmp;

    printf("Narcissistic numbers between %u and %u: ", start, end);

    sum = 0;
    slen = num_length(start);
    elen = num_length(end);
    if (slen != elen)
    {
        pow10 = power(10, slen);
        do
        {
            for (i = start; i < pow10; i++)
            {
                tmp = i;
                sum = 0;
                while (tmp)
                {
                    sum += power(tmp % 10, slen);
                    tmp /= 10;
                }

                if (sum == i)
                    printf("%u  ", i);
            }

            start = pow10;
            slen++;

            pow10 *= 10;
        } while (slen != elen);
    }

    for (i = start; i <= end; i++)
    {
        tmp = i;
        sum = 0;
        while (tmp)
        {
            sum += power(tmp % 10, slen);
            tmp /= 10;
        }

        if (sum == i)
            printf("%u  ", i);
    }

    putchar('\n');
}

uint8_t num_length(uint32_t number)
{
    uint8_t len;

    len = 1;
    while (number /= 10)
        len++;

    return len;
}

uint32_t power(uint8_t base, uint8_t exp)
{
    uint32_t res;

    res = base;
    while (--exp)
        res *= base;

    return res;
}
