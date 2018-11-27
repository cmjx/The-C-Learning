//��������: TDM-GCC 4.8.1 32-bit Debug
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
			head = add(&head,number);//����headָ������ĵ�ַ�����������߸�ֵ����ֵ��û��ϵ�ˡ� 
		}						     
	} while(number != -1);
	
	return 0;
}

Node* add(Node** pHead,int number)//�������ָ������ĵ�ַ�� 
{							      //������*pHead�������ܲ����ⲿָ����� 
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
		return *pHead;//�Ƿ�return�Ѿ�û��ϵ�ˡ� 
}
