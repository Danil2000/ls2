#include "uls.h"

void mx_choose_flag(char *arg, char **args, DIR *dir, int argc) {
	if (!mx_strcmp(arg, "-R"))
		mx_ls_R(args[2], args);
	if (!mx_strcmp(arg, "-d"))
		mx_ls_d(args);
	if (!mx_strcmp(arg, "-a"))
		mx_lsa(dir, args[2]);
	if (!mx_strcmp(arg, "-A"))
		mx_ls_A(dir, args);
	if (!mx_strcmp(arg, "-1"))
		mx_ls_flag_one(dir, args, args[2]);
	if (!mx_strcmp(arg, "-m"))
		mx_ls_m(dir, args);
	//  if (!mx_strcmp(arg, "-G"))
	// 	mx_ls_G(args[2]);
	if (!mx_strcmp(arg, "-f"))
		mx_ls_f(dir, args);
	if (!mx_strcmp(arg, "-p"))
		mx_ls_p(dir, args);
	argc = 0;
	if (!mx_strcmp(arg, "-l"))
		mx_ls_l(dir, args);
}

static void choose_combination(char *arg, char **args, DIR *dir) {
	if (!mx_strcmp(arg, "-a1") || !mx_strcmp(arg, "-1a"))
		mx_ls_a_one(dir, args);
	if (!mx_strcmp(arg, "-A1") || !mx_strcmp(arg, "-1A"))
		mx_ls_A_one(dir, args);
	if (!mx_strcmp(arg, "-fa") || !mx_strcmp(arg, "-af"))
		mx_ls_f(dir, args);
	if (!mx_strcmp(arg, "-fA") || !mx_strcmp(arg, "-Af"))
		mx_ls_f(dir, args);
	if (!mx_strcmp(arg, "-aA") || !mx_strcmp(arg, "-Aa"))
		mx_lsa(dir, args[2]);
	if (!mx_strcmp(arg, "-lm"))
		mx_ls_m(dir, args);
	if (!mx_strcmp(arg, "-ma"))
		mx_ls_ma(dir, args);
	if (!mx_strcmp(arg, "-Ra"))
		mx_ls_R(arg, args);
	if(args[1][2] == 'd' || args[1][1] == 'd') {
		mx_ls_d(args);
	}
}

static void choose_wf_d(char **argv, int argc) {
	DIR *dir;
	
	if (argv[1][0] != '-') 	{
		dir = opendir(argv[1]);
		mx_check_dir(argv);
		mx_ls_wf(dir, argv[1]);
		system("leaks -q uls");
		exit(1);
	}
	if (argv[1][0] == '-' && argv[2] == NULL) {
		dir = opendir(".");
		mx_choose_flag(argv[1], argv, dir, argc);
		system("leaks -q uls");
		exit(1);
	}
	if(mx_strcmp(argv[2], "") == 0) {
	 	mx_ls_d(argv);
		exit(1);
	}
	system("leaks -q uls");
}

static void ls_isatty_prnt_1_clm(char **argv, int argc) {
	//isatty если перенаправляет в терминал, то единица, иначе ноль
	if (isatty(1) == 0) {
		if (argc > 2 && argv[1][0] != '-')
			mx_few_dirs(argv);
		else
			mx_ls_atty(argv);
		//system("leaks -q uls");
		exit(1);
	}
	if (argc == 1) {
		mx_ls_wd();
		exit(1);
	}
	if (argc > 2 && argv[1][0] != '-') {
		mx_few_dirs(argv);
		system("leaks -q uls");
		exit(1);
	}
}

int main(int argc, char **argv) {
	DIR *dir;
	
	ls_isatty_prnt_1_clm(argv, argc);
	choose_wf_d(argv, argc);
	if (argv[1][0] == '-')
	{
		mx_check(argc, argv);
		system("leaks -q uls");
	}
	mx_check(argc, argv);
	dir = opendir(argv[2]);
	//mx_print_strarr(argv, " ");
	mx_check_dir(argv);
	choose_combination(argv[1], argv, dir);
	mx_choose_flag(argv[1], argv, dir, argc);
	system("leaks -q uls");
}
