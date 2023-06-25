#include <stdio.h>
int main()
{
	void test(int i);
	test(1);
}

 void test(int i)
{
	void come();
	char buf[8];//用于发生溢出的数组
	unsigned long go=(unsigned long)&come;

	//用come()函数的地址覆盖EIP
	// *((size_t*)(&i-sizeof(size_t)))=go;

	// *( (unsigned long *)(buf+0x18) )=go;
	__asm__("movq %0,8(%%rbp)" : :"r"(go) :);
}
void come()
{
	printf("Success!");
	return;
}
