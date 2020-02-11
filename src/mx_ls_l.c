#include "uls.h"

static char *mx_take_fm(struct stat stats, char *dirname) {
	mode_t mode = stats.st_mode;
	mode_t *modes = NULL;
	char *str;

	if(!(str = (char *)malloc(sizeof(char) * 12))) 
		return NULL;
	modes = mx_f_m(modes);
	mx_dir_type(mode, dirname);
	mx_take_ogp(mode, modes, str);
	if (mode & S_ISUID)
		str[3] = ((int) modes & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		str[3] = ((int) modes & S_IXGRP) ? 's' : 'i';
	if (mode & S_ISVTX)
		str[3] = ((int) modes & S_IXOTH) ? 't' : 'T';
	str[10] = mx_tacl(dirname);
	str[11] = '\0';
	return str;
}

// static void mx_links() {
// 	mx_
// }

void mx_ls_l(char *dirname) {
	mode_t mode;
	char *str;
	struct stat fst;
	int st;

	st = stat(dirname, &fst);
	mx_printint(st);
	mode = mx_get_mode(dirname);
	//mx_printstr(mode);
	str = mx_take_fm(fst, dirname);
	//mx_printstr(str);
}
