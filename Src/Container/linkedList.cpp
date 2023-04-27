#include<iostream>
#include<assert.h>
using namespace std;

typedef int Datatype;
typedef struct Node//链表是由一个个节点组成所以这里单独定义这一类型方便在链表类中使用
{
    Datatype _data;
    struct Node* next;
    struct Node* prev;
}Node,*pNode;

typedef class LinkList
{
private:
    pNode head;
public:
    LinkList()
    {
        head=NULL;
    }

    void pushback(Datatype x)
    {
        pNode p=new Node[sizeof(Node)];
        p->_data=x;
        p->next=NULL;
        if(head==NULL)
        {
            head=p;
            head->prev=NULL;
        }
        else
        {
            pNode cur=head;
            while(cur->next)
            {
                cur=cur->next;
            }
            cur->next=p;
            p->prev=cur;
        }
    }

    void pushfront(Datatype x)
    {
        pNode tmp=new Node[sizeof(Node)];
        if(head==NULL)
        {
            tmp->_data=x;
            head=tmp;
            head->next= NULL;
            head->prev=NULL;
        }
        else
        {
            //我们要在头结点前再插入一个结点，需要先创建一个新的结点，将头结点的值保存在新节点，然后让新节点的下
            //个结点指向头结点的下一个结点，再让新节点的prev指向头结点，这样就将新节点与原来的链表融合了，然后我
            //们将头结点的数据换成x即可。
            tmp->_data=head->_data;
            tmp->next=head->next;
            tmp->prev=head;//
            head->next=tmp;
            head->_data=x;
        }
    }
    void popback()
    {
        if(head!=NULL)
        {
            pNode cur=head;
            pNode pre=NULL;
            while(cur->next)
            {
                pre=cur;
                cur=cur->next;
            }
            delete[] cur;
            cur=NULL;
            pre->next=NULL;//一定要将pre->next置为空,前面一句仅仅是将cur的值置为空，此时pre->next还指向原来的那块空间
        }
    }

    void popfront()
    {
        if(head!=NULL)
        {
            if(head->next==NULL)
            {
                delete[] head;
                head=NULL;
            }
            else
            {
                pNode del=head;
                head=head->next;
                delete[] del;
                del=NULL;//这里将del置为空可以防止它变为野指针
            }
        }
    }

    pNode find(Datatype x)
    {
        if(head==NULL)
        {
            return NULL;
        }
        else
        {
            pNode cur=head;
            while(cur)
            {
                if(x==cur->_data)
                {
                    return cur;
                }
                cur=cur->next;
            }
            return NULL;
        }
    }

    void insert(pNode pos,Datatype x)
    {
        assert(pos);//防止pos为空指针
        if(head==NULL)
        {
            return ;
        }
        else
        {
            pNode cur=head;
            if(head==pos)
            {
                pushfront(x);
            }
            else
            {
                while(cur)
                {
                    if(cur==pos)
                    {
                        pNode tmp=new Node[sizeof(Node)];
                        tmp->_data=cur->_data;
                        tmp->next=cur->next;
                        tmp->prev=cur;
                        cur->_data=x;
                        cur->next=tmp;
                        return ;//insert成功后不要忘了直接返回结束函数
                    }
                    cur=cur->next;
                }
                cout<<"没有找到这个数字"<<endl;
            }
        }
    }

    void erase(pNode pos)//删除指定位置的结点
    {
        assert(pos);
        if(head==NULL)
        {
            return;
        }
        else
        {
            if(pos==head)
            {
                popfront();
            }
            else
            {
                pNode del=head->next;
                pNode pre=head;
                while(del)
                {
                    if(del==pos)
                    {
                        if(del->next!=NULL)
                        {
                            pre->next=del->next;
                            del->next->prev=pre;
                            delete[] del;
                            del=NULL;
                        }
                        else
                        {
                            delete[] del;
                            pre->next=NULL;
                        }
                        return;
                    }
                    del=del->next;
                    pre=pre->next;
                }
            }
        }
    }

    int use_count()//返回链表中结点的数量
    {
        int count=0;
        pNode cur=head;
        while(cur)
        {
            cur=cur->next;
            count++;
        }
        return count;
    }

    void display()//打印链表
    {
        pNode cur=head;
        while(cur!=NULL)
        {
            cout<<cur->_data<<endl;
            cur=cur->next;
        }
    }

    ~LinkList()
    {
        pNode cur=head;
        while(cur!=NULL)
        {
            pNode Next=cur->next;
            delete cur;
            cur=Next;
            if(cur!=NULL)
            {
                Next=Next->next;
            }
            else
                break;
        }
    }
};

void test()
{
    LinkList ls1;
    ls1.pushback(1);
    ls1.pushback(2);
    ls1.pushback(3);
    ls1.pushfront(0);
    ls1.display();
    ls1.popback();
    ls1.display();
    ls1.popfront();
    ls1.display();
    pNode ret=ls1.find(2);
    if(ret==NULL)
    {
        cout<<"没有找到"<<endl;
    }
    else
    {
        cout<<ret->_data<<endl;
    }
    ls1.insert(ret,5);
    ls1.display();
    pNode ret2=ls1.find(2);
    ls1.erase(ret2);
    ls1.display();
    int ret3=ls1.use_count();
    cout<<ret3<<endl;
}

int main()
{
    test();
    getchar();
    return 0;
}