#include "uls.h"

char **mx_write_to_arr_A(DIR *dir,char **s) {
	struct dirent *entry;
	int i =0;

	while ((entry = readdir(dir)) != NULL) {
		if (mx_strcmp(entry->d_name , ".") && mx_strcmp(entry->d_name , ".."))
		{
			s[i] = entry->d_name;
			i++;
		}
	}
	s[i] =0;
	return s;
}

void mx_ls_A(DIR *dir, char **argv) {
	DIR *dir1;
	t_ls *ls = NULL;

	ls = malloc(sizeof(ls));
	ls->size_dir = mx_dir_size(dir);
	dir1 = opendir(argv[2]);
	ls->s = malloc(sizeof(char *) * ls->size_dir + 1);
	ls->s = mx_write_to_arr_A(dir1, ls->s);
	ls->hres = mx_count_for_print(ls->s);
	ls->count = mx_uls_len_name(ls->hres);

	mx_get_width(ls->s, ls->count); //вывод колонок
	//mx_ls_print(ls->s, ls->count, ls->size_dir);
	//free(ls->s);
}
