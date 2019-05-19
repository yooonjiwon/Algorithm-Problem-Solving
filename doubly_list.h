#pragma once

#define TRUE 1
#define FALSE 0

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
	struct Node* cursor;
};

// LinkedList라는 구조체 정희
typedef struct _DB_LinkedList {
	char str[1000000]; // 길이 L인 문자열 
	struct Node* head;
	// head 포인터에 다른 노드의 메모리 주소 저장, 리스트 머리
	struct Node* tail;
	// last 포인터에 다른 노드의 메모리 주소 저장, 리스트 꼬리
	struct Node* cur;
	// cur 포인터에 다른 노드의 메모리 주소 저장, 데이터 조회에 사용
	int numOfData;

} DB_LinkedList;

void ListInit(DB_LinkedList* plist);
int ListItemCount(DB_LinkedList* plist);
int IsEmpty(DB_LinkedList* plist);
void InsertItem(DB_LinkedList* plist, int data);
int Find(DB_LinkedList* plist, int pdata);
int RemoveItem(DB_LinkedList* plist, int pdata);
int getFirstItem(DB_LinkedList* plist, int* pdata);
int getNextItem(DB_LinkedList* plist, int* pdata);
int getPrevItem(DB_LinkedList* plist, int* pdata);