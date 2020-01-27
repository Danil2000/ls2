#include "uls.h"

static char type_of_file(mode_t mode) {
    switch (mode & S_IFMT) {
    case S_IFCHR:
        return 'c';
    case S_IFBLK:
        return 'b';
    case S_IFIFO:
        return 'p';;
    case S_IFDIR:
       return 'd';
    case S_IFLNK:
        return 'l';
    case S_IFSOCK:
       return 's';
    default:
        return 0;
    }
}

static void choose_color(char type, char* filename) {
	char *str;
	if(type == 'd') {
		str = mx_strjoin("\x1b[35m", filename);
		str = mx_strjoin(str, "\x1b[0m");
		mx_printstr(str);
		mx_printchar('\n');
	}
	else if (type == 'l') {
		str = mx_strjoin("\x1b[35m", filename);
		str = mx_strjoin(str, "\x1b[0m");
		mx_printstr(str);
		mx_printchar('\n');
	}
	else if (type == 's') {
		str = mx_strjoin("\x1b[32m", filename);
		str = mx_strjoin(str, "\x1b[0m");
		mx_printstr(str);
		mx_printchar('\n');
	}
	else if (type == 'p') {
		str = mx_strjoin("\x1b[32m", filename);
		str = mx_strjoin(str, "\x1b[0m");
		mx_printstr(str);
		mx_printchar('\n');
	}
	else {
		mx_printstr(filename);
		mx_printchar('\n');
	}
} 

void mx_ls_G(char *filename) {
	struct stat fst;
	mode_t type;
	int st = 0;
	char reztype;

	st = stat(filename, &fst);
	type = fst.st_mode;
	reztype = type_of_file(type);
	choose_color(reztype, filename);
}
