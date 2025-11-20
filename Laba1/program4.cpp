#include <iostream>
#include <vector>
using namespace std;

class Book
{
private:
    string author;
    string name;
    bool type;

public:
    // конструктор
    Book(string author1, string name1, bool type1) {
        author = author1;
        name = name1;
        type = type1;
    }

    // Геттер 
    bool getType() const {
        return type;
    }


    void print() const {
        cout << "Автор: " << author
            << ", Название: " << name
            << ", Тип: " << (type ? "Художественная" : "Техническая") << endl;

    }
};

void examination(vector<Book>& books, string author, string name, bool type) {
    if (author.empty()) {
        cout << "у книги  " << name << " не указан автор. Она не будет добавлена в библиотеку " << endl;
        return;
    }
    if (name.empty()) {
        cout << "у автора " << author << " не указано название. Она не будет добавлена в библиотеку " << endl;
        return;
    }
    books.push_back(Book(author, name, type));
}

// вывод всей библиотеки
void printLibrary(const vector<Book>& library) {
    cout << "БИБЛИОТЕКА:" << endl;
    for (const Book& book : library) {
        book.print();
    }

}
void F_switch(vector<Book>& library) {
    int artistical = 0;
    int technical = 0;

    for (const Book& book : library) {
        switch (book.getType()) {
        case true:
            artistical += 1;
            break;
        case false:
            technical += 1;
            break;
        }
    }
    cout << "оператор switch:" << endl;
    cout << "Художественных книг: " << artistical << endl;
    cout << "Технических книг: " << technical << endl;
}

void F_if_else(vector<Book>& library) {
    int artistical = 0;
    int technical = 0;

    for (const Book& book : library) {
        if (book.getType() == true) {
            artistical += 1;
        }
        else {
            technical += 1;
        }
    }

    cout << "оператор if_else:" << endl;
    cout << "Художественных книг: " << artistical << endl;
    cout << "Технических книг: " << technical << endl;
}

int main() {
    setlocale(LC_ALL, "rus");
    vector<Book> library;

    examination(library, "", "Преступление и наказание", true);
    examination(library, "Таненбаум", "", false);
    examination(library, "Булгаков", "Мастер и Маргарита", true);
    examination(library, "Кнут", "Искусство программирования", false);
    examination(library, "Гоголь", "Мертвые души", true);
    examination(library, "Гамма", "Паттерны проектирования", false);

    //было бы прикольно если через клаву добавлялись книги!!!!!!!!!!!!!!!!!!!
    printLibrary(library);


    F_switch(library);
    F_if_else(library);

    return 0;
}
