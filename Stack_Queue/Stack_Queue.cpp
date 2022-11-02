#include <iostream>
#define MAXSIZE 50
typedef struct
{
    int top;
    char data[MAXSIZE];
}SqStack;

typedef struct
{
    int front;
    int rear;
    int tag;
    int *data;
}SqQueue;

bool InitSqStack(SqStack &s);
char Pop(SqStack &s);
void Push(SqStack &s,char c);
char GetTheTop(SqStack& s);
bool JudgePalindromic(char* c);//判断是否是回文序列
bool EmptyStack(SqStack& s);

bool InitSqQueue(SqQueue& Q);
bool EnSqQueue(SqQueue& Q,int e);
int DeSqQueue(SqQueue& Q);

bool isRightBracket(SqStack &s, char* c);//判断小括号是否匹配
int main()
{
    
    //判断字符串是否是回文
    /*char c1[7] = {"abccba"};
    char c2[8] = { "ufoxofu" };
    char c3[7] = { "xxxooo" };
    char c4[8] = { "vvvxooo" };
    JudgePalindromic(c1);
    JudgePalindromic(c2);
    JudgePalindromic(c3);
    JudgePalindromic(c4);*/

    //循环队列操作
    /*int i;
    int e = 0;
    SqQueue Q;
    InitSqQueue(Q);
    for ( i = 0; i < 12; i++)
    {
        printf("输入数据：");
        scanf_s("%d", &e);
        EnSqQueue(Q, e);
    }
    for (i = 0; i < 10; i++)
    {
        
        DeSqQueue(Q);
    }*/

   /* SqStack s;
    char c1[11] = { "((ac))(13)" };
    isRightBracket(s, c1);
    char c2[11] = { "((ac(()13)" };
    isRightBracket(s, c2);
    char c3[11] = { "((ac()1)))" };
    isRightBracket(s, c3);
    char c4[11] = { "(()(()))()" };
    isRightBracket(s, c4);
    */

    return 0;

}
bool InitSqStack(SqStack &s)
{
    s.top = 0;
    return true;
}

bool InitSqQueue(SqQueue& Q)
{
    Q.rear = 0;
    Q.front = 0;
    Q.tag = 0;
    Q.data = new int[10];
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
char GetTheTop(SqStack& s)
{
    return s.data[s.top - 1];
}
bool EnSqQueue(SqQueue& Q, int e)
{
    if (Q.front == Q.rear && Q.tag == 1)
    {
        //队满 无法入队
        printf("队满 无法入队\n");
        return false;
    }
    else
    {
        Q.data[Q.rear] = e;
        Q.rear = (Q.rear + 1) % 10;
        Q.tag = 1;
        printf("%d进队,队列长度为%d\n", e, (Q.rear-Q.front+10)%10);
    }
    return true;

}
int DeSqQueue(SqQueue& Q)
{
    if (Q.front == Q.rear && Q.tag == 0)
    {
        //队空 无法出队
        printf("队空 无法出队\n");
        return false;
    }
    else
    {
        int e;
        e = Q.data[Q.front];
        Q.front = (Q.front + 1) % 10;
        Q.tag = 0;
        printf("%d出队,队列长度为%d\n", e, (Q.rear - Q.front + 10) % 10);
    }
    return true;
    
}

bool JudgePalindromic(char* c)
{
    /*
    错误点：
         1.判断奇偶数时，将%写成了/导致逻辑严重错误
    */
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
            
            printf("%c与%c相等\n",c[i],e);
            i++;
        }
        else
        {
            printf("%c与%c不相等\n", c[i], e);
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

bool isRightBracket(SqStack &s, char* c)//判断小括号是否匹配
{
   
    /*
    易错点：
        应注意考虑所有种可能的情况;左右括号相等，左多又少，左少右多
    */
    InitSqStack(s);
    int l = strlen(c);
    int i;
    for ( i = 0; i < l; i++)
    {
        if (c[i] =='(')
        {
            Push(s,c[i]);
        }
    }
    for ( i = 0; i < l; i++)
    {
        if (c[i] == ')')
        {
            if (GetTheTop(s) == '(')
            {
                Pop(s);
            }
            else
            {
                printf("右括号多余，括号不匹配\n");
                return false;
            }
        }
    }
    if (EmptyStack(s))
    {
        printf("括号匹配\n");
        return true;
    }
    else
    {
        printf("左括号多余，匹配失败\n");
        return false;

    }
    return true;
    

}
