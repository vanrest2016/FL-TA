#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *getarr(int);

int main(void) {

	int i, j;
	int orient;
	int size;
	char *numb[size];
	int svyaz[size][size];
    
	printf("Press\n1-for graph\n2-for digraph\n 	");
	scanf("%d", &orient);

	if(orient == 1){
		printf("You choose graph\n");
	}
	if(orient == 2){
		printf("You choose digraph\n");
	}

	printf("Size of \n");
	scanf("%d", &size);

	if(size <= 0)
		exit(1);
		
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{

			svyaz[i][j] = 0;

		}
	}

	printf("Enter numbers your elements\n");
	getchar();

	for (i = 0; i < size; i++)
	{
		printf("\n---\n");
		numb[i] = getarr(0);

		for (j = 0; j < i; j++)
		{
			
			if(strcmp(numb[i], numb[j]) == 0){
                printf("There are similar elements, enter another\n");
                i--;

			}
		}
	}

	printf("Enter connection\n");

    char *str = getarr(1);
    i=0;
    int k;

    while(str[i] != '\0'){

        char name1[32] = {0}, name2[32] = {0};
        int numname1 = -1, numname2 = -1;
        char ch1 = 0;
        int j=0;

        while((ch1 = str[i++]) != '-'){ 

        	name1[j++] = ch1; 
        }

        j=0;

        while((ch1 = str[i++]) != ';' && ch1 != '\0'){ 
        	
        	name2[j++] = ch1; 

        }
        
        for(k=0; k<size; k++){

            if(strcmp(numb[k], name1) == 0){

                numname1 = k;

            }

            if(strcmp(numb[k], name2) == 0){
                
                numname2 = k;

            }
        }

        svyaz[numname1][numname2]++;

    }
        
    printf("\n");

    _Bool relat_graph = 1;

    for(i=0; i<size; i++){

        _Bool temp_relat_graph = 0;

        for(j=0; j<size; j++){

            if(svyaz[i][j] == 1)
                temp_relat_graph = 1;
            
            if(svyaz[j][i] == 1)
                temp_relat_graph = 1;

        }

        if(temp_relat_graph == 0)
            relat_graph=0;

    }

    if(relat_graph == 0){

        printf("unrelated\n");

    } else {

        printf("related\n");

    }

    printf("Connection table\n");

    for(i=0; i<size; i++) {

        printf("%s\t", numb[i]);

        for (j=0; j<size; j++) {

            printf("%d ", svyaz[i][j]);

        }

        printf("\n");

    }
    
    
    char strsys[1024] = {0};
    strcat(strsys, "echo '");

    char arr[3] = "";

    if(orient == 2){

        strcat(strsys, "digraph G {");
        strcat(arr, "->");

    } else {

        strcat(strsys, "graph G {");
        strcat(arr, "--");

    }

    for(i=0; i<size; i++){

        strcat(strsys, numb[i]);
        strcat(strsys, "; ");

    }

    for(i=0; i<size; i++){

        for(j=0; j<size; j++){

            for(k=0; k<svyaz[i][j]; k++){

                strcat(strsys, numb[i]);
                strcat(strsys, arr);
                strcat(strsys, numb[j]);
                strcat(strsys, "; ");

            }
        }
    }
    
    strcat(strsys, "}");
    strcat(strsys, "}' | dot -Tpng > ./graph.png");

    
    system(strsys);

    return 0;

}


char *getarr(int ch){

    int n=1;
    int i, j; 
    char *arr,c;

    arr = calloc(n+1, sizeof(char));

    char trigger = ';';

    if(ch){

        trigger = '\n';

    }

    i = 0;

    while((c=getchar()) != trigger){

        if(ch == 1 || (('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))){ 

            char *temp_arr;

            temp_arr = calloc(n+1, sizeof(char));
            
            for(j = 0; j < n; j++){

                temp_arr[j] = arr[j];

            }

            temp_arr[n-1] = c;
            n++;
            i++;

            free(arr);

            arr = temp_arr;

        }

        else if(c == '\n'){

            arr[n]='\0';

            return arr;

        }
    }

    arr[n-1]='\0';

    return arr;
    
}
