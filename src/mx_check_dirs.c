#include "uls.h"

int mx_dirlen(char *dir) {
    DIR *dd;
    int len = 0;
    struct dirent *entry;

    dd = opendir(dir);
    if (dd == NULL && errno == 20)
        return -1;
    if (dd == NULL)
        return -2;
    while ((entry = readdir(dd)) != NULL)
        len++;
    closedir(dd);
    return len;
}

static void not_file(char **argv, char *file) {
    char *str;

    mx_dirlen(file);
    if (errno == 2)
    {
        if (argv[1][0] != '-')
        {
            str = mx_strjoin("uls: ", &argv[1][0]);
            perror(str);
            mx_strdel(&str);
            exit(1);
        }
        else {
            str = mx_strjoin("uls: ", &argv[2][0]);
            perror(str);
            mx_strdel(&str);
            exit(1);
        }
    }
}

static void not_perm(char **argv, char *file) {
    char *str;

    mx_dirlen(file);
    if (errno == 13)
    {
        if (argv[1][0] != '-')
        {
            str = mx_strjoin("uls: ", &argv[1][0]);
            perror(str);
            mx_strdel(&str);
            exit(1);
        }
        else {
            str = mx_strjoin("uls: ", &argv[2][0]);
            perror(str);
            mx_strdel(&str);
            exit(1);
        }
    }
}

void mx_check_files(char *file, char **argv) {
    errno = 0;
    
    not_file(argv, file);
    not_perm(argv, file);
}
