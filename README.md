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
C 语言面试的考点，考倒一大波人   

有这么两个结构体：  

> ```C
> struct man
> {
>     char hisCountry;
>     char hisWife;
>     int earnMoney;
> };
> ```
>
> ```C
> struct B
> {
>     char a;
>     int b;
>     short c;
> };
> ```

已知 sizeof(char) =1,  sizeof(short)=2, sizeof(int)=4, 请问这两个结构体占用的空间大小是多少字节？

答案分别是8和12，请看下图，一目了然

![](https://github.com/Oslomayor/Markdown-Imglib/blob/master/Imgs/%E5%AD%97%E8%8A%82%E5%AF%B9%E9%BD%90.png?raw=true)



假如之前没有了解字节对齐，是不是有点意外？可以跑一下代码验证并加深印象

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

### 3. 宏定义陷阱

C 语言中使用带参数的宏定义时，不加留意，代码会出现风险  

看一段代码：  

```c
#include <stdio.h>
#define square(x) x*x
int main()
{
   printf("%d\n",square(3));
   return 0;
}
```

貌似没有什么问题，运行结果是9，也没有问题  

但是这个宏定义有潜在的风险，比如用 square(2+1) 调用该宏定义时，square(2+1) 被宏替换为 2+1*2+1，运行结果等于5，完全错误。因此，带参数的宏定义的安全写法是给参数加上括号。  

改写为安全写法：  

```c
#define square(x) (x)*(x)
```

### 4.printf 输出格式符
我们一般都知道输出16进制数可以采用 printf 格式控制符 %x, 其实还有 %#x 这种格式控制符，它们的输出有所区别  
运行以下代码观察到结果  
```c
# include <stdio.h>
int main(void)
{
    int i = 33;
    printf("%x\n", i);   
    printf("%X\n", i);   
    printf("%#x\n", i);   
    printf("%#X\n", i);   
    return 0;
}  
```
![](https://github.com/Oslomayor/Markdown-Imglib/blob/master/Imgs/printf%E8%BE%93%E5%87%BA%E7%9A%84%23%E5%92%8Cx.png?raw=true)
