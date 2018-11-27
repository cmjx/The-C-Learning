#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct {
	int *array;
	int size;
} Array;

Array array_create(int init_size);	//�������� 
void array_free(Array *a);	//����ռ��ͷŻ��� 
int array_size(const Array *a);	//���������ж��ٵ�Ԫ���� 
int* array_at(Array *a,int index);	//��������ĳ����Ԫ����������ֵҲ��������ֵ 
void array_inflate(Array *a,int more_size);	//�������鵥Ԫ 

#endif
