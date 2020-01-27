#include "uls.h"

static char type_of_file(mode_t mode) {
    switch (mode & S_IFMT) {
    case S_IFCHR:
        return "c";
    case S_IFBLK:
        return "b";
    case S_IFIFO:
        return "c";;
    case S_IFDIR:
       return "d";
    case S_IFLNK:
        return "c";
    case S_IFSOCK:
       return "s";
    default:
        return;
    }
}

void mx_ls_G(char *filename) {
	
}