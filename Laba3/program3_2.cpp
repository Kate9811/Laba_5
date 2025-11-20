#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
using namespace std;
class Base {
public:
    virtual void show() const {
        cout << "Это объект Base" << endl;
    }
    virtual Base* clone() const {
        return new Base(*this);
    }
    virtual ~Base() {
        cout << "Деструктор Base" << endl;
    }
};
class Derived : public Base {
public:
    void show() const override {
        cout << "Это объект Derived" << endl;
    }
    Base* clone() const override {
        return new Derived(*this);
    }
    ~Derived() override {
        cout << "Деструктор Derived" << endl;
    }
};
//добавление копий
void add(vector<unique_ptr<Base>>& storage, const Base& obj) {
    storage.push_back(unique_ptr<Base>(obj.clone()));
}
int main() {
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned>(time(nullptr)));
    vector<unique_ptr<Base>> storage;
    for (int i = 0; i < 10; ++i) {
        int r = rand();
        if (r % 2 == 0) {
            Base b;
            add(storage, b);
        }
        else {
            Derived d;
            add(storage, d);
        }
    }

    cout << "Полиморфное поведение объектов в хранилище:\n";
    for (const auto& obj : storage) {
        obj->show();
    }

    return 0;
}
