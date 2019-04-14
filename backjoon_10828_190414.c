#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define STACK_LEN 10000

// https://dojang.io/mod/page/view.php?id=409 참고 
typedef struct _stack { //structure이름: _stack
	int stackArr[STACK_LEN]; // length 100000를 가진 멤버1 
	int topIndex; // topIndex라는 멤버2
} Stack; // Stack이라는 이름으로 사용하겠다는 뜻.

// Stack의 초기화를 진행
// Stack생성 후 제일 먼저 호출되어야 하는 함수
// -> 의미는 http://blog.naver.com/PostView.nhn?blogId=skout123&logNo=50132236162 참고
void StackInit(Stack * pstack) {
	// 구조체 포인터 이름 -> 멤버 이름
	// 포인터가 참조하는 위치를 -1로 초기화 시킴
	pstack->topIndex = -1;
}

// Stack이 빈경우 TRUE(1), 그렇지 않은 경우 FALSE(0)을 반환
int SIsEmpty(Stack * pstack) {
	if (pstack->topIndex == -1) { // 초기화 상태 그대로 비어있다면
		return 1; // TRUE를 반환
	}
	else { // 그렇지 않다면 FALSE
		return 0;
	}
}

// Stack에 데이터를 저장.
// 매개변수 data로 전달된 값을 Stacck에 저장
void SPush(Stack * pstack, int data) {
	// 포인터의 위치를 1 증가시켜줌.
	pstack->topIndex += 1;
	// stack에 받은 데이터를 저장
	pstack->stackArr[pstack->topIndex] = data;
}

// 마지막에 저장된 요소를 삭제
// 삭제된 데이터는 반환
// 본 함수의 호출을 위해서는 하나 이상의 데이터의 존재가 보장되어야 함.
int SPop(Stack*pstack) {
	int rIdx;
	// stack이 비어있다면 다음 문구를 출력
	if (SIsEmpty(pstack)) {
		//printf("Stack Memory Error!");
		//exit(-1);
		return -1;
	} 
	// rIdx에 topIndex가 가르키는 위치 저장
	rIdx = pstack->topIndex;
	// topIndex 위치 -1처리
	pstack->topIndex -= 1;
	// rIdx에 저장한 위치에 저장된 데이터 반환
	return pstack->stackArr[rIdx];
}
// 마지막에 저장된 요소를 반환하되 삭제하지 않음
// 본 함수의 호출을 위해서는 하나 이상의 데이터의 존재가 보장되어야 함.
int STop(Stack * pstack) {
	// 스텍 비어있으면 다음 메세지 출력
	if (SIsEmpty(pstack)) {
		return -1;
	}
	// 현재 포인터가 가르키는 값 return
	return pstack->stackArr[pstack->topIndex];
}

// 사이즈 반환 (-1부터 시작하므로 +1)
int SSize(Stack * pstack) {
	return pstack->topIndex + 1;
}

int main(void) {
	int i, n, num;
	char str[6]; // 주어지는 정수 1-100,000
	Stack stack; 

	scanf("%d", &n); // 숫자 받음.
	
	StackInit(&stack); // Stack 초기화시키기

	for (i = 0; i < n; i++) { // 0 ~ N만큼 
		scanf("%s", str); // string 받음

		// strcmp는 문자열 비교 같으면 0
		// 받은 string이 push/pop/size/empty/top이면에 대한 조건
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