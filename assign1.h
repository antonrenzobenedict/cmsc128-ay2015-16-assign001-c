

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int menu();
char * getOnes(int num);
char * getTens(int tens);
char * getHundreds(int hundreds);
char * specialOne(int num);
int scanNum(char* word);
int toNum(char* word);
int toPlace(char* word);
void trim(char* word);

int menu(){
	int choice;
	printf("\n===========MENU==========\n");
	printf("[1] Number to Words\n");
	printf("[2] Words to Number\n");
	printf("[3] Words to Currency\n");
	printf("[4] Number Delimited\n");
	printf("[5] Exit\n");
	printf("=========================\n");
	printf("Choice: ");
	scanf("%d", &choice);

	return choice;
}

void numToWords()
{
	int num;
	int accumulator = 0;
	int ones, tens, hundreds, thousands, ten_thousands, hundred_thousands;
	char word [256] ;
	
	
	strcpy(word,"");
	printf("Enter Number: ");
	scanf("%d",&num);
	
	if(num == 1000000)
	{
		strcat(word,"one million");
	}
	else if(num == 0)
	{
		strcat(word,"zero");
	}
	else
	{
		ones = num % 10;
		tens = num % 100 / 10;
		hundreds = num % 1000 / 100;
		thousands = num % 10000 / 1000;
		ten_thousands = num % 100000 / 10000;
		hundred_thousands = num % 1000000 / 100000;
		
		
		if(hundred_thousands > 0)
			{
				strcat(word,getOnes(hundred_thousands));
				strcat(word,"hundred ");
			}
		if(ten_thousands > 0)
				strcat(word,getTens(ten_thousands));
		if(ten_thousands == 1)
				strcat(word,specialOne(thousands));
		if(ten_thousands != 1)
				strcat(word,getOnes(thousands));
				
		if(thousands > 0)
			strcat(word,"thousand ");
		
		
		if(hundreds > 0)
			{
				strcat(word,getOnes(hundreds));
				strcat(word,"hundred ");
			}
		if(tens > 0)
				strcat(word,getTens(tens));
		if(tens == 1)
				strcat(word,specialOne(ones));
		if(tens != 1)
				strcat(word,getOnes(ones));
	}	
		
	
	printf("%s",word);
}

char * getOnes(int num){
	
	char *n = malloc(sizeof(char) * 20);
	
	switch(num)
	{
		case 1:strcpy(n,"one ");
			break;
		case 2:strcpy(n,"two ");
			break;
		case 3:strcpy(n,"three ");
			break;
		case 4:strcpy(n,"four ");
			break;
		case 5:strcpy(n,"five ");
			break;
		case 6:strcpy(n,"six ");
			break;
		case 7:strcpy(n,"seven ");
			break;
		case 8:strcpy(n,"eight ");
			break;
		case 9:strcpy(n,"nine ");
			break;
	}
	
	return n;
	
}

char * getTens(int tens)
{
	char *n = malloc(sizeof(char) * 20);
	switch(tens)
	{
		case 2:
				strcat(n,"twenty ");
			break;
		case 3:
				strcat(n,"thirty ");
			break;
		case 4:
				strcat(n,"fourty ");
			break;
		case 5:
				strcat(n,"fifty ");
			break;
		case 6:
				strcat(n,"sixty ");
			break;
		case 7:
				strcat(n,"seventy ");
			break;
		case 8:
				strcat(n,"eighty ");
			break;
		case 9:
				strcat(n,"ninety ");
			break;
	}
	return n;
}

char * getHundreds(int hundreds){
	
	char *n = malloc(sizeof(char) * 20);
	
	switch(hundreds)
	{
		case 1:strcpy(n,"one ");
			break;
		case 2:strcpy(n,"two ");
			break;
		case 3:strcpy(n,"three ");
			break;
		case 4:strcpy(n,"four ");
			break;
		case 5:strcpy(n,"five ");
			break;
		case 6:strcpy(n,"six ");
			break;
		case 7:strcpy(n,"seven ");
			break;
		case 8:strcpy(n,"eight ");
			break;
		case 9:strcpy(n,"nine ");
			break;
	}
	
	return n;
	
}
char * specialOne(int num)
{
	
	char *n = malloc(sizeof(char) * 20);
	
	switch(num)
	{
		case 0:strcpy(n,"ten ");
			break;
		case 1:strcpy(n,"eleven ");
			break;
		case 2:strcpy(n,"twelve ");
			break;
		case 3:strcpy(n,"thirteen ");
			break;
		case 4:strcpy(n,"fourteen ");
			break;
		case 5:strcpy(n,"fifteen ");
			break;
		case 6:strcpy(n,"sixteen ");
			break;
		case 7:strcpy(n,"seventeen ");
			break;
		case 8:strcpy(n,"eighteen ");
			break;
		case 9:strcpy(n,"nineteen ");
			break;
	}
	
	return n;
}

