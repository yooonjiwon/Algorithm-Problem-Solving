#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define STACK_LEN 10000

// https://dojang.io/mod/page/view.php?id=409 ���� 
typedef struct _stack { //structure�̸�: _stack
	int stackArr[STACK_LEN]; // length 100000�� ���� ���1 
	int topIndex; // topIndex��� ���2
} Stack; // Stack�̶�� �̸����� ����ϰڴٴ� ��.

// Stack�� �ʱ�ȭ�� ����
// Stack���� �� ���� ���� ȣ��Ǿ�� �ϴ� �Լ�
// -> �ǹ̴� http://blog.naver.com/PostView.nhn?blogId=skout123&logNo=50132236162 ����
void StackInit(Stack * pstack) {
	// ����ü ������ �̸� -> ��� �̸�
	// �����Ͱ� �����ϴ� ��ġ�� -1�� �ʱ�ȭ ��Ŵ
	pstack->topIndex = -1;
}

// Stack�� ���� TRUE(1), �׷��� ���� ��� FALSE(0)�� ��ȯ
int SIsEmpty(Stack * pstack) {
	if (pstack->topIndex == -1) { // �ʱ�ȭ ���� �״�� ����ִٸ�
		return 1; // TRUE�� ��ȯ
	}
	else { // �׷��� �ʴٸ� FALSE
		return 0;
	}
}

// Stack�� �����͸� ����.
// �Ű����� data�� ���޵� ���� Stacck�� ����
void SPush(Stack * pstack, int data) {
	// �������� ��ġ�� 1 ����������.
	pstack->topIndex += 1;
	// stack�� ���� �����͸� ����
	pstack->stackArr[pstack->topIndex] = data;
}

// �������� ����� ��Ҹ� ����
// ������ �����ʹ� ��ȯ
// �� �Լ��� ȣ���� ���ؼ��� �ϳ� �̻��� �������� ���簡 ����Ǿ�� ��.
int SPop(Stack*pstack) {
	int rIdx;
	// stack�� ����ִٸ� ���� ������ ���
	if (SIsEmpty(pstack)) {
		//printf("Stack Memory Error!");
		//exit(-1);
		return -1;
	} 
	// rIdx�� topIndex�� ����Ű�� ��ġ ����
	rIdx = pstack->topIndex;
	// topIndex ��ġ -1ó��
	pstack->topIndex -= 1;
	// rIdx�� ������ ��ġ�� ����� ������ ��ȯ
	return pstack->stackArr[rIdx];
}
// �������� ����� ��Ҹ� ��ȯ�ϵ� �������� ����
// �� �Լ��� ȣ���� ���ؼ��� �ϳ� �̻��� �������� ���簡 ����Ǿ�� ��.
int STop(Stack * pstack) {
	// ���� ��������� ���� �޼��� ���
	if (SIsEmpty(pstack)) {
		return -1;
	}
	// ���� �����Ͱ� ����Ű�� �� return
	return pstack->stackArr[pstack->topIndex];
}

// ������ ��ȯ (-1���� �����ϹǷ� +1)
int SSize(Stack * pstack) {
	return pstack->topIndex + 1;
}

int main(void) {
	int i, n, num;
	char str[6]; // �־����� ���� 1-100,000
	Stack stack; 

	scanf("%d", &n); // ���� ����.
	
	StackInit(&stack); // Stack �ʱ�ȭ��Ű��

	for (i = 0; i < n; i++) { // 0 ~ N��ŭ 
		scanf("%s", str); // string ����

		// strcmp�� ���ڿ� �� ������ 0
		// ���� string�� push/pop/size/empty/top�̸鿡 ���� ����
		if (strcmp(str, "push")==0) { 
			scanf("%d", &num);
			SPush(&stack, num);
		}
		else if (strcmp(str, "pop")==0) {
			printf("%d\n", SPop(&stack));
		}
		else if (strcmp(str, "size")==0) {
			printf("%d\n", SSize(&stack));
		}
		else if (strcmp(str, "empty")==0) {
			printf("%d\n", SIsEmpty(&stack));
		}
		else if (strcmp(str, "top")==0) {
			printf("%d\n", STop(&stack));
		}

	}
	return 0;
}