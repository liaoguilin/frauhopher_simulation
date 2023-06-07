#include "frauhopher_sim.h"
#include "qcustomplot.h"
#include "ui_frauhopher_sim.h"
//#include <gsl/gsl_sf_bessel.h>
#include <onlyfor_parameter.h>
//#include <unistd.h>
#include<QtDebug>
//#include<QPixmap>
double wavelength=589e-9;
double I0 = 1;
double a = 0.5e-2;
double b = 0.5e-2;
double distance = 10e-2;
double h0,v0,z;
double d = 0.01e-2;
frauhopher_sim::frauhopher_sim(QWidget *parent):QMainWindow(parent), ui(new Ui::frauhopher_sim)
{
//    QPixmap img = QPixmap::QPixmap("C:/Users/srady/Desktop/frauhofer_simulation/1.jpg");
//    QPixmap img = QPixmap::QPixmap("C:/Users/srady/Desktop/frauhofer_simulation/1.jpg");
//    ui->label_5->setPixmap(img);
    ui->setupUi(this);
    ui->customPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom); // this will also allow rescaling the color scale by dragging/zooming
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->xAxis->setLabel("x cm");
    ui->customPlot->yAxis->setLabel("y cm");
    colorMap = new QCPColorMap(ui->customPlot->xAxis, ui->customPlot->yAxis);
    this->colorMap->data()->setSize(nx, ny); // we want the color map to have nx * ny data points
    colorMap->data()->setRange(QCPRange(-0.005, 0.005), QCPRange(-0.005, 0.005)); // and span the coordinate range -4..4 in both key (x) and value (y) dimensions
    for (int xIndex=0; xIndex<nx; ++xIndex)
    {
        for (int yIndex=0; yIndex<ny; ++yIndex)
        {
            colorMap->data()->cellToCoord(xIndex, yIndex, &h0, &v0);
//            z = I0*qPow(qSin(h0*wavelength*a/distance),2)*qPow(qSin(v0*wavelength*b/distance),2)/(h0*h0*v0*v0);
            z = I0*qPow(qSin(h0*a/(distance*wavelength)),2)*qPow(qSin(v0*b/(distance*wavelength)),2)/(h0*h0*v0*v0);
            colorMap->data()->setCell(xIndex, yIndex, z);
//            qDebug()<<"nx原始1"<<nx<<"ny"<<ny;
        }
    }
    QCPColorScale *colorScale = new QCPColorScale(ui->customPlot);
    ui->customPlot->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
    colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
    colorMap->setColorScale(colorScale); // associate the color map with the color scale
    colorScale->axis()->setLabel("light Strength");
    colorMap->setGradient(QCPColorGradient::gpHot);
    colorMap->rescaleDataRange();
    QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
    ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    ui->customPlot->replot();
    ui->customPlot->rescaleAxes();

