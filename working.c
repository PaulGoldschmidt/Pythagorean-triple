/*
 * math.c
 * 
 * Copyright 2018  <Paul Goldschmidt>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
int clearScreen();
int starttime;
int varpassage = 0;
int starttime;
int main()
{
	int a = 0, apow, b = 0, bpow, c, cpow, abpow, avgpow, calc_status = 0; //define the variables
	clearScreen();
	time_t mytime;
	mytime = time(NULL);
	printf("------------------------------------------------------------\n");
	printf("             Pythagorean triple calculator                  \n");
	printf("                                         by Paul Goldschmidt\n");
	printf("                                         paul-goldschmidt.de\n");  
	printf("------------------------------------------------------------\n");
    printf("The time is now: %s", ctime(&mytime));
	a++; //a and b is zero, but it must be one. So add one to a and b.
	b++;
	printf("\n\nPlease enter the length of c (hypotenuse)\n");
	scanf("%d", &c); //input for the number.
	printf("Starting calculation...\n");
	time_t starttime;
	starttime = time(NULL);
	while (abpow != cpow) { //loop until solved
		varpassage++;
		apow = pow(a, 2); //power a by two
		bpow = pow(b, 2); //power b by two
		cpow = pow(c, 2); //power c by two
		abpow = apow + bpow; //add a and b together.
		avgpow = abpow / 2;

		if (c < b || avgpow >= cpow) { //check if unsolveble.
			abpow = cpow; 
			calc_status = 1; //now the *not solveble* result will be displayed.
		}
		else { //print the tried combinations.
			printf("starting next calculation! Tryed already until a = ");
			printf("%i", a);
			printf(" and b = ");
			printf("%i\n", b);
		}
		
		if (c >= a) { //is c bigger or simular than a?
			a++; //add to a one
		}
		
		else { //no, it's not.
			a = 1; //"reset" a to one
			b++; //add to b one
		}    
		
	}
	time_t timefinished;
	timefinished = time(NULL);
	if (calc_status == 0) { //this will be displayed in case the calculation is solveble. 
		clearScreen();
		printf("Done with the calculation!");
		printf("\n");
		printf("\n\nThe result of the calculation is:\na = ");
		printf("%i\n", a - 1);
		printf("b = ");
		printf("%i\n", b);
		printf("c = ");
		printf("%i\n", c);
		printf("\nStats:\n\nProcess started at: ");
		printf("%s", ctime(&starttime));
		printf("The time is now: %s", ctime(&timefinished));
		printf("\nThe CPU tired ");
		printf("%i", varpassage);
		printf(" different combinations to solve this tripel!\n\n");
		printf("Script by Paul Goldschmidt\n");
		printf("This code is published under");
		printf("\nthe GNU General Public License.");
		printf("\n\npaul-goldschmidt.de\n\n");
    }
    
    else { //and this when it isn't solveble.
		clearScreen();
		printf("Sorry, but this calculation is not solvable!");
		printf("\n");
		printf("in case you think you found a bug, please \n");
		printf("write me a short notice over the contact form over my");
		printf(" website.\n");
		printf("\nStats:\n\nProcess started at: ");
		printf("%s", ctime(&starttime));
		printf("The time is now: %s", ctime(&timefinished));
		printf("\nThe CPU tired ");
		printf("%i", varpassage);
		printf(" different combinations to solve this tripel!\n\n");
		printf("Thanks for using this script. \n");
		printf("Script by Paul Goldschmidt \n");
		printf("This code is published under the \n");
		printf("GNU General Public License.");
		printf("\n\npaul-goldschmidt.de \n");
    }
    sleep(20);
}

int clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
  return 0;
}
