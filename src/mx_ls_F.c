#include "uls.h"

bool mx_is_dir(char *fname)
{
	struct stat f;
	stat(fname, &f);
	if (S_ISDIR(f.st_mode)) {
        return true;
    }
    return false;
}

void mx_ls_F(DIR* dir) {
	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL) {
		if (mx_is_dir(entry->d_name))
		{
			if (entry->d_name[0] != '.') {
				mx_printstr(entry->d_name);
				mx_printchar('/');
				mx_printchar('\n');
			}
		}
		if (entry->d_name[0] != '.') {
			mx_printstr(entry->d_name);
			mx_printchar('\n');
		}
	}
}
