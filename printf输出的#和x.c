/* printf 格式控制符#和x */
#include <stdio.h>
int main(void)
{
    int i = 47;
    printf("%x\n", i);   
    printf("%X\n", i);   
    printf("%#x\n", i);   
    printf("%#X\n", i);   
    return 0;
}
