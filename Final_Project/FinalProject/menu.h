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

#ifndef MENU_H
#define MENU_H

#define _CRT_SECURE_NO_WARNINGS

#include"importweatherdata.h"

//function prototypes

//main menu
void menuMain(struct WeatherRecord* data, const int max);

//menu items
void displayallheader(void);
void viewbyregionheader(void);
void viewbyreigonheaderpartone(void);
void displayWeatherData(struct WeatherRecord* data, int max);
void displayall(struct WeatherRecord data[], int max);
void viewbyregion(struct WeatherRecord data[], int max);
void viewbyMonthHeader(void);
void viewbyMonth(struct WeatherRecord* data, const int max);
void viewbyLocationNameHeader(void);
void viewbyLocationName(struct WeatherRecord* data, const int max);

//utility functions
void suspend(void);
void clearInputBuffer(void);
int inputInt(void);
int inputIntRange(const int lower, const int upper);
void unitConvertCMtoMM(struct WeatherRecord* data, const int max);
void unitConvertMMtoCM(struct WeatherRecord* data, const int max);
int findNextEmptyIndex(double* precip, const int max);
#endif