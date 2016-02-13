
#include<stdio.h>
#include "assign1.h"

main(){
	int choice;



		while((choice = menu()) != 5)
		{
			switch(choice)
			{
			case 1:;
					int num;
					printf("Enter Number: ");
					scanf("%d",&num);
					printf("%s\n",numToWords(num));
					
					break;
			case 2:;
					char word[256];
					printf("Enter Word: ");
					getchar();
					fgets(word,256,stdin);
					trim(word);
					printf("%d\n",wordsToNum(word));
					break;
			case 3:	
					;
					char word2[256];
					char currency[256];
					printf("Enter Word: ");
					getchar();
					fgets(word2,256,stdin);
					trim(word2);
					printf("Enter Currency: ");
					fgets(currency,256,stdin);
					trim(currency);
					printf("%s\n",wordsToCurrency(word2,currency));
					break;
			case 4:;
					char number[256];
					printf("Number from 0 to 1,000,000\n");
					printf("Number: ");
					scanf("%s",number);
					
					printf("Enter Character: ");
					char character;
					getchar();
					scanf("%c",&character);
					
					int jumps;
					printf("Enter Jumps: ");
					scanf("%d", &jumps);
					printf("%s\n",numberDelimited(number,character,jumps));
					break;
			}
		}

}


