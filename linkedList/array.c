#include "array.h"
#include <stdio.h>
#include <stdlib.h>

const BLOCK_SIZE = 20;
//typedef struct {
//	int *array;
//	int size;
//} Array;

//创建数组 create array
Array array_create(int init_size){
	Array a;
	a.size = init_size;
	a.array = (int*)malloc(sizeof(int)*a.size);
	return a;
}

//数组空间释放回收 free array 
void array_free(Array *a){
	free(a->array);
	a->array = NULL;	//防止重复free相同内存 
	a->size = 0;
}

//返回数组有多少单元可用  
int array_size(const Array *a){
	return a->size;
}

//访问数组某个单元，可以做左值也可以做右值
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
	return &(a->array[index]);	//返回指针方便使用时可以做左值 
}

// 如果不喜欢 *array_at(Array *a,int index)做左值可以进一步封装如下样例 
//int array_get(const Array *a,int index){
//	return a->array[index];
//} 
//
//void array_set(Array *a,int index,int value){
//	a->array[index] = value;
//}

//扩充数组单元 
void array_inflate(Array *a,int more_size){
	int *p = (int*)malloc(sizeof(int)*(a->size + more_size));
	int i;
	//memcpy((void*)p,(void*)a->array,a->size*sizeof(int));  //标准库函数代替下面的for循环效率更高 
	for( i=0;i<a->size;i++){
		p[i] = a->array[i];
	}
	free(a->array);
	a->array = p;
	a->size += more_size;
}
