#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct nwordl{
	int line;
	struct nwordl *next;
};
struct tnode {
	char *word;
	int count;
	struct nwordl *lines;
	struct tnode *left;
	struct tnode *right;
};

int getword(char *word,int max);
struct tnode *addtree(char *word,struct tnode *n,int line);
void tprint(struct tnode *t);

int main(int argc,char *argv[])
{
	char word[MAXWORD];
	struct tnode *wordtree=NULL;
	int line=1;char c=0;

	while((c=getword(word,MAXWORD))!=EOF){
		if(isalpha(word[0]))
			wordtree=addtree(word,wordtree,line);
		else if(c=='\n')
			line++;
	}
	tprint(wordtree);
	return 0;
}
//getword:get next word or character from input*****************************
int getword(char *word,int lim)
{
	int c,getch(void);
	void ungetch(int);

	while(isspace(c=getch()))
		if(c=='\n')
			break;
	if(c!=EOF)
		*word++=c;
	if(!isalpha(c)){
		*word='\0';
	}else{
		while(lim-->0 && isalnum(*word++=getch()))//lim-- or --lim  ??
			;
		if(lim>0){
			ungetch(*--word);
			*word='\0';
		}
	}
	return c;
}
//buffer*******************************
#define BUFSIZE 100

static char buf[BUFSIZE];// buffer for ungetch
static char *bufp = buf;// next free position in buf

int getch(void) // get a (possibly pushed-back) character
{
	return (bufp > buf) ? *--bufp : getchar();
}
void ungetch(int c) // push character back on input
{
	if (bufp-buf >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		*bufp++ = c;
}
//*************************************************************************
//tprint:print a tree of tnode
void tprint(struct tnode *t)
{
	void lprint(const struct nwordl *w);
	if(t->left!=NULL)
		tprint(t->left);
	printf("%4d %10s   ",t->count,t->word);
	lprint(t->lines);
	printf("\n");
	if(t->right!=NULL)
		tprint(t->right);
}
//lprint:print a list of lines
void lprint(const struct nwordl *w)
{
	for(;w!=NULL;w=w->next)
		printf("%3d ",w->line);
}
//addtree:add a tree of tnode ,at or below *n
struct tnode *addtree(char *word,struct tnode *n,int line)
{
	char *strdup(char *s);
	struct nwordl *addline(struct nwordl *lines,int n);
	int cond;

	if(n==NULL){ //a new word has arrived
		n=(struct tnode *) malloc(sizeof(struct tnode));
		n->word=strdup(word);
		n->count=1;
		n->lines=addline(n->lines,line);
		n->left = n->right = NULL;
		n->lines->next = NULL;
	}else if(!(cond=strcmp(n->word,word))){
		n->count++;
		n->lines=addline(n->lines,line);
	}else if(cond>0)
		n->left=addtree(word,n->left,line);
	else
		n->right=addtree(word,n->right,line);
	return n;
}
//addline:add a node of nwordl
struct nwordl *addline(struct nwordl *l,int n)
{
	if(l==NULL){
		l=(struct nwordl *)malloc(sizeof(struct nwordl));
		l->line=n;
		l->next=NULL;
	}else
		l->next=addline(l->next,n);
	return l;
}


/* make a duplicate of s */
char *strdup(char *s)
{
	char *p;
	p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
	if (p != NULL)
		strcpy(p, s);
	return p;
}
