// Konus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class KONYS {
private:
    double height;
    double baseRadius;

    friend double surfaceArea(KONYS k);
    friend double volume(KONYS k);

public:
    KONYS(double setHeight, double setBaseRadius) {
        height = setHeight;
        baseRadius = setBaseRadius;
    }

    KONYS() {
        height = 1;
        baseRadius = 1;
    }
};

double surfaceArea(KONYS k) {
    return M_PI * pow(k.baseRadius, 2) + M_PI * k.baseRadius * k.height;
}

double volume(KONYS k) {
    return (M_PI * pow(k.baseRadius, 2) * k.height) / 3;
}

void swapMaxMin(int* arr, int size) {
    //зберігаєм значення найбільшого і найменшого елементів
    int tempMin = INT_MAX;
    int tempMax = INT_MIN;
    //зберігаєм індекси найбільшого і найменшого елементів
    int minIndex = -1;
    int maxIndex = -1;
    //шукаємо найбільший і найменший елемент та їх індекси
    for (int i = 0; i < size; i++) {
        if (arr[i] < tempMin) {
            tempMin = arr[i];
            minIndex = i;
        }
        if (arr[i] > tempMax) {
            tempMax = arr[i];
            maxIndex = i;
        }
    }
    //мінєямо їх місцями
    int temp = arr[minIndex];
    arr[minIndex] = arr[maxIndex];
    arr[maxIndex] = temp;

    //виводим поміняний масив
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main()
{
    //створюємо масив
    int* arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
        cout << i << " ";
    }
    cout << endl;
    //викликажмо для нього функцію
    swapMaxMin(arr, 10);
}