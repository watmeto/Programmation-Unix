int main()
{
int num=1;
char *cptr;

cptr = (char *)&num;

if (*cptr)
printf ("little endian %d \n",cptr);
else
printf ("big endian %d \n", cptr);

return 0;
}
