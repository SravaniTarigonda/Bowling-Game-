/********************************************
 * *FILENAME	      : Bowler_file_handling.c
 *
 * *DESCRITION        : This file defines the functions opens the file and return address
 * 			of file and stored in file type pointer.
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


#include "structure.h" 
#include <stdio.h>
#include <stdlib.h>

/********************************************
 * *FUNCTION NAME : bowler_to_list 
 *
 * *DESCRIPTION   : This function allocate memory for the bowler to open and read the file 
 * 		    from beginning till end of file and put each bowler into the list.
 *
 * *RETURNS       : No Returns 
 *
 *
 *
*********************************************/


int bowler_to_list()
{
	bd *last,*new,*ptr;
	FILE *fp;
	if((fp=fopen("bowler","rb"))==NULL)
	{
		//printf("Can't open bowler file\n");
		return(0);
	}

	if((new=(bd *)calloc(1,sizeof(bd)))==NULL)
	{
	   printf("Memory allocation failed\n");
	   return(0);
	}
	fread(new,sizeof(bd),1,fp);
	while(!feof(fp))
	{
		if(start == NULL)
		{
			start=last=new;
			new->next=NULL;
		}
		else
		{
			last->next=new;
			last=new;
			new->next=NULL;
		}
		if((new=(bd *)calloc(1,sizeof(bd)))==NULL)
		{
			printf("Memory allocation failed\n");
			return(0);
		}

		fread(new,sizeof(bd),1,fp);
	}
	free(new);
	fclose(fp);
}


/********************************************
 * *FUNCTION NAME : list_to_bowler 
 *
 * *DESCRIPTION   : This function is used to write bowler data into the file
 * 		    by traversing the list.
 *
 * *RETURNS       : No Returns
 *
 *
 *
*********************************************/

int list_to_bowler()
{
	bd *ptr;

	FILE *fp;
	if((fp=fopen("bowler","wb"))==NULL)
	{
		printf("Can't open bowler file"); // optional
		return(0);
	}

	for(ptr=(start);(ptr);ptr=ptr->next)
	{
		fwrite(ptr,sizeof(bd),1,fp);
	}
	fclose(fp);
	free(ptr);
}



