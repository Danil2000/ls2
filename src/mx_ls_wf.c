#include "mx_uls.h"

static void mx_printspaces(int count) {
	count/=8;
    for (int i = 0; i < count; i++)
        mx_printchar(9);
}

static void mx_ls_print(char **s, int count) {
	int i = 0;
	while (s[i]) {
		mx_printstr(s[i]);
		mx_printspaces(count);
		i++;
	}
	mx_printchar('\n');
}

void mx_ls_wf(DIR *dir, char **argv) {
	DIR *dir1;
	struct dirent *entry;
	char **s;
	int size_dir = 0;

	size_dir = mx_dir_size(dir);
	
	dir1 = opendir(argv[1]);
	int i = 0;
	s = malloc(sizeof(char *) * size_dir + 1);
	while ((entry = readdir(dir1)) != NULL) {
		if (entry->d_name[0] != '.')
		{
			if (argv[1][0] != '-')
			{
				
					s[i] = entry->d_name;
					i++;
					//mx_printstr(entry->d_name);
					//mx_printchar('\n');	
			}
		}	
	}
	s[i] = 0;
	i = 0;

	int hres = mx_count_for_print(s);
	int count = mx_uls_len_name(hres);
	mx_ls_print(s, count);
	free(s);
}
