#include "uls.h"

static void mx_choose_flag(char *arg, char **args, DIR *dir) {
	if (!mx_strcmp(arg, "-F"))
		mx_ls_F(dir);
	if (!mx_strcmp(arg, "-R"))
		mx_ls_R(args[2]);
	if (!mx_strcmp(arg, "-d"))
		mx_ls_d(args);
	if (!mx_strcmp(arg, "-a"))
		mx_lsa(dir, args);
	if (!mx_strcmp(arg, "-A"))
		mx_ls_A(dir, args);
	if (!mx_strcmp(arg, "-1"))
		mx_ls_flag_one(dir, args);
}

static void choose_wf_d(char **argv) {
	DIR *dir;
	//mx_printstr("\x1b[34mTes
	if (argv[1][0] != '-') 	{
		dir = opendir(argv[1]);
		mx_check_dir(dir, argv);
		mx_ls_wf(dir, argv);
		exit(1);
	}
	if(mx_strcmp(argv[2], "") == 0) {
	 	mx_ls_d(argv);
		exit(1);
	}
}

int main(int argc, char **argv) {
	DIR *dir;

	if (argc == 1)
	{
		mx_ls_wd();
		return 0;
	}
	mx_check(argc, argv);
	choose_wf_d(argv);
	dir = opendir(argv[2]);
	mx_check_dir(dir, argv);
	mx_choose_flag(argv[1], argv, dir);
	closedir(dir);
	//system("leaks -q uls");
}
