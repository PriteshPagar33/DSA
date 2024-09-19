#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct
{
    int *data;
    int size;
    int length;
} ArrayADT;

void initArray(ArrayADT *arr, int size)
{
    arr->data = (int *)malloc(size * sizeof(int));
    if (!arr->data)
        return;
    arr->size = size;
    arr->length = 0;
}

void fillarray(ArrayADT *arr)
{
    for (int i = arr->length; i < arr->size; i++)
    {
        arr->data[i] = rand() % 100 + 1;
        return;
    }
    arr->length = arr->size;
}

void display(ArrayADT *arr)
{
    if (arr->length == 0)
    {
        printf("Array is empty\n ");
        return;
    }
    for (int i = 0; i < arr->length; i++)
    {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

void insert(ArrayADT *arr, int element, int index)
{
    if (arr->length > arr->size)
    {
        printf("Array is Full\n");
        return;
    }
    if (index < 0 || index > arr->length)
    {
        printf("Invalid Index!!");
        return;
    }
    for (int i = arr->length; i > index; i++)
    {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = element;
    arr->length++;
}

void delete(ArrayADT *arr, int index)
{
    if (arr->length == 0)
    {
        printf("Array is Emptyyy\n");
        return;
    }
    if (index < 0 || index > arr->length)
    {
        printf("Array index is invalid!!");
        return;
    }
    for (int i = index; i < arr->length - 1; i++)
    {
        arr->data[i] = arr->data[i + 1];
    }
    arr->length--;
}
int searchEle(ArrayADT *arr, int element)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->data[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int findMAX(ArrayADT *arr)
{
    int max = arr->data[0];
    for (int i = 0; i < arr->length; i++)
    {
        if (max < arr->data[i])
        {
            max = arr->data[i];
        }
    }
    return max;
}

int findMIN(ArrayADT *arr)
{
    int min = arr->data[0];
    for (int i = 0; i < arr->length; i++)
    {
        if (min > arr->data[i])
        {
            min = arr->data[i];
        }
    }
    return min;
}

void reverse(ArrayADT *arr)
{
    int temp;
    for (int i = 0; i < arr->length / 2; i++)
    {
        int temp = arr->data[i];
        arr->data[i] = arr->data[arr->length - i - 1];
        arr->data[arr->length - i - 1] = temp;
    }
}

void sortarray(ArrayADT *arr)
{
    int temp, min;
    for (int i = 0; i < arr->length; i++)
    {
        min = i;
        for (int j = i + 1; j < arr->length; j++)
        {
            if (arr->data[min] > arr->data[j])
            {
                min = j;
            }
        }
        temp = arr->data[min];
        arr->data[min] = arr->data[i];
        arr->data[i] = temp;
    }
}

void appendEle(ArrayADT *arr, int newele)
{
    if (arr->length == arr->size)
    {
        printf("Array is Full\n");
        return;
    }
    arr->data[arr->length++] = newele;
}
ArrayADT joinarrays(ArrayADT *arr1, ArrayADT *arr2)
{
    ArrayADT joined;
    initArray(&joined, arr1->length + arr2->length);

    for (int i = 0; i < arr1->length; i++)
    {
        appendEle(&joined, arr1->data[i]);
    }
    for (int i = 0; i < arr2->length; i++)
    {
        appendEle(&joined, arr2->data[i]);
    }
    return joined;
}
void freearray(ArrayADT *arr)
{
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->length = 0;
}
int main()
{
    ArrayADT arr;
    initArray(&arr, MAX_SIZE);
    printf("Array Before Insertion  : ");
    display(&arr);

    insert(&arr, 10, 0);
    insert(&arr, 20, 1);
    insert(&arr, 30, 2);
    insert(&arr, 40, 3);
    insert(&arr, 50, 4);
    printf("Array After Insertion : ");
    display(&arr);

    delete (&arr, 4);
    printf("After Deletion: ");
    display(&arr);

    int element = 40;
    int res = searchEle(&arr, element);
    if (res != -1)
    {
        printf("Element %d found at %d index\n", element, res);
    }
    else
    {
        printf("Element doesnt exist\n");
    }

    printf("Max element : %d\n", findMAX(&arr));
    printf("Min Element : %d\n", findMIN(&arr));

    printf("After Reverse :");
    reverse(&arr);
    display(&arr);

    printf("Array after Sorting: ");
    sortarray(&arr);
    display(&arr);

    printf("After Appending Ele: \n");
    appendEle(&arr, 999);
    display(&arr);

    ArrayADT arr2;
    initArray(&arr2, 99);
    insert(&arr2, 91, 0);
    insert(&arr2, 81, 1);
    insert(&arr2, 71, 2);

    ArrayADT merge = joinarrays(&arr, &arr2);
    printf("Merge Arrays: ");
    display(&merge);

    free(&arr);
    free(&arr2);
    free(&merge);

    return 0;
}
