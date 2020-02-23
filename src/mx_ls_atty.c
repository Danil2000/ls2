#include "uls.h"

static char *ls_choose(char **argv) {
	if (!argv[1])
		return ".";
	else {
		if (argv[1][0] != '-')
			return argv[1];
		else
			return argv[2];	
	}
	return NULL;
}

//вывод некоторых флагов
static char **ls_chs_sm_flg(DIR *dir, char **s, char **argv) {
	if ((argv[1][1] == 'a') || (argv[1][1] == 'f'))
				mx_write_to_arr_a(dir, s);
	if (argv[1][1] == 'A')
		mx_write_to_arr_A(dir, s);
	if (argv[1][1] == 'p')
		mx_write_p(dir, s);
	return s;
}

static bool ls_is_flg_aAf(char **argv) {
	if ((argv[1][1] == 'a') || (argv[1][1] == 'f') || (argv[1][1] == 'A'))
		return 1;
	else
		return 0;
}

static bool ls_is_flg_A(char **argv) {
	if (argv[1][1] == 'A')
		return 1;
	else
		return 0;
}

void mx_ls_atty(char **argv) {
	DIR *dir = NULL;
	char **s = NULL;
	int size_dir = 0;
	DIR *dir1 = NULL;
	char *c;


	//mx_printchar(argv[1][0]);

	c = ls_choose(argv);
	dir = opendir(c);
	dir1 = opendir(c);
	if (!argv[1]) { //вывод с кат -е без папок и флагов
		size_dir = mx_dir_size(dir, 0);
		s = malloc((sizeof(char *) * size_dir) + 1);
		s = mx_write_to_arr(dir1, s);
		mx_bubble_sort(s, size_dir);
		mx_print_flag_one(s, size_dir);
		closedir(dir1);
	}
	//отрабатываем флаги аАф
	if (ls_is_flg_aAf(argv) == 1) {
		size_dir = mx_dir_size(dir, ls_is_flg_aAf(argv));
		if (ls_is_flg_A(argv))
			size_dir -= 2;
		s = malloc((sizeof(char *) * size_dir) + 1);
		s = ls_chs_sm_flg(dir1, s, argv);
		mx_bubble_sort(s, size_dir);
		mx_print_flag_one(s, size_dir);
		closedir(dir1);
	}
	if (argv[1][0] != '-') {
		size_dir = mx_dir_size(dir, 0);
		s = malloc((sizeof(char *) * size_dir) + 1);
		s = mx_write_to_arr(dir1, s);
		mx_bubble_sort(s, size_dir);
		mx_print_flag_one(s, size_dir);
	}
	mx_del_strarr(&s);
	
}
