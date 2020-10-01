#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct stack {
	int elem[MAX];
	int top;
};

void init(struct stack *stk) {
	stk->top = 0;
}

void push(struct stack *stk, int f) {
	
	if(stk->top < MAX) {
		stk->elem[stk->top] = f;
		stk->top++;
	} 
	else
		printf("error\n", stk->top);
    
}

int pop(struct stack *stk) {
	int elem;
  
	if((stk->top) > 0)
  {
		stk->top--;
    
		elem = stk->elem[stk->top];
    
		return elem;
	}
	else
	{
  	
   		printf("pustoi!\n");
    
		return 0;
	}
}

int isempty(struct stack *stk) {
	
	if(stk->top == 0)    
	return 1;
  
	else 
	return 0;
  
}

void stkPrint(struct stack *stk) {
	int i;
  
	i=stk->top; // i - êîëè÷åñòâî ýëåìåíòîâ â ñòåêå
  
	if(isempty(stk) == 1) return; // ñòåê ïóñò
  
	do {
  	
		i--;
		printf("\n%d\n", stk->elem[i]);
    
	} while(i>0);
}

int main(void) {
	struct stack *stk;
	int i,n,v;
	int elem;
  
	stk = (struct stack*)malloc(sizeof(struct stack));
	init(stk);
  
	printf("1)ADD\n2)DELETE\n3)PRINT\n4)exit\nCHOOSE: ");  
	while(v!=4){
	
  		scanf("%d", &v);
  
	switch(v){
			case 1:
			    printf("enter element:");
    			scanf("%d", &elem);
    			push(stk,elem);
			break;
			
			case 2:
			    printf("delete %d\n", pop(stk));	
			break;
			
			case 3:
			    stkPrint(stk);
			break;
			
			case 4:
				exit(0);
			break;
  
		}

	}
	
	return 0;
	
}
