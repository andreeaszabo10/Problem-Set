#include <stdio.h>
#include <stdlib.h>

void op1(int N, int a[401][401], int lin[401][401])
{
	int i, X;
	scanf("%d", &X);
	for (i = 0; i < N * N; ++i) {
		if (a[X - 1][i] != 0)
			lin[X - 1][a[X - 1][i]]++;
	} //verificare pe linie
	for (i = 1; i <= N * N; ++i) {
		if (lin[X - 1][i] == 0) //daca valoarea i nu a aparut
			printf("1 ");
		if (lin[X - 1][i] != 0)
			printf("0 ");
	}
	printf("\n");
}

void op2(int N, int a[401][401], int col[401][401])
{
	int i, Y;
	scanf("%d", &Y);
	for (i = 0; i < N * N; ++i) {
		if (a[i][Y - 1] != 0)
			col[a[i][Y - 1]][Y - 1]++;
	} //verificare pe coloane
	for (i = 1; i <= N * N; ++i) {
		if (col[i][Y - 1] == 0) //daca valoarea i nu a aparut
			printf("1 ");
		if (col[i][Y - 1] != 0)
			printf("0 ");
	}
	printf("\n");
}

void op3(int N, int a[401][401])
{
	int i, j, Z, c[401] = {0};
	scanf("%d", &Z);
	 // aflu coordonatele primului element din careul Z si verific careul lui
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (a[(Z - 1) / N * N + i][(Z - 1) % N * N + j] != 0)
				c[a[(Z - 1) / N * N + i][(Z - 1) % N * N + j]]++;
		}
	}
	for (i = 1; i <= N * N; ++i) {
		if (c[i] == 0) //daca valoarea i nu a aparut
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");
	for (i = 1; i <= N * N; ++i)
		c[i] = 0;
}

void op4(int N, int a[401][401])
{
	int i, j, X, Y, Z, col[401][401], c[401] = {0}, lin[401][401];
	scanf("%d %d", &X, &Y);
	if (a[X - 1][Y - 1] != 0) { // e deja valoare
		for (i = 0; i < N * N; ++i)
			printf("0 ");
		printf("\n");
	} else {
		for (i = 0; i < N * N; ++i) { //verificare linii, coloane
			if (a[X - 1][i] != 0)
				lin[X - 1][a[X - 1][i]]++;
			if (a[i][Y - 1] != 0)
				col[a[i][Y - 1]][Y - 1]++;
		}
		// aflu careul prin coordonate
		Z = (X - 1) / N * N + (Y - 1) / N + 1;
		for (i = 0; i < N; ++i) // verificare careu
			for (j = 0; j < N; ++j)
				if (a[(Z - 1) / N * N + i][(Z - 1) % N * N + j] != 0)
					c[a[(Z - 1) / N * N + i][(Z - 1) % N * N + j]]++;
		for (i = 1; i <= N * N; ++i) {
			if (lin[X - 1][i] == 0 && col[i][Y - 1] == 0 && c[i] == 0)
				printf("1 "); // se poate pune cifra i
			if (lin[X - 1][i] != 0 || col[i][Y - 1] != 0 || c[i] != 0)
				printf("0 "); // nu se poate pune cifra i
		}
		printf("\n");
		for (i = 1; i <= N * N; ++i)
			c[i] = 0;
	}
}

void op5(int a[401][401])
{
	int X, Y, C;
	scanf("%d %d %d", &X, &Y, &C);
	if (a[X - 1][Y - 1] == 0) // celula e goala
		a[X - 1][Y - 1] = C;
}

void op6(int N, int a[401][401], int v[401], int u[401])
{
	int ok = 1, ok1 = 1, i, j;
	// verific daca este configuratie invalida cu un "ok"
	for (i = 0; i < N * N && ok == 1; ++i) {
		for (j = 0; j < N * N; ++j) {
			if (a[i][j] != 0) {
				v[a[i][j]]++;
				if (v[a[i][j]] >= 2) // daca se repeta o valoare
					ok = 0;
			}
			if (a[j][i] != 0) {
				u[a[j][i]]++;
				if (u[a[j][i]] >= 2) // daca se repeta o valoare
					ok = 0;
			}
		}
		//reinitializare ptr urmatoarea linie sau coloana
		for (j = 1; j <= N * N; ++j) {
			v[j] = 0;
			u[j] = 0;
		}
	}
	if (ok == 0) {
		// am pus acolade ptr checker, desi e o singura instructiune
		printf("1\n");
	} else {
		for (i = 0; i < N * N && ok1 == 1; ++i)
			for (j = 0; j < N * N; ++j)
				if (a[i][j] == 0)
					ok1 = 0;
		// daca un element e 0, se continua ptr ca e configuratie valida
		if (ok1 == 0)
			printf("0\n");
		else
			printf("2\n");
	}
}

int main(void)
{
	int a[401][401], lin[401][401] = {0}, col[401][401] = {0};
	unsigned long long M;
	int N, i, j, op, v[401] = {0}, u[401] = {0};
	scanf("%d %llu", &N, &M);
	for (i = 0; i < N * N; i++)
		for (j = 0; j < N * N; j++)
			scanf("%d", &a[i][j]);
	while (M != 0) {
		scanf("%d", &op);
		if (op == 1)
			op1(N, a, lin);
		if (op == 2)
			op2(N, a, col);
		if (op == 3)
			op3(N, a);
		if (op == 4)
			op4(N, a);
		if (op == 5)
			op5(a);
		if (op == 6)
			op6(N, a, v, u);
		M--;
	}
}
