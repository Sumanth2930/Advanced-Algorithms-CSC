#include <iostream>
#include <stdexcept>

// each node has four fields
class Node {
public:
    int value; //value of element
    int row; //row of element
    int col; //column of element
    Node* next; //next node pointer

//constructor
    Node(int val, int r, int c){
        value = val;
        row = r;
        col= c;
        next = nullptr;
    } 
};

// The matrix for collection of rows and columns
class SparseMatrix {
private:
    int rows;
    int cols;
    Node** heads;

//constructor
public:
    SparseMatrix(int row, int col) {
        rows = row;
        cols = col;
        heads = new Node*[rows]();
    }


    void insert(int value, int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            throw std::out_of_range("index out of bounds");
        }

        Node* new_node = new Node(value, row, col);
        if (heads[row]) {
            Node* current = heads[row];
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
            
        }
        if (!heads[row]){
            heads[row] = new_node;
        }
    }



    void display() {
        for (int row = 0; row < rows; ++row) {
            Node* current = heads[row];
            int row_values[cols] = {0};
            while (current) {
                row_values[current->col] = current->value;
                current = current->next;
            }
            int col=0;
            while(col < cols)  {
                std::cout << row_values[col] << " ";
                col++;
            }
            std::cout << std::endl;
        }
    }
int get(int row, int col) {
    
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            std::cout << "Row or column index out of bounds";
            return 0;
        }

        Node* current = heads[row];
        while (current) {
            if (current->col == col) {
                return current->value;
            }
            current = current->next;
        }
        return 0;  // Return 0 for elements not explicitly set
    }
};

int main() {
    int rows, cols;
    std::cout << "Please Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Please Enter the number of columns: ";
    std::cin >> cols;

    SparseMatrix matrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Enter value at row " << i << " and column " << j << ": ";
            int value;
            std::cin >> value;
            matrix.insert(value, i, j);
        }
    }

    std::cout << "Sparse Matrix:\n";
    matrix.display();

    
    std::cout << "Please Enter the row and column to retrieve a value: ";
    int search_row, search_col;
    std::cin >> search_row >> search_col;
    int result = matrix.get(search_row, search_col);
    std::cout << "Value at (" << search_row << ", " << search_col << ") is " << result << std::endl;

    return 0;
}
