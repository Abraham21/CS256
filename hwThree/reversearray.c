/*
/*
 * File: reversearray.c
 *
 * Author: Abraham Yepremian
 *
 * Description: Homework 3 for CS 256
 * Chapter 9 Problem 10 Reverse Array
 *
 * Last edited: 4/19/2018
 *
 */

#include <stdio.h>
#include <stdlib.h>

int* reverseArray(int a[], int size){
    int *array;
    array= malloc(size*sizeof(int));

	int j = 0;

	for(int i = size;i>=0;i--){
		array[j] = a[i];
		j++;
	}

	return array;
	}

int main() {
	//example array in sorted order
	int array[] = {1, 2, 4, 8, 16};

	int *arrayReversed = reverseArray(array, 5);

	printf("Original array: ");
	for(int i = 0;i<5;i++){
		printf("%d ",array[i]);
	}
	printf("\n");

	printf("Reverse of array: ");
	for(int i = 1;i<6;i++){
		printf("%d ",arrayReversed[i]);
	}

	return 0;
}
