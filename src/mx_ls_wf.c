#include "uls.h"

char** mx_write_to_arr(DIR *dir, char **s) {
	int i = 0;
	struct dirent *entry;

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_name[0] != '.') {
			s[i] = mx_strdup(entry->d_name);
			i++;
		}
	}
	s[i] = NULL;
	return s;
}

void mx_ls_wf(DIR *dir, char *argv) {
	DIR *dir1;
	int size_dir = 0;
	char **s = NULL;
	int hres = 0;
	int count = 0;

	size_dir = mx_dir_size(dir, 0);
	dir1 = opendir(argv);
	s = (char**)malloc(sizeof(char **) * (size_dir + 1));
	s = mx_write_to_arr(dir1, s);
	hres = mx_count_for_print(s);
	count = mx_uls_len_name(hres);
	mx_get_width(s, count, 0);
	mx_del_strarr(&s);
	closedir(dir1);
}
