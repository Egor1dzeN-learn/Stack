//
// Created by egorm on 25.10.2023.
//

#ifndef UNTITLED7_TSTACK_H
#define UNTITLED7_TSTACK_H

#include <iostream>


template<typename T>
class TStack {
private:
    T *begin;
    T *end;
    int size;
public:
    TStack(){
        size = 100;
        begin = new T[size];
        end = reinterpret_cast<int>(begin);
    }
    TStack(T _n){

        if(_n>=0){
            size = _n;
            begin = new T[size];
            end = begin;
        }else{
            throw "Invalid Argument";
        }
    }
    TStack(const TStack& s){
        size = s.size;
        begin = new T[size];
        for(int i =0;i<size;++i){
            begin[i] = s.begin[i];
        }
        end = begin + size;
    }
    ~TStack(){
        delete[] begin;
    }
    void push(T el){
        int now_size = (end - begin);
        std::cout<<now_size<<size<<std::endl;
        if(now_size >= size){
            T* tmp = new T[size*2];
            delete[] begin;
            for(int i = 0;i<size;++i){
                tmp[i] = begin[i];
            }
            begin = tmp;
            begin[size] = el;
            std::cout<<"!!!"<<begin[size]<<std::endl;
            end = begin +size+1;
            size = size*2;
            std::cout<<size<<std::endl;
        }else{
            int ind = (end - begin);
            begin[ind] = el;
            std::cout<<begin[ind]<<std::endl;
            end++;

        }

    }
    T top(){
        if(!isEmpty()){
            return *(end--);
        }
    }
    void pop(){
        end--;
    }
    bool isEmpty(){
        return begin == end;
    }
    bool operator==(const TStack& s){
        if(s.end - s.begin != end - begin){
            return false;
        }
        for(int i =0;i<end-begin;++i){
            if(begin[i] !=  s.begin[i]){
                return false;
            }
        }
        return true;
    }
    friend std::ostream& operator<<(std::ostream &out, const TStack &s){
        for(size_t i = 0;i<s.end - s.begin;++i){
            out<<s.begin[i];
        }
        return out;
    }
};



#endif //UNTITLED7_TSTACK_H
