#include "node.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct _node {
//	int value;
//	struct _node *next;
//} Node;

Node* add(Node* head,int number);

int main(int argc, char *argv[]) {
	Node * head = NULL;
	int number;
	do{
		scanf("%d",&number);
		if(number != -1){
			head = add(head,number);//这样写无法防呆，无法强迫调用者必须做指针赋值，
		}						    //如果使用函数的人忘了做赋值，对main里的空链表add就是错的。 
	} while(number != -1);
	
	return 0;
}

Node* add(Node* head,int number)//C的函数调用永远都是传值，或者说拷贝值。所以必须将结果return回去 
{								//void add(Node* head,int number);是无效的。 
		// add to linked-list
		Node *p = (Node*)malloc(sizeof(Node));
		p->value = number;
		p->next = NULL;
		//find the last
		Node *last = head;
		if(last){
			while(last->next){
				last = last->next;
			}
			//attach
			last->next = p;
		}
		else{
			head = p;
		}
		return head;
}
