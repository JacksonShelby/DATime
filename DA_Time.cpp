//Jackson Shelby
//Daily Assignment: Time
#include "Time.h"
#include <iostream>

using namespace std;

//Function Prototypes
void assignmentTest();
void testTimeAddition();
void testTimeSubtraction();
void testTimeRelationalOperators();
void testTimeOutStreamOperator();
void testTimeIntegerConversion();

int main()
{
  //Test assignment operator=
  assignmentTest();
  cout << endl;

  //Test overloaded operator+ to add times together
  testTimeAddition();
  cout << endl;

  //Test overloaded operator- to subtract times from each other
  testTimeSubtraction();
  cout << endl;

  //Test relational operators(==, !=, <, >, <=, >=)
  testTimeRelationalOperators();
  cout << endl;

  //Test overloaded << operator for output
  testTimeOutStreamOperator();
  cout << endl;

  //Test conversion from Time object to int
  testTimeIntegerConversion();

  return 0;
}

//Function Definitons

//Tests assignment operator by setting time2 = time 1
void assignmentTest() 
{
  Time time1(1, 25, 25, 15);
  Time time2;

  time2 = time1;

  cout << "Assignment Operator:" << endl;
  cout << "Time 2 Days: " << time2.getDays() << endl;
  cout << "Time 2 Hours: " << time2.getHours() << endl;
  cout << "Time 2 Minutes: " << time2.getMinutes() << endl;
  cout << "Time 2 Seconds: " << time2.getSeconds() << endl;
}

//Tests overloaded operater+ to get a sum of 2 Time objects
void testTimeAddition()
{
  Time time1(8, 4, 45, 18);
  Time time2(3, 8, 12, 34);

  Time sum = time1 + time2;

  cout << "Operator+ Overload:" << endl;
  cout << "The sum of Time 1 and Time 2 is:" << endl;
  cout << sum.getDays() << " Days." << endl;
  cout << sum.getHours() << " Hours." << endl;
  cout << sum.getMinutes() << " Minutes." << endl;
  cout << sum.getSeconds() << " Seconds." << endl;
}

//Tests the overloaded operator- to subtract one Time object from another
void testTimeSubtraction()
{
  Time time1(8, 4, 45, 18);
  Time time2(3, 6, 12, 34);

  Time sub = time1 - time2;

  cout << "Operator- Overload:" << endl;
  cout << "Time 1 minus Time2 is:" << endl;
  cout << sub.getDays() << " Days." << endl;
  cout << sub.getHours() << " Hours." << endl;
  cout << sub.getMinutes() << " Minutes." << endl;
  cout << sub.getSeconds() << " Seconds." << endl;
}

//Tests relational operators by comparing 2 Time objects
void testTimeRelationalOperators()
{
  Time time1(5, 8, 15, 16);
  Time time2(6, 7, 53, 54);

  cout << "Relational Operators:" << endl;
  cout << "Time 1 == Time 2: " << ((time1 == time2) ? "True" : "False") << endl;
  cout << "Time 1 != Time 2: " << ((time1 != time2) ? "True" : "False") << endl;
  cout << "Time 1 < Time 2: " << ((time1 < time2) ? "True" : "False") << endl;
  cout << "Time 1 > Time 2: " << ((time1 > time2) ? "True" : "False") << endl;
  cout << "Time 1 <= Time 2: " << ((time1 <= time2) ? "True" : "False") << endl;
  cout << "Time 1 >= Time 2: " << ((time1 >= time2) ? "True" : "False") << endl;

}

//Tests overloaded operator<< for displaying Time objects
void testTimeOutStreamOperator()
{
  Time time1(4, 6, 34, 7);
  Time time2(5, 29, 45, 56);

  cout << "Stream Operator:" << endl;
  cout << "Time 1 is: \n" << time1 << endl;
  cout << "Time 2 is: \n" << time2;
}

//Tests conversion of Time object to total seconds using int operator
void testTimeIntegerConversion()
{
  Time time(1, 2, 3, 4);
  int seconds = time;

  cout << "Time Object to Int Conversion:" << endl;
  cout << "Total Seconds in Time Object: " << seconds << " seconds." << endl;
}