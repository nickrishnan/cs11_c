/*
* 
* easter.c reads in years from a file
* and returns in an output file the year along with
* the corresponding date of Easter Sunday of that year
* according to the algorithm from Knuth's Art of Computer
* Programming
*
* Usage: easter < infile > outfile
*/

#include <stdio.h>
#include <stdlib.h>

#define YEAR_MIN 1582
#define YEAR_MAX 39999


int calculate_easter_date( int year );
int main ( void );

int calculate_easter_date( int year )
{ 
    int golden_year;
    int century;
    int skipped_leap_years;
    int correction; /* correction factor for moon orbit */
    int epact; /* specifies when full moon occurs */
    int sunday_date;
    int day_of_month;
   

    if( year < YEAR_MIN || year > YEAR_MAX) { /* guard against invalid years */
        return 0;
    } 

    golden_year = year % 19 + 1; /* set golden year */
    century = year / 100 + 1; /* calculate century */
    skipped_leap_years = 3 * century / 4 - 12;
    correction = (8 * century + 5) / 25 - 5;
    sunday_date = 5 * year / 4 - skipped_leap_years - 10;
    epact = (11 * golden_year + 20 + correction - skipped_leap_years) % 30;
    
    if ( ( epact == 25 && golden_year > 11 ) || epact == 24 ){
        epact++;
    }
 
    day_of_month = 44 - epact;
    
    if ( day_of_month < 21 ) {
        day_of_month += 30;
    }
    
    day_of_month = day_of_month + 7 - (sunday_date + day_of_month) % 7;
   
    if (day_of_month < 31 ) {
        day_of_month *= -1;
    }
 
    else { 
        day_of_month -= 31;
    }

    return day_of_month;    
}    
    
int main( void )
{
    int year;
    int date;
    int result;

    while ( 1 ){
        result = scanf("%d", &year);

        if ( result == EOF ) {
            break;
        }

        date = calculate_easter_date(year);
        
        if ( date == 0 ) {
            fprintf(stderr, "Error: Year %d Out of Range\n", year);
            return -1;
        }
        
        else {
            if (date > 0) {
                printf("%d - April %d\n", year, date);
            }
            else {
                printf("%d - March %d\n", year, abs(date));
            }
        }
    }
    return 0;
}

