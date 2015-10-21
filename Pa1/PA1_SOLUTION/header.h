#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> //this has toupper in it

void StringSorter(char **strar, char way, int str_length);

char *WSRemover(char *str);
void IsPalindrome(char *NoWSstring, char *str, int start, int end);

void IsPal(char *str);

char *CaesarShift();
void CaesarShiftDriver();

#endif
