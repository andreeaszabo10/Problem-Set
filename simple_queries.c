#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char n, L, space, aux, test, u[27];
	int v[27] = {0}, nr_lit = 0, a = 0, i, j, w[27], K, ok = 0;
	while (scanf("%c", &n)) {
		if (n >= 'a' && n <= 'z') {
			a++; // litere de la ultima alerta
			v[n - 'a'] = v[n - 'a'] + 1;
			nr_lit++;
			if (ok == 0) { // nu exista 2 litere distincte
				if (nr_lit == 1)
					test = n;
				else if (n != test)
					ok = 1; //exista 2 litere distincte
				}
		if (a >= 5 && ok == 1) {
			for (i = 0; i < 26; ++i) {
				if (v[i] >= nr_lit / 2 + nr_lit % 2) {
					int b = v[i], nrlit = nr_lit;
					for (j = b; j >= 2; --j) //simplific fractia
						if (b % j == 0 && nrlit % j == 0) {
							b = b / j;
							nrlit = nrlit / j;
						}
					a = 0; // nr litere primite de la ultima alerta = 0
					printf("%c %d/%d\n", i + 'a', b, nrlit);
					}
				}
			}
		} else {
			if (n == 'Q') {
				scanf("%c %c", &space, &L);
				printf("%c %d\n", L, v[L - 'a']);
			}
			if (n == 'T') {
				scanf("%d", &K);
				for (i = 0; i < 26; ++i) {
					w[i] = v[i]; // nr aparitii litera i + 'a'
					u[i] = i + 'a'; // pozitia literei i + 'a'
				}
				for (i = 0; i < 25; ++i) // ordononare descrescatoare
					for (j = i + 1; j < 26; ++j)
						if (w[i] < w[j] || (w[i] == w[j] && u[i] > u[j])) {
							// pentru pozitia literei
							aux = u[i];
							u[i] = u[j];
							u[j] = aux;
							// pentru pozitia numarului de aparitii
							int aux1 = w[i];
							w[i] = w[j];
							w[j] = aux1;
						}
				for (i = 0; i < K; ++i) {
					if (i < K - 1)
						printf("%c ", u[i]);
					else
						printf("%c\n", u[i]);
				}
			}
			if (n == 'E') {
				scanf("%c %c", &space, &L);
				nr_lit = nr_lit - v[L - 'a'];
				if (nr_lit < 2) // daca nu mai sunt 2 litere distincte
					ok = 0;
				v[L - 'a'] = 0;
			}
			if (n != 'Q' && n != 'E' && n != 'T' && n != ' ' && n != '\n')
				break; // daca e un caracter invalid
		}
	}
}
