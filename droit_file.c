#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
void	aff_char(char c)
{
write(1, &c, 1);
}
void aff_str(char *str)
{
int i;
for (i = 0; str[i] != '\0'; i++)
aff_char(str[i]);
}	

void	aff_droit(int mode)
{
char droit[10];
droit[0] = mode&S_IRUSR? 'r':'-';
droit[1] = mode&S_IWUSR? 'w':'-';
droit[2] = mode&S_IXUSR? 'x':'-';
droit[3] = mode&S_IRGRP? 'r':'-';
droit[4] = mode&S_IRGRP? 'w':'-';
droit[5] = mode&S_IXGRP? 'x':'-';
droit[6] = mode&S_IROTH? 'r':'-';
droit[7] = mode&S_IWOTH? 'w':'-';
droit[8] = mode&S_IXOTH? 'x':'-';
droit[9] = '\0';
aff_str(droit);
}
int main(int ac, char **av)
{
struct stat s;
stat(av[1],&s);
aff_droit(s.st_mode);
}
