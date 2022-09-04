/********************************************
 * *FILENAME	      : play_the_game_function.c
 *
 * *DESCRITION        : This file defines the function that would be used by the program to 
 * 			generates various scores details when bowler play the game. 
 * 	    
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


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structure.h"
#define FRAME_NUMBER 10

static int random_num()
{
	int num = (rand()%(10-0+1))+0;
	return num;
}


int strike_condition(int balls, int current_score)
{
	if(balls == 1 && current_score == 10)
        {
	    return 1;
	} 
	else
	{
	    return 0;
	}
}

int spare_condition(int current_score, int previous_ball)
{
	if((current_score + previous_ball) == 10)
	{
	    return 1;
	}
	else
	{
	    return 0;
	}
}

int extra_balls(int balls)
{
  if(balls == 1)
  {
    return 2;
  }
  else
  {
    return 1;
  }
}


/******************************************************
 * *FUNCTION NAME : play_the_game_function 
 *
 * *DESCRIPTION   : This function perform various operations when bowler plays the game
 * 		    and displays the scores with FRAME NUMBER.
 *		  
 * *RETURNS       : STRIKE - returns Ball No. and Current score
 *		    SPARE  - returns Ball No. and Current score
 *		    extra_balls - returns extra ball no. and current score
 *		    total_score - returns total score of the game 
 *		    total_strike- returns total strike of the game
 *		    total_spare - returns total spare of the game 
 *
********************************************************/


