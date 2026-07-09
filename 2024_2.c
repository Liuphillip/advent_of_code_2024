#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


typedef struct{
    int data[6];
}inc_dec_both;

typedef struct{
    int data[6];
}inc_dec_too_much;

inc_dec_both check_increasing_or_decreasing( int rows, int columns, int matrix[rows][columns]){

    inc_dec_both mystruct = {0};
    int keep_track_increasing[6] = {0, 0, 0, 0, 0, 0};
    int keep_track_decreasing[6] = {0, 0, 0, 0, 0, 0};

    //check if row is increasing
    // Outer loop iterates through each row 
    for (int row = 0; row < rows; row++) {
        // Inner loop iterates through each column in the current row
        for (int col = 1; col < columns; col++) {

            // check if the column before is less than the column after.
            if(matrix[row][col-1] < matrix[row][col]){
                // if the column before is less than the column after then increase the increasing counter
                // at the end if keep_track_increasing for that row is 6 then it is all increasing
                keep_track_increasing[row]++;
            }
        }
    }

    //check if row is decreasing
    // Outer loop iterates through each row 
    for (int row = 0; row < rows; row++) {
        // Inner loop iterates through each column in the current row
        for (int col = 1; col < columns; col++) {

            // check if the column before is less than the column after.
            if(matrix[row][col-1] > matrix[row][col]){
                // if the column before is less than the column after then increase the decreasing counter
                // at the end if keep_track_decreasing for that row is 6 then it is all decreasing
                keep_track_decreasing[row]++;
            }
        }
    }

    for(int i = 0; i < rows; i++){
        if (keep_track_increasing[i] == columns - 1){
            mystruct.data[i] = 1;
        }
    }
    for(int i = 0; i < rows; i++){
        if (keep_track_decreasing[i] == columns - 1){
            mystruct.data[i] = -1;
        }
    }

    return mystruct;
}

inc_dec_too_much check_too_much( int rows, int columns, int matrix[rows][columns]){

    inc_dec_too_much mystruct = { .data = {1,1,1,1,1,1} };
    int keep_track_too_much[6] = {0, 0, 0, 0, 0, 0};

    //check if row is increasing
    // Outer loop iterates through each row 
    for (int row = 0; row < rows; row++) {
        // Inner loop iterates through each column in the current row
        for (int col = 1; col < columns; col++) {

            // check if the column before is less than the column after.
            if(abs(matrix[row][col-1] - matrix[row][col]) > 3){
            
                keep_track_too_much[row] = 1;
                break;

            }
        }
    }


    for(int i = 0; i < rows; i++){
        if (keep_track_too_much[i] == 1){
            mystruct.data[i] = 0;
        }
    }

    return mystruct;
}

int main(void){


    inc_dec_both inc_or_dec = {0};
    inc_dec_too_much too_much = {0};

    int levels [6][5] = {
        {7, 6, 4, 2, 1},
        {1, 2, 7, 8, 9},
        {9, 7, 6, 2, 1},
        {1, 3, 2, 4, 5},
        {8, 6, 4, 4, 1},
        {1, 3, 6, 7, 9}
    };

    inc_or_dec = check_increasing_or_decreasing(6, 5, levels);
    too_much = check_too_much(6, 5, levels);

    for(int i = 0; i < 6; i++){
        printf("%d\n", inc_or_dec.data[i]);
    }

    printf("\n");

    for(int i = 0; i < 6; i++){
        printf("%d\n", too_much.data[i]);
    }

    for(int i = 0; i < 6; i++){
        if((abs(inc_or_dec.data[i]) == 1) && (too_much.data[i] == 1)){
            printf("Row %d is safe\n", i);
        }else{
            printf("Row %d is not safe\n", i);
        }
    }

    return 0;
}