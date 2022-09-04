/********************************************
 * *FILENAME	      : main.c
 *
 * *DESCRIPTION        : This file defines the functions that consists of various subfunctions 
 * 			to perform certain operations. 
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
#include<stdlib.h>
#include "structure.h"

#include "bowler_file_handling.c"
#include "bowling_file_handling.c"
#include "play_the_game_function.c"
#include "show_report.c"
#include "maintain_database_function.c"  
#include <pthread.h>


/********************************************************
 * *FUNCTION NAME : main 
 *
 * *DESCRIPTION   : This function calls the other functions to performs various 
 * 		    operations by taking choice option from the user. 
 *
 * *RETURNS       : maintain_database function
 *		    play_the_game function
 *                  show_report function
 *                  exit - exit the main function
 *
********************************************************/

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int main()
{
	pthread_t thread_id;

	start = NULL;
	start1 = NULL;
	int choice=0;
	bowler_to_list();
	bowling_to_list();
	make_current_tournament_zero();
	
	while(choice!=4)
	{
		system("clear");
		printf("-------The Bowling Game Begins---------\n");
		printf("1. Maintain Bowler Database\n2.Play the game\n3.Show Report\n4.Exit\n");
		printf("Enter Your Choice: \n");
		(void)scanf("%d",&choice);
		switch(choice)
		{
			case 1: maintain_database();
				break;
			case 2: pthread_create(&thread_id,NULL,play_the_game,NULL);
	    			pthread_join(thread_id,NULL);

			       //	play_the_game();
	
				break; //play the game function here

			case 3:show_reports();
			       break;
			case 4:break;
			default: printf("Invalid Choice!\n"); 
		}
	}
	if(start)
	{
	list_to_bowler();
	}
	if(start1)
	{
	list_to_bowling();
	}
	//pthread_mutex_destroy(&lock);
	return 0;
}

/********************************************************
 * *FUNCTION NAME : maintain_database 
 *
 * *DESCRIPTION   : This function is used to performs various operations of bowler
 * 		    database by taking choice option from the user.
 *
 * *RETURNS       : add_bowler    - adding bowler data
 * 		    edit_bowler   - editing bowler data
 * 		    delete_bolwer - deleting bowler data
 *		    view_bowler_information - view bowler data
 *
 *
********************************************************/

int maintain_database()
{
	int choice1 = 0;
        system("clear");
	while(choice1!=5)
	{
		printf("1.Add Bowler\n2.Edit Bowler information\n3.Delete Bowler information\n4.View Bowler information\n5.Back to the main Menu\n");
		(void)scanf("%d",&choice1);
		switch(choice1)
		{
			case 1: add_bowler();
				break;//create/add function here
			case 2: edit_information();
				break; // editing option here
			case 3: delete_bowler();
				break; //Delete function here
			case 4: view_bowler_information();
				break; //View function here
			case 5: 
				return 1;
			default: printf("Invalid Choice!\n\n");
		}
		(void)system("read a");
		(void)system("clear");
	}
	return(0);
}

/********************************************************
 * *FUNCTION NAME :  show_reports 
 *
 * *DESCRIPTION   : This function is used to performs various operations of bowler
 * 		    datasheet and bowling day report by taking choice option from the user.
 *
 * *RETURNS       : Bowler_data_sheet  - shows bowler datasheet Report
 * 		    Bowling_day_report - shows bowling day report
 *
 *
********************************************************/

int show_reports()
{
	int choice2 = 0;
	system("clear");
	while(choice2!=3)
	{
		printf("1.Show Bowler data sheet\n2.Show Bowling day report\n3.Back to the main Menu\n");
		(void)scanf("%d",&choice2);
		switch(choice2)
		{
			case 1: Bowler_data_sheet(); 
				break; //Bowler_data_sheet report
			case 2: Bowling_day_report();
			       	break; //Bowling day report
			case 3: 	system("read n");
				system("clear");
			       return 1; //Back to the main menu
			default: printf("Invalid Choice!\n\n");
		}

	}

		return 0;
}


/********************************************************
 * *FUNCTION NAME : play_the_game
 *
 * *DESCRIPTION   : This function is used to perform play the game function 
 * 		    by taking player id from the user.
 * 
 * *RETURNS       : No returns 
 *
 *
********************************************************/

int play_the_game()
{

	char player_id[SIZE];
	bd *ptr;
	int id;
	int i = 0;
        int wish_to_add_option = 0;	
	while(1)
	{
		printf("Enter the player id: \n");
		(void)scanf("%s",player_id); // validation should be done
		int check=0;
		if(strlen(player_id)>MAX)
		{
		  continue;
		}
		for(i=0;player_id[i]!='\0';i++)
		{
			if(!isdigit(player_id[i]))
			{
				check=1;
			}
		}
		if(check==1)
		{
		        printf("Player id should be an integer\n");
			continue;
		}
		break;
	}
	id = atoi(player_id);
	for(ptr=start;(ptr != NULL) && (ptr->bowler_id !=id);ptr=ptr->next);
        if(!ptr)
	{
	   printf("Player id not found\n");		
	   printf("Do you wish to add the player id? \npress 1 for yes else any other number\n");
	   (void)scanf("%d",&wish_to_add_option);
		if(wish_to_add_option != 1)
		{
			return(1);
			}
		else
		{
		add_bowler();
		play_the_game();
		}

	}
	else
	{
	   pthread_mutex_lock(&lock);
	   

	   play_the_game_function(id);
	   pthread_mutex_unlock(&lock);
	}	
        
	return (1);
}


int make_current_tournament_zero()
{
  bd1 *ptr1;
  for(ptr1 = start1;(ptr1);ptr1=ptr1->next)
  {
    ptr1->current_tournament = 0;
  }
}


