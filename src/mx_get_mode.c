#include "uls.h"

mode_t* mx_f_m(mode_t *mode) {
	mode = (mode_t *)malloc(9 * sizeof(mode_t));
    mode[0] = S_IRUSR;
    mode[1] = S_IWUSR;
    mode[2] = S_IXUSR;
    mode[3] = S_IRGRP;
    mode[4] = S_IWGRP;
    mode[5] = S_IXGRP;
    mode[6] = S_IROTH;
    mode[7] = S_IWOTH;
    mode[8] = S_IXOTH;
    return mode;
}

mode_t mx_get_mode(struct stat fst) {
    mode_t type;

    type = fst.st_mode;
    return type;
}
