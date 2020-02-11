#include "uls.h"

int mx_dir_size(DIR *dir, int is_a) {
	struct dirent *entry;
	int count = 0;

	while ((entry = readdir(dir)) != NULL) {
		if(!is_a) {
			if (entry->d_name[0] != '.') {
				count++;
			}
		}
		else {
			count++;
		}
	}
	closedir(dir);
	return count;
}
