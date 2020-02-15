#include "uls.h"

static void mx_take_fm(struct stat stats, char *str) {
	mode_t mode = stats.st_mode;
	mode_t *modes = NULL;
	// char *str;

	str = (char *)malloc(12); 
	//if(!(str = (char *)malloc(sizeof(char) * 12))) 
		// return NULL;
	modes = mx_f_m(modes);
	mx_dir_type(mode, str);
	mx_take_ogp(mode, modes, str);
	if (mode & S_ISUID)
		str[3] = ((int)modes & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		str[6] = ((int)modes & S_IXGRP) ? 's' : 'i';
	if (mode & S_ISVTX)
		str[9] = ((int)modes & S_IXOTH) ? 't' : 'T';
	//str[10] = mx_tacl(path);
	str[11] = '\0';
	// return str;
}

void mx_ls_l(DIR *dir, char *dirname) {
	mode_t mode;
	char *str;
	struct stat fst;
	int st;
	struct dirent *d;

	while ((d = readdir(dir)) != NULL) {
		if (mx_strcmp(d->d_name, ".") != 0 
                && mx_strcmp(d->d_name, "..") != 0 
                && d->d_name[0] != '.') {
			st = stat(dirname, &fst);
		//mx_printint(st);
			mode = mx_get_mode(fst);
		//mx_printstr(mode);
			mx_take_fm(fst, str);
			//mx_printstr(str);
			mx_strdel(&str);
		}
	}
	closedir(dir);
	exit(0);
}
