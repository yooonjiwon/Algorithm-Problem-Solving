#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define QUE_LEN 10000

// Queue ����ü ����
typedef struct _queue {
	int front;
	int rear;
	int queArr[QUE_LEN];
} Queue;

// Queue �ʱ�ȭ
// Queue ������� Ȯ��
void QueueInit(Queue * pq) {
	pq->front = 0;
	pq->rear = 0;
}

// Front�� Rear�� ������ ��ġ
// Que�� ��������� 1,  �ƴϸ� 0 ���
// pq -> front = (*pq).front
// Queue struct���� front, rear member pointing
int QIsEmpty(Queue * pq) {
	if (pq->front == pq->rear) { // front = rear
		return 1;
	}
	else {
		return 0;
	}
}

// Queue �� á���� Ȯ��
// Rear + 1�� front�� ������ �����ִ� ���� �ǹ�
int QIsFull(Queue * pq) {
	if (((pq->rear + 1) % QUE_LEN) == pq->front) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

// queArr�� rear�ڸ� 
int Size(Queue * pq) {
	return (pq-> rear) - (pq -> front);
}

// Enqueue
void Push(Queue * pq, int data) {
	if (QIsFull(pq)) { // Queue�� ����������
		return -1;
	}
	// �׷��� ������ REAR�ڸ� + 1 
	pq -> rear = (pq -> rear + 1) % QUE_LEN;
	// data �ֱ�
	pq -> queArr[pq -> rear] = data;
}

// Dequeue
int Pop(Queue * pq) {
	if (QIsEmpty(pq)) { // Queue�� ���������
		return -1;
	}
	// ������� ������ FRONT + 1
	pq->front = (pq->front + 1) % QUE_LEN;
	// front �ڸ��� �ִ� ������ ��ȯ 
	return pq->queArr[pq->front];
}

// ��������� ���� �ռ� �����͸� ��ȯ�ϵ� �������� ����.
// �� �Լ��� ȣ�� ���ؼ��� ������ �ϳ� �̻� �����ؾ���.
int Front(Queue * pq) {
	if (QIsEmpty(pq)) {
		return -1;
	}
	// FRONT + 1 ��ġ�� ������ ��ȯ
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

	scanf("%d\n", &n); // ���� �ޱ�

	QueueInit(&q); //ť �ʱ�ȭ
	
	for (i = 0; i < n; i++) {
		scanf("%s", quearr); // chracter �ޱ�

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