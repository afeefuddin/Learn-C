#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = (2 * i) + 1;

    if (left <= n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right <= n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n; i > 1; i--) {
        swap(&arr[1], &arr[i]);
        heapify(arr, i - 1, 1);
    }
}

int main() {
    int n;
    printf("Enter the length of the array\n");
    scanf("%d", &n);

    int arr[n + 1];
    printf("Enter the elements of the array\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    heapsort(arr, n);

    printf("The array after performing the heap sort is: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
