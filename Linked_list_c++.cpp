#include <iostream>

/*
created by Romany
    GitHup   : @romanyn36
    LinkedIn : @romanyn36
    Twitter  : @romanyn36
*/
/*lines have "romo" comment mean that edited by romany
and original code is has problems that i fixed it in this lines */
using namespace std;
struct node
{
    int inf;
    node* next;
};
class linkedlist
{
private:
    node* list;
public:
    linkedlist() {
        list = NULL;
    }
    node* creatnode()
    {
        node* n = new node;
        return n;
    }
    void free_node(node* p)
    {
        delete p;
    }
    void add_first(int val)
    {
        node* p;
        p = creatnode();
        p->inf = val;
        if (list == NULL)
        {
            p->next = NULL;
            list = p;
            return;
        }
        p->next = list;
        list = p;

    }
    void add_last(int val)
    {
        node* p;
        p = creatnode();
        p->inf = val;
        p->next = NULL;
        if (list == NULL)
        {
            list = p;
            return;
        }
        node* q = list;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
    void add_after(int val, int pos)
    {
        node* p, * q;
        q = list;
        for (int i = 1; i <= pos - 1; i++)     //romo
        {
            q = q->next;

            if (q == NULL)
            {
                cout << "no more space in position " << pos << endl;
                return;
            }
        }
        p = creatnode();
        p->inf = val;
        p->next = q->next;
        q->next = p;

    }
    void delete_(int data)
    {
        node* p = list;
        if (p->inf == data)
        {
            list = list->next;
            free_node(p);
            return;
        }
        node* k = NULL, * q = list;  //romo
        while (q->inf != data)
        {
            k = q;
            q = q->next;
        }
        if (q->next == NULL && q->inf != data)
        {
            cout << "this element not found in this linked list " << endl;
            return;
        }
        k->next = q->next;
        free_node(q);
    }
    int remove_first()
    {
        int val;
        node* p = list;
        if (list == NULL)
            return -1;
        if (p->next == NULL)
        {
            val = p->inf;
            free_node(list);
            list = NULL;
            return val;
        }
        val = p->inf;
        list = p->next;
        free_node(p);
        return val;
    }
    int remove_last()
    {
        int val;
        node* p = list;
        if (list == NULL)
            return -1;
        if (p->next == NULL)
        {
            val = p->inf;
            free_node(list);
            list = NULL;
            return val;
        }
        node* k = NULL;
        while (p->next != NULL)
        {
            k = p;
            p = p->next;
        }
        val = p->inf;
        k->next = NULL;
        free_node(p);
        return val;
    }
    void display_list()
    {
        node* p = list;
        if (list->next == NULL)
        {
            cout << "list is empty " << endl;
            return;
        }
        cout << "data of list is : ";
        while (p != NULL)///romo 
        {
            cout << p->inf << " ";
            p = p->next;
        }
    }
    int count_list()
    {
        node* p = list;
        int c = 0;
        while (p != NULL)
        {
            p = p->next;
            c++;
        }
        return c;
    }
    int search_list(int data)
    {
        node* p = list;
        int pos = 0;
        bool a = 1;//romo
        while (p != NULL)//romo
        {
            if (p->inf == data)
                pos++;

            p = p->next;
            a = 0;//romo
        }

        if (p == NULL && a)//romo
            return -1;
        return pos;
    }
    void reverse_list()
    {
        node* cnode = list;
        node* nnode = NULL;
        node* pnode = NULL;
        while (cnode != NULL)
        {
            nnode = cnode->next;
            cnode->next = pnode;
            pnode = cnode;
            cnode = nnode;
        }
        list = pnode;
    }
};
int main()
{
    linkedlist obj;
    obj.add_first(1);
    //obj.add_first(2);
    obj.add_last(3);
    obj.add_last(4);
    obj.add_after(7, 3);
    obj.add_last(5);
    obj.delete_(5);
    cout << obj.search_list(7) << endl;
    cout<<obj.count_list() << endl;
    obj.display_list();
    obj.reverse_list();
    obj.display_list();
    //obj.remove_first();
    //obj.remove_last();
    //obj.remove_last();
    //obj.display_list();
}
