#include <stdio.h>

void spacer(int n, char c);

int main() {
//Initialise variables
	int num1,num2,test,test2;
	int myQuotient, myRemainder, tempRemainder, tempSub, tempChunk;
	int num1Length, num2Length, sumMid, tempLength;
	char space;
	int spaceLength;
	int numChunks, chunkCount, arrayLine;

//get user input and confirm to display
	printf("Enter number that you would like to divide.\n");
	scanf("%i", &num1);
	printf("Enter number that you would to divide by.\n");
	scanf("%i", &num2);
	printf("\nYou would like to divide %i", num1);
	printf(" by %i, the answer is :-\n", num2);
	printf("\n");

//Set up calculation variables
	myQuotient = num1 / num2;
	myRemainder = num1 - (myQuotient * num2);
	num1Length = numDigits(num1);
	num2Length = numDigits(num2);
	sumMid = num1Length + num2Length + 1;
	tempLength = numDigits(myQuotient);

//Calculate initial chunk value
	tempChunk = 1;
	numChunks = 1;
	test=num1Length - num2Length;
	while (test >= 1)
	{
	tempChunk = 10 * tempChunk;
	test--;
	numChunks++;
	}
	tempSub = tempChunk * num2;
	tempRemainder = num1;

//Set up chunking output array and initialise
	int chunkArray[numChunks][2];
	for (test=0; test < numChunks; test++)
	{
		for (test2=0; test2 < 2; test2++)
		{		
		chunkArray[test][test2]=0;
		}
	}

//Format initial chunking display
	spacer (sumMid - tempLength, ' ');
	printf("%i remainder %i\n", myQuotient, myRemainder);

	spacer (num2Length+1, ' ');
	spacer (num1Length, '_');
	printf("\n");
	printf("%i|%i| \n", num2, num1);

//Start displaying chunk breakdown
	arrayLine=0;	
	while (tempChunk >= 1)
	{
		chunkCount=0;
		while (tempRemainder >= tempSub)
		{
		tempLength = numDigits(tempSub);
		chunkCount++;
		//Line 1 of chunking sum
		spacer ((sumMid -tempLength), ' ');
		printf("%i|%i x %i\n", tempSub, tempChunk, num2);
		tempLength = numDigits(tempSub);
//Subtracting divisor of chunking sum
		spacer ((sumMid - tempLength), ' ');
		tempLength = numDigits(tempSub);
		spacer (tempLength, '-');
		printf("|");
		printf("\n");
//Result of subtraction
		tempRemainder = (tempRemainder - tempSub);
		tempLength = numDigits(tempRemainder);
		spacer ((sumMid - tempLength), ' ');
		printf("%i|\n", tempRemainder);

		}
	chunkArray[arrayLine][0] = chunkCount * tempChunk;
	chunkArray[arrayLine][1] = num2;
	arrayLine++;
	tempChunk = (tempChunk / 10);
	tempSub = (tempChunk * num2);
	}

//Format answer
	printf("\n%i = ", num1);
	for (test=0; test < numChunks; test++)
	{
		if (chunkArray[test][0] != 0)
		{
		printf("(%i x %i) + ",  chunkArray[test][0], chunkArray[test][1]);
		}	
	}
	if (tempRemainder < 1)
	{
	printf("zero remainder\n\n");
	}
	else
	{
	printf("%i\n\n", tempRemainder);
	}
	return 0;
}

//Routine to count digits
int numDigits(int n)
{
int count = 0;
do
{
++count;
n /= 10;
}
while(n != 0);
return count;
}


//Routine to make spacers 
void spacer (int n, char c)
{
int temp;
	for (temp=0; temp < n; temp++)
	{
	printf("%c", c);
	}
return;
}
