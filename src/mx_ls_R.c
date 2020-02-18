#include "uls.h"

static void print_name_dir(char *s1) {

	mx_printstr(s1);
	mx_printchar(':');
	mx_printchar('\n');
}

static void open_dir1_print_fl(char *fn, char **argv) {
	DIR *dir1;

	dir1 = opendir(fn);
	if(!mx_strcmp(argv[1], "-Ra")) {
		mx_lsa(dir, argv[2]);
	}
	else {
		mx_ls_wf(dir1, fn);
	}
}

static void open_dubble_read_dir(DIR *dir) {
	struct dirent *files;

	files = readdir(dir);
	files = readdir(dir);
}

static char* make_R_str(char *fn, char *filename) {
	char *s1;
	char *s;

	s = mx_strjoin(fn, "/");
	s1 = mx_strjoin(s, filename);
	free(s);
	return s1;
}

void mx_ls_R(char *fn, char** argv) {
	DIR *dir;
	struct dirent *files;
	char *s1 = NULL;
	
	dir = opendir(fn);
	open_dir1_print_fl(fn, argv);
	open_dubble_read_dir(dir);
	while ((files = readdir(dir)) != NULL) {
		if (mx_is_dir(files->d_name)) {
			if (files->d_name[0] != '.') {
				mx_printchar('\n');
				s1 = make_R_str(fn, files->d_name);
				print_name_dir(s1);
				mx_ls_R(s1, argv);
				free(s1);
			}
		}
	}
	closedir(dir);
}
