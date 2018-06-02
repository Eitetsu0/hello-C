#define swap(t,a,b) {\
    t temp=a;\
    a=b;\
    b=temp;\
}
#define swap2(x,y) {\
	x=x+y;\
	y=x-y;\
	x=x-y;\
}
#define dprint(i) printf("\t"#i"=%d\n",i)
#include <stdio.h>

int main()
{
    int i,j;
    float a,b;
    i=1;
    j=2;
    a=3.0f;
    b=4.0f;
	dprint(i);dprint(j);
	printf("at the begining i=%d,j=%d\n\t\ta=%.1f,b=%.1f\n",i,j,a,b);

    swap(int,i,j);
    swap(float,a,b);
    printf("swap(t,a,b)\n");
    printf("\ti=%d,j=%d\n\ta=%.1f,b=%.1f\n",i,j,a,b);

    swap2(i,j);
    swap2(a,b);
    printf("swap2(x,y);\n");
    printf("\ti=%d,j=%d\n\ta=%.1f,b=%.1f\n",i,j,a,b);
    return 0;
}
