#include <stdlib.h>
#include <stdio.h>

#define CalendarTitleRowLength 16

enum DayOfWeek
{
    DayOfWeek_Unknown = 0,
    DayOfWeek_Sunday  = 1,
    DayOfWeek_Monday,
    DayOfWeek_Tuesday,
    DayOfWeek_Wednesday,
    DayOfWeek_Thursday,
    DayOfWeek_Friday,
    DayOfWeek_Saturday
};

enum Month
{
    Month_Unknown = 0,
    Month_January = 1,
    Month_February,
    Month_March,
    Month_April,
    Month_May,
    Month_June,
    Month_July,
    Month_August,
    Month_September,
    Month_October,
    Month_November,
    Month_December
};

int is_leap_year(int year);

const char *day_of_week_to_str(enum DayOfWeek day);

const char *month_to_str(enum Month month);

enum DayOfWeek get_week_day(int day, enum Month month, int year);

void cal(int day, enum Month month, int year);

int main(void)
{
    cal(31, Month_August, 2017);

    return EXIT_SUCCESS;
}

int is_leap_year(int year)
{
    return ((year % 100) != 0 && (year % 400) != 0) || ((year % 4) == 0);
}

int get_day_count_for_month(enum Month month, int year)
{
    const int DaysInMonthNotLeapYearLookup[] = {
        [Month_Unknown]   = 0,
        [Month_January]   = 31,
        [Month_February]  = 28,
        [Month_March]     = 31,
        [Month_April]     = 30,
        [Month_May]       = 31,
        [Month_June]      = 30,
        [Month_July]      = 31,
        [Month_August]    = 31,
        [Month_September] = 30,
        [Month_October]   = 31,
        [Month_November]  = 30,
        [Month_December]  = 31,
    };

    const int DaysInMonthLeapYearLookup[] = {
        [Month_Unknown]   = 0,
        [Month_January]   = 31,
        [Month_February]  = 29,
        [Month_March]     = 31,
        [Month_April]     = 30,
        [Month_May]       = 31,
        [Month_June]      = 30,
        [Month_July]      = 31,
        [Month_August]    = 31,
        [Month_September] = 30,
        [Month_October]   = 31,
        [Month_November]  = 30,
        [Month_December]  = 31,
    };

    const int days_in_month = is_leap_year(year)?
        DaysInMonthLeapYearLookup[month] : DaysInMonthNotLeapYearLookup[month];

    return days_in_month;
}

const char *day_of_week_to_str(enum DayOfWeek day)
{
    if (!(DayOfWeek_Sunday <= day && day <= DayOfWeek_Saturday)) {
        return NULL;
    }

    static const char *const DayOfWeekLookup[] = {
        [DayOfWeek_Sunday]      = "Su",
        [DayOfWeek_Monday]      = "Mo",
        [DayOfWeek_Tuesday]     = "Tu",
        [DayOfWeek_Wednesday]   = "We",
        [DayOfWeek_Thursday]    = "Th",
        [DayOfWeek_Friday]      = "Fr",
        [DayOfWeek_Saturday]    = "Sa",
    };

    return DayOfWeekLookup[day];
}

const char *month_to_str(enum Month month)
{
    if (!(Month_January <= month && month <= Month_December)) {
        return NULL;
    }

    static const char *const MonthLookup[] = {
        [Month_January]   = "January",
        [Month_February]  = "February",
        [Month_March]     = "March",
        [Month_April]     = "April",
        [Month_May]       = "May",
        [Month_June]      = "June",
        [Month_July]      = "July",
        [Month_August]    = "August",
        [Month_September] = "September",
        [Month_October]   = "October",
        [Month_November]  = "November",
        [Month_December]  = "December",
    };

    return MonthLookup[month];
}

enum DayOfWeek get_week_day(int day, enum Month month, int year)
{
    /* Assumes the year is in the XXIst century. */

    static const int XxiCenturyOffset = 6;
    static const int DaysInWeek       = 7;

    static const int MonthLookup[] = {
        [Month_Unknown]   = -1,
        [Month_January]   = 0,
        [Month_February]  = 3,
        [Month_March]     = 3,
        [Month_April]     = 6,
        [Month_May]       = 1,
        [Month_June]      = 4,
        [Month_July]      = 6,
        [Month_August]    = 2,
        [Month_September] = 5,
        [Month_October]   = 0,
        [Month_November]  = 3,
        [Month_December]  = 5,
    };

    const int week_day          = day % DaysInWeek;
    const int last_two_digits   = year % 100;
    const int without_remainder = last_two_digits / 4;
    
    const int sum = (XxiCenturyOffset + last_two_digits
                    + without_remainder + MonthLookup[month] + week_day);

    const int remainder = sum % DaysInWeek;

    return (enum DayOfWeek)(1 + remainder);
}

void cal(int day, enum Month month, int year)
{
    const int DaysInMonth = get_day_count_for_month(month, year);
    const int DaysInWeek  = 7;

    char calendar_title[1 + CalendarTitleRowLength] = { 0 };

    (void)snprintf(calendar_title, CalendarTitleRowLength, 
                    "%s %d\n", month_to_str(month), year);

    (void)printf("%*s", 1 + CalendarTitleRowLength, calendar_title);    

    const enum DayOfWeek first_week_day = get_week_day(1, month, year);
    enum DayOfWeek       week_day       = DayOfWeek_Sunday;

    while (day_of_week_to_str(week_day))
    {
        if (week_day < first_week_day) {
            (void)printf("%2s ", " ");
        } else {
            const char *const day_name = day_of_week_to_str(week_day);
            (void)printf("%s ", day_name);
        }

        ++week_day;
    }

    (void)putchar('\n');

    for (int curday = 1; curday <= DaysInMonth; ++curday) 
    {
        (void)printf("%2d ", curday);

        if (curday % DaysInWeek == 0 || curday == DaysInMonth) 
        {
            (void)putchar('\n');

            const int first_week_day = 1 + DaysInWeek * ((curday - 1) / DaysInWeek);
            const int last_day       = curday;

            if (first_week_day <= day && day <= last_day)
            {
                for (int last_week_day = first_week_day; last_week_day <= last_day; ++last_week_day)
                {
                    if (last_week_day == day) {
                        (void)printf("%2s ", "^");
                    } else {
                        (void)printf("%3s", " ");
                    }
                }

                (void)putchar('\n');
            }
        }
    }
}

