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
					s[i] = entry->d_name;
					i++;
				}
				else if (restype == 'd')
				{
					s[i] = entry->d_name;
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
	t_ls *ls = NULL;

	ls = malloc(sizeof(ls));
	ls->size_dir = mx_dir_size(dir, 0);
	if (!argv[2]) {
		dir1 = opendir(".");
	}
	else {
		dir1 = opendir(argv[2]);
	}
	ls->s = (char**)malloc(sizeof(char **) * (ls->size_dir + 1));
	ls->s = write_p(dir1, ls->s);
	ls->hres = mx_count_for_print(ls->s);
	ls->count = mx_uls_len_name(ls->hres);
	mx_get_width(ls->s, ls->count, 0);
}
