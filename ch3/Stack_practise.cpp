#include <iostream>
using namespace std;
// /* 第 3 题 */
// bool is_valid_seq(const string& s) {
//     int cnt = 0;
//     bool flag = true;
// 	for(int i = 0; i < s.length(); i++) {
//         if(s[i] == 'I') {
//             cnt++;
//         } else if(s[i] == 'O') {
//             if(cnt > 0) {
//                 cnt--;
//             } else {
//                 flag = false;
//             }
//         }
//     }
//     if(cnt == 0) {
//         flag = true;
//     } else {
//         flag = false;
//     }

//     return flag;
// }

// /* 第4 题 : 判断是否中心对称：abccba */
// typedef struct LNode{
//     char data;
//     LNode *next;
// } LNode, *LinkList;
// // 方法一：利用栈操作
// bool is_symmetry(LinkList L, int n)
// {
//     // 考研数据结构不让用stl，所以写栈只能用数组表示
//     LNode *p = L->next;
//     char stack[n/2];
//     int i;
//     for(i = 0; i < n / 2; i++) {
//         stack[i] = p->data;
//         p = p->next;
//     }
//     if(n % 2 == 1) {
//         p = p->next;
//     }
//     i--;
//     while(p != NULL && stack[i] == p->data) {
//         i--;
//         p = p->next;
//     }
//     if(i == -1) {
//         return true;
//     } else {
//         return false;
//     }
// }
// // 方法二：转化为数组写  下面是我leetcode上的刷题第234题 可以直接转化为数组来写
// bool isPalindrome(ListNode* head) 
// {
//     if(!head) return true;
//     ListNode *p = head;
//     vector<int> arr;
//     while(p) {
//         arr.push_back(p->val); //arr 可以设定为数组
//         p = p->next;
//     }
//     for(int i = 0, j = arr.size() - 1; i < j; i++, j--) {
//         if(arr[i] != arr[j]) {
//             return false;
//         }
//     }
//     return true;
// }

/* 第 5 题*/
#define MaxSize 100
struct sharedStack{
    int data[MaxSize];
    int top1;
    int top2;
};

bool push(sharedStack s, int number, int x)
{
    if(s.top2 - s.top1 == 1) {
        cout <<"Stack full!" << endl;
        return false;
    }
    if(number == 1) {
        s.top1++;
        s.data[s.top1] = x;
        return true;
    }
    if(number == 2) {
        s.top2--;
        s.data[s.top2] = x;
        return true;
    }
}

int pop(sharedStack s, int number) 
{
    if(number == 1){
        if(s.top1 == -1) {
            cout << "栈1空！"<<endl;
        } else {
            return s.data[s.top1];
            s.top1--;
        }
    } else if(number == 2) {
        if(s.top1 == MaxSize) {
            cout << "栈2空！"<<endl;
        } else {
            return s.data[s.top2];
            s.top2++;
        }
    }
}


int main() {
    // /*第3题测试*/
	// cout << is_valid_seq("IOIIOIOO") << endl;
	// cout << is_valid_seq("IOOIOIIO") << endl;
	// cout << is_valid_seq("IIIOIOIO") << endl;
	// cout << is_valid_seq("IIIOOIOO") << endl;

    /*第4题测试*/


    /*第5题测试*/
    struct sharedStack stk;
    stk.top1 = -1;
    stk.top2 = MaxSize;

 	return 0;
}