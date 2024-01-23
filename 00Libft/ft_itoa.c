#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int  ft_n_len(long nbr)
{
    int count;

    count = 0;
    if (nbr < 0)
    {
        nbr = -nbr;
        count++;
    }
    if (nbr == 0)
        count++;
    while (nbr != 0)
    {
        nbr /= 10;
        count++;
    }
    return (count);
}

static char *ft_mem_n(int len)
{
    char    *mem;

    mem = malloc((len + 1) * sizeof(char));
    if (!mem)
    {
        return (NULL);
    }
    mem[0] = '\0';
    return (mem);
}

char    *ft_itoa(int n)
{
	char	*str;
    int     i;
    int     len;
    long    nbr;

    nbr = n;
    len = ft_n_len(nbr);
    str = ft_mem_n(len);
    if (!str)
        return (NULL);
    if (nbr < 0)
        nbr = -nbr;
    i = len - 1;
    if (nbr != 0)
    {
        str[i] = ((nbr % 10) + 48);
        nbr = nbr / 10;
        i--;
    }
    if (n < 0)
    {
        str[0] = '-';
        str[len] = 0;
    }
    return (str);
}

int main()
{
    int x = 234;

    printf("%s\n", ft_itoa(x));
    return (0);
}