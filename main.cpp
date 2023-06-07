
#include "frauhopher_sim.h"

#include <QApplication>
#include <gsl/gsl_math.h>
//#include <gsl/gsl_sf_bessel.h>
#include <onlyfor_parameter.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    double x = 5.0;
//    double y = gsl_sf_bessel_J0 (x);
    printf ("J0(%g) = %.18e\n", x, M_E);
    frauhopher_sim w;
    w.show();
    return a.exec();
}
