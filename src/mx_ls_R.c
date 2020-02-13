#include "uls.h"

//она не срабатывает
bool mx_is_dir(char *fname) {
	struct stat f;
	stat(fname, &f);
	if (S_ISDIR(f.st_mode))
	{
		return true;
	}
	return false;
}

void mx_ls_R(char *fn) {
	DIR *dir;
	struct dirent *files;
	char *s;
	char *s1;
	DIR *dir1;

	dir = opendir(fn);
	dir1 = opendir(fn);
	mx_ls_wf(dir1, fn);
	files = readdir(dir);
	files = readdir(dir);
	while ((files = readdir(dir)) != NULL) {
		if (mx_is_dir(files->d_name)) {
			if (files->d_name[0] != '.') {
				mx_printchar('\n');
				s = mx_strjoin(fn, "/");
				s1 = mx_strjoin(s, files->d_name);
				mx_printstr(s1);
				mx_printchar(':');
				mx_printchar('\n');
				mx_ls_R(s1);
				free(s);
				free(s1);
			}
		}
	}
	closedir(dir);
}
