#include <stdio.h>
#include <string.h>

//指针：就是变量,用来存放地址的变量（存放在指针中的值都被当做地址处理）
//如何编址？
//对于32位的机器，假设有32根地址线，那么假设每一根地址线在寻址的是产生一个电信号正电/副电（1/0）
//这是就产生2^32次方个地址，每一个地址标识一个字节。 即一个指针变量的大小为4个字节（32机器）
int main1() {

//    int a = 32;
//    int *p = &a;

    //当前为64位机器
    printf("%d\n", sizeof(char *)); //8
    printf("%d\n", sizeof(short *));//8
    printf("%d\n", sizeof(int *));//8
    printf("%d\n", sizeof(double *));//8

    //指针类型的实际意义
    int a = 0x11223344;
    int *pa = &a;
    char *pc = &a;
    *pa = 0;
    //0000007a5e3ff70c
    //0000007a5e3ff70c 地址相同
    printf("%p\n", pa);
    printf("%p\n", pc);

    //**1**指针类型决定了指针进行解引用操作的时候能够访问空间的大小
    //int* p; *p能够访问4个字节
    //char* p; *p能够访问1个字节
    //double* p; *p能够访问8个字节

    return 0;
}

int main2() {
    int a = 0x11223344;
    int *pa = &a;

    printf("%p\n", pa); //0000007c909ffbcc
    //因为当指针是int类型，pa指向int，跳过一个字符就是跳过4个字节
    printf("%p\n", pa + 1); //0000007c909ffbd0

    char *pc = &a;
    printf("%p\n", pc); //0000007c909ffbcc
    printf("%p\n", pc + 1); //0000007c909ffbcd

    //*2**指针类型决定了：指针走一步走多远(指针的步长)
    //int*p; p+1-->4
    //char*p; p+1-->1
    //double*p; p+1-->8
}

int main3() {
    int arr[10] = {0};

    //int *p = arr; //数组名：首元素的地址

    //错误写法：p指向的是char类型，跳一步只有1个字节，int一步4个字节
    char *p = arr;

    for (int i = 0; i < 10; i++) {
        *(p + i) = 1;
    }

    return 0;


}

int main4() {
    //野指针：指针的指向是不可知的(随机的,不正确的，没有明确标识)

    //  int a; //局部变量不初始化，默认是随机值
    //int *p; //1:局部变量的指针变量，就被初始化为随机值

    int arr[10] = {0};
    int *p = arr;
    for (int i = 0; i < 12; i++) {
        *(p + i) = 1;
        //2:当p++越出自己能够管理时  就回成为野指针
        //当指针指向的范围超过了数组arr的范围时，p就是野指针
        //数组越界到导致的野指针问题
        p++;
    }
    printf("%p\n", *p);
}

int *test() {
    int a = 10;

    return &a;
}

int main5() {
    //3:指针指向的空间释放了
    int *p = test();
    //局部变量：调用时初始化，结束调用时销毁
    printf("%d\n", *p); //当指针回调时，已经被销毁了

    return 0;

}

int main6() {
    int a = 10;

    int *pa = &a; //初始化指针

    //NULL ((void *)0)   将0强类型转换为(void*)
//    int*p = NULL; //当不知道初始化为什么类型的指针时，初始化为null

    pa = NULL; //不用时，置为NULL
//    *pa = 0;
    if (pa != NULL) {

    }


}

/*
 * 如何避免野指针?
 * 1:指针初始化
 * 2:小心指针越界
 * 3:指针指向空间释放时将指针置为NULL
 * 4：指针使用之前检查有效性
 */
int main7() {
    //指针运算：
    //1:指针+-整数
    //2:指针+指针
    //3:指针的关系运算
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = sizeof(arr) / sizeof(arr[0]);


    int *p = &arr; //数组名：首元素地址

    for (int i = 0; i < sz; i++) {
        printf("%d\n", *p);
        p += 2; //指针步长为1
    }


}

#define N_VALUES 5

int main8() {
    float valus[N_VALUES]; // 0 1 2 3 4
    float *vp;
    //数组的地址是递进的 故首元素的地址肯定小于arr[5]的地址
    for (vp = &valus[0]; vp < &valus[N_VALUES];) {
        *vp++ = 0;
    }
}

int main9() {
    //指针+-指针
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20};

    //指针-指针=中间元素的个数
    int p = &arr[9] - &arr[0]; //9

    printf("%d\n", p); //9

}

//使用指针获取数组元素个数
int my_strlen(char *arr) {

    char *start = arr;
    char *end = arr; //指向第一个元素

    while (*end != '\0') {
        end++; //指针向后递进
    }
    //指针-指针：中间的元素个数
    return end - start;
}

int main10() {
    char arr[] = "bit";
    printf("%d", my_strlen(arr));


    char *p1 = arr;
    char *p2 = arr[3]; //数组最后一个元素后面的指针
    //c语言标准规定：允许指向数组元素的指针与指向数组最后一个元素后面的那个内存的指针比较
    //不允许与指向第一个元素的那个内存位置的指针进行比较
}

int main11() {
    int arr[10] = {1, 2, 20};


    //0000003c3f3ff6e0
    //0000003c3f3ff6e0
    printf("%p\n", arr); //绝大部分：arr-首元素地址
    printf("%p\n", arr + 1); //+4个字节

    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[0] + 1);//+4个字节

    printf("%p\n", &arr); //整个数组的地址

    //添加了整个数组的大小
    printf("%p\n", &arr + 1);

    //1:&arr-  &数组名：数组名不是首元素的地址-数组名表示整个数组的地址
    //2:sizeof(arr)- sizeof(数组名); 数组名表示整个数组; sizeof(数组名)计算的是整个数组的大小




    int i = 0;
    int *p = &arr;
    for (i = 0; i < 10; i++) {
        //指针可以访问数组
//        printf("%p ============== %p \n",p+i,&arr[i]);
        *(p + i) = i;
//        printf("%d\n",arr[i]); //两种方式进行访问
        printf("%d\n", *(p + i));
    }


}

