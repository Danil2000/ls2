#include "uls.h"

static char **write_p(DIR *dir, char** s) {
	int i = 0;
	struct dirent *entry;
	struct stat fst;
    mode_t type;
    int st = 0;
    char restype;

	while ((entry = readdir(dir)) != NULL) {
		st = stat(entry->d_name, &fst);
        type = fst.st_mode;
        restype = mx_type_of_file(type);
		if (entry->d_name[0] != '.')
		{
			if (entry->d_name[i+1])
			{
				if (restype != 'd')
				{
					s[i] = mx_strdup(entry->d_name);
					i++;
				}
				else if (restype == 'd')
				{
					s[i] = mx_strdup(entry->d_name);
					s[i] = mx_strjoin(s[i], "/");
					i++;
				}
			}
		}	
	}
	//mx_printint(mx_len_arr(s));
	s[mx_len_arr(s)] = NULL;
	return s;
}

void mx_ls_p(DIR *dir, char **argv) {
	DIR *dir1;
	int size_dir = 0;
	char **s = NULL;
	int hres = 0;
	int count = 0;

	size_dir = mx_dir_size(dir, 0);
	if (!argv[2]) {
		dir1 = opendir(".");
	}
	else {
		dir1 = opendir(argv[2]);
	}
	s = (char**)malloc(sizeof(char **) * (size_dir + 1));
	s = write_p(dir1, s);
	hres = mx_count_for_print(s);
	count = mx_uls_len_name(hres);
	mx_get_width(s, count, 0);
}
