#include "uls.h"

bool mx_is_dir(char *fname)
{
	struct stat fst;
	mode_t type;
	int st = 0;
	char reztype;

	st = stat(fname, &fst);
	type = fst.st_mode;
	reztype = mx_type_of_file(type);
	if (reztype == 'd') {
        return true;
    }
    return false;
}

void mx_ls_R(char *fn) {
	DIR *dir;
	struct dirent *files;
    char *s;
    char *s1;

	dir = opendir(fn);
	files = readdir(dir);
	free(files);
	files = readdir(dir);
	while ((files = readdir(dir)) != NULL) {
		if (mx_is_dir(files->d_name))
		{
			if (files->d_name[0] != '.') {
				mx_printstr(files->d_name);
				mx_printchar(':');
				mx_printchar('\n');
           		s = mx_strjoin(fn, "/");
           		s1 = mx_strjoin(s, files->d_name);
            	mx_ls_R(s1);
            }
		}
		else {
			if (files->d_name[0] != '.') {
				mx_printstr(files->d_name);
				mx_printstr("       ");
			}
		}
	}
}
