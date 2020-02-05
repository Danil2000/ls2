#include "uls.h"

char mx_type_of_file(mode_t mode) {
    switch (mode & S_IFMT) {
    case S_IFCHR:
        return 'c';
    case S_IFBLK:
        return 'b';
    case S_IFIFO:
        return 'p';
    case S_IFDIR:
       return 'd';
    case S_IFLNK:
        return 'l';
    case S_IFSOCK:
       return 's';
    default:
        return 0;
    }
}

void mx_ls_G(DIR *dir, int size_dir) {
    struct stat fst;
    mode_t type;
    int st = 0;
    char reztype;
    char** s = NULL;
    int i = 1;

    s = malloc(sizeof(char *) * size_dir + 1);
    s = mx_write_to_arr(dir, s);
    while (s[i]) {
        st = stat(s[i], &fst);
        type = fst.st_mode;
        reztype = mx_type_of_file(type);
        choose_color(reztype, s[i]);
        i++;
    }
}
