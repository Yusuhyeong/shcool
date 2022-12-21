#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int key;
	struct Node* tail;
} listNode;

typedef struct Head {
	struct Node* head;
}headNode;

int printList(headNode* h) {
	int i = 0;
	listNode* p = (listNode*)malloc(sizeof(listNode));
	if (h == NULL) {
		printf("Nothing to print....\n");
		return 0;
	}

	p = h->head;

	while (p != NULL) {
		p = p->tail;
		i++;
	}

	return i;
}

int freeNode(headNode* h) {
	free(h);
	return 0;
}

headNode* intialize(headNode* h) {
	if (h != NULL)
		freeNode(h);
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->head = NULL;
	return temp;
}


int findValue(headNode* h, int key) {
	if (h->head == NULL)
		return 1;

	listNode* n = h->head;

	while (n != NULL) {
		if (n->key == key)
			return 0;

		n = n->tail;
	}
	return 1;
}

int insertNode(headNode* h, int key) {
	int returnTemp;
	returnTemp = findValue(h, key);

	if (returnTemp != 0) {
		listNode* node = (listNode*)malloc(sizeof(listNode));
		node->key = key;
		node->tail = NULL;

		if (h->head == NULL) {
			h->head = node;
			return 0;
		}

		listNode* n = h->head;
		while (n->tail != NULL) {
			n = n->tail;
		}
		n->tail = node;
	}
	return 0;
}

int getCntNode(FILE* fp, headNode* h)
{
	int cntNode = 0;
	char* pstr;
	char strTemp[10];
	while (!feof(fp))
	{
		pstr = fgets(strTemp, 11, fp);
		int temp = atoi(pstr);

		intsertNode(h, temp);
	}
	cntNode = printList(h);

	return cntNode;
}

int getCnt(FILE* fp)
{
	int cnt = 0;
	char* pstr;
	char strTemp[10];
	while (!feof(fp))
	{
		pstr = fgets(strTemp, 10, fp);
		int temp = atoi(pstr);
		if (temp > 5000)
			cnt++;
	}
	return cnt;
}

int main()
{
	int cnt = 0;
	int cntNode = 0;
	FILE* fp;
	fp = fopen("input.txt", "r");
	headNode* headnode = NULL;
	headnode = intialize(headnode);


	if (fp = NULL)
	{
		printf("error");
		return 0;
	}

	cntNode = getCntNode(fp, headnode);

	fseek(fp, 0, SEEK_SET);

	cnt = getCnt(fp);

	printf("The total number of nodes : %d\n", cntNode);
	printf("More than 5000 values : %d\n", cnt);

	freeNode(headnode);
	fclose(fp);

	return 0;

}