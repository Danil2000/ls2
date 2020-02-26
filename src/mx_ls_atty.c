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

void mx_ls_atty(char **argv) {
	DIR *dir = NULL;
	char **s = NULL;
	int size_dir = 0;
	DIR *dir1 = NULL;
	char *c;

	c = ls_choose(argv);
	dir = opendir(c);
	dir1 = opendir(c);
	if (!argv[1])
		mx_ls_prnt_cat_e_no_dir(size_dir, s, dir, dir1);
	if (ls_is_flg_aAf(argv) == 1)
		mx_prnt_aAf(size_dir, s, dir, dir1, argv);
	if (argv[1][0] != '-')
		mx_ls_prnt_flg_one(size_dir, s, dir, dir1);
}
