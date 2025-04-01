// VectorLikeContainer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <stdexcept>
#include <memory> // For unique_ptr

using namespace std;

template <typename T>
class VectorLikeContainer {
private:
    T* data;
    int size;
    int capacity;

    void resize(int newCapacity) {
        cout << "resize()" << endl;
        if (newCapacity < size) {
            throw std::invalid_argument("New capacity must be greater or equal to current size.");
        }

        T* newData = new T[newCapacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = std::move(data[i]); // Move elements to new array.
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    //default constructor
    VectorLikeContainer() : data(nullptr), size(0), capacity(0) {
        cout << "Default constructor" << endl;
    }

    //parameterized constructor
    VectorLikeContainer(int initialCapacity) : size(0), capacity(initialCapacity) {
        cout << "parameterized constructor" << endl;
        if (initialCapacity > 0) {
            data = new T[initialCapacity];
        }
        else {
            data = nullptr;
        }
    }

    //copy constructor
    VectorLikeContainer(const VectorLikeContainer& other) : size(other.size), capacity(other.capacity) {
        cout << "Copy constructor" << endl;
        data = new T[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    //move constructor with no exception
    VectorLikeContainer(VectorLikeContainer&& other) noexcept : data(other.data), size(other.size), capacity(other.capacity) {
        cout << "Move constructor" << endl;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    //assignment operator
    VectorLikeContainer& operator=(const VectorLikeContainer& other) {
        cout << "Assignment operator without exception" << endl;
        if (this != &other) {
            VectorLikeContainer temp(other);
            std::swap(data, temp.data);
            std::swap(size, temp.size);
            std::swap(capacity, temp.capacity);
        }
        return *this;
    }

    //assignment operator with no exception
    VectorLikeContainer& operator=(VectorLikeContainer&& other) noexcept {
        cout << "Assignment operator with exception" << endl;
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            capacity = other.capacity;

            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }

    //destructor
    ~VectorLikeContainer() {
        cout << "Destructor" << endl;
        delete[] data;
    }

    //operator overloading
    T& operator[](int index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range.");
        }
        return data[index];
    }

    const T& operator[](int index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range.");
        }
        return data[index];
    }

    //pushback functionality
    void push_back(const T& value) {
        cout << "pushback functionality with const" << endl;
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
    }

    //pushback functionality
    void push_back(T&& value) {
        cout << "pushback functionality without const" << endl;
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = std::move(value);
    }
    //popback functionality
    void pop_back() {
        cout << "popback functionality with const" << endl;
        if (size > 0) {
            --size;
        }
    }

    int getSize() const { 
        cout << "getSize functionality" << endl;
        return size;
    }
    int getCapacity() const {
        cout << "getCapacity functionality" << endl;
        return capacity;
    }
    bool empty() const {
        cout << "empty functionality" << endl;
        return size == 0;
    }
    void clear() {
        cout << "clear functionality" << endl;
        size = 0;
    }

    void reserve(int newCapacity) {
        cout << "reszing from reserve functionality" << endl;
        if (newCapacity > capacity) {
            resize(newCapacity);
        }
    }

    //iterator functions
    T* begin() { return data; }
    T* end() { return data + size; }

    const T* begin() const { return data; }
    const T* end() const { return data + size; }
};

int main() {

    VectorLikeContainer<int> objvec;
    objvec.push_back(10);
    objvec.push_back(20);
    objvec.push_back(30);

    for (int i = 0; i < objvec.getSize(); ++i) {
        std::cout << objvec[i] << " "<<endl;
    }
    std::cout << std::endl;

    VectorLikeContainer<int> obj2vec = objvec; // Copy constructor
    obj2vec.push_back(40);

    for (int x : obj2vec) { // range-based for loop
        std::cout << x << " ";
    }
    std::cout << std::endl;

    VectorLikeContainer<int> obj3vec = std::move(objvec); // Move constructor
    std::cout << "objvec size after move: " << objvec.getSize() << std::endl;
    for (int x : obj3vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    obj3vec.clear();
    if (obj3vec.empty())
    {
        std::cout << "obj3vec is empty" << std::endl;
    }

    return 0;
}