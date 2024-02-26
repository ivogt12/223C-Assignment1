// Author: Isaiah Vogt
// Author email: ivogt@csu.fullerton.edu
// CPSC 223C-1
// Due Date: 02/06/2024 11:59pm
//
// Triangle Trigonometry Data IO:
// This program demonstrates the use of the C language time.h library, math functions, and input/output functionality.
// The program asks the user for two sides of a triangle and the measured degrees between the two. Then it calculates
// the size of the third side and the area of the triangle.
// Files in this program: assignment1.c, r.sh
// Date of last update: 2024-Feb-1
// Status: Finished. The program was tested extensively with no errors in 11.1.0ubuntu4.
//
// Comile: gcc -c -Wall -m64 -no-pie -o number.o assignment1.c -std=c2x -lm
// Link: gcc -m64 -no-pie -o num.out number.o -std=c2x -lm
//
// OS developed on: 11.1.0ubuntu4
// OS developed on: 11.1.04ubuntu4

#include <stdio.h> //printf, scanf
#include <math.h> //sin, sqrt functions
#include <time.h> //time_t

int main()
{
    //variables to be collected and/or calculated
    double first_side = 0;
    double second_side = 0;
    double angle = 0;
    double area = 0;


    printf( "Welcome to Euclidean Triangles.\n This software was built by and maintained by Systems Programmer Isaiah Vogt.\n" );

    //declaring variable 'rawtime' with a type of long time_t
    time_t rawtime;
    //declaring variable 'timeinfo' as a structure of day of the week, month, day, hh::mm::ss, year
    struct tm * timeinfo;
    //set rawtime equal to current time with time function
    time( &rawtime );
    //set 'timeinfo' equal to the local time of the user
    timeinfo = localtime( &rawtime );
    //print string of time with asctime format
    printf( "Today is %s", asctime( timeinfo ) );
    
    printf( "This program will manage all of your triangles.\n" );
    printf( "Enter a float number for each quantity first side, second side, and angle in degrees between\n those two sides. Separate each quantity by ws. After the third quantity press enter.\n" );

    //collect user input
    scanf( "%lf %lf %lf", &first_side, &second_side, &angle );

    printf( "You entered %1.5lf and %1.5lf for sides and %1.5lf for the angle.\n", first_side, second_side, angle );

    //check for invalid inputs, if so print message and do not perform calculations
    if( (first_side < 0) | (second_side < 0) | (angle < 0) )
    {
        printf( "There is invalid data among the inputs. Please run this program again.\n" );
        printf( "Have a nice day.\nAn integer 0 will be sent to the operating system as a signal of successful execution. Bye.\n" );

        return 0;
    }
    
    //calculate third side using Pythagorean Theorem
    double third_side = sqrt( first_side * first_side + second_side * second_side );

    //calculate area using formula: A = (side1 x side2 x sin(angle in radians)) /2
    //note conversion from degrees to radians: angle in radians = ( angle in degrees * pi )/ 180
    area = ( first_side * second_side * sin( ( angle * 3.141592 ) / 180 ) )  / 2;

    printf( "The area of this triangle is %1.5lf square units.\n", area );
    printf( "The length of the third side of the triangle is %1.5lf linear units.\n", third_side );
    printf( "The elapsed time since the Great Epoch is %1.5ld seconds\n", (long)time(NULL) );

    printf( "Have a nice day.\nAn integer 0 will be sent to the operating system as a signal of successful execution. Bye.\n" );

    return 0;
}
