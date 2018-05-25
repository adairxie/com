#include <stdio.h>

int partition(int array[], int start, int end) {
    if (start >= end) {
        return start;
    }

    int index = start + (end - start) / 2;
    int tmp = array[index];
    array[index] = array[end];
    array[end] = tmp;
    
    int small = start - 1;
    for(index = start; index < end; index++) {
       
        if(small != index && array[index] < array[end]) {
            ++small;
            tmp = array[small];
            array[small] = array[index];
            array[index] = tmp;
        }
    }
    ++small;
    tmp = array[small];
    array[small] = array[end];
    array[end] = tmp;

    return small;
}

int quicksort(int array[], int start, int end) {
    if(NULL == array || start < 0 || end < start) {
        return -1;
    }

    int index = partition(array, start, end);
    if(index > start) {
        quicksort(array, start, index-1);
    } else if (index < end) {
        quicksort(array, index+1, end);
    }

}

void printarr(int array[], int length) {
    int index;
    for(index = 0; index < length; index++) {
        printf("%d\n", array[index]);
    }
}

int main(int argc, char ** argv) {
    int arr[] = {3, 2, 1, 4, 9, 6, 8, 7, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, length-1);
    printarr(arr, length);
}
