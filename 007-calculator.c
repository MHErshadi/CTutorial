#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

#define OP_LEN 3

void calculate(const char *operator, double left, double right);

int main()
{
    char *operator, *ptr;
    double left, right;

    operator = malloc(OP_LEN);
    if (!operator)
    {
        fprintf(stderr, "Could not allocate %hu bytes of memory\n", OP_LEN);
        abort();
    }

    while (1)
    {
        fputs("Enter the left operand: ", stdout);
        scanf("%lf", &left);
        fflush(stdin);

        fputs("Enter the operator: ", stdout);
        fgets(operator, OP_LEN, stdin);

        ptr = strchr(operator, '\n');
        if (ptr)
            *ptr = '\0';

        fputs("Enter the right operand: ", stdout);
        scanf("%lf", &right);

        calculate(operator, left, right);
    }

    free(operator);
    return 0;
}

void calculate(const char *operator, double left, double right)
{
    fputs("Result: ", stdout);

    if (!strcmp(operator, "+"))
    {
        printf("%lf\n", left + right);
        return;
    }
    if (!strcmp(operator, "-"))
    {
        printf("%lf\n", left - right);
        return;
    }
    if (!strcmp(operator, "*"))
    {
        printf("%lf\n", left * right);
        return;
    }
    if (!strcmp(operator, "/"))
    {
        if (!right)
        {
            puts("Division by zero");
            return;
        }

        printf("%lf\n", left / right);
        return;
    }
    if (!strcmp(operator, "%"))
    {
        if (!right)
        {
            puts("Modulo by zero");
            return;
        }

        printf("%lf\n", fmod(left, right));
        return;
    }
    if (!strcmp(operator, "//"))
    {
        if (!right)
        {
            puts("Division by zero");
            return;
        }

        printf("%lld\n", (int64_t)(left / right));
        return;
    }
    if (!strcmp(operator, "**"))
    {
        printf("%lf\n", pow(left, right));
        return;
    }

    puts("Invalid operation");
}
