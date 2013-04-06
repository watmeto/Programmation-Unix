int main(int ac, char ** av)
{
	int i;
	char tab[5];
	while (i < 5)
	{
		read(0, &tab[i], 1);
		i++;
	}
	tab[i] = '\0';
	i = 0;
	while(i < 5)
	{
		write(2, &tab[i], 1);
		i++;
	}
}
