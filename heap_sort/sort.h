#ifndef _sort_h_
#define _sort_h_

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *array, int start, int end, size_t size);


#endif
