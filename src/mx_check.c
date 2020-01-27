#include "uls.h"

void mx_check_dir(DIR *dir, char **argv) {
	char *str;
	char *str_buf = NULL;
// не работает вообще
	if (!dir) {
		str = mx_strnew(1);
		str = mx_strjoin("uls: ", &argv[1][0]);
		str_buf = str;
		mx_printstr("Куку тут переменная str_buf:  ");
		mx_printstr(str_buf);
		free(str);
		perror(str_buf);
		exit(1);
	}
}
//вроде как работает, но ловит так же с флагами и папки
void mx_check(int argc, char **argv) {
	char *str;

	if (mx_check_flags(argv[1][1]) == 1) {
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
