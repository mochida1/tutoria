#include <unistd.h>
#include <stdio.h>

#define CPF_LEN	11
#define false	0
#define true	1

int valida_cpf(char *cpf);

int main (void)
{
	         //  012345678901
	char *cpf = "123456789-01";
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
	int	i;

	i = 0;
	while (cpf[i] != '\0')
	{
		if (i == 9)
			i++;
		if (is_number(cpf[i]) == false)
			return(false);
		i++;
	}
    return (true);
}

int valida_cpf(char *cpf)
{
    int i;
    int digitverific;


	printf("CPF lenght: %d\n", ft_strlen(cpf));
	if (ft_strlen(cpf) != 12)
	{
		printf("CPF is of wrong size!\n");
		return (false);
	}

    if (cpf[9] != '-')
	{
		printf("CPF is lacking the digit\n");
    	return (false);
	}
    
    if (is_only_number(cpf) == false)
	{
		printf ("CPF is not only numbers!\n");
        return (false);
	}

    i = 0;
    digitverific = 0;
    
	while (i < 9)
	{
        digitverific += (cpf[i] - 48) * (i + 1);
        i++;
	}
	printf ("Our result: %d. Expected result: 285\n", digitverific);
    digitverific = digitverific % 11;
    if (digitverific == 10)
        digitverific = 0;
    printf ("%d\n", cpf[10]);
    if (digitverific != cpf[10] - 48)
    {
        printf("o valor de digitverific é: %d\no valor esperado era: %c\n", digitverific, cpf[10]);
        return (false);	
    }

	digitverific = 0;
	i = 0;
	while (i < 9)
	{
        digitverific += (cpf[i] - 48) * i;
        i++;
	}
	digitverific += (cpf[10] - 48) * 9;
	digitverific = digitverific % 11;
	if (digitverific == 10)
        digitverific = 0;
	if (digitverific != cpf[11] - 48)
    {
        printf("o valor de digitverific é: %d\no valor esperado era: %c\n", digitverific, cpf[11]);
        return (false);	
    }
    return (true);
}