//
// Created by vincent on 09/05/19.
//

#include "../headers/Point.h"
#include <iostream>
#include <iomanip>

// =====================================================================================================================
// CONSTRUCTORS

Point::Point() : m_hour(0), m_minute(0), m_second(0), m__ms(0), m_long(0.0), m_lat(0.0),m_f1(0.0), m_f2(0.0), m_f3(0.0),
                 m_f4(0.0), m_f5(0.0), m_f6(0.0){}

Point::Point(int mHour, int mMinute, int mSecond, int mMs, long double mLong, long double mLat, long double mF1,
             long double mF2, long double mF3, long double mF4, long double mF5, long double mF6) : m_hour(mHour),
                                                               m_minute(mMinute), m_second(mSecond),
                                                               m__ms(mMs), m_long(mLong), m_lat(mLat), m_f1(mF1),
                                                               m_f2(mF2), m_f3(mF3), m_f4(mF4), m_f5(mF5), m_f6(mF6){}

// =====================================================================================================================
// DESTRUCTORs

Point::~Point() = default;
// =====================================================================================================================

// =====================================================================================================================
// ========== GETTERS ==========

int    Point::getHour()   const { return m_hour; }
int    Point::getMinute() const { return m_minute; }
int    Point::getSecond() const { return m_second; }
int    Point::getMs()     const { return m__ms; }
long double Point::getLong()   const { return m_long; }
long double Point::getLat()    const { return m_lat; }
long double Point::getF1()     const { return m_f1; }
long double Point::getF2()     const { return m_f2; }
long double Point::getF3()     const { return m_f3; }
long double Point::getF4()     const { return m_f4; }
long double Point::getF5()     const { return m_f5; }
long double Point::getF6()     const { return m_f6; }
// =====================================================================================================================

// =====================================================================================================================
// ========== SETTERS ==========

void   Point::setHour(int mHour)     { m_hour = mHour; }
void   Point::setMinute(int mMinute) { m_minute = mMinute; }
void   Point::setSecond(int mSecond) { m_second = mSecond; }
void   Point::setMs(int mMs)         { m__ms = mMs; }
void   Point::setLong(long double mLong)  { m_long = mLong; }
void   Point::setLat(long double mLat)    { m_lat = mLat; }
void   Point::setF1(long double mF1)      { m_f1 = mF1; }
void   Point::setF2(long double mF2)      { m_f2 = mF2; }
void   Point::setF3(long double mF3)      { m_f3 = mF3; }
void   Point::setF4(long double mF4)      { m_f4 = mF4; }
void   Point::setF5(long double mF5)      { m_f5 = mF5; }
void   Point::setF6(long double mF6)      { m_f6 = mF6; }
// =====================================================================================================================

void Point::displayPoint()
{
    std::cout << "Time : " << this->getHour();
    std::cout << ":" << this->getMinute();
    std::cout << ":" << this->getSecond();
    std::cout << "." << this->getMs() << std::endl;
    std::cout << std::setprecision(9) << "Long : " << this->getLong() << std::endl;
    std::cout << std::setprecision(9) << "Lat : "  << this->getLat() << std::endl;
    std::cout << "F1 : " << this->getF1() << std::endl;
    std::cout << "F2 : " << this->getF2() << std::endl;
    std::cout << "F3 : " << this->getF3() << std::endl;
    std::cout << "F4 : " << this->getF4() << std::endl;
    std::cout << "F5 : " << this->getF5() << std::endl;
    std::cout << "F6 : " << this->getF6() << "\n" << std::endl;
}