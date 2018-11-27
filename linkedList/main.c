//编译器名: TDM-GCC 4.8.1 32-bit Debug
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct _node {
//	int value;
//	struct _node *next;
//} Node;

typedef struct _list{
	Node* head;
// Node* tail; //通过定义自己的数据结构代表整个链表 
// 给我们将来升级， 将来改进List带来了无限可能。 
//如果没有这个结构，我们只是一个悬在外面的 head，这是工程化程序思维。  
} List;//将head指针变量放入List结构体，方便将来对链表的结构扩充，比如增加结构tail指针。 

void add(List* pList,int number);

int main(int argc, char *argv[]) {
	List list;
	list.head = NULL;
//	list.tail = NULL;
	int number;
	do{
		scanf("%d",&number);
		if(number != -1){
			add(&list,number);//传入List地址比传入head指针变量的地址好。 
		}						     
	} while(number != -1);
	
	return 0;
}

void add(List* pList,int number)//传入的是结构的地址。 
{							     
		// add to linked-list
		Node *p = (Node*)malloc(sizeof(Node));
		p->value = number;
		p->next = NULL;
		//find the last
		Node *last = pList->head;
		if(last){
			while(last->next){
				last = last->next;
			}
			//attach
			last->next = p;
		}
		else{
			pList->head = p;
		}
}
