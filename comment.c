
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
  
	\file	: comment.c
	\Author	: Aswin chandran
	\Date	: 28/01/2014
	\brief	: 
	\see	: 
  ==========================================================================*/


#include"header.h"

void comment(FILE *fpr,FILE *fpw1)
{					//file pointer to read and write passed as arguments
	char ch;

	while((ch=fgetc(fpr))!=EOF)
	{
		if(ch=='"')		//avoid comment removing inside ""     printf("")
		{
			fputc(ch,fpw1);
			while((ch=fgetc(fpr))!='"')
			{
				fputc(ch,fpw1);
			}
		}
		else
		{
			if(ch=='/')
			{
				ch=fgetc(fpr);
				if(ch=='/')		//remove comments after //
				{
					while(1)
					{
						ch=fgetc(fpr);
						if(ch=='\n')
						goto LABEL;
					}
				}

				if(ch=='*')		//remove comments inside  /*   */
				{
					while((ch=fgetc(fpr))!=EOF)
					{
						if(ch=='*')
						{
							ch=fgetc(fpr);
							if(ch=='/')
							{
								ch=fgetc(fpr);
								goto LABEL;
							}
						}
					}
				}
				else
					putc('/',fpw1);		//if single '/' it not a comment
			}
		}
		
	LABEL : fputc(ch,fpw1);			//with in while loop to read non-commands
	}
	fclose(fpw1);				//close all file pointers
	fclose(fpr);

}


