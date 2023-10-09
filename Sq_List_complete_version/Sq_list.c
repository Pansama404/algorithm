#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
#define List_Increase 10

typedef int Status;
typedef int ElemType;
typedef struct SqList {
    ElemType *elem;          ///数据存储的大小
    int length;                 ///定义线性表的长度
    int listsize;
} SqList;

void Check_Capacity(SqList L);

//创建线性表
Status InitSqList(SqList *L) {
    L->elem = (int *) malloc(MAXSIZE * sizeof(int));
    if (!L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listsize = MAXSIZE;
    return OK;
}

//得到长度
Status GetLength(SqList L) {
    if (!L.elem) exit(OVERFLOW);//前提是得用这个顺序表
    return L.length;
}

//判空
Status IsEmpty(SqList *L) {
    if (!L->elem) exit(OVERFLOW);
    if (L->length == 0) return OK;
    else return ERROR;
}

//插入
Status SqList_Insert(SqList *L, int i, ElemType e) {
    if (!L->elem) exit(OVERFLOW);
    if (i < 1 || i > L->length + 1) return ERROR;//增加代码的健壮性
    if (L->length >= MAXSIZE) Check_Capacity(*L);//表满了进行加内存操作
    if (i != L->length + 1) {//插入位置非最尾部的要进行往后移位
        for (int j = i; j < L->length; j--) {
            L->elem[j] = L->elem[j - 1];
        }
    }
    L->elem[i - 1] = e;//是尾部直接插
    L->length++;//插入之后要变表长
    return OK;
}

//删除操作
Status SqList_Del(SqList *L, int i, ElemType *e) {///第i个位置的元素
    if (!L->elem) exit(OVERFLOW);
    if (i < 1 || i > L->length) return ERROR;
    *e = L->elem[i - 1];        ///该元素在列表的下标就是i-1
    if (i != L->length) {
        for (int j = i; j < L->length; j++) {
            L->elem[j - 1] = L->elem[j];
        }
    }
    L->length--;
    return OK;
}

//清空列表
Status ClearList(SqList *L) {
    if (!L->elem) exit(OVERFLOW);
    L->length = 0;
    return OK;
}

//销毁列表
Status Destroy_SqList(SqList *L) {
    if (!L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listsize = 0;
    free(L->elem);//把表中的元素全部释放用free函数
    L->elem = NULL;//把表的元素赋值为NULL表示全部销毁之后为空
    return OK;
}

void Check_Capacity(SqList L) {
    if (L.length == L.listsize) {
        ElemType *ptr = (ElemType *) realloc(L.elem, (MAXSIZE + List_Increase) * sizeof(ElemType));
        L.elem = ptr;
        L.listsize = L.length + List_Increase;
    }
}
//下面就举两个例子，来说明一下。
//1. realloc第一种行为引发的bug
//void *ptr = realloc(ptr, new_size);
//if (!ptr) {
//错误处理
//}
//这里就引出了一个内存泄露的问题，当realloc分配失败的时候，会返回NULL。但是参数中的ptr的内存是没有被释放的。如果直接将realloc的返回值赋给ptr。那么当申请内存失败时，就会造成ptr原来指向的内存丢失，造成泄露。
//
//正确的处理应该是这样
//void *new_ptr = realloc(ptr, new_size);
//if (!new_ptr) {
//错误处理。
//}
//ptr = new_ptr

//按位查找
ElemType GetElem(SqList L, int i) {
    ElemType e;
    if (!L.elem) exit(OVERFLOW);
    if (i < 1 || i > L.length) return ERROR;
    e = L.elem[i - 1];
    return e;
}

//按值查找
Status LocateElem(SqList L, ElemType e) {
    if (!L.elem) exit(OVERFLOW);
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e)
            return i + 1;
    }
    return ERROR;
}

//遍历
void Travel(SqList L){
    if(!L.elem) exit(OVERFLOW);
    for (int i = 0; i < L.length; i++) {
        printf("%d\t",L.elem[i]);//这就没办法了改类型也要改他了
    }
}

