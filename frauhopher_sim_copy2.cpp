#include "frauhopher_sim.h"
#include "ui_frauhopher_sim_oopy.h"
#include <gsl/gsl_sf_bessel.h>


frauhopher_sim::frauhopher_sim(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::frauhopher_sim)
{
    ui->setupUi(this);
    // configure axis rect:
    ui->customPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom); // this will also allow rescaling the color scale by dragging/zooming
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    int nx = 200;
    int ny = 200;
    double x, y, z;
    double wavelength,distance,x0,y0,I0,a,b;
    I0 = 0.5;
    wavelength = 0.5;
    a = 1;
    b = 1;
    distance = 0.5;

    // set up the QCPColorMap:
    QCPColorMap *colorMap = new QCPColorMap(ui->customPlot->xAxis, ui->customPlot->yAxis);

    colorMap->data()->setSize(nx, ny); // we want the color map to have nx * ny data points
    colorMap->data()->setRange(QCPRange(-10, 10), QCPRange(-10, 10)); // and span the coordinate range -4..4 in both key (x) and value (y) dimensions
    // now we assign some data, by accessing the QCPColorMapData instance of the color map:

    frauhopher_sim::on_lineEdit_editingFinished();

    for (int xIndex=0; xIndex<nx; ++xIndex)
    {
        for (int yIndex=0; yIndex<ny; ++yIndex)
        {
            colorMap->data()->cellToCoord(xIndex, yIndex, &x0, &y0);
//            double r = 3*qSqrt(x*x+y*y)+1e-2;
//            z = 2*x*(qCos(r+2)/r-qSin(r+2)/r); // the B field strength of dipole radiation (modulo physical constants)
            z = I0*qPow(qSin(x0*wavelength*a/distance),2)*qPow(qSin(y0*wavelength*b/distance),2)/(x0*x0*y0*y0);
//            z = I0*qPow(qSin(x0*wavelength*a/distance),2)*qPow(qSin(y0*wavelength*b/distance),2);
            colorMap->data()->setCell(xIndex, yIndex, z);
        }
    }

    // add a color scale:
    QCPColorScale *colorScale = new QCPColorScale(ui->customPlot);
    ui->customPlot->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
    colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
    colorMap->setColorScale(colorScale); // associate the color map with the color scale
    colorScale->axis()->setLabel("Magnetic Field Strength");

    // set the color gradient of the color map to one of the presets:
    colorMap->setGradient(QCPColorGradient::gpGeography);
    // we could have also created a QCPColorGradient instance and added own colors to
    // the gradient, see the documentation of QCPColorGradient for what's possible.

    // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:
    colorMap->rescaleDataRange();

    // make sure the axis rect and color scale synchronize their bottom and top margins (so they line up):
    QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
    ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

    // rescale the key (x) and value (y) axes so the whole color map is visible:
    ui->customPlot->rescaleAxes();
//    setCentralWidget(ui->customPlot);
}

frauhopher_sim::~frauhopher_sim()
{
    delete ui;
}



void frauhopher_sim::on_lineEdit_returnPressed()
{
    printf("entered!");
}
void frauhopher_sim::on_lineEdit_editingFinished()
{
    printf("entered!");

    //    printf(t.text());
    //    frauhopher_sim::
//    wavelength = ui->lineEdit->text().toDouble();
    ui->customPlot->replot();
}






