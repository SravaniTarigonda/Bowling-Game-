/*********************************************************
 * * FILENAME    : show_report.c
 *
 * * DESCRIPTION : This file defines the function that would be used by the program to 
 * 		   generate various reports about the Bowler & Bowling details using the database.
 *
 *
 * Revision History:
 * 
 *	 Date 				NAME 					Reason
 *
 * 25th Aug 2022        	Shyam Goli and Chandan Kashyap		         ---
 *
 *    
 ********************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "structure.h"



/********************************************************
 *FUNCTION NAME  : Bowler_data_sheet
 *
 *DESCRIPTION    : This function takes the user id as an input from the user and displays the
                   details of the user present inside the database.
 *
 *
 *RETURNS        :  ID           - returns id of the player
 *		    NAME         - returns name of the player	           
 *		    EXPERIENCE   - returns the experience of the player
 * 	 	    NO OF TOURNAMENTS WON - returns the total number of tournaments won by the player
 * 		    FRAME NUMBER - returns the frame number of the game
 * 		    BALL         - returns the current ball of the frame
 *                  FRAME SCORE  - returns the score of current frame
 *                  TOTAL SCORE  - returns the total score of the tournament
 *
 *
 *******************************************************/


int Bowler_data_sheet()
{
  bd *ptr; 	
  int i = 0;
  int bowler_id = 0;
  while(1)
  {
	  char check_id[SIZE];	
	  int flag = 0;
	  printf("Enter the bowler id:\n");
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

	  bowler_id = atoi(check_id);
          break;
  }

  if(!start)
  {
    printf("No player data present\n");
    return(0);
  }
  else
  {
    for(ptr=start; (ptr != NULL) && (ptr->bowler_id != bowler_id); ptr=ptr->next);
    if(ptr == NULL)
    {
       printf("%d bowler id not found\n\n",bowler_id);
       return(0);
    }
    system("clear");
    printf("\n*******************************************************************************************************************\n");
  printf("\n******************************************  Bowler Data  ************************************\n");
printf("\n*******************************************************************************************************************\n");


    printf("bowler id : %d\nbowler_name : %s\nbowler_experience : %d\nno_of_tournaments_won : %d\n",ptr->bowler_id,ptr->bowler_name,ptr->bowler_experience,ptr->no_of_tournaments_won);
  }
  
 
  bd1 *ptr1;
  if(!start1)
  {
    printf("No player data present\n");
    return(0);
  }
  else
  {
    for(ptr1=start1; (ptr1 != NULL) && (ptr1->bowler_id != bowler_id); ptr1=ptr1->next);
    if(ptr1 == NULL)
    {
       printf("\nbowler id %d not played any tournament.\n",bowler_id);
       printf("\n******************************************************************************************\n");
       return(0);

    }
    
    if(ptr1->current_tournament == 0)
    {
	    printf("********************************** Bowler not participated in current tournament   ***********************\n");
    printf("****************************** Scores of the previous tournament played ***************************\n");
    }
    else
    {
     printf("************************************** Bowler Participated in current tournament **********************************\n");
     printf("**************************************  Scores from the current tournament played  ********************************\n");
    }
    printf("Total_strikes : %d\nTotal_spares : %d\ntotal score : %d\n",ptr1->no_of_strikes,ptr1->no_of_spares,ptr1->total_score);
    printf("Scores for each frame : [ ");
    for(i = 0; i< 9; i++)
    {
      printf("%d, ",ptr1->frame_and_cumulative_score[0][i]);
    }
    printf("%d ]\n",ptr1->frame_and_cumulative_score[0][9]);

     printf("Cumulative Score : [ ");
    for(i = 0; i< 9; i++)
    {
      printf("%d, ",ptr1->frame_and_cumulative_score[1][i]);
    }
    printf("%d ]\n",ptr1->frame_and_cumulative_score[1][9]);
    printf("\n\n**********************************************************************************************\n");
    system("read n");
    system("clear");
  }
   return(1);  
}


/********************************************************
 *FUNCTION NAME : Bowling_day_report
 *
 *DESCRIPTION   : This function displays the overall details of the tournament 
                  including all players playing on that day.
 *
 *
 *RETURNS       :  ID    - returns id of the player
 * 		   FRAME NUMBER - returns the frame number of the game
 * 		   BALL - returns the current ball of the frame
 *                 FRAME SCORE -  returns the score of current frame
 *                 TOTAL SCORE -  returns the total score of the tournament
 *
 *
 *******************************************************/


int Bowling_day_report()
{
        bd1 *ptr1;
	int i = 0;
	if(!start1)
	{
		printf("Database is empty\n");
		return(0);
	}
	else
	{
                (void)system("clear");
		printf("**********************************************************************************\n");
		printf("*************************************   Bowling day report   *********************\n ");
		printf("**********************************************************************************\n");
		printf(" Bowler id \t Total Strikes \t Total Spares \t Total Score \t Scores for each frame \n");
		for(ptr1=start1; (ptr1); ptr1=ptr1->next)
		{     	 
			if(ptr1->current_tournament == 1)
			{
				printf("%11d %14d %13d %12d   [",ptr1->bowler_id,ptr1->no_of_strikes,ptr1->no_of_spares,ptr1->total_score);
				for(i = 0; i< 9; i++)
				{
					printf("%d, ",ptr1->frame_and_cumulative_score[0][i]);
				}
				printf("%d ]\n",ptr1->frame_and_cumulative_score[0][9]);
			}
		}
		printf("***********************************************************************************\n");
		(void)system("read n");
		(void)system("clear");
	}

        return(1);
}







