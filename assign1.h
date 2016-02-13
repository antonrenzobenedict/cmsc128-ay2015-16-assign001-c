

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int menu();
char * getOnes(int num);
char * getTens(int tens);
char * getHundreds(int hundreds);
char * specialOne(int num);
char * numToWords(int num);
int wordsToNum(char* word);
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

char* numToWords(int num)
{
	int accumulator = 0;
	int ones, tens, hundreds, thousands, ten_thousands, hundred_thousands;
	char *word = malloc(sizeof(char) * 256);
	
	
	strcpy(word,"");
	
	
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
				
		if(thousands > 0 || ten_thousands > 0 || hundred_thousands > 0)
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
		
	
	return word;
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
				strcat(n,"forty ");
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

int wordsToNum(char* word)
{
	int returnThis = 0 ;
	int number;
	strcat(word," ");
	if(strcmp(word,"one million") == 0)
	{
		number = 0;
	}
	else if(strcmp(word,"zero") == 0)
	{
		number = 0;
	}
	else
	{
		for(returnThis = 0; returnThis < 1000000; returnThis++)
		{
			if(strcmp(word,numToWords(returnThis)) == 0)
			break;
		}
			
	}
	if(returnThis == 1000000)
		returnThis = 0;
	return returnThis;
	
}
void trim(char* word)
{
	word[strlen(word) - 1] = '\0';
}

char* wordsToCurrency(char* word, char* currency){
	int num;
	num = wordsToNum(word);
	char *output = malloc(sizeof(char) * 256);
	sprintf(output,"%d",num);
	
	if(strcmp(currency,"JPY") == 0 || strcmp(currency,"PHP") == 0 || strcmp(currency,"USD") == 0)
		return strcat(currency,output);
	else
		return "Invalid Currency!";
	
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