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
			head = add(head,number);//����д�޷��������޷�ǿ�ȵ����߱�����ָ�븳ֵ��
		}						    //���ʹ�ú���������������ֵ����main��Ŀ�����add���Ǵ�ġ� 
	} while(number != -1);
	
	return 0;
}

Node* add(Node* head,int number)//C�ĺ���������Զ���Ǵ�ֵ������˵����ֵ�����Ա��뽫���return��ȥ 
{								//void add(Node* head,int number);����Ч�ġ� 
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
