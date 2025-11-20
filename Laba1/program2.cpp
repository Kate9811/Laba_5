#include <iostream>
#include<ctime>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));
    const int n = 10;
    double* arr = new double[n];

    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) / 10.0;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    cout << endl;

    cout << "Адрес начала массива: " << arr << endl;

    for (int i = 0; i < n; i++) {
        cout << "расстояние " << i << "-го элемента от начала: "
            << &arr[i] - arr << " элементов, смещение в байтах: " //&arr[i] - адрес i-го  массива, arr - адрес начала массива(0 - го элемента),Разность адресов дает количество элементов между ними
            << (char*)(&arr[i]) - (char*)arr << " байт" << endl;
    }


    delete[] arr;
}
