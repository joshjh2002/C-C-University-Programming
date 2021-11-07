#include <stdio.h>
#include "matrix.h"

void main()
{
    matrix_t *matrix1 = matrix_init(2,2);

    matrix_set(matrix1, 0, 0, 1);
    matrix_set(matrix1, 1, 0, 2);
    matrix_set(matrix1, 0, 1, 3);
    matrix_set(matrix1, 1, 1, 4);

    matrix_save(matrix1, "save");

    matrix_t *matrix2 = matrix_load("save2");

    matrix_t *multiply = matrix_mul(matrix1, matrix2); 
    matrix_save(multiply, "save3");
}