/*-------------------------------------------------------
 * Tarea de Analisis de Algoritmos: 11389 - The Bus Driver Problem
 * Fecha: 30-03-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>

int n, d, r, i, c1, c2, sum, tax;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int compare2 (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}


int main(int argc, char const *argv[])
{

	while (scanf("%d %d %d", &n, &d, &r) != EOF && (n || d || r)) {
		int mor[n];
		int night[n];
		for (i = 0; i < n; i++) {
			scanf("%d", &mor[i]);
		}
		for (i = 0; i < n; i++) {
			scanf("%d", &night[i]);
		}

		qsort(mor, n, sizeof(int), compare);
		qsort(night, n, sizeof(int), compare2);
		sum = 0;

		for (c1 = 0; c1 < n; c1++) {
			tax = mor[c1] + night[c1] - d;
			if (tax < 0) {
                tax = 0;
			}
			sum += tax*r;
		}

		printf("%d\n", sum);
	}
    return 0;
}
