#include "mx_uls.h"

void mx_lsa(DIR *dir) {
	struct dirent *entry;

	while ((entry = readdir(dir)) != NULL) {
		mx_printstr(entry->d_name);
		mx_printchar('\n');
	}
}
