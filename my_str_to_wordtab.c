/*
 ** my_str_to_wordtab.c for  in /home/users/ndiaye_am/rendu
 ** 
 ** Made by "ndiaye amadou al hassane belly"
 ** Login   <ndiaye_am@supdetech.lan>
 ** 
 ** Started on  Wed Dec 21 11:51:59 2011 "ndiaye amadou al hassane belly"
 ** Last update Wed Dec 21 11:55:13 2011 "ndiaye amadou al hassane belly"
 */
#include <malloc.h>
char	**strcpy2(char **tab, char *str)
{
	int i, j, k,l;

	i = 0;
	j = 0;
	k = 0;

	while (str[i])
	{
		if (str[i] != ' ')
		{
			l = k;
			tab[j][k] = str[i];
			k++;
		}
		if (str[i] == '\n'&& str[i+1] != ' ')
		{
			//l = k;
			tab[j][k] = '\0';
			k = 0;
			j++;
		}
		if (str[i] == ' '&& str[i+1] != ' ')
		{
			//l = k;
			tab[j][k] = '\0';
			k = 0;
			j++;
		}
		i++;
	}
//	printf("l = %d \n", l);
	tab[j][l+1] = '\0';	
	return (tab);
}
int	count_num(char *str)
{
	int i, cpt;
	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] == ' ' && (str[i+1] >= 33 && str[i+1] <= 126))
			cpt++;
		i++;
	}
	return (cpt+1);

}

char	**my_str_to_wordtab(char *str)
{
	char **p;
	int i;
	p = malloc(count_num(str) * sizeof(p));
	i = 0;
	while (i <= count_num(str))
	{
		p[i] = malloc(sizeof(p));
		i++;
	}
	p[i-1][0] = '\0';
	p = strcpy2(p,str);
	return (p);

}
/*
   int main()
   {
   char **tab;
   int i;
   char s[] = " geek resident evil vsdfhuv isigdf sdiy ysui ysu sduzzzzzz ";
   tab = my_str_to_wordtab(s);
   for(i = 0; i < count_num(s); i++)
   {
   printf("%s \n", tab[i]);
   }
   }
 */
