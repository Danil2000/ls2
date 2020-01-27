#include "uls.h"

void mx_ls_A_one(DIR *dir) {
	struct dirent *entry;
	while ((entry = readdir(dir)) != NULL) {
		if (mx_strcmp(entry->d_name , ".") && mx_strcmp(entry->d_name , "..")) {
			mx_printstr(entry->d_name);
			mx_printchar('\n');
		}
	}
}
