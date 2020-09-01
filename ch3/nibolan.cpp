#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
//比较lhs的优先级是否不高于rhs，rhs表示栈顶的符号
bool priority(const char &lhs, const char &rhs)
{
    if (rhs == '(') //左括号在栈外优最高
        return false;
    if (lhs == '+' || lhs == '-')
        return true;
    if ((lhs == '*' || lhs == '/') && (rhs == '*' || rhs == '/'))
        return true;
    return false;
}
//将中缀表达式转换成后缀式（逆波兰表达式）
string exchange(string &str)
{
    vector<char> vec;
    string res;
    stack<char> st; //操作符堆栈
    for (int i = 0; i < str.size(); ++i)
    {
        cout << st.size() << " ";

        if (isdigit(str[i]) || (str[i] >= 'a' && str[i] <= 'z'))
        { //如果是数字，直接输出到后序表达式中
            vec.push_back(str[i]);
        }
        else
        { //如果是符号,需要与栈顶的元素进行比较
            if (st.empty() || str[i] == '(')
            { //小括号在栈外优先级最高，直接压栈
                st.push(str[i]);
            }
            else
            {
                if (str[i] == ')')
                { //遇到右括号，则弹栈，直到遇到左括号，两者相互抵消
                    while (!st.empty() && st.top() != '(')
                    {
                        vec.push_back(st.top());
                        st.pop();
                    }
                    if (!st.empty())
                    {
                        st.pop();
                    }
                }
                else
                { //遇到的是其他操作符
                    if (priority(str[i], st.top()))
                    { //优先级比栈顶元素低
                        while (!st.empty())
                        {
                            vec.push_back(st.top());
                            st.pop();
                        }
                        st.push(str[i]);
                    }
                    else
                    { //优先级比栈顶元素高，压栈
                        st.push(str[i]);
                    }
                }
            }
        }
    }
    while (!st.empty())
    { //如果堆栈不为空，则将其中的元素全部弹出
        vec.push_back(st.top());
        st.pop();
    }
    for (int i = 0; i < vec.size(); i++)
        res += vec[i];
    return res;
}

int main()
{
    /*第5题测试*/
    string str = "a+b-a*((c+d)/e-f)+g";
    //vector <char> vec(s.begin(), s.end());
    cout << exchange(str) << endl;

    return 0;
}