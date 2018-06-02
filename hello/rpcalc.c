/*
 * reverse Polish calculator
 */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

#include <math.h>
#define SIN '1'
#define COS '2'
#define TAN '3'
#define EXP '4'
#define POW '5'
#define CLS '6'

int getop(char []);
void push(double);
double pop(void);
void prtop(void);
void exch(void);
void cls(void);

/* reverse Polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];
	while((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				exch();//op2 = pop();
				push(pop() - pop());
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
			case SIN:
				push(sin(pop()));
				break;
			case COS:
				push(cos(pop()));
				break;
			case TAN:
				push(tan(pop()));
				break;
			case EXP:
				push(exp(pop()));
				break;
			case POW:
				op2=pop();
				push(pow(pop(),op2));
				break;
			case '\n':
				prtop();
				break;
			case CLS:
				cls();
				break;
			case 'q':
				return 0;
			default:
				printf("error: unknown command %s\n", s);
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

//getop*************************************************************************
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand and return type*/
int getop(char s[])
{
	int i, c;
	int d,e;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(c == 's' || c == 'c' || c == 't' || c =='e' || c=='p'){
	d=getch();
	e=getch();
	switch(c){
	case 's':
		if(d=='i' && e=='n')
			return SIN;
	case 'c':
		if(d=='o' && e =='s')
			return COS;
		if(d=='l' && e=='s')
			return CLS;
	case 't':
		if(d=='a' &&e=='n')
			return TAN;
	case 'e':
		if(d=='x' && e=='p')
			return EXP;
	case 'p':
		if(d=='o' && e=='w')
			return POW;
	}
	ungetch(d);ungetch(e);
	}
	if (!isdigit(c) && c != '.')
		return c;/* not a number */
	i = 0;
	if (isdigit(c))
		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

//buffer***********************************************************************
#define BUFSIZE 100

static char buf[BUFSIZE];/* buffer for ungetch */
static int bufp = 0;/* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
void ungets(int s[])
{
	int i=-1;
	while(s[++i]!='\0')
		;
	while(--i>=0)
		ungetch(s[i]);
}
