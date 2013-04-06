#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdarg.h>

char   cmd[4096];
#define MAXELEMS 32
char* argv[MAXELEMS];
void get_cmd()
{
  if (!fgets(cmd,sizeof(cmd)-1,stdin)) {
    printf("\n");
    exit(0);
  }
}
void get_args()
{
  char * debut = cmd;
  int i;
  for (i=0; i<MAXELEMS-1; i++) 
    {
    while (*debut && isspace(*debut)) debut++;
    /* fin de cmd ? */
    if (!*debut) break;
    argv[i] = debut;
    /* cherche la fin du mot */
    while (*debut && !isspace(*debut)) debut++; /* saute le mot */
    /* termine le mot par un \0 et passe au suivant */
    if (*debut) 
      { 
       *debut = 0; 
       debut++; 
     }
  }

  argv[i] = NULL;
}/*
void  aff_nom(){
struct stat buffer;
struct passwd *p, *n;
stat(av[0], &buffer);
char *temp;
temp = ctime(&buffer.st_mtime);
p = getpwuid(buffer.st_uid);
n = getpwuid(buffer.st_gid);
printf("INODE %d - USER %s - GUID %s - Derniere modif %s - TAILLE %d - NOM  %s \n",buffer.st_ino, p->pw_name, n->pw_name, temp,buffer.st_size, av[1]);
}*/
int main()
{

  if(fork() == 0) {
    execlp("/usr/bin/clear", "clear", NULL);
    exit(1);
  } else {
    wait(NULL);
  }

  while(1){
  printf("[MY_SHELL ] ");
  get_cmd();
  get_args();
if (strcmp(argv[0],"exit") == 0 ){
   exit(1);
  } 

else{
}
 if(fork() == 0) {
    execlp(argv[0], argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], NULL);
    exit(1);
  } else {
    wait(NULL);
  } 
}

}
 