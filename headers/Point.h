//
// Created by vincent on 09/05/19.
//

#ifndef POST_TRAITEMENT_POINT_H
#define POST_TRAITEMENT_POINT_H

#include <string>

class Point
{

    public:

        Point();
        Point(int hour, int minute, int second, int ms, long double mLong, long double lat, long double f1, long double f2, long double f3, long double f4, long double f5, long double f6);
        ~Point();

        int    getHour() const;
        int    getMinute() const;
        int    getSecond() const;
        int    getMs() const;
        long double getLong() const;
        long double getLat() const;
        long double getF1() const;
        long double getF2() const;
        long double getF3() const;
        long double getF4() const;
        long double getF5() const;
        long double getF6() const;

        void   setHour(int mHour);
        void   setMinute(int mMinute);
        void   setSecond(int mSecond);
        void   setMs(int mMs);
        void   setLong(long double mLong);
        void   setLat(long double mLat);
        void   setF1(long double mF1);
        void   setF2(long double mF2);
        void   setF3(long double mF3);
        void   setF4(long double mF4);
        void   setF5(long double mF5);
        void   setF6(long double mF6);

        void displayPoint();



private:

        int m_hour;
        int m_minute;
        int m_second;
        int m__ms;

        long double m_long;
        long double m_lat;
        long double m_f1;
        long double m_f2;
        long double m_f3;
        long double m_f4;
        long double m_f5;
        long double m_f6;
};

#endif //POST_TRAITEMENT_POINT_H
