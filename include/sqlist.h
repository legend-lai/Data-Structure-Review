#ifndef SQLIST_H
#define SQLIST_H

#include <iostream>
#define MAXLENGTH 100


template <typename T>
class SqList
{
public:
    int length;
    int MaxLength;
    T ary[MAXLENGTH];

    SqList(): 
        length(0), MaxLength(MAXLENGTH), ary{(T)0}{}
    
    SqList(std::initializer_list<T> l): MaxLength(MAXLENGTH)
    {
        for(int i = 0; i < l.size(); ++i){
            ary[i] = *(l.begin() + i);
        }
        length = l.size();
    }

    void print(){
        for(int i = 0; i < length; ++i)
            std::cout << ary[i] << (char)(i!=length-1?' ':'\n');
    }

    T& operator[](int i){
        return ary[i];
    }
};






#endif