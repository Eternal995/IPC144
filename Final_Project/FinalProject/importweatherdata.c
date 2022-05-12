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

#include"importweatherdata.h"


int importWeatherDataFile(FILE* fp, struct WeatherRecord* data, int max)

{
   int recs = 0;

   if (fp != NULL)
   {

      while (recs < max &&

         fscanf(fp, "%d,%d,%lf,%c,%d,%15[^\n]\n",

            &data[recs].date.year, &data[recs].date.month,

            &data[recs].precipAmt, &data[recs].unit,

            &data[recs].location.regionCode,

            data[recs].location.name) == 6)
      {
         recs++;
      }
   }

   return recs;
}