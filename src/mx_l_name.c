#include "uls.h"

char *mx_link(char *file) {
    char buf[1024];
    int len;
    char *link;
    int i;
    char *tmp;

    len = readlink(file, buf, 1024);
    if (len == -1)
        return NULL;
    link = mx_strnew(len);
    for (i = 0; i < len; i++)
        link[i] = buf[i];
    tmp = link;
    //mx_strdel(&link);
    link = mx_strjoin(" -> ", tmp);
    mx_strdel(&tmp);
    return link;
}

void mx_add_name(char **mas_for_print, int count_of_row, char **name, char **files) {
    char *link;
    char *help_v;
    char *help_v_1;

    for (int i = 0; i < count_of_row; i++) {
        link = mx_link(files[i]);
        if (link != NULL) {
            help_v = mx_strjoin(name[i], link);
            help_v_1 = mx_strjoin(mas_for_print[i], help_v);
            mx_strdel(&mas_for_print[i]);
            mas_for_print[i] = help_v_1;
        }
        else {
            help_v = mx_strjoin(mas_for_print[i] ,name[i]);
            mx_strdel(&mas_for_print[i]);
            mas_for_print[i] = mx_strdup(help_v);
            mx_strdel(&help_v);
        }
        mx_strdel(&help_v);
        mx_strdel(&link);
    }
    return;
}
