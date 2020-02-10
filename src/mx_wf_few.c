#include "uls.h"

void mx_ls_wf_few(DIR *dir, char **argv, int count) {
	DIR *dir1;
	struct dirent *entry;

	dir1 = opendir(argv[count]);
	entry = readdir(dir);
	mx_printstr(entry->d_name);
}
