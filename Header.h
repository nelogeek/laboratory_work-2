#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string>
#include <stdio.h>
#include <conio.h>


using namespace std;


void RandomInit(void)
{
    srand(time(NULL));
}


int** initialize_array(size_t r, size_t c) {
    int** arr = new int* [r];
    for (int i = 0; i < r; i++) {
        arr[i] = new int[c];
    }
    return arr;
}


void input_array(int** array, size_t r, size_t c) {

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            cin >> array[i][j];
        }
    }
}
void output_array(int** array, size_t r, size_t c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}

int** random_array(size_t r, size_t c) {
    RandomInit();
    int** arr = new int* [r];
    for (int i = 0; i < r; i++) {
        arr[i] = new int[c];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            arr[i][j] = 0 + rand() % 10;
        }
    }
    return arr;
}
template<typename T>
T* matrix_to_array(T** arr, size_t r, size_t c)
{
    int* newArr = new T[r * c];

    for (size_t i = 0; i < r; ++i)
    {
        for (size_t j = 0; j < c; ++j)
        {
            newArr[i * c + j] = arr[i][j];
        }
    }

    return newArr;

}


#pragma region SumAndProduct
template<typename T>
T row_sum(T** arr, size_t r, size_t c, size_t row) {
    int sum = 0;
    for (int i = 0; i < c; i++) {
        sum += arr[row][i];
    }
    return sum;
}




template<typename T>
T column_sum(T** arr, size_t r, size_t c, size_t column) {
    int sum = 0;
    for (int i = 0; i < r; i++) {
        sum += arr[i][column];
    }
    return sum;
}




template<typename T>
T main_diagonal_sum(T** arr, size_t r, size_t c) {
    T sum = 0;
    for (int i = 0; i < r; ++i) {
        sum += arr[i][i];
    }
    return sum;
}






template<typename T>
T second_diagonal_sum(T** arr, size_t r, size_t c) {
    T sum = 0;
    for (int i = 0; i < r; ++i) {
        sum += arr[r + i][i];
    }
    return sum;
}




template<typename T>
T row_product(T** arr, size_t r, size_t c, size_t row) {
    int sum = 0;
    for (int i = 0; i < c; i++) {
        sum *= arr[row][i];
    }
    return sum;
}




template<typename T>
T column_product(T** arr, size_t r, size_t c, size_t column) {
    int sum = 0;
    for (int i = 0; i < r; i++) {
        sum *= arr[i][column];
    }
    return sum;
}






template<typename T>
T main_diagonal_product(T** arr, size_t r, size_t c) {
    T sum = 0;
    for (int i = 0; i < r; ++i) {
        sum *= arr[i][i];
    }
    return sum;
}






template<typename T>
T second_diagonal_product(T** arr, size_t r, size_t c) {
    T sum = 0;
    for (int i = 0; i < r; ++i) {
        sum *= arr[r + i][i];
    }
    return sum;
}




#pragma endregion

#pragma region MinAndMax

//?????????? ?????? ? ????? ??????????, ??????? ? ???????? ????????
template<typename T>
int* IndexOfMinInRow(T** arr, size_t r, size_t c, size_t row) {
    int* min = new int[2];
    min[0] = row;
    min[1] = 0;
    for (int i = 0; i < c; i++) {
        if (arr[min[0]][min[1]] < arr[row][i]) {
            min[1] = i;
        }
    }
    return min;
}

//?????????? ?????? ? ????? ??????????, ??????? ? ???????? ????????
template<typename T>
int* IndexOfMinInCollumn(T** arr, size_t r, size_t c, size_t Collumn) {
    int* min = new int[2];
    min[0] = 0;
    min[1] = Collumn;
    for (int i = 0; i < c; i++) {
        if (arr[min[0]][min[1]] < arr[i][Collumn]) {
            min[0] = i;
        }
    }
    return min;
}

template<typename T>
int* IndexOfMaxInRow(T** arr, size_t r, size_t c, size_t row) {
    int* min = new int[2];
    min[0] = row;
    min[1] = 0;
    for (int i = 0; i < c; i++) {
        if (arr[min[0]][min[1]] > arr[row][i]) {
            min[1] = i;
        }
    }
    return min;
}

//?????????? ?????? ? ????? ??????????, ??????? ? ???????? ????????
template<typename T>
int* IndexOfMinInMainDiagonal(T** arr, size_t r, size_t c) {
    int* min = new int[2];
    min[0] = 0;
    min[1] = 0;
    for (int i = 0; i < c; i++) {
        if (arr[min[0]][min[1]] > arr[i][i]) {
            min[0] = i;
            min[1] = i;
        }
    }
    return min;
}

