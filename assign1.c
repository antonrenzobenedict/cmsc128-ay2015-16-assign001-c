
#include<stdio.h>
#include "assign1.h"

main(){
	int choice;



		while((choice = menu()) != 5)
		{
			switch(choice)
			{
			case 1:numToWords();
					break;
			case 2:wordsToNum();
					break;
			case 3:wordsToCurrency();
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


