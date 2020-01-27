#include "uls.h"

void mx_ls_flag_one(DIR *dir, char **argv) {
	struct dirent *entry;

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_name[0] != '.')
		{
			if (argv[2][0] != '-')
			{
					mx_printstr(entry->d_name);
					mx_printchar('\n');	
			}
		}	
	}
}
