#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_LIST_LEN 100
#define MAX_STR_LEN 100

void lexicographical_sort(char **strs, uint8_t len);
uint8_t compare_str(const char *str1, const char *str2);

int main()
{
    char **strs, *ptr;
    uint8_t i;
    uint16_t len;

    strs = malloc(MAX_LIST_LEN * sizeof(char*));
    if (!strs)
    {
        fprintf(stderr, "Could not allocate %llu bytes of memory\n", MAX_LIST_LEN * sizeof(char*));
        abort();
    }

    for (i = 0; i < MAX_STR_LEN; i++)
    {
        strs[i] = malloc(MAX_STR_LEN);
        if (!strs[i])
        {
            fprintf(stderr, "Could not allocate %hu bytes of memory\n", MAX_STR_LEN);
            abort();
        }
    }

    while (1)
    {
        fputs("Enter the number of strings: ", stdout);
        scanf("%hu", &len);
        fflush(stdin);

        for (i = 0; i < len; i++)
        {
            fputs("Enter the string: ", stdout);
            fgets(strs[i], MAX_STR_LEN, stdin);

            ptr = strchr(strs[i], '\n');
            if (ptr)
                *ptr = '\0';
        }

        lexicographical_sort(strs, len);

        for (i = 0; i < len; i++)
            printf("String number %hu: %s\n", i + 1, strs[i]);
    }

    for (i = 0; i < MAX_LIST_LEN; i++)
        free(strs[i]);

    free(strs);
    return 0;
}

void lexicographical_sort(char **strs, uint8_t len)
{
    uint8_t i, j;
    char *tmp;

    for (i = 0; i < len; i++)
        for (j = i + 1; j < len; j++)
            if (compare_str(strs[i], strs[j]))
            {
                tmp = strs[i];
                strs[i] = strs[j];
                strs[j] = tmp;
            }
}

uint8_t compare_str(const char *str1, const char *str2)
{
    uint8_t len1, len2, i;

    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len1 <= len2)
    {
        for (i = 0; i < len1; i++)
        {
            if (str1[i] < str2[i])
                return 0;
            if (str1[i] > str2[i])
                return 1;
        }

        return 0;
    }

    for (i = 0; i < len2; i++)
    {
        if (str1[i] < str2[i])
            return 0;
        if (str1[i] > str2[i])
            return 1;
    }

    return 1;
}
