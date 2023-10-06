#include <iostream>

using namespace std;

#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node, *LinkList;

//初始化
Status InitLinkList(LinkList &L) {
    L = new Node;
    L->next = nullptr;
    return OK;
}

//判断是否为空
Status IsEmpty(LinkList &L) {
    if (L->next == nullptr) return OK;
    else return ERROR;
}

//获得链表长度
Status GetLength(LinkList &L) {
    LinkList p = L->next;
    int count = 0;
    while (p){
        ++count;
        p = p->next;
    }
    cout<<count<<endl;
    return OK;
}

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

//插入元素
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

//删除元素
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

//查找
Node *LocateElem(LinkList L, ElemType e) {
    LinkList p = L->next;
    while (p && p->data != e) {
        p = p->next;//不断移动直到找到与数据匹配的节点为止
    }
    cout<<p->data<<endl;//输出出来
    return p;
}

//遍历打印元素
Status Travel(LinkList &L) {
    LinkList p = L->next;
    while (p) {
        cout << p->data << endl;
        p = p->next;
    }
    cout << endl;
    return OK;
}

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

//测码
int main() {
    return 0;
}