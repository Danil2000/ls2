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

static DIR *dirs(DIR *dir, char *c, char **argv) {
	if (argv[2] == NULL || argv[1] == NULL)
		dir = opendir(".");
	else
		dir = opendir(c);

	return dir;
}

static DIR *dirs1(DIR *dir1, char *c, char **argv) {
	if (argv[2] == NULL)
		dir1 = opendir(".");
	else
		dir1 = opendir(c);
	return dir1;
}

void mx_ls_atty(char **argv) {
	DIR *dir = NULL;
	char **s = NULL;
	int size_dir = 0;
	DIR *dir1 = NULL;
	char *c;
	char **ss = NULL;

	c = ls_choose(argv);
	dir = dirs(dir, c, argv);

	dir1 = dirs1(dir1, c, argv);
	if (mx_len_arr(argv) == 1)
	{
		mx_ls_prnt_flg_one(size_dir, s, dir, dir1);
		return;
	}
	else {
		mx_chk(argv, ss);
		if(!mx_is_dir(argv[1]) && argv[1][0] != '-') {
			mx_print_with_new_line(argv[1]);
			return;
		}
		if (!argv[1])
			mx_ls_prnt_cat_e_no_dir(size_dir, s, dir, dir1);
		if (mx_ls_is_flg_aAf(argv) == 1)
			mx_prnt_aAf(size_dir, s, dir, dir1, argv);
		if (argv[1][0] != '-')
			mx_ls_prnt_flg_one(size_dir, s, dir, dir1);
		if (argv[1][1] == 'l')
			mx_ls_l(dir1, argv);
	}
	
}
