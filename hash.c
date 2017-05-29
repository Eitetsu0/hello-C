#include <stdlib.h>
#include <string.h>
struct nlist {/* table entry: */
	struct nlist *next; /* next entry in chain */
	char *name;/* defined name */
	char *defn;/* replacement text */
};

int main()
{
	return 0;
}

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* pointer table */
//hash: form hash value for string s
unsigned int hash(char *s)
{
	unsigned hashval;

	for(hashval=0;*s!='\0';s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}
/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;

	for(np=hashtab[hash(s)];np!=NULL;np=np->next)
		if(strcmp(np->name,s)==0)
			return np;//found
	return NULL;//not found
}

char *strdup(char *);
/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned int hashval;

	if((np=lookup(name))==NULL){//not found
		np=(struct nlist *)malloc(sizeof(*np));
		if(np==NULL || (np->name = strdup(name)) == NULL)
			return NULL;//error:
		np->next=hashtab[(hashval=hash(name))];
		hashtab[hashval]=np;
	}else //already there
		free((void *)np->defn);
	if((np->next->defn=strdup(defn))==NULL)
		return NULL;//error:
	return np;
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

//undef:delete a node form hashtab[] list
void undef(char *name)
{
	struct nlist *np,*temp;
	unsigned int hashval;

	if((np=lookup(name))==NULL)
		return;//the define do not exist
	if(hashtab[hashval=hash(name)]==np)
		hashtab[hashval]=np->next;
	else{
		for(temp=hashtab[hashval];np->next!=np;temp=temp->next)
			;
		temp=np->next;
	}
	free((void *)np->name);
	free((void *)np->defn);
	free((void *)np);
}
