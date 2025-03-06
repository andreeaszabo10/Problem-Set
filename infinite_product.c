#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
	double n_a, n_b, ps = 0, sa = 0, sb = 0;
	int testa = -1, testb = -1; // verifica daca exista a_max si b_max
	unsigned long long a, b, a_max = 0, i, b_max = 0, a_max1, b_max1, n;
	scanf("%llu", &n);
	for (i = 0; i < n; ++i) {
		scanf("%llo %llo", &a, &b);
		ps = ps + a * b; // produs scalar
		sa = sa + pow(a, 2);
		sb = sb + pow(b, 2);
		if (i == 0) { // nu exista un nr cu care sa fie comparat a sau b
			a_max1 = a;
			b_max1 = b;
		} else {
			if (a < a_max1 && a >= a_max) { // a devine a_max
				testa = 1;
				a_max = a;
			} else if (a > a_max1) { // a e cel mai mare nr
				a_max = a_max1;
				a_max1 = a;
				testa = 1;
			}
			if (b < b_max1 && b >= b_max) { // b devine b_max
				testb = 1;
				b_max = b;
			} else if (b > b_max1) { // b e cel mai mare nr
				b_max = b_max1;
				b_max1 = b;
				testb = 1;
			}
		}
	}
	n_a = sqrt(sa); // norma lui a
	n_b = sqrt(sb); // norma lui b
	printf("%.0lf\n", ps);
	if (testa == 1)
		printf("%llu ", a_max);
	else
		printf("-1 ");
	if (testb == 1)
		printf("%llu\n", b_max);
	else
		printf("-1\n");
	printf("%.7lf %.7lf\n", n_a, n_b);
}
