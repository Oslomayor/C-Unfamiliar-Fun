#include <stdio.h>

//�Զ����ֽڶ���Ԥ����ָ��
//�Բ���n���룬ȱʡ����ϵͳĬ��
//#pragma pack(n)

// size = 8
struct man
{
	char hisCountry;
    char hisWife;
    // ���2�����ֽ�,�����Ƿ��壬�ṹ���size��ͬ
    // char reserved[2];
    int earnMoney;
};

// size = 12
struct B
{
		char a;
        // ���3�����ֽ�,�����Ƿ��壬�ṹ���size��ͬ
        // char reserved1[3];
        
        int b;
        
        short c;
        // ���2�����ֽ�,�����Ƿ��壬�ṹ���size��ͬ
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
