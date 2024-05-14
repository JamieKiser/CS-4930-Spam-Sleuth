/*
Class Name: Privacy and Censorship - CS 4930
Name: Jamie Kiser
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// amount of point values stored
#define MAX 30
// quick acess to 3 test emails
#define EMAIL1 "testEmail1.txt"
#define EMAIL2 "testEmail2.txt"
#define EMAIL3 "testEmail3.txt"

// scans the file and prints words found along with point value
void scanEmail(const char **wordPtr, const int points[]);
// prints overall point value
void printPoints(int pointTotal);

int main(int argc, char *argv[])
{

	// char array of pointers to store words/phrases
	const char *wordPtr[] = {"free", "cash", "fast", "debt",
  "risk-free", "compromised", "gift", "account", "transfer", "invoice", "tech",
  "restricted", "download", "file", "sir", "mam", "deleted", "apple",
  "microsoft", "facebook", "ebay", "amazon", "netflix", "hold", "cancel",
  "unsubscribe", "refund", "update", "eligible", "replying"};

	// int array of pointers to store point values for words
	const int points[MAX] = {3, 4, 3, 4,
  4, 3, 3, 4, 3, 2, 2,
  2, 3, 4, 3, 5, 3, 1,
  1, 1, 1, 1, 1, 2, 1,
  2, 5, 2, 3, 2};

	// function scans file and prints results
	scanEmail(wordPtr, points);
	return 0;
}// main

void scanEmail(const char **wordPtr, const int points[])
{
	// creates file pointer
	FILE *cfPtr;

	// reads the file/ if can't read file, exit
	if ((cfPtr = fopen(EMAIL3, "r")) == NULL)
	{
		puts("File could not be found");
	}
	else
	{
		// char array to store one word from email
		char email[15];
		// variable to store overall points initialized to 0
		unsigned int overallPoints = 0;

		// scans email and stores word from email until end of file is reached
		while(fscanf(cfPtr, "%s", email) != EOF)
		{
			// loops 30 times until all words of email 
      // have been compared to words phishing words array
			for(int i = 0; i < MAX; i++)
			{
				// if result is 0, there's a match
				// strcasecmp is really useful for ignoring capitalization
				int result = strcasecmp(email, wordPtr[i]);

				// if match was found, print matched word and element number
				if (result == 0)
				{
					printf("Word found: %s \nPoint value added: +%d\n\n",
					       wordPtr[i], points[i]);

					// adds points of word found until email is completely scanned
					overallPoints += points[i];
				}
			}
		}
		// calls to printPoints method to print overall points
		printPoints(overallPoints);
		//closes file
		fclose(cfPtr);
	}
}// scanFile

void printPoints(int pointTotal)
{
	// prints amount of points
  if (pointTotal == 0) 
  {
    printf("Overall point value: %d", pointTotal);
		puts("\nNo suspicious words found.");
  }
	else if(pointTotal <= 3 && pointTotal > 0)
	{
		printf("Overall point value: %d", pointTotal);
    puts("\n0-3: low chance to be phishing scam.");
	}
	else if(pointTotal <= 7 && pointTotal > 3)
	{
    printf("Overall point value: %d", pointTotal);
		puts("\n4-7: medium chance to be phishing scam.");
	}
  else
  {
    printf("Overall point value: %d", pointTotal);
    puts("\n>= 8: high chance to be phishing scam.");
  }
}// printPoints