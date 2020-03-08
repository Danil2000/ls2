#include "uls.h"

static void ls_isatty_prnt_1_clm(char **argv, int argc) {
	if (isatty(1) == 0) {
		if (argc > 2 && argv[1][0] != '-')
			mx_few_dirs(argv);
		else
			mx_ls_atty(argv);
		exit(1);
	}
	if (argc > 2 && argv[1][0] != '-') {
		mx_few_dirs(argv);
		exit(1);
	}
}


static void wf_atty(char **argv, int argc) {
	if (argc == 1) {
		if (isatty(1) == 0)
			mx_ls_atty(argv);
		mx_ls_wd();
		exit(1);
	}
}

static void choose_wf_d(char **argv, int argc) {
	DIR *dir;

	wf_atty(argv, argc);	
	if (argv[1][0] != '-') {
		dir = opendir(argv[1]);
		mx_check_dir(argv);
		mx_ls_wf(dir, argv[1]);
		exit(1);
	}
	if (argv[1][0] == '-' && argv[2] == NULL) {
		dir = opendir(".");
		mx_choose_flag(argv[1], argv, dir);
		exit(1);
	}
	if (mx_strcmp(argv[2], "") == 0) {
		mx_ls_d(argv);
		exit(1);
	}
}

void mx_choose(char **argv, int argc) {
	if (argc == 1) {
		choose_wf_d(argv, argc);
		return;
	}
	if (argv[1][0] == '-') {
		mx_check(argc, argv);
	}
	ls_isatty_prnt_1_clm(argv, argc);
	if (argv[1][0] == '-') {
		mx_not_file(argv, argv[2]);
		mx_not_perm(argv[2]);
		mx_check(argc, argv);
	}
	else {
		mx_not_file(argv, argv[1]);
		mx_not_perm(argv[2]);
		choose_wf_d(argv, argc);
	}
}
