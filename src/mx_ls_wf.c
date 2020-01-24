#include "uls.h"

static char** write_to_arr(DIR *dir, char **s) {
	int i = 0;
	struct dirent *entry;

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_name[0] != '.')
		{
				
					s[i] = entry->d_name;
					i++;
		}	
	}
	s[i] = 0;
	return s;
}

void mx_ls_wf(DIR *dir, char **argv) {
	DIR *dir1;
	char **s;
	int size_dir = 0;
	int hres = 0;
	int count = 0;

	size_dir = mx_dir_size(dir);
	dir1 = opendir(argv[1]);
	s = malloc(sizeof(char *) * size_dir + 1);
	s = write_to_arr(dir1, s);
	hres = mx_count_for_print(s);
	count = mx_uls_len_name(hres);
	mx_ls_print(s, count, size_dir);
	free(s);
}
