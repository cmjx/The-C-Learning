#include <stdio.h>
#include <stdlib.h>
#include "array.h"
//����ʱ��������: TDM-GCC 4.8.1 64-bit Release
int main(int argc, char *argv[]) {
	Array a = array_create(100);
	printf("%d\n",array_size(&a));
	*array_at(&a,0) = 10;	//��Ϊ���ص���ָ���ټ�*��ȡ�ñ��� 
	printf("%d\n",*array_at(&a,0));
	int number = 0;
	int cnt = 0;
	while(number != -1){
		scanf("%d",&number);
		if(number != -1){
			*array_at(&a,cnt++) = number;
		}
	}
	array_free(&a);	
	return 0;
}
