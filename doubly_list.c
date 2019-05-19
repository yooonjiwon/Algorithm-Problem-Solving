#include <stdio.h>
#include <stdlib.h>
#include "doubly_list.h"

//https://awesomebit.tistory.com/55
// 초기화
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
	struct Node * newNode = (struct Node*)malloc(sizeof(struct Node)); // newNode 생성
	newNode->data = Data; // newNode에 데이터 넣어줌
	newNode->next = NULL; // next는 비워둠
	if (plist->head == NULL) { // List가 비어있으면
		newNode->prev = NULL;
		plist->head = newNode; // head에 newNode주소 넣어줌
		plist->tail = newNode; // tail에 newNode주소 넣어줌
	}
	else {
		plist->tail->next = newNode; // 기존 tail의 next는 새노드의 주소
		newNode->prev = plist->tail; // newNode의 prev은 plist의 tail
		plist->tail = plist->tail->next; // tail은 새노드의 next를 가리킴
	}
	(plist->numOfData)++;
}

int Find(DB_LinkedList* plist, int pdata) {
	struct Node* temp; // temp 생성
	if (IsEmpty(plist)) // 비어있으면
		return FALSE; // 값 찾을 수 없으므로 FALSE return
	temp = plist->head; // temp에 head가 가리키는 주소값 넣음
	while (temp->next != NULL) { // next가 NULL이 아닐때까지
		if (temp->data == pdata) // temp의 data가 찾고자하는 data와 일치하면
			return TRUE; // TRUE return
		else // 아니면 
			temp = temp->next; //temp에 next가 가리키는 주소 부여
	}
	if (temp->data == pdata) // 마지막 노드의 데이터가 pdata와 일치하면
		return TRUE; // TRUE
	return FALSE; // 아니면 FALSE

}

int RemoveItem(DB_LinkedList* plist, int pdata) {
	struct Node* delNode; //delNode 포인터 생성
	struct Node* temp; //temp 포인터 생성

	if (IsEmpty(plist)) { // 리스트 비어 있으면 삭제못하므로
		return FALSE; // FALSE return
	} 

	delNode = plist->head; // delNode에 head 가르키는 주소 할당
	temp = plist->head; // temp에 head 가르키는 주소 할당
	// 첫 번째 노드
	if (delNode->data == pdata) {
		plist->head = plist->head->next; // head의 주소를 다음노드로 바꿔주기
		plist->head->prev = NULL; // 그 다음노드의 prev NULL처리
		free(delNode); // 주소 해제
		(plist->numOfData)--; // 노드갯수 하나 줄이기
		return TRUE;
	}
	// 두번째 ~ 마지막-1 노드
	else { 
		delNode = delNode->next; // delNode에 그 다음주소 부여
	}
	while (temp->next != NULL) { // 마지막 전까지 반복
		if (delNode->data == pdata) { // 삭제 대상 데이터가 노드에 있다면
			temp->next = delNode->next; // 현재노드 next가 delNode가 가르키는 Node의 next 가르키도록
			delNode->next->prev = temp; // delNode next가 가르키는 노드의 prev가 가르키는 곳이 temp가 되도록
			free(delNode); // 메모리 해제
			(plist->numOfData)--; // 노드 갯수 1개 감소
			return TRUE;
		}
		else {
			temp = delNode; // temp 주소 delNode와 동일
			delNode = delNode->next; // delNode에 next가 가르키는 곳 주소 저장
		}
	}
	// 마지막 노드
	if (delNode->data == pdata) {
		delNode->prev->next = NULL; // 이전노드의 next 비우기
		delNode->prev = NULL;
		plist->tail = delNode->prev; // tail에 prev가 가르키는 주소 넣기
		free(delNode);
		(plist->numOfData)--; // 노드 갯수 1개 감소
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
	if (plist->cur->next == NULL) { // 마지막 노드면
		return FALSE;
	}
	plist->cur = plist->cur->next; // cur 위치 next로 옮겨주기
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