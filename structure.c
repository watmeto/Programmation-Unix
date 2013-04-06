#include<stdio.h>
typedef struct type type;
struct type
{
	int age;
	char nom[100];
};

int main(int ac, char **av)
{
type eleve;
printf("Entrez votre nom \n");
scanf("%s",&eleve.nom);
printf("Entrez votre nom \n");
scanf("%d",&eleve.age);
printf("Vous vous appelez %s et vous avez %d ans",eleve.nom, eleve.age); 
}
