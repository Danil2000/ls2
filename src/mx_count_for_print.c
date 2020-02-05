#include "uls.h"

int mx_uls_len_name(int a) {
    int max_len = 0;

	max_len = ((a / 8) + 1) * 8;
    return max_len;
}

int mx_len_arr(char **s) {
    int i = 0;

    while (s[i]) {
        i++;
    }
    return i;
}
//длина максимального имени файла
int mx_count_for_print(char **s) {
    int i = 0;
    int loc = 0;
    int size = mx_len_arr(s);
    int res = 0;
    int lens[size];

    //size = mx_len_arr(s);
    //lens = (int *)malloc(sizeof(int) * 300);
    while(s[i]) {
        lens[i] = mx_strlen(s[i]);
        i++;
    }
    for (int c = 1; c < i; c++)
        if (lens[c] > lens[loc])
            loc = c;
    res = lens[loc];
    return res;
}
