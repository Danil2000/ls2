#include "uls.h"

static void S_x_s(struct stat file, char **str) {
    char *tmp;

    tmp = *str;
    if ((file.st_mode & S_IXGRP) == S_IXGRP) {
        if ((file.st_mode & S_ISGID) == S_ISGID)
            *str = mx_strjoin(tmp, "s");
        else
            *str = mx_strjoin(tmp, "x");
    }
    else {
        if ((file.st_mode & S_ISGID) == S_ISGID)
            *str = mx_strjoin(tmp, "S");
        else
            *str = mx_strjoin(tmp, "-");
    }
    //mx_strdel(&tmp);
}

void mx_group_permissions(struct stat file, char **str) {
    char *tmp = *str;

    if ((file.st_mode & S_IRGRP) == S_IRGRP)
        *str = mx_strjoin(tmp, "r");
    else
        *str = mx_strjoin(tmp, "-");
    //mx_strdel(&tmp);
    tmp = *str;
    if ((file.st_mode & S_IWGRP) == S_IWGRP)
        *str = mx_strjoin(tmp, "w");
    else
        *str = mx_strjoin(tmp, "-");
    //mx_strdel(&tmp);
    S_x_s(file, str);
}
