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
void print(List* pList);

int main(int argc, char *argv[]) {
	List list;
	list.head = NULL;
//	list.tail = NULL;
	int number;
	do{
		scanf("%d",&number);
		if(number != -1){
			add(&list,number);
		}						     
	} while(number != -1);
	
//	Node *p;
//	for(p=list.head;p;p=p->next){//链表操作中常见的经典写法，只要p还存在就不断循环遍历。 
//		printf("%d\t",p->value);
//	}
//	printf("\n");
	print(&list);
	
	//链表的简单搜索 
	scanf("%d",&number);
	 
	Node *p;
	int isFound = 0;
	for(p=list.head;p;p=p->next){
		if(p->value==number){
			printf("找到了!\n");
			isFound = 1;
			break;
		}
	}
	
	if(!isFound){
		printf("没找到！\n");
	}
	//链表的删除
	scanf("%d",&number);	 
	Node* q;
	for(q=NULL,p=list.head; p; q=p,p=p->next){
		if(p->value==number){
			if(q)//Be careful boundary
			{
				q->next = p->next;
			}
			else{
				list.head = p->next;
			}
			free(p);
			break;
		}
	}
	print(&list);//验证链表节点是否删除了 
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

void print(List* pList){
	Node *p;
	for(p=pList->head;p;p=p->next){//链表操作中常见的经典写法，只要p还存在就不断循环遍历。 
		printf("%d\t",p->value);
	}
	printf("\n");
}




