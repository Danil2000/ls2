#include "mx_uls.h"

void mx_ls_wd() {
	DIR *dir;
	struct dirent *entry;

	dir = opendir("./");
	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_name[0] != '.')//!= 1 || mx_strcmp(entry1->d_name, "..") != 0)
		{
			mx_printstr(entry->d_name);
			mx_printchar('\n');	
		}	
	}
}
