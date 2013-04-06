#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int  cpt = 0;
void 	my_kill(pid_t a, int sig)
{
	kill(a, sig);
}
void 	catch_sighup(int num_sig){
	if (num_sig == SIGHUP)
	{
		printf("J'ai recu le signal\n");
	}
	if (num_sig == SIGUSR1)
	{

		printf("J'ai recu le signal SIGUSR1 %d fois\n", ++cpt);
	}
}
int 	main(int ac, char** av)
{
	int i;
	char *buff;
	printf(" %d \n",getpid());

    //buff[100] = 'l';
	for (i = 0; i < NSIG; ++i){
		signal(i, catch_sighup);

	}
	for (i = 1; i < 500; ++i)
	{
		kill(atoi(av[1]),SIGUSR1);	
	}
	return(0);
}




