#include "uls.h"

void mx_dir_type(mode_t mode, char *dirname) {
	switch (mode & S_IFMT) {
    case S_IFCHR:
        mx_strcat(dirname, "c");
    case S_IFBLK:
        mx_strcat(dirname, "b");
    case S_IFIFO:
        mx_strcat(dirname, "p");
    case S_IFDIR:
       mx_strcat(dirname, "d");
    case S_IFLNK:
        mx_strcat(dirname, "l");
    case S_IFSOCK:
       mx_strcat(dirname, "s");
    case S_IFREG:
    	mx_strcat(dirname, "-");
    default:
       mx_strcat(dirname, " ");
    }
}

mode_t* mx_f_m(mode_t *mode) {
	mode = (mode_t *)malloc(9 * sizeof(mode_t));
    mode[0] = S_IRUSR;
    mode[1] = S_IWUSR;
    mode[2] = S_IXUSR;
    mode[3] = S_IRGRP;
    mode[4] = S_IWGRP;
    mode[5] = S_IXGRP;
    mode[6] = S_IROTH;
    mode[7] = S_IWOTH;
    mode[8] = S_IXOTH;
    return mode;
}

void mx_take_ogp(mode_t mode, mode_t *modes, char *str) {
	for (int i = 0; i < 9; i++)
	{
		if ((modes[i] & mode) == S_IRUSR
            || (modes[i] & mode) == S_IRGRP
            || (modes[i] & mode) == S_IROTH)
            mx_strcat(str, "r");
		else if ((modes[i] & mode) == S_IWUSR
            || (modes[i] & mode) == S_IWGRP
            || (modes[i] & mode) == S_IWOTH)
            mx_strcat(str, "w");
		else if ((modes[i] & mode) == S_IXUSR
            || (modes[i] & mode) == S_IXGRP
            || (modes[i] & mode) == S_IXOTH)
            mx_strcat(str, "x");
        else {
        	mx_strcat(str, "-");
        }
	}
}
char mx_tacl(char *dirname) {
	acl_t acl;

    if (listxattr(dirname, NULL, 0, XATTR_NOFOLLOW) > 0) //ssize_t listxattr(struct dentry *dentry, char *list, size_t size);
        return ('@'); //file or dir has extended atribute
    else if (!(acl = acl_get_file(dirname, ACL_TYPE_EXTENDED)))//acl_extended поддерж тип
        return (' ');
    acl_free(acl);
    return ('+');
}

mode_t mx_get_mode(char *dirname) {
	struct stat fst;
    mode_t type;
    int st = 0;

    st = stat(dirname, &fst);
    type = fst.st_mode;
    return type;
}
