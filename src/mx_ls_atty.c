#include "uls.h"

void mx_ls_atty(char **argv) {
	DIR *dir;
	//mx_printstr(argv[0]);
	if (!argv[1]) {
		dir = opendir(".");
		//exit(1);
	}
	else {
		if (argv[1][0] != '-') {
			//mx_printchar('j');
			dir = opendir(argv[1]);
		}
		else {
			dir = opendir(argv[2]);
		}
	}
	mx_ls_flag_one(dir, argv);
}
