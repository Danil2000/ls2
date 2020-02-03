#include "uls.h"

void mx_check_dir(DIR *dir, char **argv) {
	char *str;

	if (!dir) {
		str = mx_strnew(1);
		str = mx_strjoin("uls: ", &argv[1][0]);
		mx_printerr(str);
		mx_printerr(": No such file or directory");
		mx_printerr("\n");
		free(str);
		exit(1);
	}
}
//вроде как работает, но ловит так же с флагами и папки
void mx_check(int argc, char **argv) {
	char *str;

	if (mx_check_flags(argv[1][1]) == 0) {
		str = mx_strnew(1);
		str = mx_strjoin("uls: illegal option -- ", &argv[1][1]);
		mx_check_flags(argv[1][1]);
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
