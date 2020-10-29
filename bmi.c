/*Mengyue Duan
I try to add the people and then use name and height and weight to add or seach or update and print all*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bmi.h"

///////////////////////////////////////////////////////////////
// helper functions

Person *createPerson(char *first, char *last, int height, int weight, Person *nextHeight, Person *nextWeight)
{
    Person *ptr=malloc(sizeof(Person));
    ptr->first=malloc(strlen(first)+1);
    strcpy(ptr->first, first);
    ptr->last=malloc(strlen(last)+1);
    strcpy(ptr->last, last);

    ptr->height=height;
    ptr->weight=weight;

    ptr->nextHeight=nextHeight;
    ptr->nextWeight=nextWeight;

    return ptr;
}

///////////////////////////////////////////////////////////////
int compareWeight(Person *pNew, Person *pExist)
{
	if(pNew->weight > pExist->weight||pNew->weight == pExist ->weight) return 1;
	if(pNew->weight < pExist->weight) return -1;
	return 0;
}

int compareHeight(Person *pNew, Person *pExist)
{
	if(pNew ->height > pExist -> height) return -1;
	if(pNew ->height < pExist ->height || pNew -> height == pExist -> height)return 1;
	return 0;
}

PersonList *add(PersonList *list, char *first, char *last, int height, int weight) {
	Person *ptr=search(list, first, last);
	if (ptr!=NULL) {
		printf("Error: %s %s already exists in the list\n", first, last);
		return list;
	}

	Person *pNew=createPerson(first, last, height, weight, NULL, NULL);

	if(list->headHeightList==NULL){
	list->headHeightList=pNew; 
	}
	
	else if(compareHeight(pNew, list ->headHeightList)<0){
		pNew -> nextHeight =list ->headHeightList;
		list->headHeightList =pNew;
	}
	else{
		for(Person *cur=list ->headHeightList; cur!=NULL; cur=cur->nextHeight){
			if(cur->nextHeight ==NULL){
				cur->nextHeight =pNew;
				break;
			}
			else if(compareHeight(pNew,cur->nextHeight)==-1){
				pNew -> nextHeight =cur->nextHeight;
				cur->nextHeight =pNew;
				break;
			}
		}
	}

	if(list ->headWeightList==NULL){
		list -> headWeightList =pNew;
		return list;
	}
	else if(compareWeight(pNew,list->headWeightList)<0){
		pNew->nextWeight =list->headWeightList;
		list->headWeightList=pNew; 
		return list;
	}
	else{
		for(Person *cur=list -> headWeightList; cur!=NULL; cur=cur->nextWeight){
			if( cur ->nextWeight ==NULL){
                        cur->nextWeight= pNew;
			return list;
		}
		else if(compareWeight(pNew,cur->nextWeight)<0){
			pNew ->nextWeight =cur ->nextWeight;
			cur -> nextWeight =pNew;
	return list;
			}
		}	
	}
	return list;
}
int size(PersonList *list) {
	int count=0;
	for(Person *cur =list ->headHeightList; cur!= NULL; cur=cur->nextHeight){
		count++;
	}
	return count;
}

void printByHeight(PersonList *list) {
	for(Person *cur=list -> headHeightList; cur!= NULL; cur=cur->nextHeight){
		printf("%s %s: height = %d, weight = %d\n",cur->first, cur->last, cur->height, cur->weight);
	}
}

void printByWeight(PersonList *list) {
	for(Person *cur=list ->headWeightList; cur!= NULL; cur = cur->nextWeight){
		printf("%s %s: height = %d, weight =%d\n",cur->first, cur ->last, cur->height, cur ->weight);
	}
}

Person *search(PersonList *list, char *first, char *last) {
	for(Person *cur=list->headWeightList; cur!=NULL; cur=cur->nextWeight){
		if(strcmp(cur->first, first)==0 && strcmp (cur->last, last)==0) return cur;
	}
	return NULL;
}
Person *search1(PersonList *list,char *first, char *last){
	for(Person *cur =list -> headHeightList; cur!=NULL;cur=cur->nextHeight){
		if(strcmp(cur->first,first)==0 && strcmp(cur->last,last)==0) return cur;
	}
	return NULL;
}

void updateName(PersonList *list, char *first, char *last, char *newFirst, char *newLast) { 
	for(Person *cur =list-> headWeightList; cur!=NULL; cur=cur->nextWeight){
		if(strcmp(cur->first,first)==0 && strcmp(cur->last, last)==0){
			strcpy(cur->first, newFirst);
			strcpy(cur->last, newLast);
		}
	}
}


PersonList *delet(PersonList *list,char *first, char *last)
{
 Person *pExist = search(list,first, last);
        if(list->headWeightList==pExist){
                list->headWeightList=list->headWeightList->nextWeight;
                }
        for(Person *cur=list->headWeightList;cur!=NULL;cur=cur->nextWeight){
        if(cur->nextWeight==pExist){
                cur->nextWeight=cur->nextWeight ->nextWeight;
        break;
        }
}

	Person *pExist1 = search1(list,first, last);
	if(list->headHeightList==pExist1){
		list->headHeightList=list->headHeightList->nextHeight;
		return list;
		}
	for(Person *cur=list->headHeightList;cur!=NULL;cur=cur->nextHeight){
	if(cur->nextHeight==pExist1){
		cur->nextHeight=cur->nextHeight ->nextHeight;
		return list;
	}
}

return NULL;
}

PersonList *removePerson(PersonList *list, char *first, char *last) {
        Person *pExist =search1(list, first, last);
        if(pExist ==NULL)return list;
        return delet(list,first,last);
        
}


PersonList *updateHeight(PersonList *list, char *first, char *last, int height)
{ 
	for(Person *cur=list->headWeightList;cur!=NULL;cur=cur->nextWeight){
		if(strcmp(cur->first, first)==0 && strcmp(cur->last, last)==0){
		int weightNew = cur -> weight;
		removePerson(list,first,last);
		add(list,first,last,height,weightNew);
		}
	}
	return list;
}

PersonList *updateWeight(PersonList *list, char *first, char *last, int weight)
{
	for(Person *cur=list->headHeightList; cur !=NULL; cur=cur->nextHeight){
		if(strcmp(cur->first, first)==0 && strcmp(cur->last, last)==0){
			int heightnew=cur->height;
			removePerson(list,first,last);
			add(list,first,last,heightnew,weight);
		}
	}	 
    return list;
}
