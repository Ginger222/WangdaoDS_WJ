#include <iostream>
using namespace std;
#define MaxSize 50
#define InitSize 100
typedef int ElemType_SqList;
struct SqList
{
    /* data */
    int data[MaxSize];
    int length;
};

bool ListInsert(SqList &L, int i, int e)
{
    //将元素e插入顺序表的第i个位置
    if (i <= 0 || i > L.length + 1)
    {
        return false;
    }
    if (L.length >= MaxSize)
    {
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, int &e)
{
    e = L.data[i - 1];
    // 删除线性表中第i个位置元素
    if (i <= 0 || i > L.length + 1)
    {
        return false;
    }
    for (int j = i - 1; j < L.length; j++)
    {
        L.data[j] = L.data[j + 1];
    }
    L.length--;
    return true;
}

int LocateItem(SqList L, int e)
{
    int ans = 0;
    // 查找值为e的元素，找到返回其位置，否则返回0
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            ans = 1;
        }
    }
    return ans;
}
/* 课后习题 */
// 1. 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。空出的位置由最后一个元素填补，
//    若顺序表为空则显示出错信息并退出运行。
bool DeleteMinElem(SqList &L, ElemType_SqList &e)
{
    int minpos = 0;
    if (L.length == 0)
    {
        return false;
    }
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] < L.data[minpos])
        {
            minpos = i;
        }
    }
    e = L.data[minpos];
    L.data[minpos] = L.data[L.length - 1];
    return true;
}

//2. 设计一个高效算法，将顺序表 L 的所有元素逆置，要求算法的空间复杂度为 O(1)
bool Reverse(SqList &L)
{
    for (int i = 0, j = L.length - 1; i < j; i++, j--)
    {
        int t = L.data[i];
        L.data[i] = L.data[j];
        L.data[j] = t;
    }
    return true;
}

//3. 对长度为 n 的顺序表 L，编写一个时间复杂度为 O(n)、空间复杂度为O(1)的算法，
//   该算法删除线性表中所有值为 x 的数据元素
bool Delete_x(SqList &L, ElemType_SqList x)
{
    // 原本可以重开数组但是要求空间为O（1），那么采用空间重写将需要的元素填写到正确的位置
    int j = 0;

    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] != x)
        {
            L.data[j++] = L.data[i];
        }
    }
    L.length = j;
    return true;
}

//4. 从有序顺序表中删除其值在给定值 s 与 t 之间（s<t）的所有元素，
//   如果 s 或 t 不合理或顺序表为空，则显示出错信息并退出运行
bool Delete_s_t1(SqList &L, ElemType_SqList s, ElemType_SqList t)
{
    int j = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] > t || L.data[i] < s)
        {
            L.data[j++] = L.data[i];
        }
    }
    L.length = j;
    return true;
}

//5. 从顺序表中删除其值在给定值 s 和 t 之间（包含 s 和 t，要求 s<t）的所有元素，
//   如果 s 或 t 不合理或顺序表为空，则显示出错信息并退出运行
bool Delete_s_t2(SqList &L, ElemType_SqList s, ElemType_SqList t)
{
    int j = 0;

    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] > t || L.data[i] < s)
        {
            L.data[j++] = L.data[i];
        }
    }
    L.length = j;
    return true;
}

//6. 从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同
bool Delete_Same(SqList &L)
{
    int j = 1;
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] != L.data[i - 1])
        {
            L.data[j++] = L.data[i];
        }
    }
    L.length = j;
    return true;
}

//7. 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表
// bool Merge(SqList A, SqList B, SqList &C){

// }

// //8. 已知在一维数组 A[m+n] 中依次存放两个线性表 (a1,a2,…,am) 和 (b1,b2,…,bn)。
// //   试编写一个函数，将数组中两个顺序表的位置互换，即将 (b1,b2,…,bn) 放在
// //   (a1,a2,…,am) 的前面
// bool Add(SqList &A, SqList B){

// }

// bool Reverse(SqList &L, int m, int n){

//     return true;
// }

// bool Exchange_m_n(SqList &L, int m, int n){

// }

// //9. 在有序线性表中查找值为 x 的元素，若找到将其与后继元素位置交换，若找不到将其值插入表中
// //   并使表中元素仍有序递增
// bool SearchExchangeInsert(SqList &L, ElemType_SqList x){

