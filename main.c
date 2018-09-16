//
//  main.c
//  Inversions
//
//  Created by fast-algo on 02/09/2018.
//  Copyright © 2018 fast-algo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include "funcTimer.h"

#define FILENAME "/Users/Shared/Data/IntegerArray.txt"

int loadData(int **data);
long int naive(int *data, int length);
long int countInversions(int *data, int length);
long int countSplitInversions(int *leftArray, int leftLength, int *rightArray, int rightLength);
void testCount(void);
void testFileLoad(void);


int main(int argc, const char * argv[])
{
    int *data = NULL;
    int lenData = loadData(&data);
    if (lenData == 0)
        return 0;

    startFuncTimer(0);
    long int numInversionsNaive = naive(data, lenData);
    stopFuncTimer(0);
    printf("Number of Inversions (Naive) = %ld\n", numInversionsNaive);
    printf("Time Taken for %d length array = %lf seconds.\n", lenData, getFuncTime(0));

    startFuncTimer(1);
    long int numInversions = countInversions(data, lenData);
    stopFuncTimer(1);
    printf("Number of Inversions = %ld\n", numInversions);
    printf("Time Taken for %d length array = %lf seconds.\n", lenData, getFuncTime(1));

    if (data != NULL)
        free(data);
    
    return 0;
}

long int naive(int *data, int length)
{
    long int numInversions = 0;
    int i = 0, j = 0;
    
    for (i = 0; i < length; i++)
    {
        for (j = i+1; j < length; j++)
        {
            if (data[i] > data[j])
                numInversions++;
        }
    }
    
    return numInversions;
}

void testFileLoad()
{
    int *data = NULL;
    int lenData = loadData(&data);
    
    printf("Length = %d\n", lenData);
    printf("Data %d = %d\n", 0, data[0]);
    printf("Data %d = %d\n", 1, data[1]);
    printf("Data %d = %d\n", 2, data[2]);
    printf("Data %d = %d\n", lenData - 2, data[lenData - 3]);
    printf("Data %d = %d\n", lenData - 1, data[lenData - 2]);
    printf("Data %d = %d\n", lenData, data[lenData - 1]);
}

void testCount()
{
    int test1[] = {1, 2, 3, 4, 5, 6};
    long int numInversions = countInversions(test1, 6);
    printf("Number of Inversions = %ld\n", numInversions);
}

long int countInversions(int *data, int length)
{
    long int numInversions = 0;
    int midPoint = 0;
    
    if (length == 1)
        return 0;
    else
    {
        midPoint = length / 2;
        numInversions = countInversions(data, midPoint);
        numInversions += countInversions(data + midPoint, length - midPoint);
        numInversions += countSplitInversions(data, midPoint, data + midPoint, length - midPoint);
    }

    return numInversions;
}

long int countSplitInversions(int *leftArray, int leftLength, int *rightArray, int rightLength)
{
    int i = 0, j = 0, k = 0;
    long int numInversions = 0;
    int *tempArray = malloc((leftLength + rightLength) * sizeof(int));
    bzero(tempArray, leftLength + rightLength);
    
    while ( (i < leftLength) && (j < rightLength) )
    {
        if (leftArray[i] > rightArray[j])
        {
            tempArray[k++] = rightArray[j];
            numInversions += (leftLength - i);
            j++;
        }
        else
        {
            tempArray[k++] = leftArray[i];
            i++;
        }
    }
    
    while (i < leftLength)
        tempArray[k++] = leftArray[i++];

    while (j < rightLength)
        tempArray[k++] = rightArray[j++];
    
    for (i = 0; i < (leftLength + rightLength); i++)
        leftArray[i] = tempArray[i];
    
    return numInversions;
}

int loadData(int **data)
{
    FILE *fp = NULL;
    int count = 0;
    int line = 0;
    int i = 0;
    
    fp = fopen(FILENAME, "r");
    if (fp == NULL)
    {
        printf("Could not open file %s\n", FILENAME);
        *data = NULL;
        return 0;
    }
    
    while (!feof(fp))
    {
        fscanf(fp, "%d", &line);
        count++;
    }
    fclose(fp);
    
    count--;
    //printf("File contains %d lines\n", count);
    
    *data = malloc(count * sizeof(int));
    bzero(*data, count);
    
    fp = fopen(FILENAME, "r");
    if (fp == NULL)
    {
        printf("Could not open file %s\n", FILENAME);
        *data = NULL;
        return 0;
    }
    
    for (i = 0; i < count; i++)
    {
        fscanf(fp, "%d", &line);
        *(*data + i) = line;
    }
    fclose(fp);

    return count;
}
