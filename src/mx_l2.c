#include "uls.h"

static void swtch(struct stat u) {
    switch (u.st_mode & S_IFMT) { 
    case S_IFREG:
        mx_printstr("-");
        break;
    case S_IFDIR:
        mx_printstr("d");
        break;
    case S_IFCHR:
        mx_printstr("c");
        break;
    case S_IFBLK:
        mx_printstr("b");
        break;
    case S_IFLNK:
        mx_printstr("l");
        break;
    case S_IFIFO:
        mx_printstr("p");
        break;
    case S_IFSOCK:
        mx_printstr("s");
        break;
    }
}

static void ls_l_dop(char **yy, int c) {
    t_l *l;
    int bufsiz = 100;

    l = malloc(sizeof(l) * c);
    for(l->b = 0; l->b < c; l->b++) { 
        l->res = stat(yy[l->b], &l->u);
        l->res = l->res < 0 ? lstat(yy[l->b], &l->u) : 0;
        l->t = getpwuid(l->u.st_uid);
        l->bb = mx_strlen(l->t->pw_name);
        if(l->max_user < l->bb)
            l->max_user = l->bb;
        l->i = getgrgid(l->u.st_gid);
        if((l->i)!=NULL) {
            l->times = l->i->gr_name;
        l->bb = mx_strlen(l->times);
        if(l->max_group < l->bb)
            l->max_group = l->bb;
     }
        l->times = mx_itoa(l->u.st_nlink);
        l->bb = mx_strlen(l->times);
        if (l->max_links < l->bb)
            l->max_links = l->bb;
        free(l->times);
        l->times = mx_itoa(l->u.st_size);
        l->bb = mx_strlen(l->times);
        free(l->times);
        if (l->max_size < l->bb)
            l->max_size = l->bb;
        l->total = l->total + l->u.st_blocks; ///аочему оно не то что надо бля
    }
    mx_printstr("total ");
    mx_printint(l->total);
    write(1, "\n", 2);
    for (l->b = 0; l->b < c; l->b++) {
        l->res = stat(yy[l->b], &l->u);
        l->res = l->res < 0 ? lstat(yy[l->b], &l->u) : 0; 
        swtch(l->u);
        l->var = (l->u.st_mode & ~S_IFMT);
        (l->var & S_IRUSR) ? mx_printstr("r") : mx_printstr("-");
        (l->var & S_IWUSR) ? mx_printstr("w") : mx_printstr("-");
        if (l->var & S_ISUID) 
            mx_printstr("s");
        else if (l->var & S_IXUSR) 
            mx_printstr("x") ;
        else 
            mx_printstr("-");
        (l->var & S_IRGRP) ? mx_printstr("r") : mx_printstr("-");
        (l->var & S_IWGRP) ? mx_printstr("w") : mx_printstr("-");
        if (l->var & S_ISGID) 
            mx_printstr("s");
        else if (l->var & S_IXGRP) 
            mx_printstr("x") ;
        else 
            mx_printstr("-");
        (l->var & S_IROTH) ? mx_printstr("r") : mx_printstr("-");
        (l->var & S_IWOTH) ? mx_printstr("w") : mx_printstr("-");
        if (l->var & S_ISVTX) 
            mx_printstr("t");
        else if (l->var & S_IXOTH) 
            mx_printstr("x") ;
        else 
            mx_printstr("-");
        l->acl = acl_get_file(yy[l->b], 0x0000010);
        l->xat = listxattr(yy[l->b], NULL, 0, 0x0001);
        if (l->xat > 0)
            mx_printstr("@");
        else if (l->acl != NULL && ((l->u.st_mode & 0170000) != 0120000))
            mx_printstr("+");
        else 
            mx_printstr(" ");
        mx_printstr(" "); 
        l->times = mx_itoa(l->u.st_nlink);
        if (l->max_links != mx_strlen(l->times))
            for (l->d = 0; l->d < l->max_links - (mx_strlen(l->times)); l->d++)
                mx_printstr(" ");
        free(l->times);   
        mx_printint(l->u.st_nlink);
        write(1, " ", 1);
        l->t = getpwuid(l->u.st_uid);
        if (l->max_user != mx_strlen(l->t->pw_name))
            for (l->d = 0; l->d < l->max_user - (mx_strlen(l->t->pw_name)); l->d++)
                mx_printstr(" ");    
        mx_printstr(l->t->pw_name);
        write(1,"  ", 2);
        l->i = getgrgid(l->u.st_gid);
        if ((l->i)!=NULL) {
            l->buf = l->i->gr_name;
        if (l->max_group != mx_strlen(l->buf)) //
            for (l->d = 0; l->d < l->max_group - mx_strlen(l->buf); l->d++) //
                mx_printstr(" ");      
        mx_printstr(l->buf);
        write(1, " ", 1);
    }
    else if ((l->i)==NULL) {////
        l->buf = mx_itoa(l->u.st_gid); //
        if (l->max_group != mx_strlen(l->buf)) //
            for(l->d = 0; l->d < l->max_group - mx_strlen(l->buf); l->d++) //
                mx_printstr(" ");      
        mx_printstr(l->buf);
        write(1, " ", 1); 
        free(l->buf);
    }
    if ((l->u.st_mode & S_IFMT)== S_IFCHR || (l->u.st_mode & S_IFMT) == S_IFBLK) {
        l->times = mx_itoa((l->u.st_rdev >> 24) & 0xff);
        mx_printstr(l->times);
        free(l->times);
        write(1, " ", 1);
        char *minor = NULL;
        minor = mx_itoa(l->u.st_rdev & 0xffffff);
        if((l->u.st_rdev & 0xffffff) > 256)
            minor = mx_nbr_to_hex(l->u.st_rdev & 0xffffff);
        mx_printstr(minor); 
        free(minor); 
    }  
    if ((l->u.st_mode & S_IFMT) == S_IFDIR ||
        (l->u.st_mode & S_IFMT) == S_IFSOCK ||
        (l->u.st_mode & S_IFMT) == S_IFIFO ||
        (l->u.st_mode & S_IFMT) == S_IFREG ) {
            l->times  = mx_itoa(l->u.st_size);
            if (l->max_size != mx_strlen(l->times))
                for (l->d = 0;l->d < l->max_size - (mx_strlen(l->times)); l->d++)
                    mx_printstr(" ");   
            mx_printint(l->u.st_size);
            free(l->times); 
    }
    if ((l->u.st_mode & S_IFMT) == S_IFLNK) {
        l->buf = mx_strnew(bufsiz);
        l->times = mx_itoa(readlink(yy[l->b], l->buf, bufsiz));
        if (l->max_size != mx_strlen(l->times))
            for (l->d = 0; l->d < l->max_size - (mx_strlen(l->times)); l->d++)
                mx_printstr(" "); 
        mx_printstr(l->times);
        free(l->times);
        free(l->buf);
    }
    write(1," ",1);
    l->times = ctime(&l->u.st_mtime);
    char *times_t = mx_memchr(l->times, ' ',mx_strlen(l->times));
    times_t = &times_t[1];
    char *times_t2 = mx_memrchr(times_t,':',mx_strlen(times_t));
    times_t2[0]='\0';       
    mx_printstr(times_t);
    write(1," ", 1);   
    mx_printstr(yy[l->b]);
    if ((l->u.st_mode & S_IFMT) == S_IFLNK) {
        write(1, " -> ", 4);
        mx_printstr(l->buf);
    }
    write(1, "\n", 2); 
 }
}

