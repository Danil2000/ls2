#include "uls.h"

char *spaces(char** files, char *file, int counter) {
	char *space = NULL;
	int max = 0;
	int i = 0;

	for (i = 0; i < counter; i++) {
        if (mx_strlen(files[i]) > max)
            max = mx_strlen(files[i]);
    }
    space = mx_strnew(max - mx_strlen(file));
    for (i = 0; i < (max - mx_strlen(file)); i++) {
        space[i] = ' ';
    }
    if (space == NULL)
        return "";
    return space;
}

void mx_add_count_link_help(char **arr_print, int count, char **links_arr) {
    int i;
    char *space;
    char *help_v1;
    char *help_v2;

    for (i = 0; i < count; i++) {
        space = spaces(links_arr, links_arr[i], count);
        help_v1 = mx_strcat(space, links_arr[i]);
        //mx_strdel(spaces);
        help_v2 = mx_strcat(help_v1, " ");
        mx_strdel(&help_v1);
        help_v1 = mx_strcat(arr_print[i], help_v2);
        mx_strdel(&arr_print[i]);
        arr_print[i] = mx_strdup(help_v1);
        mx_strdel(&help_v1);
        mx_strdel(&help_v2);
    }
    mx_del_strarr(&links_arr);
    return;
}
