#include "uls.h"

bool mx_is_dir(char *fname) {
	struct stat fst;
	mode_t type;
	char restype;
	int st = 0;

	st = stat(fname, &fst);
    type = fst.st_mode;
    restype = mx_type_of_file(type);

    if (restype == 'd')
    	return 1;
    return 0;
}
