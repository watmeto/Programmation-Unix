#include<time.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <unistd.h>
struct stat buffer;
struct passwd *p, *n;
stat(av[1], &buffer);
char *temp;
temp = ctime(&buffer.st_mtime);
p = getpwuid(buffer.st_uid);
n = getpwuid(buffer.st_gid);
printf("INODE %d - USER %s - GUID %s - Derniere modif %s - TAILLE %d - NOM  %s \n",buffer.st_ino, p->pw_name, n->pw_name, temp,buffer.st_size, av[1]);

}
