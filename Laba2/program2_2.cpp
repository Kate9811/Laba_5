#include <iostream>
#include <string>
using namespace std;

// Базовый класс Publication
class Publication {
protected:
    string title;
    float price;
public:
    // Метод для ввода данных
    virtual void getdata() {
        cout << "Введите название: ";
        cin.ignore(); // Очищаем буфер ввода
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
    }

    // Метод для вывода данных
    virtual void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " руб." << endl;
    }

    virtual ~Publication() {} // Виртуальный деструктор
};

// Класс Sales, наследуется от Publication
class Sales : public Publication {
protected:
    float sales[3]; // массив продаж за последние 3 месяца
public:
    void getdata() override {
        Publication::getdata(); // Вызываем метод базового класса
        getSales(); // Вводим данные о продажах
    }

    void putdata() const override {
        Publication::putdata(); // Вызываем метод базового класса
        putSales(); // Выводим данные о продажах
    }

    // Метод для ввода данных о продажах
    void getSales() {
        cout << "Введите объем продаж за последние 3 месяца:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": ";
            cin >> sales[i];
        }
    }

    // Метод для вывода данных о продажах
    void putSales() const {
        cout << "Продажи за последние 3 месяца:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Месяц " << i + 1 << ": " << sales[i] << " руб." << endl;
        }
    }
};

// Класс Book, наследуется от Sales
class Book : public Sales {
private:
    int pages;
public:
    void getdata() override {
        Sales::getdata(); // Вызываем метод базового класса (который включает Publication + Sales)
        cout << "Введите количество страниц: ";
        cin >> pages;
    }

    void putdata() const override {
        Sales::putdata(); // Вызываем метод базового класса
        cout << "Количество страниц: " << pages << endl;
    }
};

// Класс Type (аудиокнига), наследуется от Sales
class Type : public Sales {
private:
    float recording_time; // время записи в минутах
public:
    void getdata() override {
        Sales::getdata(); // Вызываем метод базового класса
        cout << "Введите время записи (в минутах): ";
        cin >> recording_time;
    }

    void putdata() const override {
        Sales::putdata(); // Вызываем метод базового класса
        cout << "Время записи: " << recording_time << " минут" << endl;
    }
};

// Демонстрация работы программы
int main() {
    setlocale(LC_ALL, "rus");
    cout << "=== Демонстрация работы с книгами ===" << endl;

    Book book;
    cout << "\nВведите данные о книге:" << endl;
    book.getdata();

    cout << "\nДанные о книге:" << endl;
    book.putdata();

    cout << "\n=== Демонстрация работы с аудиокнигами ===" << endl;

    Type audioBook;
    cout << "\nВведите данные об аудиокниге:" << endl;
    audioBook.getdata();

    cout << "\nДанные об аудиокниге:" << endl;
    audioBook.putdata();

    return 0;
}
