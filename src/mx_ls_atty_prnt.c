#include "uls.h"

//вывод с кат -е без папок и флагов
void mx_ls_prnt_cat_e_no_dir(int size_dir, char **s, DIR *dir, DIR *dir1) {
	size_dir = mx_dir_size(dir, 0);
	s = malloc(sizeof(char *) * (size_dir + 1));
	s = mx_write_to_arr(dir1, s);
	mx_bubble_sort(s, size_dir);
	mx_print_flag_one(s, size_dir);
	closedir(dir1);
	mx_del_strarr(&s);
	exit(1);
}

void mx_prnt_aAf(int size_dir, char **s, DIR *dir, DIR *dir1, char **argv)
{
	size_dir = mx_dir_size(dir, ls_is_flg_aAf(argv));
	if (ls_is_flg_A(argv))
		size_dir -= 2;
	s = malloc((sizeof(char *) * size_dir) + 1);
	s = mx_ls_chs_sm_flg(dir1, s, argv);
	mx_bubble_sort(s, size_dir);
	mx_print_flag_one(s, size_dir);
	closedir(dir1);
	mx_del_strarr(&s);
	exit(1);
}

void mx_ls_prnt_flg_one(int size_dir, char **s, DIR *dir, DIR *dir1) {
	size_dir = mx_dir_size(dir, 0);
	s = malloc((sizeof(char *) * size_dir) + 1);
	s = mx_write_to_arr(dir1, s);
	mx_bubble_sort(s, size_dir);
	mx_print_flag_one(s, size_dir);
	mx_del_strarr(&s);
	exit(1);
}
