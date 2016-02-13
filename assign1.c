
#include<stdio.h>
#include "assign1.h"

main(){
	int choice;//variable for choice
		while((choice = menu()) != 5)
		{
			switch(choice)
			{
			case 1:;
					int num;
					printf("Enter Number: ");//asks the user to enter the number that will be converted to words
					scanf("%d",&num);
					printf("%s\n",numToWords(num));//prints the number in words
					
					break;
			case 2:;
					char word[256];
					printf("Enter Word: ");//asks the user the phrase that will be converted to numbers
					getchar();
					fgets(word,256,stdin);
					trim(word);
					printf("%d\n",wordsToNum(word));//prints the phrase in numbers
					break;
			case 3:	
					;
					char word2[256];
					char currency[256];
					printf("Enter Word: ");//asks the user the phrase that will be converted to numbers
					getchar();
					fgets(word2,256,stdin);
					trim(word2);
					printf("Enter Currency: ");//asks the user for the currency
					fgets(currency,256,stdin);
					trim(currency);
					printf("%s\n",wordsToCurrency(word2,currency));//prints the currency followed by the numbers
					break;
			case 4:;
					char number[256];
					printf("Number from 0 to 1,000,000\n");//asks the user for the number
					printf("Number: ");
					scanf("%s",number);
					
					printf("Enter Character: ");//asks the user for the character
					char character;
					getchar();
					scanf("%c",&character);
					
					int jumps;
					printf("Enter Jumps: ");
					scanf("%d", &jumps);//asks the user for the jumps
					
					printf("%s\n",numberDelimited(number,character,jumps));//prints the number jumped by characters
					break;
			}
		}

}


