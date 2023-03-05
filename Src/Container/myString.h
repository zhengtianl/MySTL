//
// Created by StarkLu on 2023/3/4.
//

#ifndef MYSTL_MYSTRING_H
#define MYSTL_MYSTRING_H

#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
namespace MySTL
        {
        template <typename charType>
        class myString
        {
            private:
            charType* m_data; //设置指针指向数值 包含指针成员的类都需要拷贝构造函数
            size_t  m_nSize; //设置大小
            size_t  m_nTotalSize;//设置容器容量


            public:
            typedef charType char_type; //设置数据类型
            typedef charType* iterator; //设置迭代器
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
                m_data = new char_type[m_nTotalSize];
                for(int i = 0; i < m_nSize; i++)
                {
                    m_data[i] = str.m_data[i];
                }

            }
            //Iterators:
            iterator begin()
            {
                return m_data;
            }

            iterator end()
            {
                return m_data + m_nSize;
            }

            bool operator == (const myString& str)
            {
                if(m_nSize != str.size())
                {
                    return false;
                }
                for(int i = 0; i < m_nSize; i++)
                {
                    if (m_data[i] != str[i])
                    {
                        return false;
                    }
                }
                return true;
            }

            value_type& operator[](::size_t index)
            {
                return m_data[index];
            }
            // Capacity:

            ::size_t size() {
                return m_nSize;
            }

            ::size_t length() {
                return m_nSize;
            }

            ::size_t max_size() {
                return m_nTotalSize;
            }

            bool empty() {
                return m_nSize == 0;
            }
            //Element access:
            char_type& operator[](::size_t index)
            {
                return m_data[index];
            }


            //Modifiers:

            //String operations:
            struct Operations{
                static int compare(const char_type *s1, const char_type *s2, ::size_t n)
                {
                    for (::size_t i = 0; i < n; ++i) {
                        if (*s1 < *s2) {
                            return -1;
                        }
                        if (*s1 > *s2) {
                            return 1;
                        }
                        ++s1;
                        ++s2;
                    }
                    return 0;
                }

                static int copy(char_type *container, const char_type *src, ::size_t n)
                {
                    char_type *r = container;
                    for (int i = 0; i < n; i++) {
                        *container = *src;
                        ++container;
                        ++src;
                    }
                    return r;
                }

            };
            //Member constants

            //Non-member function overloads
        };
        }

#endif //MYSTL_MYSTRING_H
