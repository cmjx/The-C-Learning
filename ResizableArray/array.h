#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct {
	int *array;
	int size;
} Array;

Array array_create(int init_size);	//创建数组 
void array_free(Array *a);	//数组空间释放回收 
int array_size(const Array *a);	//返回数组有多少单元可用 
int* array_at(Array *a,int index);	//访问数组某个单元，可以做左值也可以做右值 
void array_inflate(Array *a,int more_size);	//扩充数组单元 

#endif
