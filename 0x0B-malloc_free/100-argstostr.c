#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of a program
 * @ac: the argument count
 * @av: an array of strings representing the arguments
 *
 * Return: a pointer to the new string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
char *str;
int i, j, k, len;

if (ac == 0 || av == NULL)
return (NULL);

len = 0;
for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j]; j++)
{
len++;
}
len++;
}

str = malloc((len + 1) * sizeof(char));
if (str == NULL)
return (NULL);

k = 0;
for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j]; j++)
{
str[k] = av[i][j];
k++;
}
str[k] = '\n';
k++;
}

str[k] = '\0';

return (str);
}

