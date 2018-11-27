//��������: TDM-GCC 4.8.1 32-bit Debug
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

//typedef struct _node {
//	int value;
//	struct _node *next;
//} Node;

typedef struct _list{
	Node* head;
// Node* tail; //ͨ�������Լ������ݽṹ������������ 
// �����ǽ��������� �����Ľ�List���������޿��ܡ� 
//���û������ṹ������ֻ��һ����������� head�����ǹ��̻�����˼ά��  
} List;//��headָ���������List�ṹ�壬���㽫��������Ľṹ���䣬�������ӽṹtailָ�롣 

void add(List* pList,int number);

int main(int argc, char *argv[]) {
	List list;
	list.head = NULL;
//	list.tail = NULL;
	int number;
	do{
		scanf("%d",&number);
		if(number != -1){
			add(&list,number);//����List��ַ�ȴ���headָ������ĵ�ַ�á� 
		}						     
	} while(number != -1);
	
	return 0;
}

void add(List* pList,int number)//������ǽṹ�ĵ�ַ�� 
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
