#include <stdio.h>
#include <string.h>

int main() {
    char a[1001], b[1001];

    scanf("%s", a);
    scanf("%s", b);

    int la = strlen(a);
    int lb = strlen(b);
    int max = (la > lb) ? la : lb;

    for (int i = 0; i < max; i++) {
        if (i < la) printf("%c", a[i]);
        if (i < lb) printf("%c", b[i]);
    }
    printf("\n");

    return 0;
}