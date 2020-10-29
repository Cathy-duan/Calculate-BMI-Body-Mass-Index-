#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bmi.h"


int main(int argc, char *argv[]) {
	int prompt=1;
	if (argc==2 && strcmp(argv[1], "no")==0) prompt=0;

	PersonList *theList=malloc(sizeof(PersonList));
	theList->headHeightList = NULL;
	theList->headWeightList = NULL;

	while (1) {
		if (prompt) printf("Enter a command or help to get a command list: ");
		char cmd[20];
		scanf("%s", cmd);
		if (strcmp(cmd, "quit")==0) break;
		char first[100], last[100];
		char newFirst[100], newLast[100];
		int h, w;
		if (strcmp(cmd,"add")==0) {
			if (prompt) printf("\tEnter first name: ");
			scanf("%s", first);
			if (prompt) printf("\tEnter last name: ");
			scanf("%s", last);
			if (prompt) printf("\tEnter height: ");
			scanf("%d", &h);
			if (prompt) printf("\tEnter weight: ");
			scanf("%d", &w);
			theList=add(theList, first, last, h, w);
		}
		else if (strcmp(cmd, "size")==0)
			printf("\nThere are %d persons in the list\n", size(theList));
		else if (strcmp(cmd, "printByHeight") == 0 )
			printByHeight(theList);
		else if (strcmp(cmd, "printByWeight")==0)
			printByWeight(theList);
		else if (strcmp(cmd, "search")==0) {
			if (prompt) printf("\tEnter first name: ");
			scanf("%s", first);
			if (prompt) printf("\tEnter last name: ");
			scanf("%s", last);
			Person *ptr=search(theList, first, last);
			if (ptr==NULL)
        		printf("%s %s does not exist in the list\n", first, last);
			else
        		printf("%s %s: height=%d, weight=%d\n", ptr->first, ptr->last, ptr->height, ptr->weight);
		}
		else if (strcmp(cmd, "updateName") == 0 ) {
			if (prompt) printf("\tEnter first name: ");
			scanf("%s", first);
			if (prompt) printf("\tEnter last name: ");
			scanf("%s", last);
			if (prompt) printf("\tEnter new first name: ");
			scanf("%s", newFirst);
			if (prompt) printf("\tEnter new last name: ");
			scanf("%s", newLast);
			updateName(theList, first, last, newFirst, newLast);
		}
		else if (strcmp(cmd, "remove")==0) {
			if (prompt) printf("\tEnter first name: ");
			scanf("%s", first);
			if (prompt) printf("\tEnter last name: ");
			scanf("%s", last);
			theList=removePerson(theList, first, last);
		}
		else if (strcmp(cmd, "updateHeight")==0) {
			if (prompt) printf("\tEnter first name: ");
			scanf("%s", first);
			if (prompt) printf("\tEnter last name: ");
			scanf("%s", last);
			if (prompt) printf("\tEnter new height: ");
			scanf("%d", &h);
			theList=updateHeight(theList, first, last, h);
		}
		else if (strcmp(cmd, "updateWeight")==0) {
			if (prompt) printf("\tEnter first name: ");
			scanf("%s", first);
			if (prompt) printf("\tEnter last name: ");
			scanf("%s", last);
			if (prompt) printf("\tEnter new weight: ");
			scanf("%d", &w);
			theList=updateWeight(theList, first, last, w);
		}
		else if (strcmp(cmd, "help")==0) {
			printf("Valid commands:\n");
			printf("***** add\n");
			printf("***** size\n");
			printf("***** printByHeight\n");
			printf("***** printByWeight\n");
			printf("***** search\n");
			printf("***** remove\n");
			printf("***** updateName\n");
			printf("***** updateHeight\n");
			printf("***** updateWeight\n");
			printf("***** help\n");
			printf("***** quit\n");
		}
		else {
			printf("Invalid command specififed - %s\n", cmd);
		}
		printf("\n");
	}
	return 0;
}

