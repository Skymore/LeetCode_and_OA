#include <memory>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Meal {
private:
    float price;
    
public:
    Meal(float price) : price(price) {}
    
    float getPrice() const {
        return price;
    }
};

class Order {
private:
    vector<shared_ptr<Meal>> meals;
    
public:
    Order() = default;

    vector<shared_ptr<Meal>>* getMeals() {
        return &meals;
    }

    shared_ptr<Order> mergeOrder(shared_ptr<Order> order) {
        auto ans = make_shared<Order>();
        for(auto& meal : meals) {
            ans->meals.push_back(meal);
        }
        if(order) {
            for(auto& meal : *(order->getMeals())) {
                ans->meals.push_back(meal);
            }
        }
        return ans;
    }

    float getBill() const {
        float bill = 0.0;
        for(const auto& meal : meals) {
            bill += meal->getPrice();
        }
        return bill;
    }
};

class Party {
private:
    int size;

public:
    Party(int size) : size(size) {}
    
    int getSize() const {
        return size;
    }
};

class Table {
private:
    int capacity;
    bool available;
    shared_ptr<Order> order;
    
public:
    Table(int capacity) : capacity(capacity), available(true), order(nullptr) {}
    
    int getCapacity() const {
        return capacity;
    }
    
    bool isAvailable() const {
        return available;
    }
    
    void markAvailable() {
        available = true;
    }
    
    void markUnavailable() {
        available = false;
    }
    
    shared_ptr<Order> getCurrentOrder() const {
        return order;
    }
    
    void setOrder(shared_ptr<Order> o) {
        if(!order) {
            order = o;
        } else if(o) {
            order = order->mergeOrder(o);
        } else {
            order = o;
        }
    }
};

class Restaurant {
private:
    vector<shared_ptr<Table>> tables;
    vector<shared_ptr<Meal>> menu;
    
public:
    Restaurant() = default;

    void findTable(shared_ptr<Party> p) {
        for(auto& t : tables) {
            if(t->isAvailable() && t->getCapacity() >= p->getSize()) {
                t->markUnavailable();
                return;
            }
        }
        // Consider throwing an exception if no table found
    }
    
    void takeOrder(shared_ptr<Table> t, shared_ptr<Order> o) {
        t->setOrder(o);
    }
    
    float checkOut(shared_ptr<Table> t) {
        float bill = 0.0;
        if(auto o = t->getCurrentOrder()) {
            bill = o->getBill();
        }
        t->markAvailable();
        t->setOrder(nullptr);
        return bill;
    }

    vector<shared_ptr<Meal>>* getMenu() {
        return &menu;
    }

    void addTable(shared_ptr<Table> t) {
        auto it = tables.begin();
        while(it != tables.end() && (*it)->getCapacity() > t->getCapacity()) {
            ++it;
        }
        tables.insert(it, t);
    }

    string restaurantDescription() const {
        stringstream description;
        int i = 0;
        for(const auto& table : tables) {
            description << "Table: " << i << ", table size: " << table->getCapacity()
                        << ", isAvailable: " << (table->isAvailable() ? "true" : "false") << ".";
            if(auto o = table->getCurrentOrder()) {
                description << " Order price: " << o->getBill() << ".0";
            } else {
                description << " No current order for this table";
            }
            description << "\n";
            i++;
        }
        description << "*****************************************\n";
        return description.str();
    }
};
