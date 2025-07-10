// Name: Oscar Barrios Jimenez
// Student ID: 1001953281

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int FillArrayFromFile(char *filename, int **array_ptr, size_t *size_ptr); // adjust to new type for FillArrayFromFile, change int to size_t 
void InsertionSort(int *array, size_t size);
void PrintArray(int *array, size_t size);

int main(int argc, char *argv[])
{
    int *array = NULL;
    size_t size = 0; // change size to size_t to not let any negative values print, .. test for 2 million record result on OMEGA shouldnt overflow, worked properly after change
    clock_t start, end;

    if (argc < 2)
    {
        printf("File must be provided on command line...exiting\n");
        return 0;
    }

    if (FillArrayFromFile(argv[1], &array, &size) == -1) // created an opportunityt to exit if file isnt there or an error occurs instead of running thorugh
    {
        // exit now if file error
        return 1;
    }
// statements for defined for printing, change layout of # of processed records and tics to bottom
#ifdef PRINTARRAY
    printf("\nUnsorted array:\n");
    PrintArray(array, size);
#endif

    start = clock();
    InsertionSort(array, size);
    end = clock();


#ifdef PRINTARRAY
    printf("\nSorted array:\n");
    PrintArray(array, size);
#endif
    printf("\n%d records were processed\n", size); 
    printf("Insertion Sort = %ld Tics\n", (long)(end - start)); // change to accomadate large values 
    
    free(array);

    return 0;
}

int FillArrayFromFile(char *filename, int **array_ptr, size_t *size_ptr) // modify the old int variable to size_t
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Error: File '%s' does not exist. Exiting...\n", filename);
        exit(0); //exit if file doesnt exist
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
        return -1; // 
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
void InsertionSort(int *array, size_t size)
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
// print the array if defined above 
void PrintArray(int *array, size_t size)
{
    size_t i; // change to size_t

    for (i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
}


