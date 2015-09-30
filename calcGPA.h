/**
* @file calcGPA.h
* Definition of calcGPA class.
*
* @author Deep Aggarwal
* @date Summer 2012
**/

#ifndef CALCGPA_H
#define CALCGPA_H

#include <QApplication>
#include <QTextEdit>
#include <QLineEdit>
#include <QtGui>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <iostream>
#include <QMenuBar>
#include <QMainWindow>
#include <QIcon>
#include <QPainter>
#include <QFile>
#include <QFrame>
#include <QGroupBox>

using namespace std;

class calcGPA : public QMainWindow //Inheriting from QMainWindow
{
    Q_OBJECT

public:
    calcGPA();
    ~calcGPA();

private slots:
    void quit();
    void display1();
    void display2();
    void about();

private:
    int number_of_textboxes;
    int courses;

    constexpr int getNumberOfCourses() const;

    /***gpa (left side)***/
    QLabel* letterGrade;
    QLabel* creditHours;
    QLineEdit* lineEditLetter;
    QLineEdit* lineEditCredits;
    QLabel* courselabels;
    QPushButton* dispButton1;

    /***goalGPA (right side)***/
    QLabel* labels;
    QLineEdit* lineEdit;
    QPushButton* dispButton2;

    QAction* aboutAction;
    QMenu* aboutMenu;
    QFrame* line;// to add seperator
    QPushButton* quitButton;

};

#endif // CALCGPA_H

