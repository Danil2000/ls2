#include "uls.h"

// void mx_dir_type(mode_t mode, char *str) {
//     (mode & S_IFMT) == S_IFCHR ? mx_strjoin(str, "c"):
//     (mode & S_IFMT) == S_IFBLK ? mx_strjoin(str, "b"):
//     (mode & S_IFMT) == S_IFIFO ? mx_strjoin(str, "p"):
//     (mode & S_IFMT) == S_IFDIR ? mx_strjoin(str, "d"):
//     (mode & S_IFMT) == S_IFLNK ? mx_strjoin(str, "l"):
//     (mode & S_IFMT) == S_IFSOCK ? mx_strjoin(str, "s"):
//     (mode & S_IFMT) == S_IFREG ? mx_strjoin(str, "-"):
//     mx_strjoin(str, "");
// }

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

// void mx_take_ogp(mode_t mode, mode_t *modes, char *str) {
// 	for (int i = 0; i < 9; i++) {
//         switch (modes[i] & mode) {
//             case S_IRUSR:
//             case S_IRGRP:
//             case S_IROTH:
//                 mx_strjoin(str, "r");
//                 break;
//             case S_IWUSR:
//             case S_IWGRP:
//             case S_IWOTH:
//                 mx_strjoin(str, "w");
//                 break;
//             case S_IXUSR:
//             case S_IXGRP:
//             case S_IXOTH:
//                 mx_strjoin(str, "x");
//             default:
//                 mx_strjoin(str, "-");
//                 break;
//         }
// 	}
// }

mode_t mx_get_mode(struct stat fst) {
	//struct stat fst;
    mode_t type;
    // int st = 0;

    // st = stat(dirname, &fst);
    type = fst.st_mode;
    return type;
}