//    qDebug()<<"nx原始2"<<nx<<"ny"<<ny;
//    setCentralWidget(ui->customPlot);

}
frauhopher_sim::~frauhopher_sim()
{

    delete ui;
}
void frauhopher_sim::on_lineEdit_editingFinished()
{
    wavelength = ui->lineEdit->text().toDouble()*1e-9;
    delete[] colorMap->mMapData->mData;
    colorMap->mMapData->mData = new double[size_t(colorMap->mMapData->va11*colorMap->mMapData->val2)];
    for (int xIndex=0; xIndex<nx; ++xIndex)
    {
        for (int yIndex=0; yIndex<ny; ++yIndex)
        {
            colorMap->data()->cellToCoord(xIndex, yIndex, &h0, &v0);
            z = I0*qPow(qSin(h0*a/(distance*wavelength)),2)*qPow(qSin(v0*b/(distance*wavelength)),2)/(h0*h0*v0*v0);
            colorMap->data()->setCell(xIndex, yIndex, z);
        }
    }
    colorMap->rescaleDataRange(true);
    ui->customPlot->replot();
}
void frauhopher_sim::on_lineEdit_2_editingFinished()
{
    a = ui->lineEdit_2->text().toDouble()*1e-2;
    delete[] colorMap->mMapData->mData;
    colorMap->mMapData->mData = new double[size_t(colorMap->mMapData->va11*colorMap->mMapData->val2)];
    for (int xIndex=0; xIndex<nx; ++xIndex)
    {
        for (int yIndex=0; yIndex<ny; ++yIndex)
        {
            colorMap->data()->cellToCoord(xIndex, yIndex, &h0, &v0);
            z = I0*qPow(qSin(h0*a/(distance*wavelength)),2)*qPow(qSin(v0*b/(distance*wavelength)),2)/(h0*h0*v0*v0);
            colorMap->data()->setCell(xIndex, yIndex, z);
        }
    }
    colorMap->rescaleDataRange(true);
    ui->customPlot->replot();
}
void frauhopher_sim::on_lineEdit_3_editingFinished()
{
    b = ui->lineEdit_3->text().toDouble()*1e-2;
    delete[] colorMap->mMapData->mData;
    colorMap->mMapData->mData = new double[size_t(colorMap->mMapData->va11*colorMap->mMapData->val2)];
    for (int xIndex=0; xIndex<nx; ++xIndex)
    {
        for (int yIndex=0; yIndex<ny; ++yIndex)
        {
            colorMap->data()->cellToCoord(xIndex, yIndex, &h0, &v0);
            z = I0*qPow(qSin(h0*a/(distance*wavelength)),2)*qPow(qSin(v0*b/(distance*wavelength)),2)/(h0*h0*v0*v0);
            colorMap->data()->setCell(xIndex, yIndex, z);
        }
    }
    colorMap->rescaleDataRange(true);
    ui->customPlot->replot();
}
void frauhopher_sim::on_lineEdit_4_editingFinished()
{
    distance = ui->lineEdit_4->text().toDouble()*1e-2;
    delete[] colorMap->mMapData->mData;
    colorMap->mMapData->mData = new double[size_t(colorMap->mMapData->va11*colorMap->mMapData->val2)];
    for (int xIndex=0; xIndex<nx; ++xIndex)
    {
        for (int yIndex=0; yIndex<ny; ++yIndex)
        {
            colorMap->data()->cellToCoord(xIndex, yIndex, &h0, &v0);
            z = I0*qPow(qSin(h0*a/(distance*wavelength)),2)*qPow(qSin(v0*b/(distance*wavelength)),2)/(h0*h0*v0*v0);
            colorMap->data()->setCell(xIndex, yIndex, z);
        }
    }
    colorMap->rescaleDataRange(true);
    ui->customPlot->replot();
}
void frauhopher_sim::on_comboBox_currentTextChanged(const QString &arg1)
{
//    qDebug()<<arg1
    delete[] colorMap->mMapData->mData;
    if(arg1 == "矩形孔")
    {
        colorMap->mMapData->mData = new double[size_t(colorMap->mMapData->va11*colorMap->mMapData->val2)];
        for (int xIndex=0; xIndex<nx; ++xIndex)
        {
            for (int yIndex=0; yIndex<ny; ++yIndex)
            {
                colorMap->data()->cellToCoord(xIndex, yIndex, &h0, &v0);
                z = I0*qPow(qSin(h0*a/(distance*wavelength)),2)*qPow(qSin(v0*b/(distance*wavelength)),2)/(h0*h0*v0*v0);
                colorMap->data()->setCell(xIndex, yIndex, z);
            }
        }
        colorMap->rescaleDataRange(true);
        ui->customPlot->replot();
    }
    if(arg1 == "双缝")
    {
        colorMap->mMapData->mData = new double[size_t(colorMap->mMapData->va11*colorMap->mMapData->val2)];
        for (int xIndex=0; xIndex<nx; ++xIndex)
        {
            for (int yIndex=0; yIndex<ny; ++yIndex)
            {
                colorMap->data()->cellToCoord(xIndex, yIndex, &h0, &v0);
                z = I0*qPow(qSin(h0*a/(distance*wavelength)),2)*qPow(qSin(h0*d*3.14/(distance*wavelength)),2)/(h0*h0);
                colorMap->data()->setCell(xIndex, yIndex, z);
            }
        }
        colorMap->rescaleDataRange(true);
        ui->customPlot->replot();
    }

}