int main12() {


    int a = 10;
    int *pa = &a; //一级指针
    int **ppa = &pa; //ppa就是二级指针


    printf("%d\n", *pa); //10
    //*ppa找上一级指针
    printf("%d\n", *ppa); //-1210058748
    printf("%d\n", **ppa); //10


    printf("\n");
    //指针数组： 数组-存放指针的数组
    //数组指针： 指针-
//    int a =10;
    int b = 20;
    int c = 30;


    //指针数组
    int *arr[3] = {&a, &b, &c};
    int i = 0;
    for (i = 0; i < 3; i++) {
        printf("%d\n", *(arr[i]));
    }
}

int i; //全局变量-不初始化 默认0
int main13() {
    i--; // -1
    //sizeof() 计算变量/类型所占空间的大小， 》= 0的无符号数
    //当整数与无符号数进行比较时，会将整数转换为无符号数，-1的无符号数非常大
    if (i > sizeof(i)) {
        printf(">");
    } else {
        printf("<");
    }
    return 0;

}

int main14() {
    int a, b, c;
    a = 5;
    c = ++a; //a = 6;   c = 6
    //c=7  a = 7
    b = ++c, c++, ++a, a++;  // b = 7 逗号表达式最后一个表达式结果
    //c = 8  a = 8;
    // 7+= 8+8   b =23
    b += a++ + c;
    //a = 9
    printf("a=%d\n", a); // a=9
    printf("b=%d\n", b); // b =23
    printf("c=%d\n", c); // c = 8
}

/*

  while  (r = m % n)
    {
//      r = m % n; //记录r的值
        m = n;
        n = r;  //不能 m%n   因为m的值已近被付给n
    }
    printf("%d\n",n);

 //求最大公倍数 欧几里得算法
   static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

}*/
//求二进制(补码)中1的个数
int count_bit_one(int num) {
//    int count= 0;
//    while (num)
//    {
//        if(num%2==1)
//        {
//            count++;
//        }
//        num= num/2;
//    }
//    return count;

    //第二种方法:一个数&1
    //0000000000000000000000001101   -13
    //0000000000000000000000000001  两个数按位与&
    //0000000000000000000000000001
//    int i = 0;
//    int count= 0;
//    for(i = 0; i< 32; i++)
//    {
//        if(((num>>i)&1) ==1 )
//        {
//            count++;
//        }
//    }

    //第三种：
    // n 13 -1101
    //1100 n-1
    //n = n&(n-1) = 1100   最低位消失
    //1100 n
    //1011 n-1&
    //1000 n
    //0111 n-1 &
    int count = 0;
    while (num) {
        num = num & (num - 1);
        //0000 执行几次 扣除几个1
        count++;
    }
    return count;
}

//求两个int数有多少位不同
int count_bit_differ(int n, int m) {
    //异或 相异则为1  计算有多少个1 就能计算有多少个不同
    int target = n ^ m;
    //数target中有多少个1
    int i = 0;
    int count = 0;
    while (target) {
        target = target & (target - 1);
        count++;
    }

    return count;

}

int main15() {
    //统计二进制中1的个数(求得补码)
//    int num = 0;
//    scanf_s("%d",&num);
//    int count = count_bit_one(num);


    int count = count_bit_differ(1999, 2299);

    printf("%d\n", count);

}

//获取一个整数中所有的奇数位和偶数位,分别打印
void print(int num) {
    int i = 0;
    printf("奇数位>");
    //0*00000  *移动30位到达最低位
    for (i = 30; i >= 0; i -= 2) {
        //两个二进制数 按位与 得到当前位
        printf("%d", (num >> i) & 1);
    }

    printf("\n");
    printf("偶数位>");
    int j = 0;
    for (j = 31; j >= 1; j -= 2) {
        printf("%d", (num >> i) & 1);
    }
}

int main16() {
    int num = 0;

//    scanf("%d", &num);
//    print(num);

    //交换两个变量 不允许创建临时变量
    int a = 5; //101
    int b = 3; //011
    a = a ^ b; // a = 110  b=011
    b = a ^ b; // b = 101 a = 110
    a = a ^ b; // a = 011  b =101

    printf("%d   %d", a, b);

}

void print_arr(int *p, int sz) {
    int i = 0;
    for (i = 0; i < sz; i++) {
        printf("%d ", *(p + i));
    }

}

//翻转数组
/*void reverse_str(char* str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}*/
void reverse_str(char *str) {

    char temp = str[0];
    int len = my_strlen(str)-1;
    str[0] = str[len];
    str[len]  ='\0';
    if(my_strlen(str+1) >= 2)
    {

        reverse_str(str+1);
    }
    str[len] = temp;
}
//对每一位进行累加
//digsum(1729)
//digsum(172) + 1729%10
//digsum(17) + 172%10 +  1729%10
int digsum(unsigned int num)
{
    if(num>9)
    return digsum((num/10))+(num%10);
    else
    return num;
}
//实现n的k次方 k个n相乘
// 2 3 --2*2^k-1
//n^k n*n^k-1
double pow(int n,int k){

    if(k < 0)
    {
        return (1.0/pow(n,-k));
    }else if(k <= 0)
    {
        return 1;
    }else
    {

        return n*pow(n,k-1);
    }
}


int main() {
//    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    print_arr(arr, sz);

//    char str[] = "abcdef";
//    reverse_str(str);
//    printf("%s",str);
//    printf("%d", digsum(1729));
    printf("%lf", pow(2, -4));
    return 0;


}