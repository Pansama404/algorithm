#include <iostream>

#define OK 1;
#define ERROR 0;


typedef int Status;
typedef int ElemType;


typedef struct Node {
    ElemType data;
    struct Node *next;
} QNode, *Queueptr;

typedef struct {
    Queueptr rear;
    Queueptr front;
} LinkQueue;

//第二种没有头结点的写法

//Status Init(LinkQueue &q){
//    q.front = nullptr;
//    q.rear = nullptr;
//    return OK;

//Status IsEmpty(LinkQueue &q){
//    if (q.front == nullptr) return OK;
//    else return ERROR;
//}

//Status EnQueue(LinkQueue &q, ElemType &e) {
//    auto *s = (QNode *) malloc(sizeof(QNode));
//    s->data = e;
//    s->next = nullptr;
//    if (q.front == nullptr) {
//        q.front = s;
//        q.rear = s;
//    } else {
//        q.rear->next = s;
//        q.rear = s;
//    }
//    return OK
//}

//Status DeQueue(LinkQueue &q,ElemType &e){
//    if (q.front == nullptr) return ERROR;
//    auto *s = q.front;
//    e =s->data;
//    q.front =s->next;
//    if (q.rear == s)
//        q.front =q.rear = nullptr;
//    delete s;
//    return OK;
//}


//Status GetHead(LinkQueue &Q,ElemType &e){
//    if (IsEmpty(Q)) return ERROR;
//    e = Q.front->data;
//    return OK;
//}

Status InitQueue(LinkQueue &q) {
    q.front = q.rear = new QNode;
    if (!q.front) exit(0);
    q.front->next = nullptr;
    return OK;
}

Status IsEmpty(LinkQueue &q) {
    if (q.front == q.rear) return OK
    else return ERROR;
}

Status EnQueue(LinkQueue &q, ElemType e) {
    auto p = new QNode;
    p->data = e;
    p->next = nullptr;
    q.rear->next = p;
    q.rear = p;
    return OK;
}

Status DeQueue(LinkQueue &q, ElemType &e) {
    if (q.front == q.rear) return ERROR;
    auto p = new QNode;
    p = q.front->next;
    e = p->data;
    q.front->next = p->next;
    if (q.rear == p) q.front = q.rear;
    delete p;
    return OK;
}

Status GetHead(LinkQueue &q,ElemType &e){
    if(IsEmpty(q)) return ERROR;
    e=q.front->next->data;
    return OK;
}

Status Travel(LinkQueue &q){
    if (IsEmpty(q)) return ERROR;
    QNode *p;
    p = q.front->next;
    do{
        std::cout<<p->data<<std::endl;
        p=p->next;
    }while(p!= nullptr);
    return OK
}

Status Destroy(LinkQueue &q){
    QNode *p;
    if (IsEmpty(q)) return ERROR;
    p=q.front->next;
    while(p){
        q.front->next=p->next;
        delete p;
        p =q.front;
    }
    return OK;
}

Status Palindrome(char *str){
    LinkQueue q;
    ElemType e;
    int i;
    for (i = 0;str[i]!=0; i++) {
        EnQueue(q,str[i]);
    }
    i=0;
    while (!IsEmpty(q)){
        DeQueue(q,e);
        if(e!=str[i]) {return ERROR;}
        else return OK;
    }
    return OK;
}
