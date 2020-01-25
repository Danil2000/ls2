#include "uls.h"

void mx_ls_wd() {
	DIR *dir;
	DIR *dir1;
	t_ls *ls;
	
	
	dir = opendir(".");
	ls = malloc(sizeof(ls));
	ls->size_dir = mx_dir_size(dir);
	dir1 = opendir(".");
	ls->s = malloc(sizeof(char *) * ls->size_dir + 1);
	ls->s = mx_write_to_arr(dir1, ls->s);
	ls->hres = mx_count_for_print(ls->s);
	ls->count = mx_uls_len_name(ls->hres);
	mx_ls_print(ls->s, ls->count, ls->size_dir);
}
