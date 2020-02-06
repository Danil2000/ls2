#include "uls.h"

mode_t mx_get_mode(char *dirname) {
	struct stat fst;
    mode_t type;
    int st = 0;

    st = stat(dirname, &fst);
    type = fst.st_mode;
    return type;
}
