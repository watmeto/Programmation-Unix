#include <sys/param.h>
#include <sys/mount.h>
//int     mount(char *type, char *dir, int flags, void *data);

int main (int ac, char ** av)
{
  umount(av[1]);
}
