#include <stdio.h>
#include <string.h>

//ָ�룺���Ǳ���,������ŵ�ַ�ı����������ָ���е�ֵ����������ַ����
//��α�ַ��
//����32λ�Ļ�����������32����ַ�ߣ���ô����ÿһ����ַ����Ѱַ���ǲ���һ�����ź�����/���磨1/0��
//���ǾͲ���2^32�η�����ַ��ÿһ����ַ��ʶһ���ֽڡ� ��һ��ָ������Ĵ�СΪ4���ֽڣ�32������
int main1() {

//    int a = 32;
//    int *p = &a;

    //��ǰΪ64λ����
    printf("%d\n", sizeof(char *)); //8
    printf("%d\n", sizeof(short *));//8
    printf("%d\n", sizeof(int *));//8
    printf("%d\n", sizeof(double *));//8

    //ָ�����͵�ʵ������
    int a = 0x11223344;
    int *pa = &a;
    char *pc = &a;
    *pa = 0;
    //0000007a5e3ff70c
    //0000007a5e3ff70c ��ַ��ͬ
    printf("%p\n", pa);
    printf("%p\n", pc);

    //**1**ָ�����;�����ָ����н����ò�����ʱ���ܹ����ʿռ�Ĵ�С
    //int* p; *p�ܹ�����4���ֽ�
    //char* p; *p�ܹ�����1���ֽ�
    //double* p; *p�ܹ�����8���ֽ�

    return 0;
}

int main2() {
    int a = 0x11223344;
    int *pa = &a;

    printf("%p\n", pa); //0000007c909ffbcc
    //��Ϊ��ָ����int���ͣ�paָ��int������һ���ַ���������4���ֽ�
    printf("%p\n", pa + 1); //0000007c909ffbd0

    char *pc = &a;
    printf("%p\n", pc); //0000007c909ffbcc
    printf("%p\n", pc + 1); //0000007c909ffbcd

    //*2**ָ�����;����ˣ�ָ����һ���߶�Զ(ָ��Ĳ���)
    //int*p; p+1-->4
    //char*p; p+1-->1
    //double*p; p+1-->8
}

int main3() {
    int arr[10] = {0};

    //int *p = arr; //����������Ԫ�صĵ�ַ

    //����д����pָ�����char���ͣ���һ��ֻ��1���ֽڣ�intһ��4���ֽ�
    char *p = arr;

    for (int i = 0; i < 10; i++) {
        *(p + i) = 1;
    }

    return 0;


}

int main4() {
    //Ұָ�룺ָ���ָ���ǲ���֪��(�����,����ȷ�ģ�û����ȷ��ʶ)

    //  int a; //�ֲ���������ʼ����Ĭ�������ֵ
    //int *p; //1:�ֲ�������ָ��������ͱ���ʼ��Ϊ���ֵ

    int arr[10] = {0};
    int *p = arr;
    for (int i = 0; i < 12; i++) {
        *(p + i) = 1;
        //2:��p++Խ���Լ��ܹ�����ʱ  �ͻس�ΪҰָ��
        //��ָ��ָ��ķ�Χ����������arr�ķ�Χʱ��p����Ұָ��
        //����Խ�絽���µ�Ұָ������
        p++;
    }
    printf("%p\n", *p);
}

int *test() {
    int a = 10;

    return &a;
}

int main5() {
    //3:ָ��ָ��Ŀռ��ͷ���
    int *p = test();
    //�ֲ�����������ʱ��ʼ������������ʱ����
    printf("%d\n", *p); //��ָ��ص�ʱ���Ѿ���������

    return 0;

}

int main6() {
    int a = 10;

    int *pa = &a; //��ʼ��ָ��

    //NULL ((void *)0)   ��0ǿ����ת��Ϊ(void*)
//    int*p = NULL; //����֪����ʼ��Ϊʲô���͵�ָ��ʱ����ʼ��Ϊnull

    pa = NULL; //����ʱ����ΪNULL
//    *pa = 0;
    if (pa != NULL) {

    }


}

/*
 * ��α���Ұָ��?
 * 1:ָ���ʼ��
 * 2:С��ָ��Խ��
 * 3:ָ��ָ��ռ��ͷ�ʱ��ָ����ΪNULL
 * 4��ָ��ʹ��֮ǰ�����Ч��
 */
int main7() {
    //ָ�����㣺
    //1:ָ��+-����
    //2:ָ��+ָ��
    //3:ָ��Ĺ�ϵ����
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = sizeof(arr) / sizeof(arr[0]);


    int *p = &arr; //����������Ԫ�ص�ַ

    for (int i = 0; i < sz; i++) {
        printf("%d\n", *p);
        p += 2; //ָ�벽��Ϊ1
    }


}

#define N_VALUES 5

int main8() {
    float valus[N_VALUES]; // 0 1 2 3 4
    float *vp;
    //����ĵ�ַ�ǵݽ��� ����Ԫ�صĵ�ַ�϶�С��arr[5]�ĵ�ַ
    for (vp = &valus[0]; vp < &valus[N_VALUES];) {
        *vp++ = 0;
    }
}

int main9() {
    //ָ��+-ָ��
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 20};

    //ָ��-ָ��=�м�Ԫ�صĸ���
    int p = &arr[9] - &arr[0]; //9

    printf("%d\n", p); //9

}

