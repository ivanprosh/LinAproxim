#include "approximator.h"


void Math::aproximator(int level, QVector<double>& IN, QVector<double>& Result)
{
    Result.resize(IN.size());

    QVector<double>::iterator itNumb = IN.begin();
    QVector<double>::iterator itRes = Result.begin();

    //рассчет Y в зависимости от выбранного уровня апроксимации
    switch (level) {

    case 1:
        *(itRes) = (5*(*itNumb) + 2*(*(itNumb+1)) - *(itNumb+2))/6;

        while((++itNumb)!=IN.end())
        {
            //qDebug() << "Current y: " << *itNumb;
            if((itNumb+1) != IN.end())
               *(++itRes) = (*(itNumb-1) + *(itNumb) + *(itNumb+1))/3;
            else
               *(++itRes) = (5*(*(itNumb)) + 2*(*(itNumb-1)) - *(itNumb-2))/6;
            //qDebug() << "Current new y: " << *itRes;
        }
        break;
    case 2:

        *(itRes) = (3*(*itNumb) + 2*(*(itNumb+1)) + *(itNumb+2) - *(itNumb+4))/5;
        itRes++;itNumb++;
        *(itRes) = (4*(*itNumb-1) + 3*(*(itNumb)) + 2*(*(itNumb+1)) + *(itNumb+2))/10;

        while((++itNumb)!=IN.end())
        {
            //qDebug() << "Current y: " << *itNumb;
            if((itNumb+1) != IN.end())
                if((itNumb+2) != IN.end())
                    *(++itRes) = (*(itNumb-2) + *(itNumb-1) + *(itNumb) + *(itNumb+1) + *(itNumb+2))/5;
                else
                    *(++itRes) = (*(itNumb-2) + 2*(*(itNumb-1)) + 3*(*(itNumb)) + 4*(*(itNumb+1)))/10;
            else
                *(++itRes) = (3*(*(itNumb)) + 2*(*(itNumb-1)) + *(itNumb-2) - *(itNumb-4))/5;

                //qDebug() << "Current new y: " << *itRes;
        }
        break;
    case 3:
        //y0
        *(itRes) = (39*(*itNumb) + 8*(*(itNumb+1)) - 4*(*(itNumb+2) + *(itNumb+3) + *(itNumb+4))
                    + *(itNumb+5) - 2*(*(itNumb+6)))/42;
        itRes++;itNumb++;
        //y1
        *(itRes) = (8*(*itNumb-1) + 19*(*(itNumb)) + 16*(*(itNumb+1)) + 6*(*(itNumb+2))
                    - 4*(*(itNumb+3)) + 4*(*(itNumb+6)) )/42;
        itRes++;itNumb++;
        //y2
        *(itRes) = (-4*(*itNumb-2) + 16*(*(itNumb-1)) + 19*(*(itNumb)) + 12*(*(itNumb+1)) + 2*(*(itNumb+2))
                    + 4*(*(itNumb+3)) + *(itNumb+4) )/42;

        while((++itNumb)!=IN.end())
        {
                //qDebug() << "Current y: " << *itNumb;
                if((itNumb+1) != IN.end())
                if((itNumb+2) != IN.end())
                if((itNumb+3) != IN.end())
                *(++itRes) = (7*(*(itNumb)) + 6*(*(itNumb+1) + *(itNumb-1)) + 3*(*(itNumb+2) + *(itNumb-2))
                              - 2*(*(itNumb+3) + *(itNumb-3)))/21;
                else
                *(++itRes) = (*(itNumb-4) - 4*(*(itNumb-3)) + 2*(*(itNumb-2)) + 12*(*(itNumb-1)) + 19*(*(itNumb))
                              + 16*(*(itNumb+1)) - 4 * (*(itNumb+2)))/42;
                else
                *(++itRes) = (4*(*(itNumb-5)) - 7*(*(itNumb-4)) - 4*(*(itNumb-3)) + 6*(*(itNumb-2)) + 16*(*(itNumb - 1))
                              + 19*(*(itNumb)) + 8 * (*(itNumb+1)))/42;
                else
                *(++itRes) = (-2*(*(itNumb-6)) + 4*(*(itNumb-5)) + 1*(*(itNumb-4)) - 4*(*(itNumb-3)) - 4*(*(itNumb-2))
                              + 8*(*(itNumb - 1)) + 39*(*(itNumb)))/42;

                //qDebug() << "Current new y: " << *itRes;
        }
        break;
    default:
        break;
    }

}
