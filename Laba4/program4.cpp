#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;


class ProgramError {
protected:
    string message;
public:
    ProgramError(const string& msg) : message(msg) {}
    virtual void print() const {
        cout << "Program error: " << message << endl;
    }
    virtual ~ProgramError() {}
};


class MemoryError : public ProgramError {
public:
    MemoryError() : ProgramError("Недостаточно памяти") {}
};


class IOError : public ProgramError {
public:
    IOError() : ProgramError("Ошибка ввода/вывода") {}
};

class FileReadError : public IOError {
public:
    FileReadError() : IOError() { message = "Ошибка чтения файла"; }
};


class FileWriteError : public IOError {
public:
    FileWriteError() : IOError() { message = "Ошибка записи файла"; }
};


template <typename T>
class Array {
private:
    T** data;
    size_t size;
    static const size_t MAX_SIZE = 1000;
public:
    Array(size_t n) : size(n) {
        if (n == 0)
            throw invalid_argument("Размер массива не может быть 0");
        if (n > MAX_SIZE)
            throw length_error("Размер массива превышает допустимое значение!");

        data = new T * [size];
        for (size_t i = 0; i < size; ++i)
            data[i] = nullptr;
    }

    T*& operator[](size_t index) {
        if (index >= size)
            throw out_of_range("Индекс вне диапазона!");
        return data[index];
    }

    void printAll() const {
        for (size_t i = 0; i < size; ++i) {
            if (data[i])
                data[i]->print();
            else
                cout << "[" << i << "] Пусто" << endl;
        }
    }

    ~Array() {
        for (size_t i = 0; i < size; ++i)
            delete data[i];
        delete[] data;
    }
};

int main() {
    setlocale(LC_ALL, "ru");


    try {
        cout << "\nмассив ProgramError\n";
        Array<ProgramError> errors(4);

        errors[0] = new MemoryError();
        errors[1] = new IOError();
        errors[2] = new FileReadError();
        errors[3] = new FileWriteError();

        cout << "\nВывод всех ошибок ProgramError:\n";
        errors.printAll();

        cout << "\n Проверка выхода за границы массива\n";
        errors[10] = new MemoryError();
    }
    catch (const out_of_range& e) {
        cerr << "Исключение out_of_range: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Другое исключение: " << e.what() << endl;
    }


    try {
        cout << "\n массив MemoryError \n";
        Array<MemoryError> memoryErrors(3);

        memoryErrors[0] = new MemoryError();
        memoryErrors[1] = new MemoryError();
        memoryErrors[2] = new MemoryError();

        memoryErrors.printAll();
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }


    try {
        cout << "\nмассив FileReadError\n";
        Array<FileReadError> fileReadErrors(2);

        fileReadErrors[0] = new FileReadError();
        fileReadErrors[1] = new FileReadError();

        fileReadErrors.printAll();
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    try {
        cout << " \nПроверка length_error \n";
        Array<ProgramError> tooBig(2000);
    }
    catch (const length_error& e) {
        cerr << "\nИсключение length_error: " << e.what() << endl;
    }

    cout << "\nПрограмма завершена без утечек памяти.\n";
    return 0;
}
