#include <iostream>
#include<ctime>
using namespace std;
int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));
    const int n = 10;
    short* arr = new short[n];

    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 65536) - 32768;  //от –32768 до 32767. не разу не випало полож число!!!
    }
    for (int i =s 0; i < n; i++) {
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
