/*
   Wolof-lang is a toy LISP Dialect written in C
   Copyright (C) 2016  Fodé Diop

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"

/* If we are compiling on Windows compile these functions */
#ifdef _WIN32
#include<string.h>

/* Declare a buffer for user input of size 2048 */
static char buffer[2048]

/* Fake readline function */
char* readline(char* prompt){
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

/* Fake add_history function */
void add_history(char* unused){}

/* Otherwise include the editline headers */
#else
#include <editline/readline.h>
/* #include <editline/history.h> */
#endif

int main (int argc, char** argv){
  /* Prinnt Version and Exit Information */
  puts("Wolof Version 0.0.0.1");
  puts("Press Ctrl+c to Exit\n");

  /* In a never ending loop */

  while (1) {
    /* Now in either case readline will be correctly defined */
    char* input = readline("wolof>> ");
    add_history(input);

    printf("Lolou dou deug, %s\n", input);
    free(input);
  }

  return 0;
}
