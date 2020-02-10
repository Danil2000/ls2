#include "uls.h"

void mx_ls_flag_one(DIR *dir) {
	struct dirent *entry;

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_name[0] != '.')
		{
			mx_print_with_new_line(entry->d_name);
		}	
	}
}
