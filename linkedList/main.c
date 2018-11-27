//编译器名: TDM-GCC 4.8.1 32-bit Debug
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct _node {
//	int value;
//	struct _node *next;
//} Node;

Node* add(Node** pHead,int number);

int main(int argc, char *argv[]) {
	Node* head = NULL;
	int number;
	do{
		scanf("%d",&number);
		if(number != -1){
			head = add(&head,number);//传入head指针变量的地址，这样调用者赋值不赋值都没关系了。 
		}						     
	} while(number != -1);
	
	return 0;
}

Node* add(Node** pHead,int number)//传入的是指针变量的地址。 
{							      //这样对*pHead操作就能操作外部指针变量 
		// add to linked-list
		Node *p = (Node*)malloc(sizeof(Node));
		p->value = number;
		p->next = NULL;
		//find the last
		Node *last = *pHead;
		if(last){
			while(last->next){
				last = last->next;
			}
			//attach
			last->next = p;
		}
		else{
			*pHead = p;
		}
		return *pHead;//是否return已经没关系了。 
}
