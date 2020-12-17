# 29. Удаление заданного ребра.
## Алгоритм
### Cчитывание удаляемой строки

```C
    char *p;
	printf("Delete rebro: ");
    gets(str);
 ```
### Определение адреса начала вхождения построки в строку

```C
        p = strstr(arr,str);
```
   
### Затирание подстроки str

```C
      if (p != NULL){
    	
		for (i=0; i<strlen(str);i++)
			for(j=0; j<strlen(arr);j++) 
				p[j]=p[j+1];
    }
```
## Структурная схема алгоритма

![Alt-текст](https://github.com/vanrest2016/FL-TA/blob/master/Схема.png)

## Результат работы:
![Alt-текст](https://github.com/vanrest2016/FL-TA/blob/master/Результат%20работы.jpg)

## Отображение графа
![Alt-текст](https://github.com/vanrest2016/FL-TA/blob/master/Graph.jpg)
