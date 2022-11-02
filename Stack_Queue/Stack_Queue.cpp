#include <iostream>
#define MAXSIZE 50
typedef struct
{
    int top;
    char data[MAXSIZE];
}SqStack;

bool InitSqStack(SqStack &s);
char Pop(SqStack &s);
void Push(SqStack &s,char c);
bool JudgePalindromic(char* c);
bool EmptyStack(SqStack& s);
int main()
{
    //xiaoai
    //判断字符串是否是回文
    /*char c1[7] = {"abccba"};
    char c2[8] = { "ufoxofu" };
    char c3[7] = { "xxxooo" };
    char c4[8] = { "vvvxooo" };
    JudgePalindromic(c1);
    JudgePalindromic(c2);
    JudgePalindromic(c3);
    JudgePalindromic(c4);*/
}
bool InitSqStack(SqStack &s)
{
    s.top = 0;
    return true;
}
char Pop(SqStack &s)
{
    s.top--;
    printf("%c出栈,栈长度为%d\n", s.data[s.top],s.top);
    return s.data[s.top];
    
}
void Push(SqStack &s,char c)
{
    s.data[s.top] = c;
    s.top++;
    printf("%c入栈,栈长度为%d\n", c,s.top);

}
bool JudgePalindromic(char* c)
{
    int i;
    char e;
    int length = strlen(c);
    SqStack s;
    InitSqStack(s);
    for (i = 0; i < length / 2; i++)
    {
        Push(s, c[i]);//前一半压入栈

    }
    if (length % 2 != 0)
    {
        i++;
        
    }
    
    while (!EmptyStack(s))
    {
        e=Pop(s);
        if (c[i] == e)
        {
            
            printf("%c与%c相等\n",c[i],e,i);
            i++;
        }
        else
        {
            printf("%c与%c不相等\n", c[i], e, i);
            printf("不是回文\n\n");
            s.top = 0;
            return false;
            break;
        }
    }
    
    printf("是回文\n\n");
    s.top = 0;
    return true;
}
bool EmptyStack(SqStack& s)
{
    if (s.top == 0)
        return true;
    else
        return false;
}