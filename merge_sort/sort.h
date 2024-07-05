#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *array, size_t left, size_t right, int *temp);
void merge(int *array, int *temp, size_t start, size_t mid, size_t end);


#endif
