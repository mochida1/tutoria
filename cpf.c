#include <unistd.h>
#include <stdio.h>

#define CPF_LEN	11
#define false	0
#define true	1

int valida_cpf(char *cpf);

int main (void)
{
	char *cpf = "12345A789-12";
    int valor = valida_cpf(cpf);

	if (valor == true)
        write (1, "OK\n", 3);
    else 
    {
        write (1, "No\n", 3);
    }
    return (0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int is_number(char key)
{
    if (key >= 48 && key <= 57)
    {
    	return (true);
    }
    return (false);
}

int is_only_number(char *cpf)
{
	(void) cpf;
    return (true);
}

int valida_cpf(char *cpf)
{
    int i;

	char x = '9';
	if (is_number(x) == true)
		printf ("%c is a number!\n", x);
	else
	{ printf("%c is not a number! :(\n", x); }
	
	printf("CPF lenght: %d\n", ft_strlen(cpf));
	if (ft_strlen(cpf) != 12)
		return (false);

    if (cpf[9] != '-')
    	return (false);
    
    if (is_only_number(cpf) == false)
        return (false);

    i = 0;
	(void) i;
    // while (i < 12)
	// {
    //   printf("%c", cpf[i]);
    //     i++;
	// }
    // printf("\n");
    return (true);
}