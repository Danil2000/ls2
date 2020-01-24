#include "uls.h"

static void mx_choose_flag(char *arg, char **args, DIR *dir) {
	if (!mx_strcmp(arg, "-F"))
		mx_ls_F(dir);
	if (!mx_strcmp(arg, "-R"))
		mx_ls_R(args[2]);
	if (!mx_strcmp(arg, "-d"))
		mx_ls_d(args);
	if (!mx_strcmp(arg, "-a"))
		mx_lsa(dir);
	if (!mx_strcmp(arg, "-A"))
		mx_ls_A(dir, args);
}

int main(int argc, char **argv) {
	DIR *dir;
	//mx_printstr("\x1b[34mTest\x1b[0m");
	if (argc == 1) 	{
		mx_ls_wd();
		return 0;
	}
	mx_check(argc, argv);
	if (argv[1][0] != '-') 	{
		dir = opendir(argv[1]);
		mx_check_dir(dir, argv);
		mx_ls_wf(dir, argv);
		return 0;
	}
	dir = opendir(argv[2]);
	mx_check_dir(dir, argv);
	mx_choose_flag(argv[1], argv, dir);
	closedir(dir);
}
