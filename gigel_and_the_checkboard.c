#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
	int i, j, n, tabla[1000][1000], poz[1000][1000] = {0};
	double dist = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &tabla[i][j]);
	i = 0;
	j = 0;
	while (poz[i][j] == 0) {
		poz[i][j]++; // piesa a fost pe tabla[i][j]
		if (tabla[i][j] >= 0)
			dist = dist + tabla[i][j];
		else
			dist = dist - tabla[i][j];
		if ((i + j) % 2 == 0) { //patratul e alb
			if (tabla[i][j] >= 0) { // spre dreapta
				if (tabla[i][j] > n - j - 1)
					j = (j + tabla[i][j] - n) % n;
				else
					j = j + tabla[i][j];
			} else { // spre stanga
				if (-tabla[i][j] > j)
					j = n - 1 - (-tabla[i][j] - j - 1) % n;
				else
					j = j + tabla[i][j];
			}
		} else { // patratul e negru
			if (tabla[i][j] >= 0) { // in jos
				if (tabla[i][j] > n - i - 1)
					i = (i + tabla[i][j] - n) % n;
				else
					i = i + tabla[i][j];
			} else { // in sus
				if (-tabla[i][j] > i)
					i = n - 1 - (-tabla[i][j] - i - 1) % n;
				else
					i = i + tabla[i][j];
			}
		}
	}
	if (j < 26) // pana cand j + 'A' inca e litera mare
		printf("%.lf\n%d %c\n", dist, n - i, j + 'A');
	if (j >= 26) // calculez indicele coloanei atunci cand e format din 2 litere
		printf("%.lf\n%d %c%c\n", dist, n - i, j / 26 - 1 + 'A', j % 26 + 'A');
}
