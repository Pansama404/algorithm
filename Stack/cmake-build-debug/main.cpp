#include <iostream>
//本次设计的是动态存储的栈，稍微比静态要难一点是建立在静态基础之上进行企业化的更改
using namespace std;

#define OK 1
#define ERROR 0
#define InitSize 100
#define OVERFLOW (-1)
#define Increase 10

typedef int Status;
typedef int ElemType;
/***
这里如果要改坐标的话就直接使用一下一下代码
 typedef struct ElemType{
    int _x;
    int _y
 }ElemType;
 ***/

typedef struct Node {
    ElemType *top;
    ElemType *base;//问就是方便更改
    int StackSize;//问就是抽象类型的优势所在
} SqStack;//顺序栈的基本实现 sequence Stack

//初始化栈
Status InitStack(SqStack &s) {
    s.base = new ElemType;//分配内存空间
    if (!s.base) exit(OVERFLOW);//分配失败则退出
    s.top = s.base;//初始化的标准操作
    s.StackSize = InitSize;//初始化栈的长度
    return OK;
}
/***
* 其实这里用两个元素是为了更好的观察两个指针的动向
 * 同时也方便我们进行学习如果你出来工作用一个top就够了
 * 一下的base指针只是用来进行判断作用
 * 只有一个top代码也简洁
*/

//判空
Status IsEmpty(SqStack &s) {
    if (s.base == s.top) return OK;//用来下面的函数判断用的早点定义好
    else return ERROR;
}

//清空
Status CleanStack(SqStack &s) {
    s.top = s.base;//清空的标准操作
    return OK;
}

//摧毁栈
Status DestroyStack(SqStack &s) {
    int i, len;
    len = s.StackSize;//获取总长
    for (i = 0; i < len; i++) {
        delete s.base;//逐个释放
        s.base++;
    }
    s.base = s.top = nullptr;//归零操作
    s.StackSize = 0;
    return OK;
}

//获取栈的长度
Status StackLength(SqStack s) {
    cout<< s.top - s.base<<endl;//直接打印比较好用return要用long long类型太费空间了
    return OK;
}

//获得栈顶元素
Status GetTop(SqStack &s){
    ElemType e;
    if (!IsEmpty(s)) return ERROR;
    e = * (s.top-1);//这里是直接用栈的性质获取
    cout<<e<<endl;
    return OK;
}

//遍历
Status Travel(SqStack s){
    ElemType e;
    if(s.base == s.top) return ERROR;
    while(s.base != s.top) {
        e = *--s.top;//如果是++在前面就是先加后赋值，在后面就是先赋值后加，主要是让代码短一点
        cout<<e<<endl;//这里就直接打印就可以了
    }
    return OK;
}

//入栈
Status Push(SqStack &s,ElemType e){
    if(s.top-s.base >=s.StackSize){
        s.base =(ElemType *) realloc(s.base,InitSize + Increase * sizeof (ElemType));//不够就分配
        if(!s.base) exit(OVERFLOW);//分配失败就报错退出
        s.top = s.base + s.StackSize;//这里是把长度给增加上去
        s.StackSize += Increase;//把栈的长度给加上
    }
    *s.top++=e;//直接赋值加上去就可以了
    return OK;
}

//出栈
Status Pop(SqStack s,ElemType &e){
    if(s.top ==s.base ) return ERROR;//这个也可以用IsEmpty函数判断
    e = *--s.top;
    return e;
}

bool BracketCheck(char str[],int length){
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            Push(S,str[i]);
        else{
            if (IsEmpty(S)) return ERROR;
        }
        ElemType topElem;
        Pop(S,topElem);
        if (str[i] == ')' && topElem !='(')
            return ERROR;
        if (str[i] == ']' && topElem !='[')
            return ERROR;
        if (str[i] == '}' && topElem !='{')
            return ERROR;
    }
    return IsEmpty(S);
}

int main(){
    SqStack s;
    cout<<"hello world"<<endl;

    InitStack(s);
    Push(s,10);
    Push(s,200);
//    GetTop(s);
    Travel(s);

    return 0;
}