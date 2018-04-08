
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
  
	\file	: header_in.c
	\Author	: Aswin chandran
	\Date	: 28/01/2014
	\brief	: 
	\see	: 
  ==========================================================================*/


#include"header.h"



void headn()
{
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	FILE *fp4;

	FILE *fp1r;
	FILE *fpr1;
	FILE *fpr2;
	FILE *fpr3;

	fp1r=fopen("new3","r");
	fp2=fopen("new4","w");

	char *ptr;
	char *str;
	char *s;

	ptr=(char *) malloc(80);
	str=(char *) malloc(80);
	s=(char *) malloc(80);


	char a[80];
	char j;
	char s1[80];


while(1)
	{
	s=fgets(str,80,fp1r);
		if((ptr=strstr(str,"#include"))!=NULL)
		{
			ptr=ptr+8;
			if(*(ptr)=='"')
			{	a[0]='\0';
				strcat(a,ptr+1);
				a[strlen(a)-2]='\0';
				strcpy(s1,a);
			}
			if(*(ptr)=='<')
			{
				char a[80]="/usr/include/";		
				strcat(a,ptr+1);
				a[strlen(a)-2]='\0';
				strcpy(s1,a);
			}

			puts(s1);

			FILE *fp1=fopen(s1,"r");
			while((j=fgetc(fp1))!=EOF)
			{
				fputc(j,fp2);
			}


		fclose(fp1);
		}
		else
		{
			fputs(str,fp2);			//this new4 file gives header included program
		}
	if(s==NULL)
		break;
	}

		fclose(fp2);

	fp3=fopen("new4","r");				
	fp4=fopen("new5","w");				//file new5 contains file without macros
	macro(fp3,fp4);


	fpr2=fopen("new5","r");				//remove comments in new5 file by passing fpr2 and fpr3
	fpr3=fopen("new6","w");				//file new6 contains file without comments
	comment(fpr2,fpr3);

	//fclose(fpr2);
	//fclose(fpr3);

	//fclose(fp1r);
	//fclose(fp3);
	//fclose(fp4);

}
