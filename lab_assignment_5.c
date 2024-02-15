#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int i = 0;
	while (head != NULL){
		i++;
		head = head->next;
	}
	return i;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int listLen = length(head);
	char* str = malloc(listLen * sizeof(char));
	for (int i = 0; i < listLen; i++) {
		str[i] = head->letter;
		head = head->next;
	}
	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* head = *pHead;
	node* newNode = (node*)malloc(sizeof(node));
	if (newNode == NULL) {
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
  }
	newNode->letter = c;
	newNode->next = NULL;
	if (head == NULL){
		*pHead = newNode;
		return;
	} else {
		while (head->next != NULL){
			head = head->next;
		}
		head->next = newNode;
	}
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* head = *pHead;
	while (head != NULL) {
		node* temp = head;
		head = head->next;
		free(temp);
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("%p", head);
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}