void wordsToNum()
{
	char word[256];
	int number = 0;
	
	getchar();
	fgets(word,256,stdin);
	trim(word);
	
	
	if(strcmp(word,"one million\n") == 0)
	{
		number += 1000000;
	}
	else
	{
		char **array = (char**) malloc((32)*sizeof(char*));
		char *token;
		char s[2] = " ";
		int i = 0;
		 token = strtok(word, s);
		while( token != NULL ) 
		{
			array[i] = token;
			i++;
			token = strtok(NULL, s);
		}
		int j;
		int c;
		int a;
		int b;
		int flag1;
		int flag2;
		for(j = 0;j < i;j++)
		{
			c = scanNum(array[j]);
			if(c)
			{
				a = toNum(array[j]);
				if (j == (i - 1 ) && flag2 == 0)
					number += a;
				if(flag2)
					number += a;
				flag2 = 1;
				flag1 = 0;
				if(j == 0)
					number = a;
					
				
			}
			else
			{
				b = toPlace(array[j]);
				if(flag1)
					number = a * b;
				number = number * b;
				flag1 = 1;
				flag2 = 0;
				
				
			}
			
			
			
			
			
		}
		
	}
	printf("%d",number);
	
}
void trim(char* word)
{
	word[strlen(word) - 1] = '\0';
}
int scanNum(char* word)
{
	char **num = (char**) malloc((28)*sizeof(char*));
	int i;
	num[0] = "zero";
	num[1] = "one";
	num[2] = "two";
	num[3] = "three";
	num[4] = "four";
	num[5] = "five";
	num[6] = "six";
	num[7] = "seven";
	num[8] = "eight";
	num[9] = "nine";
	num[10] = "ten";
	num[11] = "eleven";
	num[12] = "twelve";
	num[13] = "thirteen";
	num[14] = "fourteen";
	num[15] = "fifteen";
	num[16] = "sixteen";
	num[17] = "seventeen";
	num[18] = "eighteen";
	num[19] = "nineteen";
	num[20] = "twenty";
	num[21] = "thirty";
	num[22] = "forty";
	num[23] = "fifty";
	num[24] = "sixty";
	num[25] = "seventy";
	num[26] = "eighty";
	num[27] = "ninety";
	
	for(i = 0; i < 28; i++)
	{
		if(strcmp(num[i],word) == 0)
			return 1;
	}
		return 0;
}

int toNum(char* word){
	if(strcmp(word,"zero") == 0)
		return 0;
	if(strcmp(word,"one") == 0)
		return 1;
	if(strcmp(word,"two") == 0)
		return 2;
	if(strcmp(word,"three") == 0)
		return 3;
	if(strcmp(word,"four") == 0)
		return 4;
	if(strcmp(word,"five") == 0)
		return 5;
	if(strcmp(word,"six") == 0)
		return 6;
	if(strcmp(word,"seven") == 0)
		return 7;
	if(strcmp(word,"eight") == 0)
		return 8;
	if(strcmp(word,"nine") == 0)
		return 9;
	if(strcmp(word,"ten") == 0)
		return 10;
	if(strcmp(word,"eleven") == 0)
		return 11;
	if(strcmp(word,"twelve") == 0)
		return 12;
	if(strcmp(word,"thirteen") == 0)
		return 13;
	if(strcmp(word,"fourteen") == 0)
		return 14;
	if(strcmp(word,"fifteen") == 0)
		return 15;
	if(strcmp(word,"sixteen") == 0)
		return 16;
	if(strcmp(word,"seventeen") == 0)
		return 17;
	if(strcmp(word,"eighteen") == 0)
		return 18;
	if(strcmp(word,"nineteen") == 0)
		return 19;
	if(strcmp(word,"twenty") == 0)
		return 20;
	if(strcmp(word,"thirty") == 0)
		return 30;
	if(strcmp(word,"forty") == 0)
		return 40;
	if(strcmp(word,"fifty") == 0)
		return 50;
	if(strcmp(word,"sixty") == 0)
		return 60;
	if(strcmp(word,"seventy") == 0)
		return 70;
	if(strcmp(word,"eighty") == 0)
		return 80;
	if(strcmp(word,"ninety") == 0)
		return 90;
	
}
int toPlace(char* word){
	if(strcmp(word,"thousand") == 0)
		return 1000;
	else if(strcmp(word,"hundred") == 0)
		return 100;
	else
		return 1;
}
void wordsToCurrency(){
	
}
char* numberDelimited(char* number,char character,int jumps){
	char *output = malloc(sizeof(char) * 256);
	
	
	int i;
	
	
	i = strlen(number) - 1;
	int j = 0;
	char r;
	while(i > j)
    {
        r = number[i];
        number[i]= number[j];
        number[j] = r;
        i--;
        j++;
    }
	i = 0;
	
	int c = 0;
	int jumpC = 1;
	j = strlen(number) + strlen(number) / jumps;
	
	for(i = 0; i < j; i++)
	{
		output[i] = number[c];
		c++;
		
		if(jumpC == jumps && i < (j - 1))
			{
				
				i++;
				if(i >= j-1)
					break;
				output[i] = character;
				jumpC = 0; 
			}
		jumpC++;
		
	}
	i = strlen(output) - 1;
	 j = 0;

	while(i > j)
    {
        r = output[i];
        output[i]= output[j];
        output[j] = r;
        i--;
        j++;
    }
	
	return output;
}


//1234,56 
//i 5 4 3
//k 1 2 