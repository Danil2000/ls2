#include "uls.h"

static void type_of_file(struct stat file, char **str) {
    char *tmp = *str;

    if ((file.st_mode & S_IFMT) == S_IFSOCK)
        *str = mx_strcat(tmp, "s");
    if ((file.st_mode & S_IFMT) == S_IFLNK)
        *str = mx_strcat(tmp, "l");
    if ((file.st_mode & S_IFMT) == S_IFREG)
        *str = mx_strcat(tmp, "-");
    if ((file.st_mode & S_IFMT) == S_IFBLK)
        *str = mx_strcat(tmp, "b");
    if ((file.st_mode & S_IFMT) == S_IFDIR)
        *str = mx_strcat(tmp, "d");
    if ((file.st_mode & S_IFMT) == S_IFCHR)
        *str = mx_strcat(tmp, "c");
    if ((file.st_mode & S_IFMT) == S_IFIFO)
        *str = mx_strcat(tmp, "p");
    mx_strdel(&tmp);
}

void mx_attr_or_acl(char *file, char **permissions) {
    acl_t acl;
    char *tmp;

    tmp = *permissions;
    if (listxattr(file, NULL, 0, XATTR_NOFOLLOW) > 0){
        *permissions = mx_strcat(tmp, "@");
    }
    else {
        if ((acl = acl_get_file(file, ACL_TYPE_EXTENDED)) != NULL) {
            *permissions = mx_strcat(tmp, "+");
            mx_strdel(&tmp);
        }
        else
            *permissions = mx_strcat(tmp, " ");
        acl_free(acl);
    }
    
}

char * mx_permissions(char *f) {
    char * permissions = mx_strnew(0);
    struct stat file;

    lstat(f, &file);
    type_of_file(file, &permissions);
    mx_owner_permissions(file, &permissions);
    //mx_printstr(permissions);
    mx_group_permissions(file, &permissions);
    mx_other_permissions(file, &permissions);
    mx_attr_or_acl(f, &permissions);
    return permissions;
}

void mx_add_permissions(char **mas_for_print, int count_of_row, char **files) {
    int i;
    char *help_v;
    struct stat file;

    for (i = 0; i < count_of_row; i++) {
        lstat(files[i], &file);
        help_v = mx_permissions(files[i]);
        mas_for_print[i] = mx_strjoin(help_v, " ");
        mx_strdel(&help_v);
    }
}

