#include "matrix.h"

/*
 * Create a matrix of size n x m
 */
matrix_t *matrix_init(int n, int m)
{
    matrix_t *matrix = malloc(sizeof(matrix_t));

    matrix->rows = n;
    matrix->columns = m;
    matrix->values = malloc(sizeof(int64_t) * n);

    int i;
    for (i = 0; i < n; i++)
    {
        matrix->values[i] = calloc(m, sizeof(int64_t));
    }

    return matrix;
}

/*
 * Free all memory of the matrix
 */
void matrix_free(matrix_t *matrix)
{
    free(matrix->values);
    free(matrix);
}

/*
 * Set the value of the matrix on the coordinates like: m[x][y] = value
1PC, Formative Exercise � Week 9 3/6
 */
void matrix_set(matrix_t *m, int x, int y, int64_t value)
{
    m->values[y][x] = value;
}

/*
 * Get the value of the matrix for the coordinates
 * @Return the current value
 */
int64_t matrix_get(matrix_t *m, int x, int y)
{
    return m->values[y][x];
}

/*
 * return the new matrix that contains the result of adding the scalar to each matrix element
 */
matrix_t *matrix_add_scalar(matrix_t *matrix, int scalar)
{
    matrix_t *out = matrix_init(matrix->rows, matrix->columns);
    int row;
    int columns;
    for (row = 0; row < matrix->rows; row++)
    {
        for (columns = 0; columns < matrix->columns; columns++)
        {
            out->values[columns][row] = matrix->values[columns][row] + scalar;
        }
    }

    return out;
}

/*
 * return the new matrix that contains the result of multiplying the scalar to each matrix element
 */
matrix_t *matrix_mult_scalar(matrix_t *matrix, int scalar)
{
    matrix_t *out = matrix_init(matrix->rows, matrix->columns);
    int row;
    int columns;
    for (row = 0; row < matrix->rows; row++)
    {
        for (columns = 0; columns < matrix->columns; columns++)
        {
            out->values[columns][row] = matrix->values[columns][row] * scalar;
        }
    }

    return out;
}

/*
 * Add the two matrices and return the new matrix with the result
 * out[x][y] = m1[x][y] + m2[x][y]
 * return NULL, if the operation isn't possible
 */
matrix_t *matrix_add(matrix_t *m1, matrix_t *m2)
{
    matrix_t *out = matrix_init(m1->rows, m1->columns);
    int row;
    int columns;
    for (row = 0; row < m1->rows; row++)
    {
        for (columns = 0; columns < m1->columns; columns++)
        {
            out->values[columns][row] = m1->values[columns][row] + m2->values[columns][row];
        }
    }

    return out;
}

/*
 * Multiply the two matrices, return NULL, if the operation isn't possible
 */
matrix_t *matrix_mul(matrix_t *m1, matrix_t *m2)
{
    if (m1->columns != m2->rows)
        return NULL;

    matrix_t *out = matrix_init(m1->rows, m2->columns);

    int rows;
    int columns;
    int i;
    for (rows = 0; rows < out->rows; rows++)
    {
        for (columns = 0; columns < out->columns; columns++)
        {
            for (i = 0; i < m1->columns; i++)
            {
                out->values[rows][columns] += m1->values[rows][i] * m2->values[i][columns];
            }
        }
    }

    return out;
}

/*
 * Save the matrix into the specified file
 * @Return 0 if successful, an error code otherwise
 */
int matrix_save(matrix_t *m1, char const *file)
{
    FILE *filePointer = fopen(file, "w");

    // If there is an error opening the file, return the error code
    if (filePointer == NULL)
    {
        return errno;
    }

    int y;
    int x;
    for (y = 0; y < m1->rows; y++)
    {
        for (x = 0; x < m1->columns; x++)
        {

            if (x == m1->columns - 1) //end of line
            {
                fprintf(filePointer, "%d", matrix_get(m1, x, y));
            }
            else
            {
                fprintf(filePointer, "%d,", matrix_get(m1, x, y));
            }
        }
        fprintf(filePointer, "\n");
    }

    fclose(filePointer);
    return 0;
}

/*
 * Load the matrix from the specified file
 * @Return the matrix or NULL if the matrix cannot be loaded
 */
matrix_t *matrix_load(char const *file)
{
    FILE *filePointer = fopen(file, "r");

    // If there is an error opening the file, return NULL
    if (filePointer == NULL)
    {
        return NULL;
    }

    int rows = 0;
    int columns = 0;
    char line[1024];
    char *token = NULL;
    char c;

    // Get number of rows
    for (c = getc(filePointer); c != EOF; c = getc(filePointer))
    {
        if (c == '\n')
        {
            rows++;
        }
    }

    rewind(filePointer);

    // Get number of columns
    for (c = getc(filePointer); c != '\n'; c = getc(filePointer))
    {
        if (c == ',')
        {
            columns++;
        }
    }
    columns++;

    rewind(filePointer);

    matrix_t *out = matrix_init(rows, columns);

    int rowIndex = 0;

    // Transfer each element from the file into the matrix
    while (fgets(line, sizeof(line), filePointer) != NULL && rowIndex < rows)
    {
        int columnIndex = 0;
        for (token = strtok(line, ","); token != NULL && columnIndex < columns; token = strtok(NULL, ","))
        {
            out->values[rowIndex][columnIndex++] = atoi(token);
        }
        rowIndex++;
    }

    fclose(filePointer);
    return out;
}
