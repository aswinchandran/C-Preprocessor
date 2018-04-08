
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
  
	\file	: macro.c
	\Author	: Aswin chandran
	\Date	: 28/01/2014
	\brief	: 
	\see	: 
  ==========================================================================*/


#include"header.h"


char name[80][20];
char val[80][20];
int i=0,j=0;

void macrosub(FILE *fpw2,char *ptr,char *str,char *s,int k);


void macro(FILE *fpr1,FILE *fpw22)
{
	FILE *fpw1;	
	fpw1=fopen("new2","w");
	char *ptr;
	char *str;
	char *s;
	ptr=(char *) malloc(80);
	str=(char *) malloc(80);
	s=(char *) malloc(80);
	int k=0;


	while(1)
	{
		s=fgets(str,80,fpr1);			//str=string from new1   ie,output file of comment function
		if((ptr=strstr(str,"#define"))!=NULL)	//strstr command returns a pointer if str contains "#define"
		{
			ptr=ptr+7;
			while(*(++ptr)==' ');
			i=0;
			while(*(ptr)!=' ')
			{				//string name take the name of all macro
				name[k][i]=*ptr;
				i++;
				ptr++;
			}
				name[k][i]='\0';
			j=0;
			while(*ptr!='\n')
			{				//string val takes definition of all macro
				if(*ptr!=' ')
				{
					val[k][j]=*ptr;
					j++;
	
				}
				ptr++;
			}
			val[k][j]='\0';
			k++;
		}
		else
			fputs(str,fpw1);			//all oher than macro will stored in file new2
		if(s==NULL)
			break;
	}
	//puts(name[1]);
	//puts(val[1]);
	fclose(fpr1);
	fclose(fpw1);
macrosub(fpw22,ptr,str,s,k);			//call function to substitute macro
}

void macrosub(FILE *fpw2,char *ptr,char *str,char *s,int k)
{
	FILE *fpr2;
	fpr2=fopen("new2","r");

	int q;

	while((s=fgets(str,80,fpr2))!=NULL)
	{
		q=1;

		for(i=0;i<=k;i++)
		{
			if((ptr=strstr(str,name[i]))!=NULL)
			{					//if the name present in str its replaced by val
				q=0;
				while(str!=ptr)
				{
					fputc(*str,fpw2);
					str++;
				}
				ptr=ptr+strlen(name[i]);
				fputs(val[i],fpw2);			//macro substituted program copy to file3
				fputs(ptr,fpw2);
			}
			if(q==0)
			break;
		}
		if(q!=0)
			fputs(str,fpw2);
	}
	fclose(fpw2);
	fclose(fpr2);

}
