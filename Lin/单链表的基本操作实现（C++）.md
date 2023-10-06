# 单链表的基本操作实现（C++）

### 准备工作：

```C++
#include <iostream>

using namespace std;

#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkList;//这里如果定义一个节点
/***
* Node *L
* LinkList L
* 所表达的是一样的东西
*/
```



### 初始化链表操作：

```C++
Status InitLinkList(LinkList &L) {
    L = new Node;
    L->next = nullptr;//这里用nullptr是C++20标准的
    return OK;
}
```



### 判空：

```c++
Status IsEmpty(LinkList &L) {
    if (L->next == nullptr) return OK;
    else return ERROR;
}
```



### 获取链表长度：

```c++
Status GetLength(LinkList &L) {
    LinkList p = L->next;//让p指向L的下一个节点就是头结点的下一个
    int count = 0;
    while (p){//这里判断方式的理解是如果L的下一个节点是空的话就不成立
        ++count;
        p = p->next;
    }
    cout<<count<<endl;//测试的时候发现要用cout输出才行，return会直接结束进程
    return OK;
}
```



### 头插和尾插法：

```C++
//初始化头插，同下，头和尾只能用一个，因为要经过初始化过程会抵消
//插入之后想要再插入要使用Insert函数不然会再次初始化表格
Status HeadInsert(LinkList &L, int n) {
    InitLinkList(L);
    for (int i = 0; i < n; ++i) {
        auto p = new Node;//C++建立新节点用new简单又方便
        cin>>p ->data;//这里就直接让用户输入n个data类型的元素更方便
        p->next = L->next;//在循环里面不断创建并且移动节点来进行写入操作
        L->next =p;
    }
    return OK;
}
/***
 * 简单的重复多余且易错
 * 当你使用auto的时候，被定义实体的名称会出现在固定的位置，这样可以增加可读性。
 * 在模板函数定义中，返回值可以是成员类型。
 */

//同上
//初始化尾插，使用data进行优化插入，n表示要插入多少个
Status TailInsert(LinkList &L, int n) {
    InitLinkList(L);
    for (int i = 0; i < n; ++i) {
        auto p = new Node;
        cin >>p->data;
        p->next = L->next;
        L->next = p;
    }
    return OK;
}
```



### 插入元素：

```c++
Status Insert(LinkList &L, int k, ElemType e) {
    int j = 0;
    while (L && j < k - 1) {
        L = L->next;
        ++j;//移动到要插入那个节点
    }
    if (!L || j > k + 1) return ERROR;//判断L是否存在，插入位置是否合法
    auto p = new Node;
    p->data = e;
    p->next = L->next;//插入的基本操作具体看书或者课件
    L->next = p;
    return OK;
}
```



### 删除元素：

```c++
Status DelLinkList(LinkList &L, int i) {
    int j = 0;
    while (L->next && j < i - 1) {
        L = L->next;
        ++j;//移动到要操作的节点
    }
    if (!L->next || j > i + 1) return ERROR;
    Node *q; //把数据传进去q节点
    q = L->next;
    L->next = q->next;//复制后直接把要操作的节点断开连接
    delete q;//释放q节点完成删除
    return OK;
}
```



### 查找元素：

```c++
Node *LocateElem(LinkList L, ElemType e) {
    LinkList p = L->next;
    while (p && p->data != e) {
        p = p->next;//不断移动直到找到与数据匹配的节点为止
    }
    cout<<p->data<<endl;//输出出来
    return p;
}//我这里函数这样写其实就是装逼而已，考试按正常写就行结果都一样
```



### 遍历：

```C++
Node *LocateElem(LinkList L, ElemType e) {
    LinkList p = L->next;
    while (p && p->data != e) {
        p = p->next;//不断移动直到找到与数据匹配的节点为止
    }
    cout<<p->data<<endl;//输出出来
    return p;
}//没什么好说的
```



### 匹配物理位置：

```c++
//按值匹配元素,索引出来的是物理位置,而非下标值
Status GetElem(LinkList &L, ElemType &e) {
    LinkList p = L->next;
    int i = 1;
    while (p && p->data != e) {
        p = p->next;
        ++i;
    }
    return i;
}
```



### 清空链表和摧毁链表：

```C++
//清空链表
Status CleanLinkList(LinkList &L) {
    LinkList q;
    LinkList p = L->next;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }
    L->next = nullptr;
    return OK;
}//你可以理解为往前挪一个就清理一个

//摧毁链表
Status Destroy(LinkList &L){
    LinkList p;
    while (L){
        p = L;//全选清除
        L = L->next;
        delete p;
    }
    return OK;
}
```