#include <bits/stdc++.h>
using namespace std;
template <typename T>
class dataStruct{
public:
    dataStruct() {};
    virtual ~dataStruct() {};
    virtual void print() = 0;
    virtual int getSize() const = 0;
    virtual bool isEmpty() const = 0;
    virtual void clear() = 0;
    virtual void fill(const T &) = 0;
    virtual void insert(const T &) = 0;
    virtual void remove(const T &, function<bool (const T&, const T&)>) = 0; 
    virtual T* find(const T &, function<bool (const T&, const T&)>) const = 0;
    virtual void traverse(function<void(T&)>) = 0; 
};
template <typename T>
class array: public dataStruct{
private:
    T* arr;
    int size;
public:
    void removeIdx(int);
    int findIdx(int);
    void reverse() = 0;
    T& operator[](int) = 0;
    array<T>* merge(array<T>*) = 0;
    array<T>* split(int, int) = 0;
};
template <typename T>
class linkedList: public dataStruct{

};
////////////////////////////////////////////////////////////////////////////////
class algo{
public:
    ~algo() = default;
    virtual void print() = 0;
};
class bubbleSort: public algo{

};
class insertionSort: public algo{

};
class selectionSort: public algo{

};
////////////////////////////////////////////////////////////////////////////////
int main(){
    return 0;
}
