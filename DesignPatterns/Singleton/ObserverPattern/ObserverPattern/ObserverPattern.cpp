// ObserverPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
// implementation of store and customer for specific product in the store



#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

// IObserver Interface
class IObserver {
public:
    virtual void update(const string& message) = 0;
    virtual ~IObserver() = default; // Important for polymorphism
};

// ISubject Interface
class ISubject {
public:
    virtual void AddSubscriber(shared_ptr<IObserver> observer) = 0;
    virtual void RemoveSubscriber(shared_ptr<IObserver> observer) = 0;
    virtual void notify(const string& message) = 0;
    virtual ~ISubject() = default; /*Using "= default" is a good practice because it explicitly 
    tells the compiler to generate the default destructor, which can sometimes lead to more 
    efficient code than writing an empty destructor body.*/
};

// Concrete class of IObserver
class Customer : public IObserver {
private:
    string custName;

public:
    Customer(const string& name) : custName(name) {
        cout << "Customer Constructor called" << endl;
    }

    void update(const string& message) override {
        cout << custName << " received notification: " << message << endl;
    }
};

// Concrete class of ISubject
class MobileStore : public ISubject {
private:
    vector<shared_ptr<IObserver>> substList;

public:
    MobileStore() {
        cout << "MobileStore constructor called" << endl;
    }
    void AddSubscriber(shared_ptr<IObserver> observer) override {
        cout << "overriden AddSubscribere called " << endl;
        substList.push_back(observer);
    }

    void RemoveSubscriber(shared_ptr<IObserver> observer) override {
        cout << "overriden RemoveSubscribere called " << endl;
        for (auto it = substList.begin(); it != substList.end(); ++it) {
            if (*it == observer) {
                substList.erase(it);
                return;
            }
        }
    }

    void notify(const string& message) override {
        cout << "overriden notify " << endl;
        for (auto observer : substList) {
            observer->update(message);
        }
    }

    void addNewMobile(const string& mobileName) {
        cout << "addNewMobile called " << endl;
        string message = "New mobile '" + mobileName + "' is available!";
        notify(message);
    }
};

int main() {
    MobileStore store;
    
    shared_ptr<IObserver> customer1 = make_shared<Customer>("Alice");
    shared_ptr<IObserver> customer2 = make_shared<Customer>("Bob");
    shared_ptr<IObserver> customer3 = make_shared<Customer>("Charlie");

    store.AddSubscriber(customer1);
    store.AddSubscriber(customer2);
    store.AddSubscriber(customer3);

    store.addNewMobile("iPhone 15");

    store.RemoveSubscriber(customer2);

    store.addNewMobile("Samsung Galaxy S23");

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
