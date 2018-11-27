#include <stdio.h>
#include <stdlib.h>
#include "array.h"
//测试时编译器名: TDM-GCC 4.8.1 64-bit Release
int main(int argc, char *argv[]) {
	Array a = array_create(100);
	printf("%d\n",array_size(&a));
	*array_at(&a,0) = 10;	//因为返回的是指针再加*号取得变量 
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
