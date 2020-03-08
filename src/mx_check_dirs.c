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

void mx_not_file(char **argv, char *file) {
    char *str;
    int size = 0;

    mx_dirlen(file);
    size = mx_len_arr(argv);   
    if (errno == 2)
    {
        str = mx_strjoin("uls: ", file);
        perror(str);
        mx_strdel(&str);
        if (size > 2) {
            if (argv[1][0] == '-' && size == 3)
            {
                exit(1);
            }
            return;
        }
        exit(1);
    }
}

void mx_not_perm(char *file) {
    char *str;

    mx_dirlen(file);
    if (errno == 13)
    {
        str = mx_strjoin("uls: ", file);
        perror(str);
        mx_strdel(&str);
        exit(1);
    }
}

void mx_check_files(char *file, char **argv) {
    errno = 0;
    
    mx_not_file(argv, file);
    mx_not_perm(file);
}
