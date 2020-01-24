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
	t_ls *ls;

	ls = malloc(sizeof(ls));
	ls->size_dir = mx_dir_size(dir);
	dir1 = opendir(argv[1]);
	ls->s = malloc(sizeof(char *) * ls->size_dir + 1);
	ls->s = write_to_arr(dir1, ls->s);
	ls->hres = mx_count_for_print(ls->s);
	ls->count = mx_uls_len_name(ls->hres);
	mx_ls_print(ls->s, ls->count, ls->size_dir);
	//free(ls);
}
