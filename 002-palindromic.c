#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_INPUT_LEN 512

uint8_t is_palindromic(const char *str);

int main()
{
    char *str, *ptr;

    str = malloc(MAX_INPUT_LEN);
    if (!str)
    {
        fprintf(stderr, "Could not allocate %hu bytes of memory\n", MAX_INPUT_LEN);
        abort();
    }

    while (1)
    {
        fputs("Enter the string: ", stdout);
        fgets(str, MAX_INPUT_LEN, stdin);

        ptr = strchr(str, '\n');
        if (ptr)
            *ptr = '\0';

        puts(is_palindromic(str) ? "The string is Palindromic" : "The string is not Palindromic");
    }

    free(str);
    return 0;
}

uint8_t is_palindromic(const char *str)
{
    uint16_t len, i, j;

    len = strlen(str);
    if (len <= 1)
        return 1;

    for (i = 0, j = len - 1; i < len / 2; i++, j--)
        if (str[i] != str[j])
            return 0;

    return 1;
}
