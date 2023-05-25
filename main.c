#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>

//creates output file
void makeOutput(Record *arr, char path[500], int n)
{
    FILE *fp;
    int i;
    int idNumber;
    char name[500];
    fp = fopen(path, "w");
    fprintf(fp, "%d\n", n);
    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%d %s", arr[i].idNumber, arr[i].name);
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main()
{
	int n = 100000; //max size of array
	Record* recordsArr = malloc(n * sizeof(Record)); //creates array
	long startTime, endTime, executionTime; //time variables
	char path[500]; //file path string
	char output[500]; //output file path string
	int choice, fileChoice, sortChoice, valid = 1; //user input
	do
	{
		printf("***************************\n");
		printf("CCDSALG: Sorting Algorithms\n");
		printf("***************************\n");
		printf("[1] Sort records\n[2] End program\nEnter: ");
		scanf("%d", &choice);
		fflush(stdin);
		if(choice == 1)
		{
			do
			{
			printf("\n********************\n");
			printf("Files:\n");
			printf("[1] almostsorted\n[2] random100\n[3] random25000\n[4] random50000\n[5] random75000\n[6] random100000\n[7] totallyreversed\nEnter: ");
			scanf("%d", &fileChoice);
			fflush(stdin);
			switch (fileChoice)
			{
				case 1:
					strcpy(path, "C:\\Users\\Doniella\\Desktop\\Daniella\\CCDSALG\\starter_code_c\\data\\almostsorted.txt");
					valid = 1;
					n = 100000;
					strcpy(output, "almostsorted");
					break;
				case 2:
					strcpy(path, "C:\\Users\\Doniella\\Desktop\\Daniella\\CCDSALG\\starter_code_c\\data\\random100.txt");
					valid = 1;
					n = 100;
					strcpy(output, "random100");
					break;
				case 3:
					strcpy(path, "C:\\Users\\Doniella\\Desktop\\Daniella\\CCDSALG\\starter_code_c\\data\\random25000.txt");
					valid = 1;
					n = 25000;
					strcpy(output, "random25000");
					break;
				case 4:
					strcpy(path, "C:\\Users\\Doniella\\Desktop\\Daniella\\CCDSALG\\starter_code_c\\data\\random50000.txt");
					valid = 1;
					n = 50000;
					strcpy(output, "random50000");
					break;
				case 5:
					strcpy(path, "C:\\Users\\Doniella\\Desktop\\Daniella\\CCDSALG\\starter_code_c\\data\\random75000.txt");
					valid = 1;
					n = 75000;
					strcpy(output, "random75000");
					break;
				case 6:
					strcpy(path, "C:\\Users\\Doniella\\Desktop\\Daniella\\CCDSALG\\starter_code_c\\data\\random100000.txt");
					valid = 1;
					n = 100000;
					strcpy(output, "random100000");
					break;
				case 7:
					strcpy(path, "C:\\Users\\Doniella\\Desktop\\Daniella\\CCDSALG\\starter_code_c\\data\\totallyreversed.txt");
					valid = 1;
					n = 100000;
					strcpy(output, "totallyreversed");
					break;
				default:
					printf("Invalid input! Please try again.\n");
					valid = 0;
			}
			}while(valid == 0);
			
			do
			{
			printf("\n********************\n");
			printf("Sorting algorithms:\n");
			printf("[1] Insertion sort\n[2] Selection sort\n[3] Merge sort\nEnter: ");
			scanf("%d", &sortChoice);
			fflush(stdin);
			printf("\n");
			switch (sortChoice)
			{
				case 1:
				    readFile(recordsArr, path);
				    printf("Sorting records...");
				    startTime = currentTimeMillis(); //store the current time
				    insertionSort(recordsArr, n);
				    endTime = currentTimeMillis(); // store the current time
				    executionTime = endTime - startTime;
				    printf("\tDone!\n");
				    strcat(output, "_insertionsort.txt");
				    makeOutput(recordsArr, output, n);
				    valid = 1;
					break;
				case 2:
				    readFile(recordsArr, path);
				    printf("Sorting records...");
				    startTime = currentTimeMillis(); //store the current time
				    selectionSort(recordsArr, n);
				    endTime = currentTimeMillis(); // store the current time
				    executionTime = endTime - startTime;
	    			printf("Execution Time for Selection Sorting Algorithm: %ld\n", executionTime);
				    printf("\tDone!\n");
				    strcat(output, "_selectionsort.txt");
				    makeOutput(recordsArr, output, n);
				    valid = 1;
				    break;
				case 3:
				    readFile(recordsArr, path);
				    printf("Sorting records...");
				    startTime = currentTimeMillis(); //store the current time
				    mergeSort(recordsArr, 0, n-1);
				    endTime = currentTimeMillis(); // store the current time
				    executionTime = endTime - startTime;
				    printf("\tDone!\n");
				    printf("Execution Time for Merge Sorting Algorithm: %ld\n", executionTime);
				    strcat(output, "_mergesort.txt");
				    makeOutput(recordsArr, output, n);
				    valid = 1;
				    break;
				default:
					printf("Invalid input! Please try again.");
					valid = 0;
			}
			printf("\n");
		}while(valid == 0);
		}
		else if (choice != 2)
		{
			printf("Invalid input! Please try again.\n\n");
		}
	}while(choice != 2);
    return 0;
}