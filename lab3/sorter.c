#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define ARG_MAX 32

int main(int argc, char *argv[]);

void swap(int array[], int i, int j);
void bubble_sort(int array[], int num_elements);
void min_elem_sort(int array[], int num_elements);

void swap(int array[], int i, int j) {
    /* swaps two elements in an array */
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}    

void min_elem_sort(int array[], int num_elements) {
    int start, i;

    for(start = 0; start < num_elements; start++) {
        int smallest; /* index for smallest elem in array */
        
        smallest = start;
        for (i = start; i < num_elements; i++) {
            if (array[i] < array[smallest]) {
                smallest = i;
            }
        }
        swap(array, smallest, start);
    }
    for(i = 1; i < num_elements; i++) {
        assert(array[i] >= array[i - 1]);
    }
}
   
void bubble_sort(int array[], int num_elements) {
    /* reads in an array, and sorts it via the bubble
    * element sort algorithm */
    int i;
    int swap_flag = 1;

    while (swap_flag) {
        swap_flag = 0;
        for(i = 1; i < num_elements; i++) {
            if(array[i - 1] > array[i]) {
                swap(array, i - 1, i);
                swap_flag = 1;
            }
        }
    }
    for(i = 1; i < num_elements; i++) {
        assert(array[i] >= array[i - 1]);
    }
}

int main(int argc, char *argv[]) {
    int i;
    int to_sort[ARG_MAX];

    int q_flag = 0;
    int b_flag = 0; /* flag for bubble sort */
    int num_elements = 0;
    int h_flag = 0;
    

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-b") == 0) {
            b_flag = 1;
        }
        else if (strcmp(argv[i], "-q") == 0) {
            q_flag = 1;
        }
        else if (strcmp(argv[i], "-h") == 0) {
            h_flag = 1;
        }    
        else {
            if (num_elements <= ARG_MAX) {
                to_sort[num_elements] = atoi(argv[i]);
            }
            num_elements++;
        }   
    }
    if (num_elements <= 0 || num_elements > 32 || h_flag) {
        fprintf(stderr, "usage: NAME\n    %s\n\nSYNOPSIS\n    sorter [OPTIONS]"\
        " [NUMBERS]"\
        " - sorts numbers(max 32)\n\nDESCRIPTION\n"\
        "    sorts [NUMBERS] passed in as args"\
        " according to min elem sort algorithm\n\n    -b"\
        "\n\t--sorts numbers by bubble sort"\
        "\n\n    -q\n\t --quiets the terminal output of the sorted numbers\n"\
        , argv[0], ARG_MAX);
        return -1;
    }
 
    if (b_flag) {
        bubble_sort(to_sort, num_elements);
    }
    else {
        min_elem_sort(to_sort, num_elements);
    }
   if(!q_flag) {
        for (i = 0; i < num_elements; i++) {
            printf("%d\n", to_sort[i]);
        }        
    }
    return 0;
}
