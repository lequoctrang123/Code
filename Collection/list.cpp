// Chap 4: List
// 1. constructor / destructor / clear / fill
// 2. insert / remove
// 3. find / countEle
// 4. revert
// 5. swap, replace
// 6. merge / split
// 7. getSize, isEmpty
// 8. access / retrieve
// 9. traverse

#include <iostream>
#include <string>
using namespace std;

template <typename T> //abstract list -> can virtual cho cac phuong thuc
class List{
public:
    List() {} 
    virtual ~List() {} 

    virtual int getSize() const = 0; 
    virtual bool isEmpty() const = 0; 
    virtual void clear() = 0; 
    virtual void fill(const T&) = 0; 
    virtual void insert(const T&, int) = 0; 
    virtual void removeIdx(int) = 0; //phai doi ten de tranh lo hong voi dong duoi (khi T la int)
    //virtual void remove(const T&, bool (cmp*)(const T&, const T&)) = 0; //remove voi cac dieu kien khac nhau
    virtual void remove(const T&, function<bool (const T&, const T&)>) = 0; //advance cua dong tren
    virtual T* find(const T&, function<bool (const T&, const T&)>) = 0; //tim va tra ve con tro tai phan tu can tim
    virtual int findIdx(const T&, function<bool (const T&, const T&)>) = 0; //tim va tra ve idx tai vi tri phan tu can tim
    virtual int countEle(const T&, function<bool (const T&, const T&)>) = 0; //dem so lan xuat hien
    virtual void revert() = 0;
    virtual T& operator[](int) = 0;
    virtual List<T>* merge(List<T>*) = 0;
    virtual List<T>* split(int, int) = 0;
    virtual void traverse(function<void (T&)>) = 0;
};