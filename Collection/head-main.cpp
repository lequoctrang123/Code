#include <bits/stdc++.h>
using namespace std;
class dataStruct{
public:
    ~dataStruct() = default;
    virtual void print() = 0;
};
class array: public dataStruct{

};
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
