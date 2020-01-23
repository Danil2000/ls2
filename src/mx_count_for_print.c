#include "mx_uls.h"

int mx_uls_len_name(int a) {
    int max_len = 0;

	max_len = ((a / 8) + 1) * 8;
    return max_len;
}

static int len_arr(char **s) {
    int i = 0;

    while (s[i]) {
        i++;
    }
    return i;
}

int mx_count_for_print(char **s) {
    int *lens = NULL;
    int i = 0;
    int loc = 0;
    int size = 0;
   
    size = len_arr(s);
    lens = malloc(sizeof(int *) * size);
    while(s[i]) {
        lens[i] = mx_strlen(s[i]);
        i++;
    }
    for (int c = 1; c < i; c++)
        if (lens[c] > lens[loc])
            loc = c;
    int res = lens[loc];
     
    free(lens);
    return res;
}
