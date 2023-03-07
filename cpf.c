#include <unistd.h>
#include <stdio.h>

#define CPF_LEN	11
#define false	0
#define true	1

int valida_cpf(char *cpf);

int main (void)
{
	char *cpf = "000000001-91";
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

int my_strcmp(char *str1, char *str2)
{
    int idx;
	
    idx = 0;
    while (str1[idx] != '\0' && str2[idx] != 0)
    {
        if (str1[idx] != str2[idx])
            return (false);
        idx++;
    }
    return (true);
}

int is_edgecase(char *cpf) // mudar para 'se tudo igual' retorna falso
{
    if (my_strcmp(cpf, "111111111-11"))
	{
		return (false);
	}
    if (my_strcmp(cpf, "000000000-00"))
    {
        return (false);
    }
	return (true);
}

int is_edgecase2(char *cpf)
{
	int idx;

	idx = 0;
	while (cpf[idx])
	{	
		if (idx == 9)
			idx++;
		if (cpf[0] != cpf[idx])
			return (true);
		idx++;
	}
	return (false);
}

int valida_cpf(char *cpf)
{
    int i;
    int digitverific;

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

    if (is_edgecase2(cpf) == false)
    {
        printf("especific wrong number\n");
        return (false);
    }

    i = 0;
    digitverific = 0;
    
	while (i < 9)
	{
        digitverific += (cpf[i] - 48) * (i + 1);
        i++;
	}
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