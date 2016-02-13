
#include<stdio.h> //standard input output library
#include<stdlib.h> //standard library
#include<string.h> //string library

int menu();
char * getOnes(int num);
char * getTens(int tens);
char * getHundreds(int hundreds);
char * specialOne(int num);
char * numToWords(int num);
int wordsToNum(char* word);
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
	
	
	strcpy(word,"");//initalizes word to blank
	
	
	if(num == 1000000)
	{
		strcat(word,"one million ");// if one million
	}
	else if(num == 0)
	{
		strcat(word,"zero ");// if zero
	}
	else if(num < 1000000)
	{
		ones = num % 10;//gets the ones digit
		tens = num % 100 / 10;// gets the tens digit
		hundreds = num % 1000 / 100;// gets the hundreds digit
		thousands = num % 10000 / 1000;// gets the thousands digit
		ten_thousands = num % 100000 / 10000;// gets the ten thousands digit
		hundred_thousands = num % 1000000 / 100000;//gets the hundred_thousands digit
		
		
		if(hundred_thousands > 0)//concatenates "X hundred"
			{
				strcat(word,getOnes(hundred_thousands));
				strcat(word,"hundred ");
			}
		if(ten_thousands > 0)
				strcat(word,getTens(ten_thousands));//converts ten_thousands to words
		if(ten_thousands == 1)
				strcat(word,specialOne(thousands));//if special tens like eleven
		if(ten_thousands != 1)
				strcat(word,getOnes(thousands));//gets ones thousands
				
		if(thousands > 0 || ten_thousands > 0 || hundred_thousands > 0)//if there is a thousand value
			strcat(word,"thousand ");
		
		
		if(hundreds > 0)//concatenates "X hundred"
			{
				strcat(word,getOnes(hundreds));
				strcat(word,"hundred ");
			}
		if(tens > 0)//for not so special tens
				strcat(word,getTens(tens));
		if(tens == 1)//for special tens
				strcat(word,specialOne(ones));
		if(tens != 1)//for ones values
				strcat(word,getOnes(ones));
	}
	else//if not in range
	{
		strcat(word,"Overflow");
	}	
		
	
	return word;
}

char * getOnes(int num){//function for getting the ones value
	
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

char * getTens(int tens)//function for getting the not so special tens values
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

char * getHundreds(int hundreds){//function for getting the hundreds value
	
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
char * specialOne(int num)//function for getting the specials tens
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

int wordsToNum(char* word)//converts words to numbers using brute force
{
	int returnThis = 0 ;
	int number;
	strcat(word," ");
for(returnThis = 0; returnThis < 1000000; returnThis++)//tries every number from 0 to 1,000,000
		{
			if(strcmp(word,numToWords(returnThis)) == 0)//breaks if it matches
			break;
		}
			
	
	
	return returnThis;//returns the resulting number
	
}
void trim(char* word)
{
	word[strlen(word) - 1] = '\0';//trims the word for excess whitespaces
}

char* wordsToCurrency(char* word, char* currency){//converts words and currency to numbers
	int num;
	num = wordsToNum(word);
	char *output = malloc(sizeof(char) * 256);
	sprintf(output,"%d",num);
	
	if(strcmp(currency,"JPY") == 0 || strcmp(currency,"PHP") == 0 || strcmp(currency,"USD") == 0)//only selected currencies: USD,PHP,JPY
		return strcat(currency,output);
	else
		return "Invalid Currency!";//else invalid
	
}
char* numberDelimited(char* number,char character,int jumps){//delimits number according to characters by jumps
	char *output = malloc(sizeof(char) * 256);
	int i;
	i = strlen(number) - 1;
	int j = 0;
	char r;
	while(i > j)//reverses the numbers
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
	
	for(i = 0; i < j; i++)//delimits the numbers by the character in jumps intervals
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

	while(i > j)//reverses again the numbers
    {
        r = output[i];
        output[i]= output[j];
        output[j] = r;
        i--;
        j++;
    }
	
	return output;//returnts the numbers
}
