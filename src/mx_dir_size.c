#include "uls.h"

int mx_dir_size(DIR *dir) {
	struct dirent *entry;
	int count = 0;

	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_name[0] != '.')
		{
			count++;
		}
	}
	closedir(dir);
	return count;
}
