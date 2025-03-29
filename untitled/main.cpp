#include <iostream>
#include <valarray>
#include <cmath>
//ex1
double euclidianDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}
//ex1a
bool findIfThreePointsLieOnTheSameLength(double x1 , double x2, double x3, double y1, double y2, double y3) {
    if (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) == 0) {
        return true;
    }

    return false;

}
//ex4
int swapBits(int n, int j, int i) {
    if (((n >> i) & 1) == ((n >> j) & 1)) {
        int mask = (1 << i) | (1 << j);
        n ^= mask;
    }
    return n;
}
int main() {
    //ex1
    // double x1, y1, x2, y2;
    // std::cin >> x1 >> y1;
    // std::cin >> x2 >> y2;
    // double distance = euclidianDistance(x1, y1, x2, y2);
    // std::cout << "Euclidian Distance: "<< distance<< std::endl;
    // return 0;
    // //ex1a
    // double x3, y3;
    // std::cin >> x3 >> y3;
    // double res = findIfThreePointsLieOnTheSameLength(x1, x2,x3,y1,y2,y3);
    // std::cout << "findIfThreePointsLieOnTheSameLength: " << res << std::endl;
    //ex4
    int n, i, j;
    std::cin >> n >> i >> j;
    int res2 = swapBits(n, j, i);
    std::cout << res2 << std::endl;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.