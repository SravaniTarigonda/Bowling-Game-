/********************************************
 * *FILENAME	      : maintain_database_function.c
 *
 * *DESCRITION        : This file defines the functions that uses bowler ID to 
 * 	                perform various operations of the Bolwer database.
 *
 *
 * Revision History   :	       
 *
 * 	Date			Name			Reason
 *
 * 27th Aug 2022		----			-----
 *
 *
*********************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include "structure.h"

//all the other header files
/********************************************
 * *FUNCTION NAME : add_bowler 
 *
 * *DESCRIPTION   : This function add the bowler information by taking data as input from the 
 *		    user with respective validations.
 *
 * *RETURNS       : No Returns
 *
 *
 *
 *
*********************************************/

int add_bowler()
{ //Add the bowler function 
	bd *new, *ptr, *prev;
        int true = 1;      
        int i = 0;	
        
	system("clear");
	new=(bd *)calloc(1,sizeof(bd));
	printf("\n---------------Add the Bowler information here---------\n");
	printf(" \n ");
	while(true)
	{  // validation for bowler id starts from here
	char check_id[SIZE];
	//char check;
		int flag =0;
		printf("Enter a new bowler id \n");
		(void)scanf("%s",check_id);
		if(strlen(check_id) > MAX)
		{
		  printf("Bowler id should be less than 15 digits\n");	
		  continue;
		}
		for(i=0;check_id[i]!='\0';i++)
		{
			if(!isdigit(check_id[i]))
			{
				flag=1;
			
			}
		}
		if(flag==1)
		{
		printf("Bowler id should be an integer value    \n");
			continue;
		}
			
		new->bowler_id = atoi(check_id);
		for(ptr=(start);(ptr != NULL);ptr=ptr->next)
		{
			if(ptr->bowler_id == new->bowler_id)
			{
				printf("This bowler id  already exists! Try another one\n");
				flag = 1;
				break;
			}
			
		}
		if(flag == 1)
		{
		   continue;
		}
		else
		{
		    break;
		}
	break;
	
	}

	while(1)
	{  // validation for bowler name starts from here
		printf("\nEnter the Bowler name: \n");
		(void)scanf("%s",new->bowler_name);
		int length = strlen(new->bowler_name);
                if(length>15)
		{
		  printf("Bowler name should have less than 15 characters\n");
		  continue;
		}
		if(length==0)
		{ 
			printf("Bowler name field should not be empty!\n");
			continue;
		}
			int flag = 0;
		for(i=0;i<length;i++)
		{
			if(!isalpha(new->bowler_name[i]))
			{
				flag = 1;
				break;
			}	
		}
		        if(flag == 1)
			{	
				printf("Enter alphabets only\n");
			  	continue;
			}
			else
			{
				break;
			}
		break;
	      
	}


	while(1)
	{	// validation for bowler year of experience starts from here
		char check_exp[SIZE];
                int flag = 0;
		printf("\nEnter the Bowler_experience(in years)  \n");
		(void)scanf("%s",check_exp);
		if(strlen(check_exp) > MAX)
		{
		  continue;
		}
		for(i=0;check_exp[i]!='\0';i++)
		{
			if(!isdigit(check_exp[i]))
			{
				flag=1;
			
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an integer value\n");
			continue;
		}
			
		new->bowler_experience = atoi(check_exp);
		break;
	}

	while(1)
	{  // validation for no of tournaments won by the bowler starts from here
		char check_win[SIZE];
		printf("\nEnter the number of tournament won  \n");
		(void)scanf("%s",check_win);
	        if(strlen(check_win) > MAX)
		{
		  continue;
		}
		int flag=0;
		for(i=0;check_win[i]!='\0';i++)
		{
			if(!isdigit(check_win[i]))
			{
				flag=1;
			
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an integer value\n");
			continue;
		}
			
		new->no_of_tournaments_won = atoi(check_win);
		break;
	}

	if(!start)
	{
		start = new;
		new->next=NULL;
	}
	else if(new->bowler_id < start->bowler_id)
	{
		new->next = start;
		start = new;
	}
	else
	{
		for(ptr=start; (ptr != NULL) && (ptr->bowler_id < new->bowler_id); prev = ptr, ptr = ptr->next);
		
			prev->next=new;
			new->next = ptr;
		
	}


return(1);
} //The add to bowler function ends here


/********************************************
 * *FUNCTION NAME : edit_information 
 *
 * *DESCRIPTION   : This function edit the bowler information by taking bowler id as an 
 * 		    input from the user with respective validations.
 *
 * *RETURNS       : No Returns
 *
 *
 *
*********************************************/

int edit_information()
{						 //Edit function starts here--
	bd *new, *ptr, *prev;
        int i =0;

	system("clear");
	if(!(start))
	{
		printf("\nNo record to edit\n");
		return (0);
	}
	printf("\n------Edit information of the player------\n");
	int check_id;
	while(1)
	{
		int flag=0;
	char id[SIZE];
	printf("\nEnter the bowler id: \n");
	(void)scanf("%s",id);
		for(i=0;id[i]!='\0';i++)
		{
			if(!isdigit(id[i]))
			{
				flag=1;
			
			}
		}
		if(flag==1)
		{
			printf("This field should have an integer value\n");
			continue;
		}
		else
		{
			check_id = atoi(id);
			break;
		}
		break;
	}

	for(ptr=(start);(ptr != NULL) && (ptr->bowler_id!=check_id);ptr=ptr->next);
	if(ptr==NULL)
	{
		printf("No such id exists\n");
		return(0);
	}
	while(1)
	{
		char check_name[SIZE];
		printf("Enter the name of the bowler enter N to skip\n");
		(void)scanf("%s",check_name);
		if(strlen(check_name) > MAX)
		{
		  continue;
		}
		int flag = 0;
		int length = strlen(check_name);
		for(i=0;i<length;i++)
		{
			if(!isalpha(check_name[i]))
			{
				flag = 1;
				break;
			}	
		}
	        if(flag == 1)
			{	
				printf("Enter alphabets only\n");
			  	continue;
			}
		else
		{
		if((strcmp(check_name,"N"))!=0)
		{
			strcpy(ptr->bowler_name,check_name);
		}
		break;
		}
		break;
	}
	while(1)
	{
		char check_win[SIZE];
		printf("Enter the number of tournaments won\n");
		(void)scanf("%s",check_win);
		if(strlen(check_win) > MAX)
		{
		  continue;
		}
		int flag=0;
		for(i=0;check_win[i]!='\0';i++)
		{
			if(!isdigit(check_win[i]))
			{
				flag=1;
			
			}
		}
		if(flag==1)
		{
			printf("This field should have an integer value\n");
			continue;
		}
			
		ptr->no_of_tournaments_won = atoi(check_win);
		break;
	}
	while(1)
	{
		char check_exp[SIZE];
		printf("Enter bowler experience (in years)\n Enter N if there is no change\n");
		(void)scanf("%s",check_exp);
 		if(strlen(check_exp) > MAX)
		{
		  continue;
		}
		int flag=0;
		if(strcmp(check_exp,"N")==0)
		{ //if there is no change skip this 
			break;
		}
		for(i=0;check_exp[i]!='\0';i++)
		{
			if(!isdigit(check_exp[i]))
			{
				flag=1;
			
			}
		}
		if(flag==1)
		{
			printf("This field should have an integer value\n");
			continue;
		}
			
	 	ptr->bowler_experience = atoi(check_exp);
		break;
	}
return(1);
} //The edit function ends here

/********************************************
 * *FUNCTION NAME : delete_bolwer 
 *
 * *DESCRIPTION   : This function delete the bowler data from database by taking 
 * 		    bowler id as an input from the user
 *
 * *RETURNS       : No Returns
 *
 *
 *
*********************************************/

int delete_bowler()
{					 //Delete function starts here
	bd *ptr, *prev;
	int i;

	system("clear");
	if(!(start))
	{
		printf("\nNothing to delete here!\n");
		return (0);
	}
	int delete_id;
	printf("\n------Deleting the player information-----\n");
	while(1)
	{
		int flag=0;
	char id[SIZE];
	printf("\nEnter the bowler id: \n");
	(void)scanf("%s",id);
		for(i=0;id[i]!='\0';i++)
		{
			if(!isdigit(id[i]))
			{
				flag=1;
			
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an integer value\n");
			continue;
		}
		else
		{
			delete_id = atoi(id);
			break;
		}
		break;
	}	
	if(delete_id==(start)->bowler_id)
	{
		ptr=(start);
		(start)=(start)->next;          //Moving start from first to second node and then free the ptr
		printf("bowler id %d deleted successfully\n",delete_id);
		free(ptr);
	}
	else
	{
		for(ptr=(start);(ptr!=NULL) && (ptr->bowler_id!=delete_id);prev=ptr,ptr=ptr->next);
		if(ptr==NULL)
		{
			printf("\nNo such record found\n");
			return(0);
		}
		prev->next=ptr->next;
		printf("bowler id %d deleted successfully\n",delete_id);

		free(ptr); 
	}


return(1);
}			 //Delete function ends here

/********************************************
 * *FUNCTION NAME : view_bowler 
 *
 * *DESCRIPTION   : This function view the bowler information by taking bowler id 
 * 		    as an input from the user and show the bowler details.
 *
 * *RETURNS       : No Returns
 *
 *
 *
*********************************************/

int view_bowler_information()
{			
	bd *ptr;

	system("clear");
	if(!start)
	{
		printf("\nNo record to show\n");
		return(0);
	}
	int i;
	int show_id;
	printf("\n--------View the information of a player---------\n");
	while(1)
	{
		int flag=0;
	char id[SIZE];
	printf("\nEnter the bowler id: \n");
	(void)scanf("%s",id);
		for(i=0;id[i]!='\0';i++)
		{
			if(!isdigit(id[i]))
			{
				flag=1;
			
			}
		}
		if(flag==1)
		{
			printf("\nThis field should have an integer value\n");
			continue;
		}
		else
		{
			show_id = atoi(id);
			break;
		}
		break;
	}	
	for(ptr=(start);(ptr != NULL) && (ptr->bowler_id!=show_id);ptr=ptr->next);
	if(ptr==NULL)
	{
		printf("\nNo such bowler id found\n");
		return(0);
	}
	printf("\nBowler id: %d\n",ptr->bowler_id);
	printf("\nBowler name: %s\n",ptr->bowler_name);
	printf("\nYear of experience: %d\n",ptr->bowler_experience);
	printf("\nNumber of tournament won: %d\n",ptr->no_of_tournaments_won);
return(1);
}
