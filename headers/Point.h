//
// Created by vincent on 09/05/19.
//

#ifndef POST_TRAITEMENT_POINT_H
#define POST_TRAITEMENT_POINT_H

#include <string>

class Point
{

    public:
        int getHour() const;

        void setHour(int mHour);

        int getMinute() const;

        void setMinute(int mMinute);

        int getSecond() const;

        void setSecond(int mSecond);

        int getMs() const;

        void setMs(int mMs);

        double getLong() const;

        void setLong(double mLong);

        double getLat() const;

        void setLat(double mLat);

        double getF1() const;

        void setF1(double mF1);

        double getF2() const;

        void setF2(double mF2);

        double getF3() const;

        void setF3(double mF3);

        double getF4() const;

        void setF4(double mF4);

        double getF5() const;

        void setF5(double mF5);

        double getF6() const;

        void setF6(double mF6);

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
