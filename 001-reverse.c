#include <stdio.h> // printf, scanf
#include <stdlib.h> // malloc, free
#include <string.h> // strchr

#define STR_LEN 513

void reverse(char *str)
{
    // reverses the string

    // unsigned long long = size_t = uint64_t
    size_t size = strlen(str);
    if (size <= 1)
        return;

    char *end = str + size - 1;
    char tmp;
    for (; str < end; str++, end--)
    {
        // swap characters
        tmp = *str;
        *str = *end;
        *end = tmp;
    }
}

int main()
{
    char *str = malloc(STR_LEN);

    printf("Enter your string: ");
    fgets(str, STR_LEN, stdin);

    // remove newline
    char *ptr = strchr(str, '\n');
    if (ptr)
        *ptr = '\0';

    printf("Your string: %s\n", str);
    reverse(str);
    printf("Your reversed string: %s\n", str);

    free(str);
    return EXIT_SUCCESS;
}
