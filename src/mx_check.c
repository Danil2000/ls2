#include "uls.h"

void mx_check_dir(char **argv) {
	char **s_dir = NULL;
	char **s_files = NULL;
	char **s = NULL;

	if(argv[3] != NULL)
		return;
	s = mx_chk(argv, s);
	s_dir = mx_check_dirs(s_dir, s);
	if (argv[1][1] != 'l') {
		s_files = mx_check_files_1(s_files, s);
		mx_print_strarr(s_files, "   ");
		return;
	}
	mx_del_strarr(&s_dir);
	mx_del_strarr(&s);
}

void mx_check(int argc, char **argv) {
	char *str;
	if (mx_check_flags(argv[1][1]) == 0) {
		str = mx_strnew(1);
		str = mx_strjoin("uls: illegal option -- ", &argv[1][1]);
		mx_check_flags(argv[1][1]);
		mx_printerr(str);
		mx_printerr("\n");
		mx_printerr("usage uls [-laApR1dmf] [file ...]");
		mx_printerr("\n");
		exit(1);
	}
	if (argc < 1) {
		perror("incorect argument");
		exit(1);
	}
}
