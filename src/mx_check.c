#include "uls.h"

void mx_check_dir(DIR *dir, char **argv) {
	char *str;
	char *str_buf = NULL;

	if (!dir) {
		str = mx_strnew(1);
		str = mx_strjoin("uls: ", &argv[1][0]);
		str_buf = str;
		free(str);
		perror(str_buf);
		exit(1);
	}
}

void mx_check(int argc, char **argv) {
	char *str;

	if (mx_check_flags(argv[1][1]) == 0) {
		str = mx_strnew(1);
		str = mx_strjoin("uls: illegal option -- ", &argv[1][1]);
		mx_printerr(str);
		free(str);
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
