#include <stdio.h>
#include <stdint.h>

void print_date(uint64_t time);

int main()
{
    uint64_t time;

    while (1)
    {
        fputs("Enter the time: ", stdout);
        scanf("%llu", &time);

        print_date(time);
    }

    return 0;
}

void print_date(uint64_t time)
{
    uint8_t sec, min, hour, day, month;
    uint32_t year;

    sec = time % 60;
    min = (time /= 60) % 60;
    hour = (time /= 60) % 24;

    printf("%hu:%hu:%hu\n", hour, min, sec);
}
