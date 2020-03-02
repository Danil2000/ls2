#include "uls.h"

static void print_chk_err(char **s_dir, char **argv, int i, char *str) {
	while (s_dir[i]) {
		if (!mx_is_dir(s_dir[i])) {
			str = mx_strnew(1);
			if (argv[1][0] == '-') {
				str = mx_strjoin("uls: ", &argv[2][0]);
				perror(str);
				mx_strdel(&str);
				exit(1);
			}
			else {
				str = mx_strjoin("uls: ", &argv[1][0]);
				perror(str);
				mx_strdel(&str);
				exit(1);
			}
		}
		i++;
	}
}

void mx_check_dir(char **argv) {
	char *str = NULL;
	char **s_dir = NULL;
	int i = 0;
	char **s_files = NULL;
	char **s = NULL;

	s = mx_chk(argv, s);
	s_dir = mx_check_dirs(s_dir, s);
	if (s_dir[0] != NULL) {
		print_chk_err(s_dir, argv, i, str);
	}
	else {
		s_files = mx_check_files_1(s_files, s);
		mx_print_strarr(s_files, "   ");
		exit(0);
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
		mx_printerr("usage uls [-l] [file ...]");
		mx_printerr("\n");
		exit(1);
	}
	if (argc < 1) {
		perror("incorect argument");
		exit(1);
	}
}
