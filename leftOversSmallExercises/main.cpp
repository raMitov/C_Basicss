#include <iostream>
#include <math.h>
int convertBinaryToDecimal(long long n) {
    int decimal = 0, i = 0, reminder = 0;
    while (n != 0) {
        reminder = n % 10;
        n = n / 10;
        decimal += reminder * pow(2, i);
        ++i;
    }
    return decimal;
}
long long convertDecimalToBinary(int decimal) {
    long long binary = 0;
    int reminder = 0, i = 1;
    while (decimal != 0) {
        reminder = decimal % 2;
        decimal = decimal / 2;
        binary += reminder * i;
        i *= 10;
    }
    return binary;
}
int countSetBits(int n) {
    int count = 0;
    while (n != 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}
int swap (int a, int b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main() {


    // long long bin = 101;
    // std::cout << bin << std::endl;
    // int result = convertBinaryToDecimal(bin);
    // std::cout << result << std::endl;
    // int firstNum;
    // int secondNum;
    // std::cin >> firstNum >> secondNum;
    // std::cout << firstNum <<"Is to binary -> "<<convertDecimalToBinary(firstNum) << std::endl;
    // std::cout << secondNum<<"Is to binary -> " <<convertDecimalToBinary(secondNum) << std::endl;
    // int result1 = ~firstNum;
    // int result2 = ~secondNum;
    // std::cout << "After ~ the results are " << std::endl;
    // std::cout << result1 << "Is to binary -> " << convertDecimalToBinary(result1)<< std::endl;
    // std::cout << result2<< "Is to binary -> " << convertDecimalToBinary(result2)<< std::endl;
    // int andOperator = firstNum & secondNum;
    // int orOperator = secondNum | andOperator;
    // int xorOperator = secondNum ^ andOperator;
    // std::cout << andOperator << "Is to binary -> " << convertDecimalToBinary(andOperator)<< std::endl;
    // std::cout << orOperator << "Is to binary -> " << convertDecimalToBinary(orOperator)<< std::endl;
    // std::cout << xorOperator << "Is to binary -> " << convertDecimalToBinary(xorOperator)<< std::endl;
    // int leftshift = firstNum << 2;
    // int rightshift = firstNum >> 2;
    // std::cout << leftshift << "Is to binary -> " << convertDecimalToBinary(leftshift) << std::endl;
    // std::cout << rightshift << "Is to binary -> " << convertDecimalToBinary(rightshift) << std::endl;




    return 0;
}
