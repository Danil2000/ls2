#include "uls.h"

void mx_dir_type(mode_t mode, char *str) {
    switch (mode & S_IFMT) {
    case S_IFCHR:
        mx_strcat(str, "c");
        break;
    case S_IFBLK:
        mx_strcat(str, "b");
        break;
    case S_IFIFO:
        mx_strcat(str, "p");
        break;
    case S_IFDIR:
        mx_strcat(str, "d");
        break;
    case S_IFLNK:
        mx_strcat(str, "l");
        break;
    case S_IFSOCK:
        mx_strcat(str, "s");
        break;
    case S_IFREG:
        mx_strcat(str, "-");
        break;
    default:
        mx_strcat(str, " ");
        break;
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
        switch (modes[i] & mode) {
            case S_IRUSR:
            case S_IRGRP:
            case S_IROTH:
                mx_strcat(str, "r");
                break;
            case S_IWUSR:
            case S_IWGRP:
            case S_IWOTH:
                mx_strcat(str, "w");
                break;
            case S_IXUSR:
            case S_IXGRP:
            case S_IXOTH:
                mx_strcat(str, "x");
            default:
                mx_strcat(str, "-");
                break;
            }
       
		// if ((modes[i] & mode) == S_IRUSR
  //           || (modes[i] & mode) == S_IRGRP
  //           || (modes[i] & mode) == S_IROTH)
  //           mx_strcat(str, "r");
		// else if ((modes[i] & mode) == S_IWUSR
  //           || (modes[i] & mode) == S_IWGRP
  //           || (modes[i] & mode) == S_IWOTH)
  //           mx_strcat(str, "w");
		// else if ((modes[i] & mode) == S_IXUSR
  //           || (modes[i] & mode) == S_IXGRP
  //           || (modes[i] & mode) == S_IXOTH)
  //           mx_strcat(str, "x");
  //       else {
  //       	mx_strcat(str, "-");
  //       }
	}
}

// char mx_tacl(char *path) {
// 	acl_t acl;

//     if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0) //ssize_t listxattr(struct dentry *dentry, char *list, size_t size);
//         return ('@'); //file or dir has extended atribute
//     else if (!(acl = acl_get_file(path, ACL_TYPE_EXTENDED)))//acl_extended поддерж тип
//         return (' ');
//     acl_free(acl);
//     return ('+');
// }

mode_t mx_get_mode(struct stat fst) {
	//struct stat fst;
    mode_t type;
    // int st = 0;

    // st = stat(dirname, &fst);
    type = fst.st_mode;
    return type;
}
