#include <iostream>
#include <new>

using Matrix = double **;// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
Matrix makeMatrix(int row, int col) {
    Matrix mat = new (std::nothrow) double *[row];
    for (int i = 0; i < row; i++) {
        mat[i] = new (std::nothrow) double[col];
    }
    return mat;
}
void sortMatrix(Matrix mat) {

}
int main() {


    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.