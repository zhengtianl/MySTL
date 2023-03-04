//
// Created by StarkLu on 2023/2/28.
//
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
namespace MySTL
{
    template <typename T>
    class Vector
    {
    public:
        typedef T value_type; //设置数据类型
        typedef T* iterator;    //设置迭代器

        //constructor
        Vector(): m_data(nullptr), m_nSize(0), m_nTotalSize(0){};
        //destructor
        ~Vector()
        {
            delete[]m_data; //释放指针
            m_data = nullptr;
            m_nSize =0;
            m_nTotalSize = 0;
        }
        //copy constructor
        Vector(const Vector& vec)
        {
            m_nSize = vec.m_nSize;
            m_nTotalSize = vec.m_nTotalSize;
            m_data = new value_type[m_nTotalSize]; //构建一个容器大小和vector相同的容器，把值传进去
            for(int i = 0; i < m_nSize; i++)
            {
                m_data[i] = vec.m_data[i];
            }
        }
        
        //operator=
        Vector& operator=(const Vector& vec)
        {
            if (this == &vec)
            {
                return *this;
            }
            value_type* temp = new value_type[vec.m_nTotalSize];
            for(int i = 0; i < vec.m_nSize; i++)
            {
                temp[i] = vec.m_data[i];
            }
            delete[] m_data;
            m_data = temp;
            m_nSize = vec.m_nTotalSize;
            m_nTotalSize = vec.m_nTotalSize;
            return this;
        }

        //Capacity:
        ::size_t size()
        {
            return m_nSize;
        }
        ::size_t capacity()
        {
            return m_nTotalSize;
        }
        bool empty()
        {
            return m_nSize == 0;
        }

        
        //Element access:
        
        value_type& operator[](::size_t index)
        {
            return m_data[index];
        }
        
        value_type front()
        {
            return m_data[0];
        }
        value_type back()
        {
            return m_data[m_nSize - 1];
        }

        
        //Modifiers
        void insert(iterator it, value_type value)
        {
            int index = it - m_data;
            if(0 == m_nTotalSize)
            {
                m_nTotalSize = 1;
                m_data = new value_type[1];
                m_data[0] = value;
            }

            else if(m_nSize + 1 > m_nTotalSize)
            {
                m_nTotalSize *= 2;
                value_type *temp = new value_type[m_nTotalSize];
                for(int i = 0; i < index; i++)
                {
                    temp[i] = m_data[i];
                }
                temp[index] = value;
                for(int i = index; i < m_nSize; i++)
                {
                    temp[i] == m_data[i];
                }
                delete[] m_data;
                m_data = temp;
            }

            else
            {
                for(int i = m_nSize - 1; i >= index; i++)
                {
                    m_data[i + 1] = m_data[i];
                }
                m_data[index] = value;
                return;
            }

            ++m_nSize;

        }

        void erase(iterator it)
        {
            ::size_t index = it - m_data;
            for (int i = index; i< m_nSize - 1; i++)
            {
                m_data[i] = m_data[i+1];
            }
            --m_nSize;
        }

        void push_back(value_type value)
        {
            if(0 == m_nTotalSize)
            {
                m_nTotalSize = 1;
                m_data = new value_type[1];
            }
            else if (m_nSize + 1 > m_nTotalSize)
            {
                m_nTotalSize *= 2; //将数组的size倍增：：这里使用1.5倍增防止爆栈
                value_type *temp = new value_type[m_nTotalSize]; //构造两倍大小的数组将值传进去
                for(int i=0; i< m_nSize; i++) //将temp容器填满
                {
                    temp[i] = m_data[i];
                }
                delete[] m_data; //删除原来的指针防止内存泄露
                m_data = temp; //m_data所在地址指向tmp所在地址
            }
            m_data[m_nSize] = value; //将最后一位赋值为value
            m_nSize ++; //加到容器课查询的size
        }

        void pop_back()
        {
            if(0 == m_nSize)
            {
                throw "you can not pop an empty Vector";
            }
            --m_nSize;
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
        // compare
        bool operator == (const Vector& vec)
        {
            if(m_nSize != vec.size())
            {
                return false;
            }
            for(int i = 0; i < m_nSize; i++)
            {
                if (m_data[i] != vec[i])
                {
                    return false;
                }
            }
            return true;
        }

    private:
        value_type* m_data; //设置指针指向数值
        size_t  m_nSize; //设置大小
        size_t  m_nTotalSize;//设置容器容量
    };

}




