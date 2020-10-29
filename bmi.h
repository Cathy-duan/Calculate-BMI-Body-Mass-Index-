#ifndef _BMI_H_
#define _BMI_H_

typedef struct _person {
	char *first;				// first name of the person
	char *last;					// last name of the person
	int height;					// height in inches
	int weight;					// weight in pounds
	struct _person *nextHeight;	// next person in list, ordered by height
	struct _person *nextWeight; // next person in list, ordered by weight
} Person;

typedef struct _plist {
	Person *headHeightList;
	Person *headWeightList;
} PersonList;

///////////////////////////////////////////////////////////////

int size(PersonList *);
void printByHeight(PersonList *);
void printByWeight(PersonList *);

Person *search(PersonList *, char *, char *);
void updateName(PersonList *, char *, char *, char *, char *);

PersonList *add(PersonList *, char *, char *, int, int);
PersonList *removePerson(PersonList *, char *, char *);
PersonList *updateHeight(PersonList *, char *, char *, int);
PersonList *updateWeight(PersonList *, char *, char *, int);

#endif
