#include<stdio.h>
#include<dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int ac, char **av)
{

	DIR *rep;
	struct dirent *contenu;
	rep = opendir(av[1]);
	while(contenu= readdir(rep))
		if (contenu->d_name[0] != '.')
			printf("%s \t", contenu->d_name);
	printf("\n");
}
