#include "uls.h"

// static bool mx_check_dirs(char *dirs) {
// 	DIR *dir;

// 	if ((dir = opendir(dirs)))
// 	{
// 		return true;
// 	}
// 	closedir(dir);
// 	return false;
// }

bool mx_check_files(char *file) {
	struct stat fst;
	mode_t type;
	char restype;
	int st = 0;

	st = stat(file, &fst);
    type = fst.st_mode;
    restype = mx_type_of_file(type);
	if (restype == 0)
	{
		return true;
	}
	return false;
}

void mx_print_err_few(char **files) {
	int i = 0;
	DIR *dir;

	while (files[i]) {
		if (!mx_check_files(files[i]))
		{
			dir = opendir(files[i]);
			mx_check_dir(dir, files);
			i++;
		}
		i++;
	}
}
