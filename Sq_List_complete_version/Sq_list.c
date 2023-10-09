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
    ElemType *elem;          ///���ݴ洢�Ĵ�С
    int length;                 ///�������Ա�ĳ���
    int listsize;
} SqList;

void Check_Capacity(SqList L);

//�������Ա�
Status InitSqList(SqList *L) {
    L->elem = (int *) malloc(MAXSIZE * sizeof(int));
    if (!L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listsize = MAXSIZE;
    return OK;
}

//�õ�����
Status GetLength(SqList L) {
    if (!L.elem) exit(OVERFLOW);//ǰ���ǵ������˳���
    return L.length;
}

//�п�
Status IsEmpty(SqList *L) {
    if (!L->elem) exit(OVERFLOW);
    if (L->length == 0) return OK;
    else return ERROR;
}

//����
Status SqList_Insert(SqList *L, int i, ElemType e) {
    if (!L->elem) exit(OVERFLOW);
    if (i < 1 || i > L->length + 1) return ERROR;//���Ӵ���Ľ�׳��
    if (L->length >= MAXSIZE) Check_Capacity(*L);//�����˽��м��ڴ����
    if (i != L->length + 1) {//����λ�÷���β����Ҫ����������λ
        for (int j = i; j < L->length; j--) {
            L->elem[j] = L->elem[j - 1];
        }
    }
    L->elem[i - 1] = e;//��β��ֱ�Ӳ�
    L->length++;//����֮��Ҫ���
    return OK;
}

//ɾ������
Status SqList_Del(SqList *L, int i, ElemType *e) {///��i��λ�õ�Ԫ��
    if (!L->elem) exit(OVERFLOW);
    if (i < 1 || i > L->length) return ERROR;
    *e = L->elem[i - 1];        ///��Ԫ�����б���±����i-1
    if (i != L->length) {
        for (int j = i; j < L->length; j++) {
            L->elem[j - 1] = L->elem[j];
        }
    }
    L->length--;
    return OK;
}

//����б�
Status ClearList(SqList *L) {
    if (!L->elem) exit(OVERFLOW);
    L->length = 0;
    return OK;
}

//�����б�
Status Destroy_SqList(SqList *L) {
    if (!L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listsize = 0;
    free(L->elem);//�ѱ��е�Ԫ��ȫ���ͷ���free����
    L->elem = NULL;//�ѱ��Ԫ�ظ�ֵΪNULL��ʾȫ������֮��Ϊ��
    return OK;
}

void Check_Capacity(SqList L) {
    if (L.length == L.listsize) {
        ElemType *ptr = (ElemType *) realloc(L.elem, (MAXSIZE + List_Increase) * sizeof(ElemType));
        L.elem = ptr;
        L.listsize = L.length + List_Increase;
    }
}
//����;��������ӣ���˵��һ�¡�
//1. realloc��һ����Ϊ������bug
//void *ptr = realloc(ptr, new_size);
//if (!ptr) {
//������
//}
//�����������һ���ڴ�й¶�����⣬��realloc����ʧ�ܵ�ʱ�򣬻᷵��NULL�����ǲ����е�ptr���ڴ���û�б��ͷŵġ����ֱ�ӽ�realloc�ķ���ֵ����ptr����ô�������ڴ�ʧ��ʱ���ͻ����ptrԭ��ָ����ڴ涪ʧ�����й¶��
//
//��ȷ�Ĵ���Ӧ��������
//void *new_ptr = realloc(ptr, new_size);
//if (!new_ptr) {
//������
//}
//ptr = new_ptr

//��λ����
ElemType GetElem(SqList L, int i) {
    ElemType e;
    if (!L.elem) exit(OVERFLOW);
    if (i < 1 || i > L.length) return ERROR;
    e = L.elem[i - 1];
    return e;
}

//��ֵ����
Status LocateElem(SqList L, ElemType e) {
    if (!L.elem) exit(OVERFLOW);
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e)
            return i + 1;
    }
    return ERROR;
}

//����
void Travel(SqList L){
    if(!L.elem) exit(OVERFLOW);
    for (int i = 0; i < L.length; i++) {
        printf("%d\t",L.elem[i]);//���û�취�˸�����ҲҪ������
    }
}

