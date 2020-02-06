#include "uls.h"

static void dir_type(mode_t mode, char *dirname) {
	switch (mode & S_IFMT) {
    case S_IFCHR:
        mx_strcat(dirname, "c");
    case S_IFBLK:
        mx_strcat(dirname, "b");
    case S_IFIFO:
        mx_strcat(dirname, "p");
    case S_IFDIR:
       mx_strcat(dirname, "d");
    case S_IFLNK:
        mx_strcat(dirname, "l");
    case S_IFSOCK:
       mx_strcat(dirname, "s");
    case S_IFREG:
    	mx_strcat(dirname, "-");
    default:
       mx_strcat(dirname, " ");
    }
}

void mx_ls_l(char *dirname) {
	mode_t mode;

	mode = mx_get_mode(dirname);
	dir_type(mode, dirname);

}
