/**
* @file main.cpp
* Implementation of main() function.
*
* @author Deep Aggarwal
* @date Summer 2012
**/

#include <QApplication>
#include "calcGPA.h"

int main(int argv, char **args)
{
    QApplication app(argv, args);

    calcGPA calc;   //creating object of type calcGPA
    calc.show();    //calling show() on calc to display the widget. The show function is inherited from QWidget class

    return app.exec();
}
