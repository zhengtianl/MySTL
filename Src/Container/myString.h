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
            char* m_data; // Pointer to string data
            size_t m_nSize; // Length of string
            size_t m_nTotalSize; // Total size of allocated buffer
            // Resize buffer to given size

            public:
            typedef charType char_type; //设置数据类型
            typedef charType* iterator; //设置迭代器
            //construct
            typedef charType char_type; //设置数据类型
            typedef charType* iterator; //设置迭代器

            // Construct
            myString(const charType* str = "") :
                    m_data(new char_type[strlen(str) + 1]),
                    m_nSize(strlen(str)),
                    m_nTotalSize(m_nSize + 1) {
                    std::copy(str, str + m_nSize, m_data);
                    m_data[m_nSize] = '\0';
            }

            // Destructor
            ~myString() {
                delete[] m_data;
                m_data = nullptr;
                m_nSize = 0;
                m_nTotalSize = 0;
            }

            // Copy constructor
            myString(const myString& str) :
                    m_data(new char_type[str.m_nTotalSize]),
                    m_nSize(str.m_nSize),
                    m_nTotalSize(str.m_nTotalSize) {
                std::copy(str.m_data, str.m_data + m_nSize, m_data);
                m_data[m_nSize] = '\0';
            }

            // Copy assignment operator
            myString& operator=(const myString& s) {
                if (this != &s) {
                    delete[] m_data;
                    m_nSize = s.m_nSize;
                    m_nTotalSize = s.m_nTotalSize;
                    m_data = new char_type[m_nTotalSize];
                    std::copy(s.m_data, s.m_data + m_nSize, m_data);
                    m_data[m_nSize] = '\0';
                }
                return *this;
            }

            myString& operator+=(const myString& rhs)
            {
                size_t new_size = m_nSize + rhs.m_nSize;
                char* new_data = new char[new_size + 1];
                strcpy(new_data, m_data);
                strcat(new_data, rhs.m_data);
                delete[] m_data;
                m_data = new_data;
                m_nSize = new_size;
                return *this;
            }


            friend myString operator+(const myString& lhs, const myString& rhs)
            {
                myString result(lhs);
                result += rhs;
                return result;
            }

            // ...
            friend std::ostream& operator<< (std::ostream& os, const myString& str)
            {
                return os << str.m_data;
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
            void reserve(::size_t n)
            {
                if( n  > m_nTotalSize)
                {
                    char* temp = new char(n + 1);
                    strcpy(temp, m_data);
                    delete[] m_data;
                    m_data = temp;
                    m_nTotalSize = n;
                }
            }

            //Modifiers:

            void push_back(char_type ch)
            {
                append(1,ch);
            }
            void pop_back()
            {
                m_nSize = m_nSize - 2;
            }



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
            char* c_str()
            {
                return m_data;
            }

            ::size_t find(char* str, ::size_t index)
            {
                char* p = std::strstr(m_data + index, str);
                if( p == nullptr)
                {
                    return -1;
                }
                else
                {
                    return p - str;
                }
            }

            //Member constants



            //Non-member function overloads
        };
        }

#endif //MYSTL_MYSTRING_H
