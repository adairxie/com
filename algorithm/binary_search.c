#include <stdio.h>

int binary_search(int array[], int length, int elem)
{
    int low = 0;
    int high = length - 1;
    int mid;

    while (low <= high)
    {
        mid = low + (high - low)/2;
        if (array[mid] < elem)
            low = mid + 1;
        else if (array[mid] > elem)
            high = mid - 1;
        else
            return mid;
    }

    return -1;
}

int main(int argc, char **argv)
{
    int arr[7];
    int i;
    for (i = 0; i < 7; i++)
    {
        arr[i] = i;
    }

    int target = binary_search(arr, 7, 13);
    if (-1 == target)
    {
        printf("can not find target!\n");
        return -1;
    }

    printf("target's index is: %d\n", target);
    return 0;
}
