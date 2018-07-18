#include <stdio.h>

int bubble(int a[], int n) {
    if(a == NULL || n <= 0) {
        return -1;
    }

    int i, j;
    int flag;
    for(i=n-1; i >= 0; i--) {
        flag = 0;
        for(j=0; j<i; j++) {
            if(a[j] > a[j+1]) {
                int tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
                flag = 1;
            }
        }

        if(flag == 0) {
            break; 
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    int a[] = {5, 4, 4, 3, 2, 1, 9, 10, 11}; 
    int len = sizeof(a)/sizeof(a[0]);
    bubble(a, len);
    int i;
    for(i=0; i < len; i++) {
        printf("%d\n", a[i]);
    }
}