// }
// //书上答案
// //bool SearchExchangeInsert(SqList &L, ElemType_SqList x){
// //
// //    int low = 0, high = L.length-1,mid;
// //    while(low <= high){
// //        mid = (low + high) / 2;
// //        if(L.data[mid] == x) break;
// //        else if(L.data[mid] < x)
// //            low = mid + 1;
// //        else
// //            high = mid - 1;
// //    }
// //    if(L.data[mid] == x && mid != L.length-1){
// //        int temp = L.data[mid];
// //        L.data[mid] = L.data[mid+1];
// //        L.data[mid+1] = temp;
// //    }
// //    int i;
// //    if(low > high){
// //        for(i=L.length-1; i>high; i--)
// //            L.data[i+1] = L.data[i];
// //        L.data[i+1] = x;
// //    }
// //}

// //10.循环左移 p 个位置
// bool Shifting(SqList &L, int p){

// }

// //11.找出两个升序序列的中位数
// ElemType_SqList M_Search(SqList A, SqList B){

// }

// //12.找出主元素（个数大于一半长度的元素）
// ElemType_SqList Majority(SqList L){

// }

// //13.找出未出现的最小正整数
// int Find_Miss_Min(SqList &L){

// }

int main()
{
    //     /*题目1测试*/
    //    SqList l;
    //    l.length = 4;
    //    l.data[0] = 11;
    //    l.data[1] = 41;
    //    l.data[2] = 2;
    //    l.data[3] = 31;
    //    int value = -1;

    //    for (int i = 0; i < l.length; ++i) {
    //        printf("%d\t", l.data[i]);
    //    }
    //    printf("\n");
    //    DeleteMinElem(l, value);
    //    for (int i = 0; i < l.length; ++i) {
    //        printf("%d\t", l.data[i]);
    //    }
    //    printf("\nvalue:-->%d", value);

    //    /*题目2测试*/
    //    SqList l;
    //    l.length = 5;
    //    l.data[0] = 11;
    //    l.data[1] = 41;
    //    l.data[2] = 2;
    //    l.data[3] = 31;
    //    l.data[4] = 311;

    //    for (int i = 0; i < l.length; ++i) {
    //        printf("%d\t", l.data[i]);
    //    }
    //    printf("\n");
    //    Reverse(l);
    //    for (int i = 0; i < l.length; ++i) {
    //        printf("%d\t", l.data[i]);
    //    }

    //    /*题目3测试*/
    //    SqList l;
    //    l.length = 5;
    //    l.data[0] = 11;
    //    l.data[1] = 11;
    //    l.data[2] = 2;
    //    l.data[3] = 11;
    //    l.data[4] = 111;

    //    for (int i = 0; i < l.length; ++i) {
    //        printf("%d\t", l.data[i]);
    //    }
    //    printf("\n");
    //    Delete_x(l, 11);
    //    for (int i = 0; i < l.length; ++i) {
    //        printf("%d\t", l.data[i]);
    //    }

    //    /*题目4测试*/
    //    SqList l;
    //    l.length = 5;
    //    l.data[0] = 1;
    //    l.data[1] = 2;
    //    l.data[2] = 31;
    //    l.data[3] = 4;
    //    l.data[4] = 5;

    //    for (int i = 0; i < l.length; ++i) {
    //        printf("%d\t", l.data[i]);
    //    }
    //    printf("\n");
    //    Delete_s_t1(l, 31, 31);
    //    for (int i = 0; i < l.length; ++i) {
    //        printf("%d\t", l.data[i]);
    //    }

    /*题目6测试*/
    SqList l;
    l.length = 7;
    l.data[0] = 1;
    l.data[1] = 2;
    l.data[2] = 2;
    l.data[3] = 3;
    l.data[4] = 5;
    l.data[5] = 5;
    l.data[6] = 5;

    for (int i = 0; i < l.length; ++i)
    {
        printf("%d\t", l.data[i]);
    }
    printf("\n");
    Delete_Same(l);
    for (int i = 0; i < l.length; ++i)
    {
        printf("%d\t", l.data[i]);
    }
    return 0;

    // /*题目7测试*/
    // SqList l;
    // SqList l1;
    // SqList l2;
    // l1.length = 3;
    // l2.length = 2;
    // l1.data[0] = 1;
    // l1.data[1] = 10;
    // l1.data[2] = 1100;
    // l2.data[0] = 4;
    // l2.data[1] = 100;
    // mergeTwoList(l1, l2, l);
    // printf("\n");
    // for (int i = 0; i < l.length; ++i) {
    //     printf("%d\t", l.data[i]);
    // }

    return 0;
}