#ifndef TIME
#define TIME
#include <iostream>
using namespace std;
class Time
{
  private:
    int days;
    int hours;
    int minutes;
    int seconds;

    //Ensures times are normal
    void timeManagement();
    
    //Easier to compare times
    int totalSeconds() const;

  public:
    //Constructors
    Time();
    Time(int d, int h, int m, int s);
    Time(int h, int m, int s);
    Time(int h, int m);
    
    //Getters
    int getDays() const;
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    //Arithmetic operators
    Time operator+(const Time& other) const;
    Time operator-(const Time& other) const;

    //Relational operators
    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
    bool operator<(const Time& other) const;
    bool operator<=(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator>=(const Time& other) const;

    //Conversion to int
    operator int() const;

    //Output stream operator (Friend Class)
    friend ostream& operator<<(ostream &, const Time &);
};

#endif