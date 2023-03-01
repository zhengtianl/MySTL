//
// Created by StarkLu on 2023/2/28.
//

#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
namespace MySTL {
    template <typename T>
    class Vector
    {
    public:
        typedef T value_type; //设置数据类型
        typedef T* iterator;    //设置迭代器

        //构造函数，初始化值
        Vector(): m_data(nullptr), m_nSize(0), m_nTotalSize(0){};
        //析构函数，释放指针
        ~Vector()
        {
            delete[]m_data; //释放指针
            m_data = nullptr;
            m_nSize =0;
            m_nTotalSize = 0;
        }
        //拷贝构造函数
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
        //等于号将原数组deep copy
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

        void push_back(value_type value)
        {
            if(0 == m_nTotalSize)
            {
                m_nTotalSize = 1;
                m_data = new value_type[1];
            }
            else if (m_nSize + 1 > m_nTotalSize)
            {
                m_nTotalSize *= 1.5; //将数组的size倍增：：这里使用1.5倍增防止爆栈
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

        void pop_back(value_type value)
        {

        }

    private:
        value_type* m_data; //设置指针指向数值
        size_t  m_nSize; //设置大小
        size_t  m_nTotalSize;//设置容器容量
    };


}