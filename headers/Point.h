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
        Point(int hour, int minute, int second, int ms, double mLong, double lat, double f1, double f2, double f3, double f4, double f5, double f6);
        ~Point();

        int    getHour() const;
        int    getMinute() const;
        int    getSecond() const;
        int    getMs() const;
        double getLong() const;
        double getLat() const;
        double getF1() const;
        double getF2() const;
        double getF3() const;
        double getF4() const;
        double getF5() const;
        double getF6() const;

        void   setHour(int mHour);
        void   setMinute(int mMinute);
        void   setSecond(int mSecond);
        void   setMs(int mMs);
        void   setLong(double mLong);
        void   setLat(double mLat);
        void   setF1(double mF1);
        void   setF2(double mF2);
        void   setF3(double mF3);
        void   setF4(double mF4);
        void   setF5(double mF5);
        void   setF6(double mF6);

        void displayPoint();



private:

        int m_hour;
        int m_minute;
        int m_second;
        int m__ms;

        double m_long;
        double m_lat;
        double m_f1;
        double m_f2;
        double m_f3;
        double m_f4;
        double m_f5;
        double m_f6;
};

#endif //POST_TRAITEMENT_POINT_H
