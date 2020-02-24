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

int mx_dirlen(char *dir) {
    DIR *dd;
    int len = 0;
    struct dirent *entry;

    dd = opendir(dir);
    if (dd == NULL && errno == 20)
        return -1;
    if (dd == NULL)
        return -2;
    while ((entry = readdir(dd)) != NULL)
        len++;
    closedir(dd);
    return len;
}

void mx_check_files(char *file) {
	errno = 0;
	char *str;
    mx_dirlen(file);
    if (errno == 2) {
        str = mx_strjoin("uls: ", file);
        perror(str);
        mx_strdel(&str);
    }
}

// void mx_print_err_few(char **files) {
// 	int i = 0;
// 	DIR *dir;

// 	while (files[i]) {
// 		if (!mx_check_files(files[i]))
// 		{
// 			dir = opendir(files[i]);
// 			mx_check_dir(dir, files);
// 			i++;
// 		}
// 		i++;
// 	}
// }
