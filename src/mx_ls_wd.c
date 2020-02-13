#include "uls.h"

void mx_ls_wd() {
	DIR *dir;
	DIR *dir1;
	int size_dir = 0;
	char **s;
	int hres = 0;
	int count  = 0;

	dir = opendir(".");
	size_dir = mx_dir_size(dir, 0);
	dir1 = opendir(".");
	s = malloc(sizeof(char *) * size_dir + 1);
	s = mx_write_to_arr(dir1, s);
	hres = mx_count_for_print(s);
	count = mx_uls_len_name(hres);
	
	//mx_ls_print(ls->s, ls->count, ls->size_dir);
	mx_get_width(s, count, 0);
	mx_del_strarr(&s);
}
