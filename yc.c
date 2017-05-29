#include <stdio.h>
main()
{
  void test(int i);
  test(1);
}

void test(int i)
{
  void come();
  char buf[12];//用于发生溢出的数组
  int addr[4];
  int k=(int)&i-(int)buf;//计算参数到溢出数组之间的距离
  int go=(int)&come;
  //由于EIP地址是倒着表示的，所以首先把come()函数的地址分离成字节
  addr[0]=(go << 24)>>24;
  addr[1]=(go << 16)>>24;
  addr[2]=(go << 8)>>24;
  addr[3]=go>>24;
  //用come()函数的地址覆盖EIP
  int j;
   for(j=0;j<4;j++)
   {
    buf[k-j-1]=addr[3-j];
   }
}
void come()
{
 printf("Success!");
}
