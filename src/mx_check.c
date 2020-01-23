#include "mx_uls.h"

void mx_check_dir(DIR *dir, char *argv) {
	if (!dir)
	{
		char *str =  mx_strjoin("uls",argv);
		//mx_printstr(str);
		perror(str);
		exit(1);
	}
}

void mx_check(int argc, char **argv) {
	if (mx_strcmp(argv[1], "") != 0 && argc == 1)
	{
		mx_printstr("incorrect flag");
		exit(1);
	}
	if (argc < 1) {
		perror("uncorect argument");
		exit(1);
	}
	if (mx_strcmp(argv[1], "-l") == 0) {
		char *str =  mx_strjoin("uls:",argv[2]);
		//mx_printstr(str);
		perror(str);
		exit(1);
	}

}
