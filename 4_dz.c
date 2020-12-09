#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delete(char* arr, char* str) { 

	int t,i,j;
 
    char *p;
 
	printf("Delete rebro: ");
    gets(str);
 
    p = strstr(arr,str);
 
    if (p){
    	
		for (i=0; i<strlen(str);i++)
			for(j=0; j<strlen(arr);j++)
				p[j]=p[j+1];
				
    }
    
    printf("%s\n",arr);
 
}


int main(void)
{
    int i, j;
    printf("Choose graph - 1 or digraph - 2\n");
    scanf("%d", &fl);

    printf("Count: ");
    int n;
    scanf("%d",&n);



    int graph[n][n];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Fill the names of elements\n");
    char *name[n];

    for (i = 0; i < n; i++)
    {
        printf("# ");
        char *sname = (char*) malloc(20 * sizeof(char));
        scanf("%s", sname);
        name[i] = sname;
    }

    printf("Enter connection\n");
    char *str = (char*) malloc(100 * sizeof(char));
    scanf("%s", str);
    char *first_name;
    first_name = strtok(str, "-");
    while(first_name != NULL)
    {

        int index_first_name = -1;
        char *second_name;
        int index_second_name = -1;

        second_name = strtok(NULL, ";");

        for(i = 0; i < n; i++)
        {
            if(strcmp(name[i], first_name) == 0)
                index_first_name = i;
            if(strcmp(name[i], second_name) == 0)
                index_second_name = i;
        }

        if ((index_first_name != -1) && (index_second_name != -1))
        {
            if (fl == 1)
            {
                graph[index_first_name][index_second_name] = 1;
                graph[index_second_name][index_first_name] = 1;
            }
            else
            {
                graph[index_first_name][index_second_name] = 1;
            }
        }

        first_name = strtok(NULL, "-");
    }

    int side = 1;
    for (i = 0; i < n; i++)
    {
        int up = 0;
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] > 0)
                up = 1;

            if (graph[j][i] > 0)
                up = 1;
        }
        if (up == 0)
            side = 0;
    }
    if (!side)
        printf("Unrelated graph\n");
    else
        printf("Related graph\n");

    for (i = 0; i < n; i++)
    {
        printf("#%4s: ", name[i]);
        for ( j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

	char* strk;

    char* arr = (char*) calloc(500, sizeof(char));

    if(fl == 2)
    {
        strcat(arr, "digraph G {");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (graph[i][j] > 0)
                {
                    strcat(arr, name[i]);
                    strcat(arr, "->");
                    strcat(arr, name[j]);
                    strcat(arr, ";");
                }
            }
        }
    }
    else
    {
        strcat(arr, "graph G {");
        for (i = 0; i < n; i++)
        {
            strcat(arr, name[i]);
            strcat(arr, ";");
        }
        for (i = 0; i < n; i++)
        {
            for (j = i; j < n; j++)
            {
                if (graph[i][j] > 0)
                {
                    strcat(arr, name[i]);
                    strcat(arr, "--");
                    strcat(arr, name[j]);
                    strcat(arr, ";");
                }
            }
        }
    }
    
    strcat(arr, "}");
    
    
	printf("%s\n", arr);
	printf(" ");
        gets(strk);
    
	delete(arr, strk);
	
	
    FILE* f = fopen("graph.dot", "w");
    fprintf(f, "%s\n", arr);
    fclose(f);

    free(arr);

    return 0;
}

