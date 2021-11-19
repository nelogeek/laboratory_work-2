
#include "Header.h"
using namespace std;

int main()
{
    int r, c;
    cout << "Enter number of lines: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;

    int** arr = initialize_array(r, c);
    int** transposedArr = initialize_array(r, c);
    arr = random_array(r, c);
    cout << endl;
    output_array(arr, r, c);
    cout << endl;
    cout << "Lines with null : " << nullInRows(arr, r, c) << endl;
    longRepeat(arr, r, c);

    system("pause");
    return 0;
}