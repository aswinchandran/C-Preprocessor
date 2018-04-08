
/******************************************************************************
**+-------------------------------------------------------------------------+**
**|                                 *******                                 |**
**|                                *********                                |**
**|                               ****   ****                               |**
**|                              **** *** ****                              |**
**|                             **** ***** ****                             |**
**|                            ****         ****                            |**
**|                           ****           ****                           |**
**|                                                                         |**
**|     Copyright (c) 2014 - 2018 Aswin Chadran                             |**
**|     Author: Aswin Chandran                                              |**
**|     Author details: https://github.com/aswinchandran                    |**
**|     Contact details: https://www.linkedin.com/in/aswin-chandran/        |**
**|                                                                         |**
**| This program is free software: you can redistribute it and/or modify    |**
**| it under the terms of the GNU General Public License as published by    |**
**| the Free Software Foundation, either version 3 of the License, or       |**
**| (at your option) any later version.                                     |**
**|                                                                         |**
**| This program is distributed in the hope that it will be useful,         |**
**| but WITHOUT ANY WARRANTY; without even the implied warranty of          |**
**| MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           |**
**| GNU General Public License for more details.                            |**
**|                                                                         |**
**| You should have received a copy of the GNU General Public License       |**
**| along with this program.  If not, see <https://www.gnu.org/licenses/>   |**
**|                                                                         |**
**+-------------------------------------------------------------------------+**
******************************************************************************/
/**===========================================================================
  
	\file	: main.c
	\Author	: Aswin chandran
	\Date	: 28/01/2014
	\brief	: 
	\see	: 
  ==========================================================================*/

#include"header.h"
	//the prgm contain 4 parts main,comment,macro,header

int main(int argc,char *argv[])		//filename passed as arg
{
	int x;
	FILE *fpr;			
	FILE *fp1;
	FILE *fp2;
	FILE *fp22;
	FILE *fp3;

	char prg[20];
	

	if(argc<2)				//exit if filename not entered
	{
		printf("\t__invalid entry__please enter properly__\n");
		exit(0);
	}
	strcpy(prg,argv[1]);			//copy arg to prg
	fpr=fopen(argv[1],"r");
	if(fpr==NULL)
	{
		printf("\tfile can't open!!!\n");
		exit(0);
	}


	printf("===========================================================================================\n");
	printf("---------------------------PREPROCESSING IS STARTED----------------------------------\n");
	printf("===========================================================================================\n");
	fp1=fopen("new1","w");		//comment function remove comments in the prg and write to file new1
	comment(fpr,fp1);
	printf("============================COMMENTS SUCCESSFULLY REMOVED===================================\n");
	fp2=fopen("new1","r");
	fp3=fopen("new3","w");
	macro(fp2,fp3);	
		//function for macro substitution
	//fclose(fp3);
	printf("============================MACROS SUCCESSFULLY SUBSTITUTED=================================\n");
	headn();		//include header file present in the prg file
	printf("===========================HEADER FILES SUCCESSFULLY INCLUDED===============================\n");

	printf("===============================PREPROCESSING FINISHED========================================\n");
	printf("----------------------------------------------------------------------------------------------\n");


	while(1)
	{
	printf("ENTER    		1:COMMENT REMOVED PROGRAM\n			2:MACRO SUBSTITUTED PROGRAM\n			3:OPEN HEADER FILE INCLUDED PROGRAM\n			4:OPEN PREPROCESSED PROGRAM\n		Y:EXIT\n");
	scanf("%d",&x);

	switch(x)
		{

		case 1: system("vi new1");
			break;
		case 2: system("vi new3");
			break;
		case 3: system("vi new4");
			break;
		case 4: system("vi new6");
			break;
		default:printf("you are exiting !!!\n");
	printf("--------------------------------------------------------------------------------------------------\n");
			exit(0);
		}
	}
return 0;
}
