#include <iostream>
#include "chapter2_3.h"
#include "linked_list.h"
using namespace std;

// 1. 设计一个递归算法，删除不带头结点的单链表 L 中所有值为 x 的结点

// 因为使用了类，且链表结点结构体放在了 private 域，所以不能直接传递结点指针
void Delete_x(LinkList &L, ElemType_LinkList x, int i){

    int len = L.GetListLength();
    if(len == 0 || len < i)return;

    ElemType_LinkList e;
    L.GetElem(i, e);
    if(e == x){
        L.DeleteNode(i);
        Delete_x(L, x, i);
    }
    else{
        Delete_x(L, x, i+1);
    }
}


// 2.在带头结点的单链表 L 中，删除所有值为 x 的结点，并释放其空间，值为 x 的结点不唯一

// 由于底层函数做了兼容，可以直接用 1.题 的函数
// 2. 和 1. 的主要区别在于带不带头结点，实现时主要区别是：
// 若带头结点，操作的第一个结点是 _head -> next （即除头结点外的第一个结点）
// 若不带头结点，操作的第一个结点是 _head （即真正的第一个结点）


// 3.设 L 为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值

// 单链表可以通过递归倒序输出，这里借助序号进行递归，因为不能直接结点指针
void Reverse_Print(LinkList &L, int i){

    ElemType_LinkList e;
    int len = L.GetListLength();
    if(len == 0 || len < i){
        return;
    }
    Reverse_Print(L, i+1);
    L.GetElem(i, e);
    cout << e;
}


// 4.编写在带头结点的单链表 L 中删除一个最小值结点的高效算法（假设最小值唯一）

// 由于测试数据中有可能出现多个最小值，这里其实是删除第一个最小值
// 由于不能直接操作结点指针，其实很浪费时间
bool Delete_Min(LinkList &L){

    int i = 1;
    ElemType_LinkList e;
    ElemType_LinkList min_value;
    int min_loc = 0;
    int len = L.GetListLength();  // 这里相当于遍历了一次，很浪费时间
    while((i<=len) && L.GetElem(i, e)){  // 每次获取元素，都要从头遍历 i 个结点
        if(i == 1){
            min_value = e;
            min_loc = 1;
        }
        if(e < min_value){
            min_value = e;
            min_loc = i;
        }
        i++;
    }
    if(min_loc > 0){
        L.DeleteNode(min_loc);
        return true; // 只要表不空，一定能删除一个结点
    }
    return false;// 空表时
}

///*以下题目不以这种数据结构实现，没有意义，修改数据结构后放在工程 chapter2_3 中实现*/


// 5.将带头结点的单链表就地逆置


// 6.使带头结点的单链表 L 递增有序


// 7.带头结点的数据值无序单链表，删除表中所有介于给定两值之间的元素


// 8.给定两个单链表，找出公共结点


// 9.递增输出单链表数据，并释放空间，不允许使用数组作为辅助空间


//10.将带头结点的单链表 A 按节点序号的奇偶性分解为 A、B 两个带头结点的单链表


//11.同 10. 但是 B 逆序


//12.删除重复元素


//13.两个递增次序的单链表归并为一个递减次序的单链表，且用原先两个链表的结点存放，不新增结点


//14.从递增有序的两个单链表 A、B 的公共元素产生单链表 C，不破坏 A、B 结点


//15.将递增有序的 A、B 链表的交集存放在 A 链表中


//16.判断 B 单链表是否是 A 单链表的连续子序列


//17.判断带头结点的循环双链表是否对称


//18.将循环单链表 h1 链接到循环单链表 h2 之后，链接后仍保持循环链表的形式


//19.结点值均为正整数的带头结点的循环单链表，反复找出其中值最小的结点输出后删除，
//   最后删除表头结点


//20.带头结点的非循环双链表，除数据域和指针域，还有一个访问频度域 freq，
//   实现 Locate(L, x) 函数，使每在链表中进行一次该运算，值为 x 的结点的 freq 增 1，
//   并使结点保持访问平度非增的顺序排列，且最近访问的结点排在相同频度结点的前面（靠近表头）


//21.带头结点的单链表，只给出头指针 list，不改变链表的前提下查找倒数第 k 个位置的结点，
//   输出 data 值，并返回 1，否则只返回 0


//22.用带头结点的单链表保存单词，当两个单词有相同后缀时可共享后缀存储空间，找出两个单词
//   所在单链表的的共同后缀的起始位置。已给定两个单词的头指针。


//23.删除单链表中多余的绝对值相等的结点，只保留第一次出现的结点







