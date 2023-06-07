#ifndef FRAUHOPHER_SIM_H
#define FRAUHOPHER_SIM_H
#include <QMainWindow>
#include<qcustomplot.h>

QT_BEGIN_NAMESPACE
namespace Ui { class frauhopher_sim; }
QT_END_NAMESPACE

class frauhopher_sim : public QMainWindow

{
    Q_OBJECT

public:
    frauhopher_sim(QWidget *parent = nullptr);

    QCPColorMap *colorMap;

    ~frauhopher_sim();

private slots:

//    void on_lineEdit_returnPressed();

    void on_lineEdit_editingFinished();

//    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_3_editingFinished();

    void on_lineEdit_4_editingFinished();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::frauhopher_sim *ui;
};

#endif // FRAUHOPHER_SIM_H
