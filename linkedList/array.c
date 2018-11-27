#include "array.h"
#include <stdio.h>
#include <stdlib.h>

const BLOCK_SIZE = 20;
//typedef struct {
//	int *array;
//	int size;
//} Array;

//�������� create array
Array array_create(int init_size){
	Array a;
	a.size = init_size;
	a.array = (int*)malloc(sizeof(int)*a.size);
	return a;
}

//����ռ��ͷŻ��� free array 
void array_free(Array *a){
	free(a->array);
	a->array = NULL;	//��ֹ�ظ�free��ͬ�ڴ� 
	a->size = 0;
}

//���������ж��ٵ�Ԫ����  
int array_size(const Array *a){
	return a->size;
}

//��������ĳ����Ԫ����������ֵҲ��������ֵ
// scanf("%d",array_at(&a,cnt++));
int* array_at(Array *a,int index){
	if(index >= a->size){
		array_inflate(a,(index/BLOCK_SIZE+1)*BLOCK_SIZE - a->size);
		// BLOCK_SIZE == 20  if index == 102  , a->size == 100
		// 102/20 == 5
		//  5+1 == 6
		// 6*20 == 120 
		// 120-100 == 20
	}
	return &(a->array[index]);	//����ָ�뷽��ʹ��ʱ��������ֵ 
}

// �����ϲ�� *array_at(Array *a,int index)����ֵ���Խ�һ����װ�������� 
//int array_get(const Array *a,int index){
//	return a->array[index];
//} 
//
//void array_set(Array *a,int index,int value){
//	a->array[index] = value;
//}

//�������鵥Ԫ 
void array_inflate(Array *a,int more_size){
	int *p = (int*)malloc(sizeof(int)*(a->size + more_size));
	int i;
	//memcpy((void*)p,(void*)a->array,a->size*sizeof(int));  //��׼�⺯�����������forѭ��Ч�ʸ��� 
	for( i=0;i<a->size;i++){
		p[i] = a->array[i];
	}
	free(a->array);
	a->array = p;
	a->size += more_size;
}
