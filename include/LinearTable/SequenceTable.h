//
// Created by Administrator on 2020/7/6.
//˳������ݽṹ
//
#ifndef DATA_STRUCTURE_C_SEQUENCETABLE_H
#define DATA_STRUCTURE_C_SEQUENCETABLE_H
#include <iostream>
#include <cassert>
template <typename T>
/*˳�����������ʵ�֣��洢�ռ���ʱ�Զ�����*/
class Sqlist{
    private:
        T* data;//Ԫ��
        int MaxSize=100;//�������
        int length=0;//���Ͷ���
    public:
        Sqlist(){data=new T[MaxSize];}
        Sqlist(int MaxSize){this->MaxSize=MaxSize;data=new T[MaxSize];}
        Sqlist(T* data,int size);//������ʽ��ʼ����
        ~Sqlist() {delete [] data;}
        int Length(){ return length;};//��
        void SetLength(int n){length=n; }
        bool Empty(){ return length==0;}//�п�
        T& GetElem(int i);//���ҵ�iλ��Ԫ�ص�ֵ
        void SetElem(int i, const T& e);
        int LocateElem(const T &e);//���ҵ�һ��ֵΪe��Ԫ�ص�λ��
        void ListInsert(const T &e);//�ڱ�β���������
        void ListInsert(int i,const T &e);//�ڵ�i��λ�ò���Ԫ��
        void ListDelete();//ɾ����β����
        void ListDelete(int i);//ɾ����β��i��λ�õ�����
        void PrintList();//���
};

template <typename T>
Sqlist<T>::Sqlist(T* d,int size){
    data=new T[MaxSize];
    for(int i=0;i<size;i++){
        this->ListInsert(d[i]);
    }
}

template <typename T>
T& Sqlist<T>::GetElem(int i) {
    assert(i>=0&&i<length);
    return data[i];
}

template <typename T>
void Sqlist<T>::SetElem(int i, const T &e) {
    assert(i>=0&&i<length);
    data[i]=e;
}

template <typename T>
int Sqlist<T>::LocateElem(const T &e) {
    int i=0;
    for(;i<length;i++){
        if(data[i]==e){
            return i;
        }
    }
    return -1;
}
template <typename T>
void Sqlist<T>::ListInsert(const T &e) {
    if(MaxSize<=length){
        MaxSize*=2;
        T* newdata=new T[MaxSize];
        for(int i=0;i<length;i++){
            newdata[i]=data[i];
        }
        delete[] data;
        data=newdata;
    }
    data[length++]=e;
}

template <typename T>
void Sqlist<T>::ListInsert(int i,const T &e) {
    if(i<0||i>length){
        std::cout<<"i������Χ"<<std::endl;
        return;
    }
    if(MaxSize>length){
        MaxSize*=2;
        T* newdata=new T[MaxSize];
        for(int j=0;j<length;j++)
        {
            newdata[j]=data[j];
        }
        delete [] data;
        data=newdata;
    }
    for(int j=length;j>=i;j--){
        data[j]=data[j-1];
    }
    data[i]=e;
    length++;
}

template <typename T>
void Sqlist<T>::ListDelete() {
    if(length<0){
        std::cout<<"��Ϊ��"<<std::endl;
        return;
    }
    length--;
}

template <typename T>
void Sqlist<T>::ListDelete(int i){
    if(i<0||i>length-1){
        std::cout<<"i������Χ"<<std::endl;
        return;
    }
    for(int j=i+1;j<length;j++){
        data[j-1]=data[j];
    }
    length--;
}

template <typename T>
void Sqlist<T>::PrintList() {
    for(int i=0;i<length;i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;
}
#endif //DATA_STRUCTURE_C_SEQUENCETABLE_H
