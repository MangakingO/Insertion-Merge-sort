// Name: Oscar Barrios Jimenez

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int FillArrayFromFile(char *filename, int **array_ptr, size_t *size_ptr); // adjust to new type for FillArrayFromFile, change int to size_t 
void MergeSort(int *array, int left, int right); // merge sort recursion setup 
void Merge(int *array, int left, int mid, int right);
void InsertionSort(int *array, int size);
void PrintArray(int *array, size_t size);

int main(int argc, char *argv[])
{
    int *array = NULL;
    size_t size = 0; // change size to size_t to not let any negative values print, .. test for 2 million record result on OMEGA shouldnt overflow, worked properly after change
    clock_t start, end;
    long mergeTics, insertionTics; // variables to store tics, print at the end together

    if (argc < 2)
    {
        printf("File must be provided on command line...exiting\n");
        return 1;
    }

    // fill array from file first
    if (FillArrayFromFile(argv[1], &array, &size) != 0)
        return 1;

#ifdef PRINTARRAY
    printf("\nMerge Sort Unsorted array:\n");
    PrintArray(array, size);

#endif 
    start = clock(); // timer
    MergeSort(array, 0, size - 1); 
    end = clock();
    mergeTics = end - start;

#ifdef PRINTARRAY 
    printf("\nMerge Sort Sorted array:\n");
    PrintArray(array, size);
#endif

    free(array); // free array 


    // reload array from file
    if (FillArrayFromFile(argv[1], &array, &size) != 0)
        return 1;

// statements for defined for printing, change layout of # of processed records and tics to bottom
#ifdef PRINTARRAY
    printf("\nInsertion Sort Unsorted array:\n");
    PrintArray(array, size);
#endif

    start = clock(); 
    InsertionSort(array, size);
    end = clock();
    insertionTics = end - start; // insertion tics calculation 


#ifdef PRINTARRAY
    printf("\nInsertion Sort Sorted array:\n");
    PrintArray(array, size);
#endif
    printf("\n%d records were processed\n", size);
    printf("Merge Sort = %ld Tics\n", mergeTics); 
    printf("Insertion Sort = %ld Tics\n", insertionTics); // change to accomadate large values and not have overflow
    
    free(array); 

    return 0;
}

int FillArrayFromFile(char *filename, int **array_ptr, size_t *size_ptr) // modify the old int variable to size_t
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File does not exist...exiting\n");
        return -1; // remove exit calls
    }

    char line[100];
    size_t count = 0; // change to size_t

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        count++;
    }

    *size_ptr = count;

    *array_ptr = malloc(count * sizeof(int));

    if (*array_ptr == NULL)
    {
        printf("Memory allocation failed...exiting\n");
        fclose(fp);
        return -1; // remove eixt calls
    }

    fseek(fp, 0, SEEK_SET);

    size_t index = 0; // change to size_t 

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        (*array_ptr)[index] = atoi(line);
        index++;
    }

    fclose(fp);
    return 0; // exit 
}
// InsertionSort 
void InsertionSort(int *array, int size)
{
    size_t i, j; // change out the int to size_t
    int key; 

    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}


// Merge sort
void MergeSort(int *array, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(array, left, mid);       // Sort left half
        MergeSort(array, mid + 1, right);  // Sort right half
        Merge(array, left, mid, right);    // Merge both halves
    }
}


// Merges two sorted halves of the array
void Merge(int *array, int left, int mid, int right)
{
    int n1 = mid - left + 1; // size of left half
    int n2 = right - mid;    // size of right half

    // allocated temporary arrays
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL)
    {
        printf("Memory allocation failed during merge.\n");
        exit(1);
    }

    // copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    // merge two sorted halves back into array[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        array[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    while (i < n1)
        array[k++] = L[i++];

    while (j < n2)
        array[k++] = R[j++];

    free(L); // free memory
    free(R);
}


// print the array if defined above 
void PrintArray(int *array, size_t size)
{
    size_t i; // change to size_t

    for (i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
}