int play_the_game_function(int bowler_id)
{
	int frame_number, balls, total_score = 0, current_score = 0;
	int cumulative_score[FRAME_NUMBER]={0,0,0,0,0,0,0,0,0,0};
	int strike[FRAME_NUMBER] = {0,0,0,0,0,0,0,0,0,0};

	int total_strikes = 0;
	int total_spares = 0;
	srand((unsigned)time(0));
	int j = 0,i= 0;
       
        system("clear");
	printf("**********************************   GAME STARTED   ***************************************\n\n");
	printf("\nPlayer %d id playing the game\n\n",bowler_id);
	for(frame_number = 1; frame_number<=10; frame_number++)
	{
		printf("****************** FRAME NUMBER: %d ********************\n",frame_number);
		for(balls = 1; balls <= 2; balls++)
		{
			current_score = random_num();
			if(strike_condition(balls,current_score) == 1)
			{
				printf("Ball No. %d : Current score was: %d\n",balls, current_score);
				total_strikes++;
				printf("IT IS A STRIKE\n");
				strike[frame_number-1] = 2;
				cumulative_score[frame_number-1]+=current_score;
				for(j=0;j<frame_number-1;j++)
				{
					if(strike[j]>0)
					{
						strike[j]--;
						cumulative_score[j]+=current_score;
					}
				}
				break;
			}

			if(balls == 2)
			{
		
				while(current_score+cumulative_score[frame_number-1]>10)
				{
					current_score = random_num();
				}
				if(spare_condition(current_score, cumulative_score[frame_number-1]) == 1) 
				{
					strike[frame_number-1] = 1;
					cumulative_score[frame_number-1]+=current_score;
					printf("Ball No. %d: Current score was: %d\n", balls, current_score);
					total_spares++;
					printf("IT IS A SPARE\n");
					for(j=0;j<frame_number-1;j++)
					{
						if(strike[j]>0)
						{
							strike[j]--;
							cumulative_score[j]+=current_score;
						}
					}
					break;
				}
			}
			for(j=0;j<frame_number-1;j++)
			{
				if(strike[j]>0)
				{
					strike[j]--;
					cumulative_score[j]+=current_score;
				}
			}
			printf("Ball No. %d: Current score was: %d\n", balls, current_score);
		
			cumulative_score[frame_number-1] += current_score;
		}
if(frame_number == 10 && ((balls == 1 && current_score == 10) || (balls == 2 && cumulative_score[frame_number-1] == 10)))
		{
			int extras = extra_balls(balls);
			for(balls=1; balls<=extras; balls++)
			{
				current_score = random_num();
				cumulative_score[frame_number-1]+=current_score;
				for(j=0; j<frame_number-1; j++)
				{
					if(strike[j]>0)
					{
						strike[j]--;
						cumulative_score[frame_number-1] += current_score;
					}
				}
				printf("Extra Ball no : %d, Current score was: %d\n",balls,current_score);
			}
		}


	

		printf("Current score for the frame: %d\n", cumulative_score[frame_number-1]);
		printf("\n");
	}
	for(j=0; j<10; j++)
	{
		printf("%d Frame score: %d\n",j+1,cumulative_score[j]);
		total_score += cumulative_score[j];
	}
	printf("The total score of the game is %d\n",total_score);
        printf("Total strikes of the game is %d\n", total_strikes);
	printf("Total spares of the game is %d\n", total_spares);

         

       
	bd1 *new1, *ptr1, *prev1;
         int flag_won = 1;
	 for(ptr1=start1;(ptr1);ptr1 = ptr1->next)
	 {
		 if(ptr1->current_tournament == 1)
		 {		  
			 if(total_score < ptr1->total_score)
			 {
				 printf("\nNot won the tournament\n");
				 flag_won = 0;
				 break;
			 }
		 }
	 }

	 if(flag_won == 1)
	 {
	   printf("\n\n******CONGRATULATION YOU WON THE TOURNAMENT******\n\n");

	   bd *ptr;
	   for(ptr=start; (ptr->bowler_id != bowler_id); ptr=ptr->next);
	   ptr->no_of_tournaments_won += 1;
	   printf("Total number of tournaments you won till now is %d\n\n",ptr->no_of_tournaments_won);
	 }


          if((new1 = (bd1 *) calloc (1,sizeof(bd1)))==NULL)
	  {
	     printf("Memory allocation failed\n");
	     return(0);
	  }
 
	  new1->bowler_id = bowler_id;
	  new1->no_of_strikes = total_strikes;
	  new1->no_of_spares = total_spares;
	  new1->total_score = total_score;

	  for(i = 0; i<10; i++)
	  {
	     new1->frame_and_cumulative_score[0][i] = cumulative_score[i];
	     if(i==0)
	     {
	         new1->frame_and_cumulative_score[1][i] = cumulative_score[i]; 
	     }
	     else
	     {
	       new1->frame_and_cumulative_score[1][i] =  new1->frame_and_cumulative_score[1][i-1] + cumulative_score[i];  
	     }
	  }
	  new1->current_tournament=1;
 
	 for(ptr1=start1;(ptr1 != NULL) && (ptr1->bowler_id != new1->bowler_id);  ptr1 = ptr1->next);
	 if(ptr1)
	 {
		 ptr1->bowler_id = new1->bowler_id;
		 ptr1->no_of_strikes = new1->no_of_strikes;
		 ptr1->no_of_spares = new1->no_of_spares;
		 ptr1->total_score = new1->total_score;
		 for(i= 0;i<10; i++)
		 {
			  ptr1->frame_and_cumulative_score[0][i] = new1->frame_and_cumulative_score[0][i];
			  ptr1->frame_and_cumulative_score[1][i] = new1->frame_and_cumulative_score[1][i];  
		 }
		 ptr1->current_tournament= new1->current_tournament;

	 }
	 else
	 {
		 if(start1==NULL)
		 {
			 start1 = new1;
			 new1->next=NULL;
		 }

		 else if(new1->bowler_id < start1->bowler_id)
		 {
			 new1->next = start1;
			 start1 = new1;
		 }
		 else
		 {

			 for(ptr1=start1; (ptr1 != NULL) && (ptr1->bowler_id <= new1->bowler_id); prev1 = ptr1, ptr1 = ptr1->next);

			 prev1->next=new1;
			 new1->next = ptr1;

		 }


	 }

      system("read n");
      system("clear");
	  
	return 0;
}
