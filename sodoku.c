/*
 ============================================================================
 Name        : sodoku.c
 Author      : Richard Friedman
 Version     :
 Copyright   : 
 Description :sodoku solver in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct list{
	struct node *data;
	struct list *prev;
	struct list *next;
};

struct node *L1,*L2,*L3;
struct list *B1;
int i = sizeof(L1);

int cnt;
int val;

void AddNode(struct node **head, int position, int value);
void PrintList(struct node ** head);
void FillZ(struct node ** head);
int CompareValue(int val, int pos, struct node **head);
void AddList(struct node **head, struct list **block);

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	L1=L2=L3=NULL;
	B1=NULL;
	for(cnt=1;cnt<=9;cnt++){
//		printf("\n Enter Value for Block A position %d:  ",cnt);
//		scanf("%d",&val);
//		printf("\n");
		AddNode(&L1,cnt,0);

	}FillZ(&L1);
	PrintList(&L1);
	AddList(&L1,&B1);

	i = sizeof(L1);
/*
	for(cnt=1;cnt<=9;cnt++){
		printf("\n Enter Value for Block A position %d:  ",cnt);
		scanf("%d",&val);
		printf("\n");
		AddNode(&L2,cnt,val);

	}
	PrintList(&L2);

	for(cnt=1;cnt<=9;cnt++){
		printf("\n Enter Value for Block A position %d:  ",cnt);
		scanf("%d",&val);
		printf("\n");
		AddNode(&L3,cnt,val);

	}
	PrintList(&L3);

*/
	free(L1);
	free(L2);
	free(L3);
	free(B1);
	return EXIT_SUCCESS;
}

void AddNode(struct node **head, int position, int value)
{
    int currentNodePosition=1;
    struct node *temp, *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));

    if(*head == NULL)
    {
        printf("\nList Empty.");
        position=1;
    }

    if(!newNode)
    {
        printf("\nError while allocating memory to new Node");
        return;
    }

    newNode->data = value;
    if(position==1)
    {
        printf("\nInserting node at the beginning of the list");
        newNode->next = *head;
        newNode->prev = NULL;
        //*head->prev = newNode;
        *head = newNode;
        return;
    }

    temp = *head;
    while((currentNodePosition<position-1)&& (temp->next!=NULL))
    {
        temp = temp->next;
        currentNodePosition++;
    }

    if(temp->next==NULL)
    {
        printf("\nInserting node at the last.");
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
    }
    else
    {
        printf("\nInserting node at position : %d",position);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        return;
    }
}

void AddList(struct node **head, struct list **block)
{

    struct node *temp, *newNode;
    struct list *temp2, *newList;
    int position;


    temp=*head;
    temp2=*block;
    if(*head == NULL || *block == NULL)
    {
        printf("\nList Empty.");
        position = 1;

    }



	newList = (struct list *)malloc(sizeof(struct list));

    if(!newList)
    {
        printf("\nError while allocating memory to new Node");
        return;
    }

    if(position==1)
       {
           printf("\nInserting node at the beginning of the list");
           newList->next = * block;
           newList->prev = NULL;
           //*head->prev = newNode;
           *block = newList;

       }

    temp2=*block;
    if(temp2->next==NULL)
    {
        printf("\nInserting node at the last.");
        newList->next = temp2->next;
        newList->prev = temp2;
        temp2->next = newList;
    }
    else
    {
        return;
    }
    int cnt = 1;
    temp2->data=NULL;
    struct node *print;
    print = temp;
    PrintList(&print);
    while(temp->next != NULL)
    {
    	AddNode(&temp2->data,cnt,temp->data);
    	cnt++;
    	temp=temp->next;
    	/*
    	newNode = (struct node *)malloc(sizeof(struct node));
    	newNode->data = temp->data;
    	newNode->next = temp2->data->next;
    	newNode->prev = temp2->data;
    	temp2->data->next=newNode;
    	*/
    }

}


void PrintList(struct node ** head)
{
    struct node *temp;
    temp = *head;
    if(temp == NULL)
    {
        printf("List is empty");
        return;
    }
    printf("\n");
    while(temp->next != NULL)
    {
        printf("%d <==>",temp->data);
        temp= temp->next;
    }

    printf("%d",temp->data);
    return;
}

void FillZ(struct node ** head)
{
    struct node *temp;
    temp = *head;
    int pos=1;
    if(temp == NULL)
    {
        printf("List is empty");
        return;
    }
    printf("\n");


    while(0==0)
    {
    	if(temp->data == 0){
			do{

				int num;
				srand(time(NULL));
				num = rand() % 9+1;
				temp->data = num;


			}while(CompareValue(temp->data,pos,&L1)>2);
			if(temp->next == NULL)
				break;
    	}
        printf("%d <==>",temp->data);
        temp= temp->next;
        pos++;

    }

    printf("%d",temp->data);
    return;
}

int CompareValue(int val, int pos, struct node **head)
{
	struct node *temp;
	int match_cnt = 0;
	temp = *head;
	int cnt =1;
	/*
	if(pos ==1 || pos == 2 || pos == 3)
		cnt =1;
	if(pos ==1 || pos == 2 || pos == 3)
		cnt =4;
	if(pos ==1 || pos == 2 || pos == 3)
		cnt =7;
*/
	int loop = 0;
	while(0 == 0)
	    {
		if(val == temp->data)
			match_cnt++;

		if(pos ==1 && (cnt == 1 || cnt == 2 || cnt ==3 || cnt ==4 || cnt == 7)){
			if(val == temp->data)
				match_cnt++;
		}
		if(pos ==2 && (cnt == 1 || cnt == 2 || cnt ==3 || cnt ==5 || cnt == 8)){
			if(val == temp->data)
				match_cnt++;
		}

		if(pos ==3 && (cnt == 1 || cnt == 2 || cnt ==3 || cnt ==6 || cnt == 9)){
			if(val == temp->data)
				match_cnt++;
		}

		if(pos ==4 && (cnt == 4 || cnt == 5 || cnt ==6 || cnt ==1 || cnt == 7)){
			if(val == temp->data)
				match_cnt++;
		}

		if(pos ==5 && (cnt == 4 || cnt == 5 || cnt ==6 || cnt ==2 || cnt == 8)){
			if(val == temp->data)
				match_cnt++;
		}

		if(pos ==6 && (cnt == 4 || cnt == 5 || cnt ==6 || cnt ==3 || cnt == 9)){
			if(val == temp->data)
				match_cnt++;
		}

		if(pos ==7 && (cnt == 7 || cnt == 8 || cnt ==9 || cnt ==1 || cnt == 4)){
			if(val == temp->data)
				match_cnt++;
		}

		if(pos ==8 && (cnt == 7 || cnt == 8 || cnt ==9 || cnt ==5 || cnt == 2)){
			if(val == temp->data)
				match_cnt++;
		}

		if(pos ==9 && (cnt == 7 || cnt == 8 || cnt ==9 || cnt ==3 || cnt == 9)){
			if(val == temp->data)
				match_cnt++;
		}



		    temp= temp->next;
	        cnt ++;
	        if(loop == 0 && temp->next == NULL)
	        {
	        	loop=1;
	        }else if(loop == 0)
	        {
	        	continue;
	        }else
	        {
	        	break;
	        }

	    }

	return match_cnt;

}
