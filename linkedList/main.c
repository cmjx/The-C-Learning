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
//	for(p=list.head;p;p=p->next){//��������г����ľ���д����ֻҪp�����ھͲ���ѭ�������� 
//		printf("%d\t",p->value);
//	}
//	printf("\n");
	print(&list);
	
	//����ļ����� 
	scanf("%d",&number);
	 
	Node *p;
	int isFound = 0;
	for(p=list.head;p;p=p->next){
		if(p->value==number){
			printf("�ҵ���!\n");
			isFound = 1;
			break;
		}
	}
	
	if(!isFound){
		printf("û�ҵ���\n");
	}
	//�����ɾ��
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
	print(&list);//��֤����ڵ��Ƿ�ɾ���� 
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

void print(List* pList){
	Node *p;
	for(p=pList->head;p;p=p->next){//��������г����ľ���д����ֻҪp�����ھͲ���ѭ�������� 
		printf("%d\t",p->value);
	}
	printf("\n");
}




