#include <stdio.h>
#include <stdlib.h>
#include "doubly_list.h"

//int main(void) {
//	DB_LinkedList list;
//	int data;
//	ListInit(&list);
//
//	InsertItem(&list, 1);
//	InsertItem(&list, 2);
//	InsertItem(&list, 3);
//	InsertItem(&list, 4);
//	InsertItem(&list, 5);
//	InsertItem(&list, 6);
//	InsertItem(&list, 7);
//	InsertItem(&list, 8);
//
//	if (getFirstItem(&list, &data)) {
//		printf("%d", data);
//		while (getNextItem(&list, &data)) 
//			printf("%d", data);
//		while (getPrevItem(&list, &data))
//			printf("%d", data);
//		printf("\n\n");
//	}
//	return 0;
//}

int main() {
	DB_LinkedList list_pw; // list ����ü
	ListInit(&list_pw); // list �ʱ�ȭ

	int num; // ���̽� ����
	char str[1000000];

	scanf("%d", &num);

	while (num--) {
		scanf("%s", str);
		InsertItem2(&list_pw, str);
	}
}