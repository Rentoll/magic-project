#include <malloc.h>

typedef struct Queue {
    char *str;
    struct Queue *next;
}Queue;

Queue* add2Queue(char* s, Queue* phead) {
	Queue* pnew = (Queue*)malloc(sizeof(Queue));
	Queue *p = phead;
	while(p && p->next)	{
		p=p->next;
	}
	pnew->str = (char*)malloc(strlen(s)+1);
	pnew->next = NULL;
	strcpy(pnew->str, s);
	if(p)
		p->next = pnew;
	if(phead)
		return phead;
	return pnew;
}

Queue* deleteFromQueue(Queue *phead) {
	Queue *p = NULL;
	if(phead)
		p = phead->next;
	free(phead->str);
	free(phead);
	return p;
}

void printQueue(Queue* phead) {
	while(phead) {
		printf("%s\n",phead->str);
		phead = phead->next;
	}
}


int main() {
	Queue * head = NULL;
	char stroka[255];
	printf("Enter a string:\n");
	gets(stroka);
	while(strlen(stroka)) {
		char raz[] = {' ', '\t', '\0'};
		char *s=strtok(stroka, raz);
		while(s) {
			head = add2Queue(s, head);
			s = strtok(NULL, raz);
		}
		printf("Enter a string:\n");
		gets(stroka);
	}
	printQueue(head);
	while(head)
		head = deleteFromQueue(head);
	return 0;

}
