#include "Time.h"
#include <iostream>
using namespace std;

//Default Constructor
Time::Time() 
{
  days = 0;
  hours = 0;
  minutes = 0;
  seconds = 0;

  //Ensure time is normal
  timeManagement();
}

//Constructor holding all values
Time::Time(int d, int h, int m, int s) 
{
  days = d;
  hours = h;
  minutes = m;
  seconds = s;

  //Ensure time is normal
  timeManagement();
}

//Constructor with hours, minutes, and seconds
Time::Time(int h, int m, int s) 
{
  days = 0;
  hours = h;
  minutes = m;
  seconds = s;

  //Ensure time is normal
  timeManagement();
}

//Constructor with hours and minutes
Time::Time(int h, int m) 
{
  days = 0;
  hours = h;
  minutes = m;
  seconds = 0;

  //Ensure time is normal
  timeManagement();
}

//Getter for days
int Time::getDays() const 
{
  return days;
}

//Getter for hours
int Time::getHours() const 
{
  return hours;
}

//Getter for minutes
int Time::getMinutes() const 
{
  return minutes;
}

//Getter for seconds
int Time::getSeconds() const 
{
  return seconds;
}

//Converts incorrect time to normal
void Time::timeManagement() 
{
  if (seconds < 0 || seconds > 59) 
  {
    minutes += seconds / 60;
    seconds = seconds % 60;

    if (seconds < 0)
    {
      seconds += 60;
      minutes--;
    }
  }
  
  if (minutes < 0 || minutes > 59)
  {
    hours += minutes / 60;
    minutes = minutes % 60;

    if (minutes < 0)
    {
      minutes += 60;
      hours--;
    }
  }

  if(hours < 0 || hours > 23)
  {
    days += hours / 24;
    hours = hours % 24;

    if (hours < 0)
    {
      hours += 24;
      days--;
    }
  }
}

//Operator overload for addition
Time Time::operator+(const Time& other) const
{
  Time result;

  result.seconds = this->seconds + other.seconds;
  result.minutes = this->minutes + other.minutes;
  result.hours = this->hours + other.hours;
  result.days = this->days + other.days;

  result.timeManagement();
  return result;
}

//Operator overload for subtraction
Time Time::operator-(const Time& other) const
{
  Time result;

  result.seconds = this->seconds - other.seconds;
  result.minutes = this->minutes - other.minutes;
  result.hours = this->hours - other.hours;
  result.days = this->days - other.days;

  result.timeManagement();
  return result;
}

//Convert total time to seconds
int Time::totalSeconds() const
{
  return (((days * 24 + hours) * 60 + minutes) * 60 + seconds);
}

//Relational operators
bool Time::operator==(const Time& other) const
{
  return this->totalSeconds() == other.totalSeconds();
}

bool Time::operator!=(const Time& other) const
{
  return !(*this == other);
}

bool Time::operator<(const Time& other) const
{
  return this->totalSeconds() < other.totalSeconds();
}

bool Time::operator<=(const Time& other) const
{
  return this->totalSeconds() <= other.totalSeconds();
}

bool Time::operator>(const Time& other) const
{
  return this->totalSeconds() > other.totalSeconds();
}

bool Time::operator>=(const Time& other) const
{
  return this->totalSeconds() >= other.totalSeconds();
}

//Conversion Operator that converts Time object to int
Time::operator int() const
{
  return totalSeconds();
}

//Overloaded output for ostream operator
ostream& operator<<(ostream& out, const Time& t)
{
  out << t.days << " Days.\n";
  out << t.hours << " Hours.\n";
  out << t.minutes << " Minutes.\n";
  out << t.seconds << " Seconds.\n";
  return out;
  
}