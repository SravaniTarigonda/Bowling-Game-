/********************************************
 * *FILENAME	      : Bowling_file_handling.c
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
 * *FUNCTION NAME : bowling_to_list 
 *
 * *DESCRIPTION   : This function allocate memory for the bowling to open and read the file 
 * 		    from beginning till end of file and put each bowling data into the list.
 *
 * *RETURNS       : No Returns 
 *
 *
 *
*********************************************/


int bowling_to_list()
{
	FILE *fp1;
        if((fp1=fopen("bowling","rb"))==NULL)
	{
	//	printf("Can't open bowling file\n");
		return(0);
	}
	bd1 *last1,*new1,*ptr1;
	if((new1=(bd1 *)calloc(1,sizeof(bd1)))==NULL)
	{
	   printf("Memory allocation failed\n");
	   return(0);
	}
	fread(new1,sizeof(bd1),1,fp1);
	while(!feof(fp1))
	{
		if(start1 == NULL)
		{
			start1=last1=new1;
			new1->next=NULL;
		}
		else
		{
			last1->next=new1;
			last1=new1;
			new1->next=NULL;
		}
	
		if((new1=(bd1 *)calloc(1,sizeof(bd1)))==NULL)
		{
			printf("Memory allocation failed\n");
			return(0);
		}

		fread(new1,sizeof(bd1),1,fp1);

	}
	free(new1);
	fclose(fp1);
}


/********************************************
 * *FUNCTION NAME : list_to_bowling 
 *
 * *DESCRIPTION   : This function is used to write bowling data into the file
 * 		    by traversing the list.
 *
 * *RETURNS       : No Returns
 *
 *
 *
*********************************************/

int list_to_bowling()
{

	FILE *fp1;
	bd1 *ptr1;
	if((fp1=fopen("bowling","wb"))==NULL)
	{
		printf("Can't open bowling file");// optional
	        return (0);
	}
	

	for(ptr1=(start1);(ptr1);ptr1=ptr1->next)
	{
		fwrite(ptr1,sizeof(bd1),1,fp1);
	}
	fclose(fp1);
	free(ptr1);

}
