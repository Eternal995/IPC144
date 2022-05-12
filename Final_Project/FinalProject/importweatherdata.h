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

#ifndef IMPORT_WEATHER_DATA_H
#define IMPORT_WEATHER_DATA_H

#define REC_MAX 250
#define LOC_NAME_MAX 15

struct Date
{
   int year;
   int month;
};

struct Location
{
   int regionCode;
   char name[LOC_NAME_MAX + 1];
};

struct WeatherRecord
{
   struct Date date;
   double precipAmt;
   char unit;
   struct Location location;
};



int importWeatherDataFile(FILE* fp, struct WeatherRecord* data, int max);


#endif