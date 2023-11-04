#include <iostream>

struct Sparse
{
    int NumOfRows, NumOfCols, valCount;
    int **nonZeroData; // to store the non zero values in sparse matrix
};

// to save a non zero number
void addNumber(Sparse &matrix, int row, int col, int value)
{
    if (value != 0)
    {
        // save row colummn and the value of non zero number
        matrix.nonZeroData[matrix.valCount][0] = row;
        matrix.nonZeroData[matrix.valCount][1] = col;
        matrix.nonZeroData[matrix.valCount][2] = value;
        matrix.valCount++;
    }
}

// get the value at a row and col of sparse matrix
int getNumber(Sparse &matrix, int row, int col)
{
    for (int i = 0; i < matrix.valCount; i++)
    {
        if (matrix.nonZeroData[i][0] == row && matrix.nonZeroData[i][1] == col)
        {
            return matrix.nonZeroData[i][2];
        }
    }
    return 0;
}

// print sparse matrix
void printMatrix(Sparse &matrix)
{
    std::cout << "Sparse Matrix:" << std::endl;
    for (int i = 0; i < matrix.NumOfRows; i++)
    {
        for (int j = 0; j < matrix.NumOfCols; j++)
        {
            std::cout << getNumber(matrix, i, j) << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int rows, cols;
    std::cout << "Enter the total number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the total number of columns: ";
    std::cin >> cols;

    Sparse matrix;
    matrix.NumOfRows = rows;
    matrix.NumOfCols = cols;
    matrix.valCount = 0;

    matrix.nonZeroData = new int *[rows * cols];
    for (int i = 0; i < rows * cols; i++)
    {
        matrix.nonZeroData[i] = new int[3];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int value;
            std::cout << "Enter value for element at row " << i << " and column " << j << ": ";
            std::cin >> value;
            addNumber(matrix, i, j, value);
        }
    }

    printMatrix(matrix);

    return 0;
}
