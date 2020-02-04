#include "uls.h"

static void choose_flag(char *arg, char **args, DIR *dir, int size_dir) {
	// if (!mx_strcmp(arg, "-R"))
	// 	mx_ls_R(args[2]);
	if (!mx_strcmp(arg, "-d"))
		mx_ls_d(args);
	if (!mx_strcmp(arg, "-a"))
		mx_lsa(dir, args);
	if (!mx_strcmp(arg, "-A"))
		mx_ls_A(dir, args);
	if (!mx_strcmp(arg, "-1"))
		mx_ls_flag_one(dir);
	if (!mx_strcmp(arg, "-G"))
		mx_ls_G(dir, size_dir);
	if (!mx_strcmp(arg, "-f"))
		mx_ls_f(dir, args);
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
		mx_lsa(dir, args);
}

static void choose_wf_d(char **argv) {
	DIR *dir;
	DIR *dir1;
	int size_dir = 0;

	if (argv[1][0] != '-') 	{
		dir = opendir(argv[1]);
		mx_check_dir(dir, argv);
		mx_ls_wf(dir, argv);
		exit(1);
	}
	if (argv[1][0] == '-' && argv[2] == NULL)
	{
		dir = opendir(".");
		size_dir = mx_dir_size(dir);
		dir1 = dir;
		choose_flag(argv[1], argv, dir1, size_dir);
		exit(1);
	}
	if(mx_strcmp(argv[2], "") == 0) {
	 	mx_ls_d(argv);
		exit(1);
	}
}

int main(int argc, char **argv) {
	DIR *dir;
	DIR *dir1;
	int atty = 0;
	int size_dir = 0;
	
	atty = isatty(1);
	if (atty == 0) {
		mx_printstr(argv[1]);
	} 
	if (argc == 1) {
		mx_ls_wd();
		return 0;
	}
	if (argc > 3) {
		mx_few_dirs(argv);
		return 0;
	}
	choose_wf_d(argv);
	mx_check(argc, argv);
	mx_check(argc, argv);
	dir = opendir(argv[2]);
	size_dir = mx_dir_size(dir);
	dir1 = dir;
	mx_check_dir(dir1, argv);
	choose_combination(argv[1], argv, dir1);
	choose_flag(argv[1], argv, dir1, size_dir);
	system("leaks -q uls");
}
