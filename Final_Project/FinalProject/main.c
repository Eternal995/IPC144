// Section: IPC144NDD
// Group members:
// 
// Name: Yongda Long
// Student ID#: 172800211
// Email: ylong9@myseneca.ca
// 
// Name:
// Student ID#:
// Email:

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "importweatherdata.h"
#include "menu.h"

//main function body
int main(void)
{
   FILE* fp = NULL;
   int recs = 0;
   struct WeatherRecord data[REC_MAX] = { {0} };

   fp = fopen("weatherdata.txt", "r");

   recs = importWeatherDataFile(fp, data, REC_MAX);

   fclose(fp);

   menuMain(data, recs);

   return 0;
}