#include <stdio.h>

int find(int* matrix, int rows, int columns, int number)
{
    int found = 0; 

    if(matrix != NULL && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while(row < rows && column >= 0)
        {
            if(matrix[row * columns + column] == number)
            {
                found = 1;
                break; 
            } else if(matrix[row * columns + column] > number)
                --column;
            else
                ++row;
        }
    }

    return found;
}

void test1(int* arr)
{
    if(find(arr, 4, 4, 7) == 1) {
        printf("found!\n");
        return;
    }

    printf("not found!\n");
}

int main(int argc, char** argv)
{
    int arr[4][4] = {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}
    };

    test1((int*)arr);
}
