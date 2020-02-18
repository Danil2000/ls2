#include "uls.h"

static void ls_l_dop(char **yy, int c) {
    struct stat u;
    struct passwd *t = NULL;
    struct group *i = NULL;
    char *times = NULL;
    mode_t var;
    int b = 0;
    int bb = 0;
    ssize_t xat = 0;
    acl_t acl;
    int total = 0;
    int max_links = 0;
    int max_size = 0;
    int max_user = 0;
    int max_group = 0;
    int d = 0;
    char *buf = NULL;
    int bufsiz = 100;
    int res = 0;

    for(b = 0; b < c; b++) { 
      res = stat(yy[b], &u);
      res = res < 0 ? lstat(yy[b], &u) : 0;
      t = getpwuid(u.st_uid);
      bb = mx_strlen(t->pw_name);
      if(max_user < bb)
        max_user = bb;
        i = getgrgid(u.st_gid);
        if((i)!=NULL) {
          times = i->gr_name;
         bb = mx_strlen(times);
         if(max_group < bb)
         max_group = bb;
     }
        else if((i)==NULL){
          times = mx_itoa(u.st_gid);
         bb = mx_strlen(times);
         if(max_group < bb)
         max_group = bb;
         free(times);
       }
      times = mx_itoa(u.st_nlink);
      bb = mx_strlen(times);
      if(max_links < bb)
        max_links = bb;
      free(times);
      times = mx_itoa(u.st_size);
      bb = mx_strlen(times);
      free(times);
      if(max_size < bb)
        max_size = bb;
      total = total + u.st_blocks; ///аочему оно не то что надо бля
    }
    mx_printstr("total ");
    mx_printint(total);
    write(1, "\n", 2);
    for(b = 0; b < c; b++) {
   
     res = stat(yy[b], &u);
     res = res < 0 ? lstat(yy[b], &u) : 0;
     
    switch(u.st_mode & S_IFMT){ 
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
  
  var = (u.st_mode & ~S_IFMT);
  (var & S_IRUSR) ? mx_printstr("r") : mx_printstr("-");
  (var & S_IWUSR) ? mx_printstr("w") : mx_printstr("-");
  if(var & S_ISUID) 
    mx_printstr("s");
  else if(var & S_IXUSR) 
    mx_printstr("x") ;
  else 
    mx_printstr("-");
  (var & S_IRGRP) ? mx_printstr("r") : mx_printstr("-");
  (var & S_IWGRP) ? mx_printstr("w") : mx_printstr("-");
  if(var & S_ISGID) 
    mx_printstr("s");
  else if(var & S_IXGRP) 
    mx_printstr("x") ;
  else 
    mx_printstr("-");
  (var & S_IROTH) ? mx_printstr("r") : mx_printstr("-");
  (var & S_IWOTH) ? mx_printstr("w") : mx_printstr("-");
  if(var & S_ISVTX) 
    mx_printstr("t");
  else if(var & S_IXOTH) 
    mx_printstr("x") ;
  else 
    mx_printstr("-");
  
  acl = acl_get_file(yy[b], 0x0000010);
  xat = listxattr(yy[b], NULL, 0, 0x0001);
 if(xat > 0)
   mx_printstr("@");
  else if(acl != NULL && ((u.st_mode & 0170000) != 0120000))
    mx_printstr("+");
  else 
    mx_printstr(" ");
  mx_printstr(" "); 
  times = mx_itoa(u.st_nlink);
  if(max_links != mx_strlen(times))
    for(d = 0; d < max_links - (mx_strlen(times)); d++)
      mx_printstr(" ");
      free(times);   
       mx_printint(u.st_nlink);
       write(1, " ", 1);
       t = getpwuid(u.st_uid);
  if(max_user != mx_strlen(t->pw_name))
    for(d = 0; d < max_user - (mx_strlen(t->pw_name)); d++)
      mx_printstr(" ");    
       mx_printstr(t->pw_name);
       write(1,"  ", 2);


    i = getgrgid(u.st_gid);
    if((i)!=NULL) {
      buf = i->gr_name;
    if(max_group != mx_strlen(buf)) //
     for(d = 0; d < max_group - mx_strlen(buf); d++) //
      mx_printstr(" ");      
       mx_printstr(buf);
        write(1, " ", 1);
      }
    else if((i)==NULL) {////
      buf = mx_itoa(u.st_gid); //
   if(max_group != mx_strlen(buf)) //
     for(d = 0; d < max_group - mx_strlen(buf); d++) //
      mx_printstr(" ");      
       mx_printstr(buf);
        write(1, " ", 1); 
        free(buf);
      }
      // write(1, mx_itoa(u.st_gid), mx_strlen(mx_itoa(u.st_gid)));
      //  write(1, " ", 1);
if ((u.st_mode & S_IFMT)== S_IFCHR || (u.st_mode & S_IFMT) == S_IFBLK) {
  times = mx_itoa((u.st_rdev >> 24) & 0xff);
  mx_printstr(times);
  free(times);
  write(1, " ", 1);
  char *minor = NULL;
  minor = mx_itoa(u.st_rdev & 0xffffff);
  if((u.st_rdev & 0xffffff) > 256)
    minor = mx_nbr_to_hex(u.st_rdev & 0xffffff);
    mx_printstr(minor); 
    free(minor); 
    }  
if ((u.st_mode & S_IFMT) == S_IFDIR ||
    (u.st_mode & S_IFMT) == S_IFSOCK ||
    (u.st_mode & S_IFMT) == S_IFIFO ||
    (u.st_mode & S_IFMT) == S_IFREG ) {
  times  = mx_itoa(u.st_size);
  if(max_size != mx_strlen(times))
        for(d = 0; d < max_size - (mx_strlen(times)); d++)
          mx_printstr(" ");   
     mx_printint(u.st_size);
     free(times); 
   }
     
    
if((u.st_mode & S_IFMT) == S_IFLNK) {
  buf = mx_strnew(bufsiz);
  times = mx_itoa(readlink(yy[b], buf, bufsiz));
  if(max_size != mx_strlen(times))
        for(d = 0; d < max_size - (mx_strlen(times)); d++)
          mx_printstr(" "); 

    mx_printstr(times);
    free(times);
    free(buf);
    }
      write(1," ",1);
      times = ctime(&u.st_mtime);
        char *times_t = mx_memchr(times, ' ',mx_strlen(times));
        times_t = &times_t[1];
        char *times_t2 = mx_memrchr(times_t,':',mx_strlen(times_t));
        times_t2[0]='\0';
       
       mx_printstr(times_t);
       write(1," ", 1);
       
       mx_printstr(yy[b]);
       if((u.st_mode & S_IFMT) == S_IFLNK) {
          write(1, " -> ", 4);
          mx_printstr(buf);
        }

       write(1, "\n", 2);
       
      
     
 }
 system("leaks main -q");
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
    for(b = 0; b < c; b++){
      if((((struct dirent *)(consis->data))->d_name)[0] != '.'){
        a++;
        yy[a] = mx_strnew(mx_strlen(((struct dirent *)(consis->data))->d_name));
        yy[a] = mx_strcat(yy[a], ((struct dirent *)(consis->data))->d_name);
        //printf("%s \n",yy[c]);
      }
      consis = consis -> next;
    }   
    c = a + 1 ;
    mx_bubble_sort(yy, c);
    /*for(int i=0;i<=c;i++){
    printf("%s \n",yy[c]);
    }*/
    ls_l_dop(yy, c);
}

void mx_ls_l2(char **argv, int argc) {
    //struct dirent *e = NULL;
    DIR *r = NULL;
    //int c = 0;
    char **yy = NULL;
    //int b = 0;
    int t = 0;

    //yy = malloc (sizeof(char*) * 100);
    //int a = -1;
    //int *titi = NULL;
    //t_list *temp = NULL;
    //t_list *consis = NULL;
    //struct stat u;
    //struct passwd *t = NULL;
    //struct group *i = NULL;
    //char *times = NULL;
    int fd = 0;
    //mode_t var;
    //ioctl(STDOUT_FILENO, TIOCGWINSZ, &wine); //БОЛЬШАЯ ПРОБЛЕМА
    if(argv == NULL) {
      r = opendir(".");
      //char out=r->d_name;
      //write(1,"1",1);
      ls_l_make_yy(r);
    }  
    else {
      for(t = 2; t < argc; t++){
        if((fd = open(argv[t], O_RDONLY)) >= 0)
          yy[0] = argv[t];
          yy[1] = NULL;
          ls_l_dop(yy, 2);
        }
      for(t = 2; t < argc; t++){
        r = opendir(argv[t]);
        if(r)
        ls_l_make_yy(r);
      }
    }
}