//?????????? ?????? ? ????? ??????????, ??????? ? ???????? ????????
template<typename T>
int* IndexOfMaxInMainDiagonal(T** arr, size_t r, size_t c) {
    int* min = new int[2];
    min[0] = 0;
    min[1] = 0;
    for (int i = 0; i < c; i++) {
        if (arr[min[0]][min[1]] < arr[i][i]) {
            min[0] = i;
            min[1] = i;
        }
    }
    return min;
}

//?????????? ?????? ? ????? ??????????, ??????? ? ???????? ????????
template<typename T>
int* IndexOfMinInSecondDiagonal(T** arr, size_t r, size_t c) {
    int* min = new int[2];
    min[0] = 0;
    min[1] = r;
    for (int i = 0; i < c; i++) {
        if (arr[min[0]][min[1]] > arr[r - i][i]) {
            min[0] = i;
            min[1] = r - i;
        }
    }
    return min;
}

//?????????? ?????? ? ????? ??????????, ??????? ? ???????? ????????
template<typename T>
int* IndexOfMaxInSecondDiagonal(T** arr, size_t r, size_t c) {
    int* min = new int[2];
    min[0] = 0;
    min[1] = r;
    for (int i = 0; i > c; i++) {
        if (arr[min[0]][min[1]] < arr[r - i][i]) {
            min[0] = i;
            min[1] = r - i;
        }
    }
    return min;
}

#pragma endregion

#pragma region Transformations

template<typename T>
T** Transposition(T** arr, size_t r, size_t c) {
    int** transposedArray = initialize_array(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            transposedArray[j][i] = arr[i][j];
        }
    }
    return transposedArray;
}

template<typename T>
T** RemoveRow(T** arr, size_t r, size_t c, size_t row) {
    int** newArr = initialize_array(r - 1, c);
    size_t x = 0;
    size_t y = 0;
    for (int i = 0; i < r; i++) {
        if (i != row) {
            for (int j = 0; j < c; j++) {
                newArr[x][y] = arr[i][j];
                y++;
            }
            y = 0;
            x++;
        }
    }
    return newArr;
}


template<typename T>
T** RemoveColumn(T** arr, size_t r, size_t c, size_t column) {
    int** newArr = initialize_array(r, c - 1);
    size_t x = 0;
    size_t y = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (j != column) {
                newArr[x][y] = arr[i][j];
                y++;
            }
        }
        y = 0;
        x++;
    }
    return newArr;
}


template<typename T>
T** RemoveRowAndColumn(T** arr, size_t r, size_t c, size_t row, size_t column) {
    T** newArr = initialize_array(r - 1, c - 1);
    size_t x = 0;
    size_t y = 0;
    for (int i = 0; i < r; i++) {
        if (i != row) {
            for (int j = 0; j < c; j++) {
                if (j != column) {
                    newArr[x][y] = arr[i][j];
                    y++;
                }
            }
            y = 0;
            x++;
        }

    }
    return newArr;
}

template<typename T>
bool IsEqual(T** arr1, T** arr2, size_t r, size_t c) {

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (arr1[i][j] != arr2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

#pragma endregion


template<typename T>
int nullInRows(T** arr, size_t r, size_t c) {
    int count = 0;
    for (int j = 0; j < r; j++) {
        for (int i = 0; i < r; i++) {
            if (arr[i][j] == 0) {
                count++;
                break;
            }
            
        }
    }
    return count;

}

template<typename T>
void longRepeat(T** a, size_t r, size_t c) {
    int cnt = 0, maxcnt = 0, ipos = -1, icnt = -1;
    for (int i = 0; i < r; i++)             
    {
        cnt = 0;                      
        for (int j = 1; j < c; j++)
        {                          
            if (a[i][j] == a[i][j - 1])    
                cnt++;                    
            else
            {                        
                if (cnt > maxcnt)
                {                      
                    maxcnt = cnt;
                    ipos = i;              
                    icnt++;             
                }                    
                cnt = 0;
            }                      
        }
        if (cnt > maxcnt)
        {
            maxcnt = cnt;
            ipos = i;
            icnt++;           
        }
    }
    if (-1 == icnt)cout << "\nNone!" << endl;
    else cout << "\nLine: " << (ipos + 1) << endl;
    
    
}
   


#pragma endregion





