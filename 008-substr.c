#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 1001

// return 1 if str1 == str2 and 0 otherwise
int cmp_str(char *str1, char *str2, size_t size)
{
    for (size_t i = 0; i < size; i++)
        if (str1[i] != str2[i])
            return 0;
    return 1;
}

size_t find_sub(char *str, char *sub)
{
    size_t str_size = strlen(str);
    size_t sub_size = strlen(sub);

    if (str_size < sub_size)
        return 0;
    if (str_size == sub_size)
        return cmp_str(str, sub, str_size);

    size_t step = str_size - sub_size + 1;
    size_t count = 0;
    for (size_t i = 0; i < step; i++)
        if (cmp_str(str + i, sub, sub_size))
            count++;
    return count;
}

int main()
{
    char *str = malloc(STR_SIZE);
    printf("Enter your string: ");
    fgets(str, STR_SIZE, stdin);

    // remove newline
    char *ptr = strchr(str, '\n');
    if (ptr)
        *ptr = '\0';

    char *sub = malloc(STR_SIZE);
    printf("Enter your substring: ");
    fgets(sub, STR_SIZE, stdin);

    // remove newline
    ptr = strchr(sub, '\n');
    if (ptr)
        *ptr = '\0';

    printf("Substring count: %llu\n", find_sub(str, sub));

    free(str);
    free(sub);
    return 0;
}
