#include "uls.h"

void mx_add_time_help(char **mas_for_print, int count_of_row, char **help_arr) {
    int i;
    char *space;
    char *help_v1;
    char *help_v2;

    for (i = 0; i < count_of_row; i++) {
        space = spaces(help_arr, help_arr[i], count_of_row);
        help_v1 = mx_strjoin(space, help_arr[i]);
        help_v2 = mx_strjoin(help_v1, " ");
        help_v1 = mx_strjoin(mas_for_print[i], help_v2);
        mas_for_print[i] = mx_strdup(help_v1);
    }
    mx_strdel(&space);
    mx_strdel(&help_v1);
    mx_strdel(&help_v2);
    return;
}
static void add_hours(char **date, char *hours) {
    char **arr = mx_strsplit(hours, ':');
    char *tmp = *date;

    *date = mx_strjoin(tmp, " ");
    tmp = *date;
    *date = mx_strjoin(tmp, arr[0]);
    tmp = *date;
    *date = mx_strjoin(tmp, ":");
    tmp = *date;
    *date = mx_strjoin(tmp, arr[1]);
    mx_del_strarr(&arr);
}

static void add_day(char **date, char *day) {
    char *tmp = *date;
    char *day_tmp;

    day = mx_strdup(day);
    while (mx_strlen(day) < 2) {
        day_tmp = day;
        day = mx_strjoin(" ", day_tmp);
    }
    *date = mx_strjoin(tmp, day);
    mx_strdel(&day_tmp);
}

char *mx_time(struct stat file) {
    char *date = ctime(&file.st_mtimespec.tv_sec);
    char **date_arr = mx_strsplit(date, ' ');
    char *tmp;

    date = mx_strjoin(date_arr[1], " ");
    add_day(&date, date_arr[2]);
    if (time(NULL) - MX_HALF_YEAR < file.st_mtimespec.tv_sec)
        add_hours(&date, date_arr[3]);
    else {
        tmp = date;
        date = mx_strjoin(tmp, "  ");
        tmp = date;
        date_arr[4][4] = '\0';
        date = mx_strjoin(tmp, date_arr[4]);
    }
    mx_del_strarr(&date_arr);
    return date;
}

void mx_add_time(char **mas_for_print, int count_of_row, char **files) {
    int i;
    struct stat file;
    char **help_arr = (char **)malloc(sizeof(char **) * (count_of_row + 1));

    for (i = 0; i < count_of_row; i++) {
        lstat(files[i], &file);
        help_arr[i] = mx_time(file);
    }
    help_arr[count_of_row] = NULL;
    mx_add_time_help(mas_for_print, count_of_row, help_arr);
    mx_del_strarr(&help_arr);
    return;
}
