#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

typedef struct
{
    int rows;
    int columns;
    int64_t **values;
} matrix_t;

 matrix_t * matrix_init(int n, int m);

 void matrix_free(matrix_t * matrix);

 void matrix_set(matrix_t * m, int x, int y, int64_t value);

 int64_t matrix_get(matrix_t * m, int x, int y);

 matrix_t * matrix_add_scalar(matrix_t * matrix, int scalar);

 matrix_t * matrix_mult_scalar(matrix_t * matrix, int scalar);

 matrix_t * matrix_add(matrix_t * m1, matrix_t * m2);

 matrix_t * matrix_mul(matrix_t * m1, matrix_t * m2);

 int matrix_save(matrix_t * m1, char const* file);

 matrix_t * matrix_load(char const* file);