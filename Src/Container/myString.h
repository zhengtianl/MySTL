//
// Created by StarkLu on 2023/2/28.
//

#ifndef MYSTL_VECTOR_H
#define MYSTL_VECTOR_H
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
namespace MySTL
{
    template <typename T>
    class myString
    {
        public:
            typedef T value_type; //设置数据类型
            typedef T* iterator; //设置迭代器
            //construct
            myString(): m_data(nullptr), m_nSize(0), m_nTotalSize(0){};
            //destructor
            ~myString()
            {
                delete[]m_data;
                m_data = nullptr;
                m_nSize = 0;
                m_nTotalSize = 0;
            }
            //destructor
            myString(const myString& str)
            {
                m_nSize = str.m_nSize;
                m_nTotalSize = str.m_nTotalSize;
                m_data = new value_type[m_nTotalSize];
                for(int i = 0; i < m_nSize; i++)
                {
                    m_data[i] = str.m_data[i];
                }

            }
            //Iterators:    
            
            // Capacity:
            ::size_t size()
            {
                return m_nSize;
            }
            ::size_t length()
            {
                return m_nSize;
            }
            ::size_t max_size()
            {
                return m_nTotalSize;
            }
            //Element access:

            //Modifiers:

            //String operations:

            //Member constants

            //Non-member function overloads


        private:
            value_type* m_data; //设置指针指向数值 包含指针成员的类都需要拷贝构造函数
            size_t  m_nSize; //设置大小
            size_t  m_nTotalSize;//设置容器容量
    };

}
#endif