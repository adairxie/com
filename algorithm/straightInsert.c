#include <stdio.h>


int straightInsert(int a[], int n) {
    if(a == NULL || n <= 0) {
        return -1;
    }

    int i, j;
    for(i = 1; i < n; i++) {
        for(j = i-1; j >= 0; j--) {
            if(a[j] < a[i])
                break;
        }

        if (j != i -1)
        {
            int tmp = a[i];
            int index;
            for(index = i - 1; index > j; index--) {
                a[index+1] = a[index];
            }
            a[index+1] = tmp;
        }   
    }
}

int main(int argc, char **argv) {
    
    int a[] = {5, 4, 4, 10 , 3, 9};
    int len = sizeof(a)/ sizeof(a[0]);
    straightInsert(a, len);

    int i;
    for(i=0; i < len; i++) {
        printf("%d\n", a[i]);
    }
}
