/*
 * reverse Polish calculator 2
 */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

#include <string.h>
#include <math.h>

void push(double);
double pop(void);
void prtop(void);
void exch(void);
void cls(void);

/* reverse Polish calculator */
int main()
{
	double op2;
	char s[MAXOP];
	int i;

	while(1) {
		if(scanf("%d",&i)==1)
			push(i);
		else if(scanf("%s",s)==1){
			switch(s[0]){
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if(op2 != 0)
					push((int)pop() % (int)op2);
				else
					printf("error: zero divisor\n");
				break;
			/*case '\n':
				prtop();
				break;*/
			case 'q':
				return 0;
			default:
				if(!strncmp(s,"sin",3))
					push(sin(pop()));
				else if(!strncmp(s,"cos",3))
					push(cos(pop()));
				else if(!strncmp(s,"tan",3))
					push(tan(pop()));
				else if(!strncmp(s,"pow",3)){
					op2=pop();
					push(pow(pop(),op2));
				}else if(!strncmp(s,"exp",3))
					push(exp(pop()));
				else if(!strncmp(s,"cls",3))
					cls();
				else{
					prtop();
					fprintf(stderr,"error: unknown command %s\n", s);
				}
				break;
			}
		}else{
			prtop();
			break;
		}
	}
	return 0;
}

//stack***********************************************************************
#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0;
/* next free stack position */
double val[MAXVAL]; /* value stack */
/* push: push f onto value stack */

void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}
//prtop:print top value from stack
void prtop(void)
{
	if(sp>0)
		printf("\t %.8g\n",val[sp-1]);
	else
		printf("error: stack empty\n");
}
//exch:exchange two values from the top of stack
void exch(void)
{
	if(sp>1){
		double temp;
		temp = val[sp-2];
		val[sp-2] = val[sp-1];
		val[sp-1] = temp;
	}
	else
		printf("error:only 1 number in stack\n");
}
//cls:clean up stack
void cls(void)
{
	sp=0;
	push(0);
}
