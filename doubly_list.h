#pragma once

#define TRUE 1
#define FALSE 0

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
	struct Node* cursor;
};

// LinkedList��� ����ü ����
typedef struct _DB_LinkedList {
	char str[1000000]; // ���� L�� ���ڿ� 
	struct Node* head;
	// head �����Ϳ� �ٸ� ����� �޸� �ּ� ����, ����Ʈ �Ӹ�
	struct Node* tail;
	// last �����Ϳ� �ٸ� ����� �޸� �ּ� ����, ����Ʈ ����
	struct Node* cur;
	// cur �����Ϳ� �ٸ� ����� �޸� �ּ� ����, ������ ��ȸ�� ���
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