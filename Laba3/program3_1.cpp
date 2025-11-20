#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Detail {
protected:
    string name;
    Detail(const string& n) : name(n) {}
public:
    virtual ~Detail() = default;
    virtual void show() const {
        cout << "Деталь: " << name << endl;
    }
    template <typename T, typename... Args>
    friend shared_ptr<T> create(vector<shared_ptr<Detail>>& storage, Args&&... args);
};
class Assembly : public Detail {
    int partsCount;
protected:
    Assembly(const string& n, int p) : Detail(n), partsCount(p) {}
public:
    void show() const override {
        cout << "Сборка: " << name << ", количество деталей: " << partsCount << endl;
    }
    template <typename T, typename... Args>
    friend shared_ptr<T> create(vector<shared_ptr<Detail>>& storage, Args&&... args);
};
//  дружественная функция
template <typename T, typename... Args>
shared_ptr<T> create(vector<shared_ptr<Detail>>& storage, Args&&... args) {
    shared_ptr<T> obj(new T(forward<Args>(args)...));
    storage.push_back(obj);
    return obj;
}
int main() {
    vector<shared_ptr<Detail>> storage;
    setlocale(LC_ALL, "ru");
    auto d1 = create<Detail>(storage, "Болт");
    auto d2 = create<Detail>(storage, "Гайка");
    auto d3 = create<Detail>(storage, "Шайба");
    auto d4 = create<Detail>(storage, "Вал");
    auto d5 = create<Detail>(storage, "Шестерня");


    auto a1 = create<Assembly>(storage, "Двигатель", 120);
    auto a2 = create<Assembly>(storage, "Редуктор", 45);
    auto a3 = create<Assembly>(storage, "Коробка передач", 60);
    auto a4 = create<Assembly>(storage, "Тормозная система", 30);


    cout << "Содержимое хранилища:\n";
    for (const auto& obj : storage) {
        obj->show();
    }
    return 0;
}
