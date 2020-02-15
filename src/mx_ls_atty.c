#include "uls.h"

void mx_ls_atty(char **argv) {
	DIR *dir;

	if (argv[1][0] != '-')
	{
		dir = opendir(argv[1]);
	}
	else {
		dir = opendir(argv[2]);
	}
	mx_ls_flag_one(dir, argv);
}
