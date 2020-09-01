#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(int x, List L);
void Delete(int x, List L);
Position Findprevious(int x, List L);
void Insert(int x, Position P);
void DeleteList(List L);
void Output(List L);

struct Node
{
    int element;
    Position next;
};

List MakeEmpty(List L)
{
    return List();
}

int IsEmpty(List L)
{
    return L->next == NULL;
}

int IsLast(Position P, List L)
{
    return P->next == NULL;
}

Position Find(int x, List L)
{
    return Position();
}

void Delete(int x, List L)
{
    Position P, temp;
    P = Findprevious(x, L);
    if (!IsLast(P, L))
    {
        temp = P->next;
        P->next = P->next->next;
        free(temp);
    }
}

Position Findprevious(int x, List L)
{
    //Position P;
    //P = L;
    while (L->next != NULL && L->next->element != x)
        L = L->next;
    return L;
}

void Insert(int x, Position P)
{
    Position temp;            //定义一个插入变量
    temp = new (struct Node); //为该插入变量申请内存
    if (temp == NULL)
        cout << "Error!"; //判断是否申请成功
    else                  //成功以后对该变量赋值以及建立连接
    {
        temp->element = x;
        temp->next = P->next;
        P->next = temp;
    }
}

void DeleteList(List L)
{
    Position P, temp;
    P = L->next;
    L->next = NULL;
    while (P)
    {
        temp = P->next;
        free(P);
        P = temp;
    }
}

void Output(List L)
{
    while (L)
    {
        cout << L->element << endl;
        L = L->next;
    }
}

int main()
{
    List l = new (struct Node);
    l->next = NULL;
    for (int i = 1; i <= 9; i++)
    {
        Insert(i, l);
    }
    l = l->next;
    Output(l);

    cout << "After delete 5:" << endl;
    Delete(5, l);
    Output(l);

    DeleteList(l);
    cout << "After Delete List:";
    Output(l);
    system("pause");
}