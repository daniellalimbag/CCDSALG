#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/
void merge(Record *arr, int p, int r, int mid)
{
	int i, j;
	int n1 = mid - p + 1;
	int n2 = r - mid;
	Record* temp1 = malloc(n1 * sizeof(Record));
	Record* temp2 = malloc(n2 * sizeof(Record));

	for(i=0;i<n1;i++)
	{
		temp1[i] = arr[p+i];
	}

	for(j=0;j<n2;j++)
	{
		temp2[j] = arr[mid + 1 + j];
	}

	i = 0;
	j = 0;
	int k = p;
	while(i < n1 && j < n2)
	{
		if(temp1[i].idNumber <= temp2[j].idNumber)
		{
			arr[k] = temp1[i];
			i++;
		}
		else
		{
			arr[k] = temp2[j];
			j++;
		}
		k++;
	}
	while(i < n1)
	{
		arr[k] = temp1[i];
		i++;
		k++;
	}
	while(j < n2)
	{
		arr[k] = temp2[j];
		j++;
		k++;
	}
}

void insertionSort(Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.
	int i, j;
	Record key;
	Record temp;
	for(i=0;i<n;i++)
	{
		key = arr[i];
		j = i-1;
		while(j >= 0 && arr[j].idNumber > key.idNumber)
		{
			temp = arr[j+1];
			arr[j+1] = arr[j];
			arr[j] = temp;
			j--;
		}
		arr[j+1] = key;
	}
}

void selectionSort(Record *arr, int n)
{
    // TODO: Implement this sorting algorithm here.
	int i, j, min;
	Record temp;
	for(i=0;i<n-1;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j].idNumber < arr[min].idNumber)
				min = j;
		}
		if(min != i)
		{
			temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

void mergeSort(Record *arr, int p, int r)
{
    // TODO: Implement this sorting algorithm here.
	int mid;
	if(p<r)
	{
		mid = p + (r - p) / 2;
		mergeSort(arr, p, mid);
		mergeSort(arr, mid+1, r);
		merge(arr, p, r, mid);
	}
}

/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/
//heap sorting?










#endif