#include "uls.h"

char **mx_write_p(DIR *dir, char** s) {
	int i = 0;
	struct dirent *entry;

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_name[0] != '.') {
			if (entry->d_name[i+1])	{
				if (!mx_is_dir(entry->d_name)) {
					s[i] = mx_strdup(entry->d_name);
					i++;
				}
				else {
					s[i] = mx_strjoin(entry->d_name, "/");
					i++;
				}
			}
		}	
	}
	s[mx_len_arr(s)] = NULL;
	return s;
}

void mx_ls_p(DIR *dir, char **argv) {
	DIR *dir1;
	int size_dir = 0;
	char **s = NULL;
	int hres = 0;
	int count = 0;

	size_dir = mx_dir_size(dir, 0);
	if (!argv[2])
		dir1 = opendir(".");
	else
		dir1 = opendir(argv[2]);
	s = (char**)malloc(sizeof(char **) * (size_dir + 1));
	s = mx_write_p(dir1, s);
	hres = mx_count_for_print(s);
	count = mx_uls_len_name(hres);
	mx_get_width(s, count, 0);
	closedir(dir1);
	mx_del_strarr(&s);
}
