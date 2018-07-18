#include <stdio.h>

int quicksort(int a[], int l, int r)
{
    if(a == NULL || l < 0 || r < 0 || l > r) {
        return -1;
    }

    int i = l;
    int j = r;
    int x = a[i];

    while (i < j) {
        while (i < j && a[j] > x)
            j--;
        if(i < j) {
            a[i++] = a[j];
        }

        while(i < j && a[i] < x)
            i++;
        if(i < j) {
            a[j--] = a[i];
        }
    }

    a[i] = x;
    quicksort(a, l, i-1);
    quicksort(a, i+1, r);
    return 0;
}

int main(int argc, char **argv) {
    int a[] = {};
    int len = sizeof(a)/sizeof(a[0]);
    if(len == 0) {
        printf("empty array!\n");
    }
    int result = quicksort(a, 0, len-1);
    if(result == 0) {
        printf("%s\n", "successed!");
    }
    int i;
    for(i = 0; i < len; i++) {
        printf("%d\n", a[i]);
    }
}
