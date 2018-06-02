#include <stdio.h>
#include <string.h>
#define MAXLINES 5000/* max #lines to be sorted */
#define MAXCHARS 10000

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[],char *v, int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);/* sort input lines */

int main()
{
	char v[MAXCHARS];
	int nlines;/* number of input lines read */
	if ((nlines = readlines(lineptr,v, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort\n");
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
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	if (left >= right) /* do nothing if array contains */
		return;
	/* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}
/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
