#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLINES 5000/* max #lines to be sorted */
#define MAXCHARS 10000

char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[],char v[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right,
		   int (*comp)(void *, void *));
void rqsort(void *v[], int left, int right,int (*comp)(void *, void *));
int numcmp(char *, char *);
int rnumcmp(char *, char *);
int strcasecmp(char *s1,char *s2);

/* sort input lines */
int main(int argc, char *argv[])
{
	char *pname=argv[0];
	char v[MAXCHARS];//array to store text lines
	int nlines;/* number of input lines read */
	void (*sort)(void *v[], int left, int right,int (*comp)(void *, void *)) = qsort;//pointer to sort function
	int (*cmp)(void*,void*) = (int (*)(void*,void*))strcmp;//pointer to cmp function
	char c;
	while (--argc > 0 && (*++argv)[0] == '-')
		while ((c = *++argv[0])!='\0')
			switch (c) {
			case 'n':
				//numeric = 1;
				cmp=(int (*)(void*,void*))numcmp;
				break;
			case 'r':
				//reverse = 1;
				sort=rqsort;
				break;
			case 'f':
				cmp=(int (*)(void*,void*))strcasecmp;
				break;
/*			case 'd':
				break;*/
			case 'h':
				printf("Usage:%s [options]\n"
						"options:\n"
							"\t-n  numeric sort\n"
							"\t-r  reverse\n"
							"\t-f  ignore case\n"
							//"\t-d  makes comparisons only on letters, numbers and blanks. "
							,pname);
				return 0;
				break;
			default:
				printf("error: illegal option %c\n"
						"Usage:sortlines [options]\n"
						"use \"-h\" for details\n"
							, c);
				return 0;
				break;
			}
	if ((nlines = readlines(lineptr,v, MAXLINES)) >= 0) {
		sort((void**) lineptr, 0, nlines-1, cmp);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
}
#define MAXLEN 1000 /* max length of any input line */
int getline(char *, int);
/* readlines: read input lines *///changed
int readlines(char *lineptr[],char *v,int maxlines)
{
	int len, nlines,nchars = 0;
	//char *p, line[MAXLEN];
	nlines = 0;
	while ((len = getline(v, MAXLEN)) > 0)
		if (nlines >= maxlines || nchars+len >= MAXCHARS)
			return -1;
		else {
			*((v+=len)-1) = '\0'; /* delete newline */
			nchars+=len;
			//strcpy(p, line);
			lineptr[nlines++] = v-len;
		}
	return nlines;
}
//getline:get line into s return length
int getline(char s[],int lim)
{
	int c,i;

	i=0;
	while(--lim>0 && (c=getchar())!=EOF && c!='\n')
		s[i++]=c;
	if(c=='\n') s[i++]=c;
	s[i]='\0';
	return i;
}


/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}
/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right,
		   int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);
	if (left >= right)/* do nothing if array contains */
		return;       /* fewer than two elements */
	//swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last+1, right, comp);
}
// rqsort: sort v[left]...v[right] into decreasing order
void rqsort(void *v[], int left, int right,int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);
	if (left >= right)/* do nothing if array contains */
		return;       /* fewer than two elements */
	//swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) > 0)
			swap(v, ++last, i);
	swap(v, left, last);
	rqsort(v, left, last-1, comp);
	rqsort(v, last+1, right, comp);
}

//#include <stdlib.h>
/* Convert a string to a floating-point number.  */
extern double atof (__const char *__nptr)
	 __THROW __attribute_pure__ __nonnull ((1)) __wur;

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}
void swap(void *v[], int i, int j)
{
	void *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
int strcasecmp(char *s1,char *s2)
{
	while(tolower(*s1++)==tolower(*s2++))
		if(!*(s1-1))
			return 0;
	return (int)(*--s1 - *--s2);
}
