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
#define ARRLIST_BLOCK_SIZE 64
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
    virtual void removeAll(const T&, function<bool (const T&, const T&)>) = 0; //advance cua dong tren
    virtual T* find(const T&, function<bool (const T&, const T&)>) = 0; //tim va tra ve con tro tai phan tu can tim
    virtual int findIdx(const T&, function<bool (const T&, const T&)>) = 0; //tim va tra ve idx tai vi tri phan tu can tim
    virtual int countEle(const T&, function<bool (const T&, const T&)>) = 0; //dem so lan xuat hien
    virtual void revert() = 0;
    virtual T& operator[](int) = 0;
    virtual List<T>* merge(List<T>*) = 0;
    virtual List<T>* split(int, int) = 0;
    virtual void traverse(function<void (T&)>) = 0;
};

/// ARRAY LIST

template <typename T> //abstract list -> can virtual cho cac phuong thuc
class ArrList: public List<T>{
protected:
    T *pD;
    int nE, cap;
public:
    ArrList(): pD(nullptr), nE(0), cap(0) {} 
    ArrList(int n): pD(nullptr), nE(0), cap(0) {resize(n);} 
    ~ArrList() {clear();} 

    int getSize() const { return nE;} 
    bool isEmpty() const {return !nE;} 
    void clear(){
        if(pD){
            delete [] pD;
            pD=nullptr;
            nE=0;
            cap=0;
        }
    }
    void fill(const T& val){
        //todo
    } 
    void resize(int n){             //cap phat theo block
        int newN = (N + ARRLIST_BLOCK_SIZE - 1)/ ARRLIST_BLOCK_SIZE*ARRLIST_BLOCK_SIZE;
        if(newN < cap){
            if(nE > N) nE=N;
        }
        T *pND = new T[newN];        
        if(pD){
            for(T *p = pD, *pE = pD + nE, *pDes = pND; p!= pE;){
                *pDes++ = move(*p++);
            }
        }
        pD = pND;
        cap = newN;
    }
    void insert(const T& val, int index){               //Bo check idx, dua len precon cho user biet
        if(nE>=cap) resize(nE+1);
        for(T *p=pD+nE, *pIdx = pD+idx; p!=pIdx; --p){
            *p = move(*(p-1));
        }
        *(pD + idx) = val;
        ++nE;
    } 
    void removeIdx(int idx){
        for(T* p=pD+idx, *pE=pD+nE-1; p!=pE; ++p){
            *p = move(*(p+1));
        }
        --nE;
    }
    //virtual void remove(const T&, bool (cmp*)(const T&, const T&)) = 0; //remove voi cac dieu kien khac nhau
    void removeAll(const T& val, function<bool (const T&, const T&)> eqCmp = [](const T& a, const T& ref){return a==ref}){
        for(T *p=pD; , *pE=pD+nE, *pNR = nullptr; p!=pE; ++p){
            if(eqCmp(*p,val)){
                if(!pNR) pNR = p+1;
                while(pNR != pE && eqCmp(*pNR, val)) ++pNR;
                if(pNR==pE){
                    nE=p-pD;
                    return;
                }
                *p = move(*pNR++);
            }
        }
    }
    T* find(const T& val, function<bool (const T&, const T&)> eqCmp = [](const T& a, const T& ref){return a==ref}){
        for(T *p=pD; , *pE=pD+nE; p!=pE; ++p){
            if(eqCmp(*p,val)) return p;
        }
        return nullptr;
    }
    int findIdx(const T& val, function<bool (const T&, const T&)> eqCmp = [](const T& a, const T& ref){return a==ref} ){
        for(T *p=pD; , *pE=pD+nE; p!=pE; ++p){
            if(eqCmp(*p,val)) return p-pD;
        }
        return -1;
    }
    int countEle(const T& val, function<bool (const T&, const T&)> eqCmp = [](const T& a, const T& ref){return a==ref}){
        int count=0;
        for(T *p=pD, *pE=pD+nE; p!=pE; ++p){
            if(edCmp(*p,val)){
                ++count;
            }
        }
        return count;
    }
    void revert(){
        for(T *pL=pD, *pL=pD+nE; pL<pR; ++pL, --pR){
            T temp(move(*pL)); //move constructor
            *pL = move(*pR);
            *pR = move(*pL);
        }
    }
    T& operator[](int iddx){
        return pD[idx];
    };
    List<T>* merge(List<T> *pL){
        resize(nE+pL->getSize());
        T* p=pD+nE;
        pL->traverse([&p](T &val){*p++=val;});
        return this
    };
    List<T>* split(int bIdx, int eIdx){
        T *p = pD + bIdx, *pE = pd + eIdx, *pEL=pD+nE;
        ArrList<T> *pNL = new ArrList<T>(pE-p);
        pDes = pNL->pD;
        while(p!=pE){
            *pDes++ = move(*p++);
        }
        pNL->nE=eIdx-bIdx;
        p = pD + bIdx;
        while(pE!=pEL){
            *p++=move(*pE++);
        }
        nE = p-pD;
        return pNL;
    }
    void traverse(function<void (T&)>){
        for(T *p=pD, *pE=pD+nE; p!=pE){
            op([&]++);
        }
    }
};