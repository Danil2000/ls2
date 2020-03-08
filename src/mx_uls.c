#include "uls.h"

int main(int argc, char **argv) {
	DIR *dir;

	mx_choose(argv, argc);
	//mx_check(argc, argv);
	if (argc == 2 && argv[1][0] == '-')
		dir = opendir(".");
	else 
		dir = opendir(argv[2]);
	mx_check_dir(argv);
	mx_choose_combination(argv[1], argv, dir);
	mx_choose_flag(argv[1], argv, dir);
}
