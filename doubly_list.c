#include <stdio.h>
#include <stdlib.h>
#include "doubly_list.h"

//https://awesomebit.tistory.com/55
// �ʱ�ȭ
void ListInit(DB_LinkedList* plist) {
	plist->head = NULL;
	plist->tail = NULL;
	plist->numOfData = 0;
}

int ListItemCount(DB_LinkedList* plist) {
	return plist->numOfData;
}

int IsEmpty(DB_LinkedList* plist) {
	if (plist->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

void InsertItem(DB_LinkedList* plist, int Data) {
	struct Node * newNode = (struct Node*)malloc(sizeof(struct Node)); // newNode ����
	newNode->data = Data; // newNode�� ������ �־���
	newNode->next = NULL; // next�� �����
	if (plist->head == NULL) { // List�� ���������
		newNode->prev = NULL;
		plist->head = newNode; // head�� newNode�ּ� �־���
		plist->tail = newNode; // tail�� newNode�ּ� �־���
	}
	else {
		plist->tail->next = newNode; // ���� tail�� next�� ������� �ּ�
		newNode->prev = plist->tail; // newNode�� prev�� plist�� tail
		plist->tail = plist->tail->next; // tail�� ������� next�� ����Ŵ
	}
	(plist->numOfData)++;
}

int Find(DB_LinkedList* plist, int pdata) {
	struct Node* temp; // temp ����
	if (IsEmpty(plist)) // ���������
		return FALSE; // �� ã�� �� �����Ƿ� FALSE return
	temp = plist->head; // temp�� head�� ����Ű�� �ּҰ� ����
	while (temp->next != NULL) { // next�� NULL�� �ƴҶ�����
		if (temp->data == pdata) // temp�� data�� ã�����ϴ� data�� ��ġ�ϸ�
			return TRUE; // TRUE return
		else // �ƴϸ� 
			temp = temp->next; //temp�� next�� ����Ű�� �ּ� �ο�
	}
	if (temp->data == pdata) // ������ ����� �����Ͱ� pdata�� ��ġ�ϸ�
		return TRUE; // TRUE
	return FALSE; // �ƴϸ� FALSE

}

int RemoveItem(DB_LinkedList* plist, int pdata) {
	struct Node* delNode; //delNode ������ ����
	struct Node* temp; //temp ������ ����

	if (IsEmpty(plist)) { // ����Ʈ ��� ������ �������ϹǷ�
		return FALSE; // FALSE return
	} 

	delNode = plist->head; // delNode�� head ����Ű�� �ּ� �Ҵ�
	temp = plist->head; // temp�� head ����Ű�� �ּ� �Ҵ�
	// ù ��° ���
	if (delNode->data == pdata) {
		plist->head = plist->head->next; // head�� �ּҸ� �������� �ٲ��ֱ�
		plist->head->prev = NULL; // �� ��������� prev NULLó��
		free(delNode); // �ּ� ����
		(plist->numOfData)--; // ��尹�� �ϳ� ���̱�
		return TRUE;
	}
	// �ι�° ~ ������-1 ���
	else { 
		delNode = delNode->next; // delNode�� �� �����ּ� �ο�
	}
	while (temp->next != NULL) { // ������ ������ �ݺ�
		if (delNode->data == pdata) { // ���� ��� �����Ͱ� ��忡 �ִٸ�
			temp->next = delNode->next; // ������ next�� delNode�� ����Ű�� Node�� next ����Ű����
			delNode->next->prev = temp; // delNode next�� ����Ű�� ����� prev�� ����Ű�� ���� temp�� �ǵ���
			free(delNode); // �޸� ����
			(plist->numOfData)--; // ��� ���� 1�� ����
			return TRUE;
		}
		else {
			temp = delNode; // temp �ּ� delNode�� ����
			delNode = delNode->next; // delNode�� next�� ����Ű�� �� �ּ� ����
		}
	}
	// ������ ���
	if (delNode->data == pdata) {
		delNode->prev->next = NULL; // ��������� next ����
		delNode->prev = NULL;
		plist->tail = delNode->prev; // tail�� prev�� ����Ű�� �ּ� �ֱ�
		free(delNode);
		(plist->numOfData)--; // ��� ���� 1�� ����
		return TRUE;
	}
	return FALSE;
}

int getFirstItem(DB_LinkedList* plist, int* pdata) {
	if (plist->head == NULL) {
		return FALSE;
	}
	plist->cur = plist->head;
	*pdata = plist->cur->data;
	return TRUE;
}

int getNextItem(DB_LinkedList* plist, int* pdata) {
	if (plist->cur->next == NULL) { // ������ ����
		return FALSE;
	}
	plist->cur = plist->cur->next; // cur ��ġ next�� �Ű��ֱ�
	*pdata = plist->cur->data;
	return TRUE;
}

int getPrevItem(DB_LinkedList* plist, int* pdata) {
	if (plist->cur->prev == NULL)
		return FALSE;
	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return TRUE;
}