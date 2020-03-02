#include "uls.h"

void mx_add_group_name_help(char **mas_for_print, int count_of_row, char **help_arr) {
    int i;
    char *space;
    char *help_v1;
    char *help_v2;

    for (i = 0; i < count_of_row; i++) {
        space = spaces(help_arr, help_arr[i], count_of_row);
        help_v1 = mx_strjoin(help_arr[i], space);
        mx_strdel(&space);
        help_v2 = mx_strjoin(help_v1, "  ");
        mx_strdel(&help_v1);
        help_v1 = mx_strjoin(mas_for_print[i], help_v2);
        mx_strdel(&mas_for_print[i]);
        mas_for_print[i] = mx_strdup(help_v1);
        mx_strdel(&help_v1);
        mx_strdel(&help_v2);
    }
    mx_del_strarr(&help_arr);
    return;
}

void mx_add_group_name(char **mas_for_print, int count_of_row, char **files) {
    int i;
    struct stat file;
    char **help_arr = NULL;

    help_arr= (char **)malloc(sizeof(char **) * (count_of_row + 1));
    for (i = 0; i < count_of_row; i++) {
        lstat(files[i], &file);
        help_arr[i] = mx_group_name(file);
    }
    help_arr[count_of_row] = NULL;
    mx_add_group_name_help(mas_for_print, count_of_row, help_arr);
    return;
}
