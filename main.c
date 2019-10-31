#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>

#define MAX 15

double * a;
int32_t swap_cnt = 0;

void swap(int i, int j)
{
    if (i == j) return;
    printf("%d (%lf) <=> %d (%lf)\n", i, a[i], j, a[j]);
    double t = a[i];
    a[i] = a[j];
    a[j] = t;
    swap_cnt++;
}

int main()
{
    printf("Task #21\n\n");

    int m;
    double n;
    char c;
    char str[MAX];

    printf("Please enter array size: ");
    gets(str);
    sscanf(str, "%" PRId8 "%c", &m, &c);

    a = (double *) malloc (sizeof(double)*m);
    if (a == NULL) exit(EXIT_FAILURE);

    srand(time(NULL));

    printf("Please enter array numbers\n");
    for (int i = 0; i < m; i++) {
        printf("%d\t", i);
        gets(str);
        sscanf(str, "%lf", &a[i]);
    }

    printf("\nArray consists of: \n");
    for (int i = 0; i < m; i++)
        printf("%d\t%lf\n", i, a[i]);

    printf("\nPlease enter number to separate array by: ");
    gets(str);
    sscanf(str, "%lf", &n);
    printf("\n");

    int i = 0;
    int j = m-1;
    int k = -1;
    int l = m;
    while (i <= j) {
        if (a[i] == n) {
            if (k == -1)
                k = l = i;
            else {
                if (i < k) swap(i, --k);
                else if (i > l) swap(i, ++l);
            }
            i++;
        }
        if (a[i] < n) {
            if (i > l) {
                swap(l+1, i);
                swap(k++, ++l);
            }
            i++;
        }
        if (a[j] == n) {
            if (l == m)
                k = l = j;
            else {
                if (j > l) swap(j, ++l);
                else if (j < k) swap(j, --k);
            }
            j--;
        }
        if (a[j] > n) {
            if (j < k) {
                swap(k-1, j);
                swap(--k, l--);
            }
            j--;
        }
        if (a[i] > n && a[j] < n && i < j)
            swap(i, j);
    }
    printf("\nArray state after %" PRIu32 " swaps:\n", swap_cnt);
    for (int i = 0; i < m; i++)
        printf("%d\t%lf\n", i, a[i]);

    return 0;
}
