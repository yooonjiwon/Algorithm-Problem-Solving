#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define QUE_LEN 10000

// Queue 구조체 정의
typedef struct _queue {
	int front;
	int rear;
	int queArr[QUE_LEN];
} Queue;

// Queue 초기화
// Queue 비었는지 확인
void QueueInit(Queue * pq) {
	pq->front = 0;
	pq->rear = 0;
}

// Front와 Rear가 동일한 위치
// Que가 비어있으면 1,  아니면 0 출력
// pq -> front = (*pq).front
// Queue struct에서 front, rear member pointing
int QIsEmpty(Queue * pq) {
	if (pq->front == pq->rear) { // front = rear
		return 1;
	}
	else {
		return 0;
	}
}

// Queue 꽉 찼는지 확인
// Rear + 1과 front가 같으면 꽉차있는 것을 의미
int QIsFull(Queue * pq) {
	if (((pq->rear + 1) % QUE_LEN) == pq->front) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

// queArr의 rear자리 
int Size(Queue * pq) {
	return (pq-> rear) - (pq -> front);
}

// Enqueue
void Push(Queue * pq, int data) {
	if (QIsFull(pq)) { // Queue가 꽉차있으면
		return -1;
	}
	// 그렇지 않으면 REAR자리 + 1 
	pq -> rear = (pq -> rear + 1) % QUE_LEN;
	// data 넣기
	pq -> queArr[pq -> rear] = data;
}

// Dequeue
int Pop(Queue * pq) {
	if (QIsEmpty(pq)) { // Queue가 비어있으면
		return -1;
	}
	// 비어있지 않으면 FRONT + 1
	pq->front = (pq->front + 1) % QUE_LEN;
	// front 자리에 있던 데이터 반환 
	return pq->queArr[pq->front];
}

// 저장순서가 가장 앞선 데이터를 반환하되 삭제하지 않음.
// 본 함수의 호출 위해서는 데이터 하나 이상 존재해야함.
int Front(Queue * pq) {
	if (QIsEmpty(pq)) {
		return -1;
	}
	// FRONT + 1 위치의 데이터 반환
	return pq->queArr[pq->front+1];
}

int Back(Queue * pq) {
	if (QIsEmpty(pq)) {
		return -1;
	}
	
	return pq->queArr[pq->rear];
}

int main(void) {
	int i, n, num;
	char quearr[10000];
	Queue q;

	scanf("%d\n", &n); // 숫자 받기

	QueueInit(&q); //큐 초기화
	
	for (i = 0; i < n; i++) {
		scanf("%s", quearr); // chracter 받기

		if (strcmp(quearr, "push") == 0) {
			scanf("%d\n", &num);
			Push(&q, num);
		}
		else if (strcmp(quearr, "pop") == 0) {
			printf("%d\n", Pop(&q));
		}
		else if (strcmp(quearr, "size") == 0) {
			printf("%d\n", Size(&q));
		}
		else if (strcmp(quearr, "empty") == 0) {
			printf("%d\n", QIsEmpty(&q));
		}
		else if (strcmp(quearr, "front") == 0) {
			printf("%d\n", Front(&q));
		}
		else if (strcmp(quearr, "back") == 0) {
			printf("%d\n", Back(&q));
		}
	}
	return 0;
}