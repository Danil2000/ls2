#include "uls.h"

char *mx_count_links(struct stat file) {
    char *count_leanks;
    int links = (int)file.st_nlink;

    count_leanks = mx_itoa(links);
    return count_leanks;
}

char *mx_owner_name(struct stat file) {
    char *owner_name;
    struct passwd *owner;

    owner = getpwuid(file.st_uid);
    owner_name = mx_strdup(owner->pw_name);
    return owner_name;
}

char *mx_group_name(struct stat file) {
    char *group_name;
    struct group *group;

    group = getgrgid(file.st_gid);
    if (group == NULL)
        group_name = mx_itoa(file.st_gid);
    else
        group_name = mx_strdup(group->gr_name);
    return group_name;
}

void mx_count_link(char **arrs, int count, char **fls) {
	int i;
	struct stat file;
	char **links_arr = NULL;

	links_arr = (char **)malloc(sizeof(char*) * (count + 1));
	for (i = 0; i < count; i++)
	{
		lstat(fls[i], &file);
		links_arr[i] = mx_count_links(file);
	}
	links_arr[count] = NULL;
	mx_add_count_link_help(arrs, count, links_arr);
	return;
}

