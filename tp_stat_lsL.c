#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#ifdef HAVE_NOT_STAT_RWX_MACROS
#define S_IRUSR 00400           /* read permission: owner */
#define S_IWUSR 00200           /* write permission: owner */
#define S_IXUSR 00100           /* execute permission: owner */
#define S_IRWXG 00070           /* read, write, execute: group */
#define S_IRGRP 00040           /* read permission: group */
#define S_IWGRP 00020           /* write permission: group */
#define S_IXGRP 00010           /* execute permission: group */
#define S_IRWXO 00007           /* read, write, execute: other */
#define S_IROTH 00004           /* read permission: other */
#define S_IWOTH 00002           /* write permission: other */
#define S_IXOTH 00001           /* execute permission: other */
#endif
void	aff_char(char c)
{
write(1, &c, 1);
}
int	aff_nbr(int n)
{
	int fin, debut;

	if (n <  0)
	{
		aff_char('-');
		aff_nbr(-n);
	}
	else 
	{
		fin = n % 10;
		debut = n / 10;
		if (debut != 0)
			aff_nbr(debut);
		aff_char(fin + '0');
	}

}
void 	aff_err(char *str)
{
write(2, &str, my_strlen(str));
}
int my_strlen(char *str)
{
int i;
for (i = 0; str[i] != '\0'; i++);
return (i);
}
void aff_str(char *str)
{
int i;
for (i = 0; str[i] != '\0'; i++)
aff_char(str[i]);
//write(1, &str, my_strlen(str));
}	
int			types[] = 
{
	S_IFIFO,'p',S_IFCHR,'c',S_IFDIR,'d',S_IFBLK,'b',S_IFREG,'-',
	S_IFLNK,'l',S_IFSOCK,'s',0,0
};

void			aff_type(int mode)
{
	int		*p;

	for (p = &types[0];*(p + 1);p += 2)
	{
		if ((mode & S_IFMT) == *p)
		{
			aff_char(*(p + 1));
			return ;
		}
	}
}

int			perm0[] = {1,S_IRUSR,'r','-'};
int			perm1[] = {1,S_IWUSR,'w','-'};
int			perm2[] = {3,S_ISUID|S_IXUSR,'s',S_IXUSR,'x',S_ISUID,'S','-'};
int			perm3[] = {1,S_IRGRP,'r','-'};
int			perm4[] = {1,S_IWGRP,'w','-'};
int			perm5[] = {3,S_ISGID|S_IXGRP,'s',S_IXGRP,'x',S_ISGID,'S','-'};
int			perm6[] = {1,S_IROTH,'r','-'};
int			perm7[] = {1,S_IWOTH,'w','-'};
int			perm8[] = {3,S_ISVTX|S_IXOTH,'t',S_IXOTH,'x',S_ISVTX,'T','-'};
int			*perms[] = {perm0,perm1,perm2,perm3,perm4,perm5,perm6,perm7,perm8,0};

void			aff_perm(int mode)
{
	int		**defp;

	for (defp = &perms[0];*defp;defp++)
	{
		int	*def;
		int	n;
		
		def = *defp;
		for (n = *def++;n-- > 0;)
		if ((mode & *def) == *def)
		{
			def++;
			break ;
		}
		else
			def += 2;
		aff_char(*def);
	}
}

int			main(int argc, char **argv)
{
	struct stat	s;

	if (argc != 2)
	{
		aff_str("usage: stat file\n");
		exit(1);
	}
	if (stat(argv[1], &s) < 0)
		aff_err("fstat");
	aff_type(s.st_mode);
	aff_perm(s.st_mode);
	aff_char(' ');
	aff_nbr(s.st_nlink);
	aff_char(' ');
	aff_nbr(s.st_uid);
	aff_char(' ');
	aff_nbr(s.st_gid);
	aff_char(' ');
	aff_nbr(s.st_size);
	aff_char(' ');
	aff_str(argv[1]);
	aff_char('\n');
}
			
		
