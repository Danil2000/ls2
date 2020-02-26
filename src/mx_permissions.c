#include "uls.h"

static void type(struct stat file, char **str) {
	char *tmp = NULL;

	if ((file.st_mode & S_IFMT) == S_IFSOCK)
        *str = mx_strjoin(tmp, "s");
    if ((file.st_mode & S_IFMT) == S_IFLNK)
        *str = mx_strjoin(tmp, "l");
    if ((file.st_mode & S_IFMT) == S_IFREG)
        *str = mx_strjoin(tmp, "-");
    if ((file.st_mode & S_IFMT) == S_IFBLK)
        *str = mx_strjoin(tmp, "b");
    if ((file.st_mode & S_IFMT) == S_IFDIR)
        *str = mx_strjoin(tmp, "d");
    if ((file.st_mode & S_IFMT) == S_IFCHR)
        *str = mx_strjoin(tmp, "c");
    if ((file.st_mode & S_IFMT) == S_IFIFO)
        *str = mx_strjoin(tmp, "p");
    mx_strdel(&tmp);
}

void mx_attr_or_acl(char *file, char **permissions) {
    acl_t acl;
    char *tmp;

    tmp = *permissions;
    if (listxattr(file, NULL, 0, XATTR_NOFOLLOW) > 0)
        *permissions = mx_strjoin(tmp, "@");
    else {
        if ((acl = acl_get_file(file, ACL_TYPE_EXTENDED)) != NULL)
            *permissions = mx_strjoin(tmp, "+");
        else
            *permissions = mx_strjoin(tmp, " ");
        acl_free(acl);
    }
    mx_strdel(&tmp);
}

void mx_permissions(char **arrs, int count, char **fls) {
	int i;
	char *help_v = NULL;
	struct stat file;

	for (i = 0; i < count; i++)
	{
		lstat(fls[i], &file);
        help_v = make_perms(fls[i]);
        arrs[i] = mx_strjoin(help_v, " ");
        mx_strdel(&help_v);
	}
}

char *make_perms(char *file) {
	char *perms = NULL;
	struct stat fl;

	perms = mx_strnew(0);
	lstat(file, &fl);
	type(fl, &perms);
	mx_owner_perm(fl, &perms);
	mx_group_permissions(fl, &perms);
	mx_other_permissions(fl, &perms);
	mx_attr_or_acl(file, &perms);
	return perms;
}
