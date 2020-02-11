#include "libmx.h"

// char *mx_strcat(char *restrict s1, const char *restrict s2) {
// 	size_t i,j;
// 	for (i = 0; s1[i] != '\0'; i++)
//         ;
//     for (j = 0; s2[j] != '\0'; j++)
//         s1[i+j] = s2[j];
//     s1[i+j] = '\0';
//     return s1;
// }

int mx_strlen_null(const char *s)
{
    int len = 0;

    if (s == NULL || !s)
        return 0;
    while (true)
    {
        if (s[len] == '\0' || !s[len])
        {
            return len;
        }
        len++;
    }
}


char *mx_strcat(char *restrict s1, const char *restrict s2)
{
    int len1 = mx_strlen_null(s1);
    int len2 = mx_strlen_null(s2);
    char *str = mx_strnew(len1 + len2);
    int i;

    if (s1 == NULL)
    {
        mx_strdel(&str);
        return NULL;
    }
    if (s2 == NULL)
    {
        mx_strdel(&str);
        return s1;
    }
    for (i = 0; i < len1 + len2; i++)
    {
        if (i < len1)
            str[i] = s1[i];
        if (i > len1 - 1)
            str[i] = s2[i - len1];
    }
    return str;
}