//ʹ��ָ���ȡ����Ԫ�ظ���
int my_strlen(char *arr) {

    char *start = arr;
    char *end = arr; //ָ���һ��Ԫ��

    while (*end != '\0') {
        end++; //ָ�����ݽ�
    }
    //ָ��-ָ�룺�м��Ԫ�ظ���
    return end - start;
}

int main10() {
    char arr[] = "bit";
    printf("%d", my_strlen(arr));


    char *p1 = arr;
    char *p2 = arr[3]; //�������һ��Ԫ�غ����ָ��
    //c���Ա�׼�涨������ָ������Ԫ�ص�ָ����ָ���������һ��Ԫ�غ�����Ǹ��ڴ��ָ��Ƚ�
    //��������ָ���һ��Ԫ�ص��Ǹ��ڴ�λ�õ�ָ����бȽ�
}

int main11() {
    int arr[10] = {1, 2, 20};


    //0000003c3f3ff6e0
    //0000003c3f3ff6e0
    printf("%p\n", arr); //���󲿷֣�arr-��Ԫ�ص�ַ
    printf("%p\n", arr + 1); //+4���ֽ�

    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[0] + 1);//+4���ֽ�

    printf("%p\n", &arr); //��������ĵ�ַ

    //�������������Ĵ�С
    printf("%p\n", &arr + 1);

    //1:&arr-  &��������������������Ԫ�صĵ�ַ-��������ʾ��������ĵ�ַ
    //2:sizeof(arr)- sizeof(������); ��������ʾ��������; sizeof(������)���������������Ĵ�С




    int i = 0;
    int *p = &arr;
    for (i = 0; i < 10; i++) {
        //ָ����Է�������
//        printf("%p ============== %p \n",p+i,&arr[i]);
        *(p + i) = i;
//        printf("%d\n",arr[i]); //���ַ�ʽ���з���
        printf("%d\n", *(p + i));
    }


}

int main12() {


    int a = 10;
    int *pa = &a; //һ��ָ��
    int **ppa = &pa; //ppa���Ƕ���ָ��


    printf("%d\n", *pa); //10
    //*ppa����һ��ָ��
    printf("%d\n", *ppa); //-1210058748
    printf("%d\n", **ppa); //10


    printf("\n");
    //ָ�����飺 ����-���ָ�������
    //����ָ�룺 ָ��-
//    int a =10;
    int b = 20;
    int c = 30;


    //ָ������
    int *arr[3] = {&a, &b, &c};
    int i = 0;
    for (i = 0; i < 3; i++) {
        printf("%d\n", *(arr[i]));
    }
}

int i; //ȫ�ֱ���-����ʼ�� Ĭ��0
int main13() {
    i--; // -1
    //sizeof() �������/������ռ�ռ�Ĵ�С�� ��= 0���޷�����
    //���������޷��������бȽ�ʱ���Ὣ����ת��Ϊ�޷�������-1���޷������ǳ���
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
    b = ++c, c++, ++a, a++;  // b = 7 ���ű��ʽ���һ�����ʽ���
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
//      r = m % n; //��¼r��ֵ
        m = n;
        n = r;  //���� m%n   ��Ϊm��ֵ�ѽ�������n
    }
    printf("%d\n",n);

 //����󹫱��� ŷ������㷨
   static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

}*/
//�������(����)��1�ĸ���
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

    //�ڶ��ַ���:һ����&1
    //0000000000000000000000001101   -13
    //0000000000000000000000000001  ��������λ��&
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

    //�����֣�
    // n 13 -1101
    //1100 n-1
    //n = n&(n-1) = 1100   ���λ��ʧ
    //1100 n
    //1011 n-1&
    //1000 n
    //0111 n-1 &
    int count = 0;
    while (num) {
        num = num & (num - 1);
        //0000 ִ�м��� �۳�����1
        count++;
    }
    return count;
}

//������int���ж���λ��ͬ
int count_bit_differ(int n, int m) {
    //��� ������Ϊ1  �����ж��ٸ�1 ���ܼ����ж��ٸ���ͬ
    int target = n ^ m;
    //��target���ж��ٸ�1
    int i = 0;
    int count = 0;
    while (target) {
        target = target & (target - 1);
        count++;
    }

    return count;

}

int main15() {
    //ͳ�ƶ�������1�ĸ���(��ò���)
//    int num = 0;
//    scanf_s("%d",&num);
//    int count = count_bit_one(num);


    int count = count_bit_differ(1999, 2299);

    printf("%d\n", count);

}

//��ȡһ�����������е�����λ��ż��λ,�ֱ��ӡ
void print(int num) {
    int i = 0;
    printf("����λ>");
    //0*00000  *�ƶ�30λ�������λ
    for (i = 30; i >= 0; i -= 2) {
        //������������ ��λ�� �õ���ǰλ
        printf("%d", (num >> i) & 1);
    }

    printf("\n");
    printf("ż��λ>");
    int j = 0;
    for (j = 31; j >= 1; j -= 2) {
        printf("%d", (num >> i) & 1);
    }
}

int main16() {
    int num = 0;

//    scanf("%d", &num);
//    print(num);

    //������������ ����������ʱ����
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

//��ת����
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
//��ÿһλ�����ۼ�
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
//ʵ��n��k�η� k��n���
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