static void ls_l_make_yy(DIR *r){
    struct dirent *e = NULL;
    int c = 0;
    char **yy = NULL; 
    t_list *temp = NULL;
    t_list *consis = NULL;
    int a = -1;
    int b = 0;

    e = readdir(r);
    while (e != NULL) {
        mx_push_back(&consis, (void*)e);
        e = readdir(r);
    }
    c = mx_list_size(consis);
    yy = (char**)malloc (sizeof(char**) * c);
    temp = consis;
    for (b = 0; b < c; b++) {
        if ((((struct dirent *)(consis->data))->d_name)[0] != '.') {
            a++;
            yy[a] = mx_strnew(mx_strlen(((struct dirent *)(consis->data))->d_name));
            yy[a] = mx_strcat(yy[a], ((struct dirent *)(consis->data))->d_name);
        }
        consis = consis -> next;
    }   
    c = a + 1 ;
    mx_bubble_sort(yy, c);
    ls_l_dop(yy, c);
}




void mx_ls_l2(char **argv, int argc) {
    DIR *r = NULL;
    char **yy = NULL;
    int t = 0;
    int fd = 0;

    yy = malloc (sizeof(char*) * 100);
    if (argv == NULL) {
        r = opendir(".");
        ls_l_make_yy(r);
    }  
    else {
        for (t = 2; t < argc; t++) {
            if ((fd = open(argv[t], O_RDONLY)) >= 0)
                yy[0] = argv[t];
            yy[1] = NULL;
            ls_l_dop(yy, 2);
        }
        for (t = 2; t < argc; t++) {
            r = opendir(argv[t]);
            if(r)
                ls_l_make_yy(r);
        }
    }
}
