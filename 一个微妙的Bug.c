/*
一个微妙的Bug
if语句在 signed int 和 unsigned int 之间测试相等性，
signed int 会被升级为 unsigned int 类型，
-1 转换成为 unsigned int 的结果是一个非常巨大的正整数，
这将导致 if 语句的判断结果为假。这个 Bug 在 ANSI C 中存在
*/

#include <stdio.h>
int array[] = {23,34,12,17,204,99,16};
#define ARRAY_SIZE (sizeof(array)/sizeof(array[0]))

int main()
{
    int d = -1; 
    printf("d = %d\n",d);
    printf("array_size = %d\n",ARRAY_SIZE);
    if(d <= ARRAY_SIZE)
        printf("d <= array_size\n");
    else
        printf("d > array_size\n");
    while(1);
    return 0;
}
