#include "uls.h"

bool mx_is_dir(char *fname) {
    struct stat f;

    stat(fname, &f);
    if (S_ISDIR(f.st_mode)) {
        return true;
    }
    return false;
}
