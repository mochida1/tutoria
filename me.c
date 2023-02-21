#include <stdio.h>
#include <unistd.h>

int main (void)
{
	int	turn;

	printf("Programa teste\n");
	turn = 0;
	while (1)
	{
		if (turn == 0)
			printf("\rRodando -");
		if (turn == 1)
			printf("\rRodando /");
		if (turn == 2)
			printf("\rRodando |");
		if (turn == 3)
			printf("\rRodando \\");
		if (turn == 4)
			turn = 0;
		turn++;
		fflush(stdin);
		usleep(10 * 1000);
	}
}