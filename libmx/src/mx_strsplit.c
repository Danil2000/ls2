 #include "libmx.h"

static bool count_border(char *s, char c, char **start, char **end) {
    for (*start = s; **start == c; (*start)++)
        if (**start =='\0')
            return false;
    for (*end = *start; **end != c && **end != '\0'; (*end)++)
    ;
    return true;
}


static char **strsplit_dop(const char *s, char c, int count, char **arr) {
    char *str= (char *)s;
    char *start = NULL;
    char *end = NULL;

    for (int a = 0; a < count && count_border(str, c,&start, &end); a++) {
        int d = 0;

        arr[a] = mx_strnew((size_t)(end - start + 1));
        for (str = start; str != end; str++) {
            arr[a][d] = *str;
            d++;
        }
        str = end + 1;
    }
    return arr;
}

char **mx_strsplit(const char *s, char c) {
    char **arr = NULL;
    int count = 0;

    if (!s)
        return NULL;
    count = mx_count_words(s, c);
    arr = (char **) malloc((count+ 1) * sizeof(char *) );
    if (count == 1) {
        arr[0] = mx_strdup(s);
        arr[1] = NULL;
        return arr;
    }
    arr = strsplit_dop(s, c, count, arr);
    arr[count] = NULL;
    return arr;
}
