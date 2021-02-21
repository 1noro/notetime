
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* get_datetime_header(time_t now) {
    // variables to store date and time components
    int hours, minutes, seconds, day, month, year;

    // localtime converts a time_t value to calendar time and
    // returns a pointer to a tm structure with its members
    // filled with the corresponding values
    struct tm *local = localtime(&now);

    hours = local->tm_hour;          // get hours since midnight (0-23)
    minutes = local->tm_min;         // get minutes passed after the hour (0-59)
    seconds = local->tm_sec;         // get seconds passed after minute (0-59)

    day = local->tm_mday;            // get day of month (1 to 31)
    month = local->tm_mon + 1;       // get month of year (0 to 11)
    year = local->tm_year + 1900;    // get year since 1900

    // print current date
    // printf("[%02d-%02d-%d %02d:%02d:%02d]\n", day, month, year, hours, minutes, seconds);

    char* out = (char*) malloc(21 * sizeof(char));
    sprintf(out, "[%02d-%02d-%d %02d:%02d:%02d]", day, month, year, hours, minutes, seconds);

    return out;
}

int main(int argc, char const *argv[]) {
    // time_t is arithmetic time type
    time_t now;

    // Obtain current time
    // time() returns the current time of the system as a time_t value
    time(&now);

    printf("%s\n", get_datetime_header(now));

    return 0;
}

