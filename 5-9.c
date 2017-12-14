#include <stdio.h>

static char ptr[2][13] = { 
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
}; 

static char (*daytab)[13] = NULL;

int day_of_year(int year, int month, int day) 
{ 
    int i, leap; 
    if (month < 1 || month > 12 || year < 0) 
        return -1;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++) 
        day += daytab[leap][i]; 
    return day; 
} 

void month_day(int year, int yearday, int *pmonth, int *pday) 
{ 
    int i, leap; 
    if (year < 0 || yearday < 0 || yearday > 366 ) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 
    for (i = 1; yearday > daytab[leap][i]; i++) 
        yearday -= daytab[leap][i]; 
    *pmonth = i; 
    *pday = yearday; 
} 

int main()
{
    int m, d, day, year, year_day, year2, month2, day2;
    daytab = ptr;
    printf("Year: ");
    scanf("%d", &year);
    printf("Year day: ");
    scanf("%d", &year_day);

    printf("Year: ");
    scanf("%d", &year2);
    printf("Month: ");
    scanf("%d", &month2);
    printf("Day: ");
    scanf("%d", &day2);

    month_day(year, year_day, &m, &d); 
    if (m == -1 || d == -1)
        printf("error: invalid year or day\n");
    else
        printf("Day %d and month %d\n", d, m);
    
    day = day_of_year(year2, month2, day2);
    if (day != -1) 
        printf("Day %d \n", day);
    else printf("error: invalid year or month\n");
}
