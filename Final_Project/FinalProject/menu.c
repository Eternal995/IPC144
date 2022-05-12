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

struct descend
{
	int region;
	char name[100];
	double precip;
};

//the main menu function, loop until entered 0
void menuMain(struct WeatherRecord* data, const int max)
{
	int selection;

	do
	{
		printf("=======================================================\n"
			"         Ontario Weather Analysis Service\n"
			"                  Year: 2021\n"
			"=======================================================\n"
			"1. View all data\n"
			"2. View by region (sorted DESCENDING by precip.)\n"
			"3. View by month (sorted ASCENDING by precip.)\n"
			"4. View by location name (sorted DESCENDING by precip.)\n"
			"-------------------------------------------------------\n"
			"0. Exit\n"
			"-------------------------------------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 4);
		putchar('\n');
		switch (selection)
		{
		case 0:
			printf("Application Terminated!\n");
			break;
		case 1:
			displayall(data, max);
			break;
		case 2:
			viewbyregion(data, max);
			break;
		case 3:
			viewbyMonthHeader();
			viewbyMonth(data, max);
			break;
		case 4:
			viewbyLocationNameHeader();
			viewbyLocationName(data, max);
			break;
		}
		putchar('\n');
	} while (selection);
}

//Menu Items

void displayallheader(void)
{
	printf("Year Month Precip.Amt Unit Region Name\n");
	printf("---- ----- ---------- ---- ------ ---------------\n");
}

void viewbyregionheader(void)
{
	printf("Region Name     Precip(mm)\n");

}

void viewbyreigonheaderpartone(void)
{
	printf("------ -------- ----------\n");
}

void displayWeatherData(struct WeatherRecord* data, int max)
{
	printf("%d    %02d      %5.1lf    %c     %d %s\n", data->date.year, data->date.month, data->precipAmt, data->unit, data->location.regionCode, data->location.name);
}

void displayall(struct WeatherRecord data[], int max)
{
	int i;

	for (i = 0; i <= 14; i++)
	{
		displayWeatherData(&data[i], max);
	}
	suspend();
	for (i = 15; i < 30; i++)
	{
		displayWeatherData(&data[i], max);

	}
	suspend();
	for (i = 30; i < 45; i++)
	{
		displayWeatherData(&data[i], max);

	}
	suspend();
	for (i = 45; i < 60; i++)
	{
		displayWeatherData(&data[i], max);
	}
	suspend();
	for (i = 60; i < 75; i++)
	{
		displayWeatherData(&data[i], max);
	}
	suspend();
	for (i = 75; i < 90; i++)
	{
		displayWeatherData(&data[i], max);
	}
	suspend();
	for (i = 90; i < max; i++)
	{
		displayWeatherData(&data[i], max);
	}

}

void viewbyregion(struct WeatherRecord data[], int max)
{
	int i, j;
	int maximum = 4;
	double precipAmtwestern, precipAmtwestern1, precipAmtNorthern, precipAmtNorthern1, precipAmtEastern, precipAmtEastern1, precipAmtCentral, precipAmtCentral1;
	double precipAmtinc, totalwest, totalcentral, totalnorth, totaleast;
	double average;
	char unit = 'c';
	average = 0;
	precipAmtCentral = 0.;
	precipAmtCentral1 = 0.;
	precipAmtEastern = 0.;
	precipAmtEastern1 = 0.;
	precipAmtNorthern = 0.;
	precipAmtNorthern1 = 0.;
	precipAmtwestern1 = 0.;
	precipAmtwestern = 0.;
	precipAmtinc = 0.;

	for (i = 0; i < max; i++)
	{
		if (data[i].location.regionCode == 10)
		{
			precipAmtinc = 0;
			if (data[i].unit == unit)
			{
				precipAmtinc = data[i].precipAmt * 10;
				precipAmtwestern += precipAmtinc;
			}
			else
			{
				precipAmtwestern1 += data[i].precipAmt;
			}
		}
		else if (data[i].location.regionCode == 20)
		{
			precipAmtinc = 0;
			if (data[i].unit == unit)
			{
				precipAmtinc = data[i].precipAmt * 10;
				precipAmtNorthern += precipAmtinc;
			}
			else
			{
				precipAmtNorthern1 += data[i].precipAmt;
			}
		}
		else if (data[i].location.regionCode == 30)
		{
			precipAmtinc = 0;
			if (data[i].unit == unit)
			{
				precipAmtinc = data[i].precipAmt * 10;
				precipAmtEastern += precipAmtinc;
			}
			else
			{
				precipAmtEastern1 += data[i].precipAmt;
			}
		}
		else if (data[i].location.regionCode == 40)
		{
			precipAmtinc = 0;
			if (data[i].unit == unit)
			{
				precipAmtinc = data[i].precipAmt * 10;
				precipAmtCentral += precipAmtinc;
			}
			else
			{
				precipAmtCentral1 += data[i].precipAmt;
			}
		}
	}
	totalwest = precipAmtwestern + precipAmtwestern1;
	totalcentral = precipAmtCentral + precipAmtCentral1;
	totaleast = precipAmtEastern + precipAmtEastern1;
	totalnorth = precipAmtNorthern + precipAmtNorthern1;
	struct descend s[40] =
	{
		{10, "Western", totalwest},
		{20, "Northern", totalnorth},
		{30, "Eastern", totaleast},
		{40, "Central", totalcentral},
	};
	struct descend tmp[40] =
	{
		{0}
	};

	for (i = 0; i < maximum && s[i].precip != 0; i++)
	{
		for (j = 0; j < maximum && s[j].precip != 0; j++)
		{
			if (s[j].precip <= s[i].precip)
			{
				tmp[j] = s[i];
				s[i] = s[j];
				s[j] = tmp[j];
			}
		}
	}
	viewbyregionheader();
	viewbyreigonheaderpartone();
	for (i = 0; i < maximum; i++)
	{
		printf("    %2d %s       %.0lf\n", tmp[i].region, tmp[i].name, tmp[i].precip);
	}
	viewbyreigonheaderpartone();
	average = (double)(totalnorth + totalcentral + totaleast + totalwest) / 4;
	printf("         Total:      %.0lf\n", totalcentral + totaleast + totalnorth + totalwest);
	printf("       Average:   %.2lf\n", average);

}


void viewbyMonthHeader(void)
{
	printf("Month     Precip(mm)\n"
		"--------- ----------\n");
}

void viewbyMonth(struct WeatherRecord* data, const int max)
{
	int i, j, index;
	double total = 0.0, average;
	int month[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	double precip[12] = { 0 };
	int temp1;
	double temp2;
	char monthname[11];

	unitConvertCMtoMM(data, max);

	//add each precip. Amt data into each month
	for (i = 0; i < max && data[i].precipAmt != 0.0; i++)
	{
		for (j = 0; j < 12; j++)
		{
			if (data[i].date.month == month[j]) precip[j] += data[i].precipAmt;
		}
	}

	unitConvertMMtoCM(data, max);

	//sorting ascending by precip.
	for (i = 0; i < 12 && precip[i] != 0; i++)
	{
		index = i;

		for (j = i + 1; j < 12 && precip[j] != 0; j++)
		{
			if (precip[j] < precip[index]) index = j;
		}

		if (index != i)
		{
			temp1 = month[i];
			month[i] = month[index];
			month[index] = temp1;
			temp2 = precip[i];
			precip[i] = precip[index];
			precip[index] = temp2;
		}
	}

	//display all data and calculating total/average data
	for (i = 0; i < 12 && precip[i] != 0; i++)
	{
		//transfer integer month to character month name
		if (month[i] == 1) strcpy(monthname, "January");
		else if (month[i] == 2) strcpy(monthname, "February");
		else if (month[i] == 3) strcpy(monthname, "March");
		else if (month[i] == 4) strcpy(monthname, "April");
		else if (month[i] == 5) strcpy(monthname, "May");
		else if (month[i] == 6) strcpy(monthname, "June");
		else if (month[i] == 7) strcpy(monthname, "July");
		else if (month[i] == 8) strcpy(monthname, "August");
		else if (month[i] == 9) strcpy(monthname, "September");
		else if (month[i] == 10) strcpy(monthname, "October");
		else if (month[i] == 11) strcpy(monthname, "November");
		else strcpy(monthname, "December");

		printf("%-9s %10d\n", monthname, (int)precip[i]);
		total += precip[i];
	}

	average = total / (double)i;

	printf("--------- ----------\n"
		"%9s %10.0lf\n"
		"%9s %10.2lf\n", "Total:", total, "Average:", average);
}

void viewbyLocationNameHeader(void)
{
	printf("Location        Precip(mm)\n"
		"--------------- ----------\n");
}

void viewbyLocationName(struct WeatherRecord* data, const int max)
{
	int i, j, find, index;
	double total = 0.0, average;
	char location[REC_MAX][LOC_NAME_MAX + 1] = { "" };
	double precip[REC_MAX] = { 0 };
	char temp1[LOC_NAME_MAX + 1] = { "" };
	double temp2 = 0.0;

	unitConvertCMtoMM(data, max);

	//add each precip. Amt data into each location name 
	for (i = 0; i < max && data[i].precipAmt != 0.0; i++)
	{
		find = 0;

		for (j = 0; j < REC_MAX && precip[j] != 0.0; j++)
		{
			if (strcmp(location[j], data[i].location.name) == 0)
			{
				find = 1;
				precip[j] += data[i].precipAmt;
			}
		}

		if (!find)
		{
			index = findNextEmptyIndex(precip, REC_MAX);
			strcpy(location[index], data[i].location.name);
			precip[index] += data[i].precipAmt;
		}
	}

	unitConvertMMtoCM(data, max);

	//sorting descending by precip.
	for (i = 0; i < REC_MAX && precip[i] != 0; i++)
	{
		index = i;

		for (j = i + 1; j < REC_MAX && precip[j] != 0; j++)
		{
			if (precip[j] > precip[index]) index = j;
		}

		if (index != i)
		{
			strcpy(temp1, location[i]);
			strcpy(location[i], location[index]);
			strcpy(location[index], temp1);
			temp2 = precip[i];
			precip[i] = precip[index];
			precip[index] = temp2;
		}
	}

	//display all data and calculating total/average data
	for (i = 0; i < REC_MAX && precip[i] != 0; i++)
	{
		printf("%15s %10d\n", location[i], (int)precip[i]);
		total += precip[i];
	}

	average = total / (double)i;

	printf("--------------- ----------\n"
		"%15s %10.0lf\n"
		"%15s %10.2lf\n", "Total:", total, "Average:", average);
}


//utility Functions

void suspend(void)
{
	printf("\n");
	printf("< Press [ENTER] key to continue >");
	clearInputBuffer();
	putchar('\n');
}

void clearInputBuffer(void)
{
	// Discard all remaining char's from the standard input buffer:
	while (getchar() != '\n')
	{
		; // do nothing!

	}
}

int inputInt()
{
	int number = 0;
	char newline = 'x';
	int stop = 0;
	do
	{
		scanf("%d%c", &number, &newline);
		if (newline != '\n')
		{
			clearInputBuffer();
			printf("Error! Input a whole number: ");
			stop = 1;
		}
		else
		{
			stop = 0;
		}
	} while (stop != 0);
	return number;
}

int inputIntRange(int min, int max)
{
	int number3 = 0;
	int stop = 0;

	do
	{
		number3 = inputInt();
		if (number3 == min || number3 == max)
		{
			stop = 0;
		}
		else if (number3 < min || number3 > max)
		{
			printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
			stop = 1;
		}
		else
		{
			stop = 0;
		}
	} while (stop != 0);
	return number3;
}

//conver all cm to mm
void unitConvertCMtoMM(struct WeatherRecord* data, const int max)
{
	int i;

	for (i = 0; i < max && data[i].precipAmt != 0; i++)
	{
		if (data[i].unit == 'c')
		{
			data[i].precipAmt *= 10.;
		}
	}
}

//conver data back to original form
void unitConvertMMtoCM(struct WeatherRecord* data, const int max)
{
	int i;

	for (i = 0; i < max && data[i].precipAmt != 0; i++)
	{
		if (data[i].unit == 'c')
		{
			data[i].precipAmt /= 10.;
		}
	}
}

//find the next empty index number
int findNextEmptyIndex(double* precip, const int max)
{
	int i, empty;

	empty = 0;

	for (i = 0; i < max && precip[i] != 0.0; i++)
	{
		if (precip[i] != 0.0 && precip[i + 1] == 0.0) empty = i + 1;
	}

	return empty;
}
