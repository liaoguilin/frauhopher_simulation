QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    frauhopher_sim.cpp \
    main.cpp \
    qcustomplot.cpp

HEADERS += \
    frauhopher_sim.h \
    onlyfor_parameter.h \
    qcustomplot.h

FORMS += \
    frauhopher_sim.ui

#INCLUDEPATH += "D:/dev/temp/gsl/GnuWin32/include"
#INCLUDEPATH += "D:/dev/CUSTOM_LIB/qt/QCustomPlot"
#LIBS += -L"D:/dev/temp/gsl/GnuWin32/lib" -llibgsl -llibgslcblas -lm

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
