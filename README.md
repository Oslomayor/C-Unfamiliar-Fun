# C-Unfamiliar-Fun
C 语言冷僻知识记录  

### 1. 美元符号
C 语言允许 $ 作为变量名  
```C
#include <stdio.h>
int main()
{
    int $;
    $ = 1111;
    printf("%d\n",$);
    system("pause");
    return 0;
}
```
![](https://github.com/Oslomayor/Markdown-Imglib/blob/master/Imgs/%E7%BE%8E%E5%85%83%E7%AC%A6%E5%8F%B7%E4%BD%9C%E5%8F%98%E9%87%8F%E5%90%8D.png?raw=true)  

### 2. 字节对齐
C 语言面试的考点，考到一大波人   
```C
#include <stdio.h>

//自定义字节对齐预编译指令
//以参数n对齐，缺省按照系统默认
//#pragma pack(n)

// size = 8
struct man
{
	char hisCountry;
    char hisWife;
    // 填充2个空字节,无论是否定义，结构体的size相同
    // char reserved[2];
    int earnMoney;
};

// size = 12
struct B
{
		char a;
        // 填充3个空字节,无论是否定义，结构体的size相同
        // char reserved1[3];
        
        int b;
        
        short c;
        // 填充2个空字节,无论是否定义，结构体的size相同
        // char reserved2[2];
};

int main()
{
	long long size_longlong;
	double size_double;
    float size_float;
	int size_int;
    short size_short;
    char size_char;
    
    printf("sizeof info:\n");
    printf("size_longlong = %d\n",sizeof(size_longlong));
    printf("size_double = %d\n",sizeof(size_double));
    printf("size_float = %d\n",sizeof(size_float));
    printf("size_int = %d\n",sizeof(size_int));
    printf("size_short = %d\n",sizeof(size_short));
    printf("size_char = %d\n",sizeof(size_char));
    
    printf("\n");
    
    struct man man1;
    printf("size_man1 = %d\n",sizeof(man1));
    printf("hisCountry addr = %d\n",&man1.hisCountry);
    printf("hisWife addr = %d\n",&man1.hisWife);
    printf("earnMoney addr = %d\n",&man1.earnMoney);
    
    printf("\n");
    
    struct B testB;
    printf("size_testB = %d\n",sizeof(testB));
    printf("testB.a addr = %d\n",&testB.a);
    printf("testB.b addr = %d\n",&testB.b);
    printf("testB.c addr = %d\n",&testB.c);
    
	system("pause");
	return 0;
}
```
