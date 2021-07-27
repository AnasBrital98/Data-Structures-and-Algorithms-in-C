#include<stdio.h>
#include<stdlib.h>
#define N 10

void swap(int *a , int *b)
{
    int temp = *a ;
    *a = *b;
    *b = temp;
} 

void selectionSort(int arr[] , int size)
{
    int i,j,index;
    for(i=0;i<size-1;i++)
    {
        index = i;
        for(j = i+1;j<size;j++)
        {
            if(arr[j] < arr[index])
                index = j;
        }
        swap(&arr[index],&arr[i]);
    }
}


void bubbleSort(int arr[] , int size)
{
    int i,j;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size - i - 1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[] , int size)
{
    int i,j,val;
    for(i = 1 ; i< size ; i++)
    {
        val = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > val)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = val;
    }
}

void merge(int arr[], int start, int midlle, int end) {
	int tmp[end - start + 1] , i = start, j = midlle+1, k = 0;

	while(i <= midlle && j <= end) {
		if(arr[i] <= arr[j]) 
        {
			tmp[k++] = arr[i++];			
		}else {
			tmp[k++] = arr[j++];			
		}
	}

	while(i <= midlle) {
		tmp[k++] = arr[i++];
	}

	while(j <= end) {
		tmp[k++] = arr[j++];
	}

	for(i = start; i <= end; i += 1) {
		arr[i] = tmp[i - start];
	}
}

void mergeSort(int arr[], int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

void display(int arr[] , int size)
{   
    int i;
    for(i=0;i<size;i++)
        printf("%d\t",arr[i]);
    printf("\n");    
}



int main(int argc , char** argv)
{
    int arr[] = {5,6,7,3,9,0,1,2,8,4};
    printf("Before Sorting The List .\n");
    display(arr,N);


    printf("After Sorting The List .\n");
    //selectionSort(arr,N);
    //bubbleSort(arr,N);
    //insertionSort(arr,N);
    mergeSort(arr,0,9);
    display(arr,N);
    return 0;   
}