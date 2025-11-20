#include <iostream>
#include <string>
using namespace std;

class Publication {
private:
    string title;
    float price;

public:
    virtual void getdata() {
        cout << "Введите название: ";
        cin.ignore(1000, '\n');
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
    }

    virtual void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << " руб." << endl;
    }


    string getTitle() const { return title; }
    float getPrice() const { return price; }


    void setTitle(const string& newTitle) { title = newTitle; }
    void setPrice(float newPrice) {
        if (newPrice >= 0) price = newPrice;
    }
};

class Book : public Publication {
private:
    int pages;
public:
    void getdata() override {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pages;
    }
    void putdata() const override {
        Publication::putdata();
        cout << "Количество страниц: " << pages << endl;
    }
    int getPages() const { return pages; }
    void setPages(int newPages) {
        if (newPages > 0) pages = newPages;
    }
};

class Type : public Publication {
private:
    float time;
public:
    void getdata() override {
        Publication::getdata();
        cout << "Введите время записи (в минутах): ";
        cin >> time;
    }
    void putdata() const override {
        Publication::putdata();
        cout << "Время записи: " << time << " минут" << endl;
    }
    float getTime() const { return time; }
    void setTime(float newTime) {
        if (newTime >= 0) time = newTime;
    }
};
int main() {
    setlocale(LC_ALL, "rus");
    cout << endl;
    cout << "     ВВЕДИТЕ ДАННЫЕ КНИГИ:   " << endl;
    Book book;
    cout << "Введите данные о книге:" << endl;
    book.getdata();
    cout << "Данные о книге" << endl;
    book.putdata();
    cout << endl;
    cout << "   ВВЕДИТЕ ДАННЫЕ АУДИОКНИГИ:       " << endl;
    Type audioBook;
    cout << "Введите данные об аудиокниге:" << endl;
    audioBook.getdata();
    cout << "Данные об аудиокниге" << endl;
    audioBook.putdata();

    return 0;
}
