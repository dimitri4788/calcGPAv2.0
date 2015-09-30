/**
* @file calcGPA.cpp
* Implementation of calcGPA class.
*
* @author Deep Aggarwal
* @date Summer 2012
**/

#include "calcGPA.h"

//Default Constructor for class calcGPA
calcGPA::calcGPA()
{
    QWidget* parentWidget = new QWidget;  //This is the parent widget (parent of all the other inside children-widgets)
    setCentralWidget(parentWidget);

    //initializing variables and allocating space on heap
    number_of_textboxes = 4;
    courses = 7;
    /***gpa (left side)***/
    letterGrade = new QLabel(tr("Letter Grade"));
    creditHours = new QLabel(tr("Credit hours"));
    courselabels = new QLabel[courses];
    lineEditLetter = new QLineEdit[courses];
    lineEditCredits = new QLineEdit[courses];
    dispButton1 = new QPushButton(tr("Calculate GPA"));
    /***Common data***/
    aboutAction = new QAction(tr("&About"), this);
    line = new QFrame();
    quitButton = new QPushButton(tr("Quit"));
    /***goalGPA (right side)***/
    labels = new QLabel[number_of_textboxes];
    lineEdit = new QLineEdit[number_of_textboxes];
    dispButton2 = new QPushButton(tr("Required GPA"));

    //connecting buttons to the receiver
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
    connect(dispButton1, SIGNAL(clicked()), this, SLOT(display1()));
    connect(dispButton2, SIGNAL(clicked()), this, SLOT(display2()));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));

    //adding "About" to the menu
    aboutMenu = menuBar()->addMenu(tr("&About"));
    aboutMenu->addAction(aboutAction);

    //giving names to the labels
    (labels+0)->setText("Current GPA");
    (labels+1)->setText("Current Total Credit Hours");
    (labels+2)->setText("Goal GPA");
    (labels+3)->setText("Additional Credits");
    for(int i=0; i<courses; i++)
    {
        (courselabels+i)->setText(tr("Course %1").arg(i+1));
    }

    //adding all the widgets to the layout
    QGridLayout* layout = new QGridLayout;

    //Filling Left side
    layout->addWidget(letterGrade, 0, 1);
    layout->addWidget(creditHours, 0, 2);
    for(int j=0; j<courses; j++)
    {
        layout->addWidget(courselabels+j, j+1, 0);
        layout->addWidget(lineEditLetter+j, j+1, 1);
        layout->addWidget(lineEditCredits+j, j+1, 2);
    }
    layout->addWidget(dispButton1,8,2,2,1);
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Plain);
    line->setLineWidth(4);
    layout->addWidget(line,0,3,10,2);


    //Filling Right side
    for(int k=0; k<number_of_textboxes; k++)
    {
        layout->addWidget(labels+k,k,7);
        layout->addWidget(lineEdit+k,k,8);
        //layout->addSpacing(20);
    }
    layout->addWidget(dispButton2,4,8,2,1);
    layout->addWidget(quitButton,5,8,2,1);

    //setting background color of the widget
    QPalette Pal(palette());
    QColor cc;
    int a = 255;
    cc.setRgb(255 ,239 ,219 , a );
    Pal.setColor(QPalette::Background, cc);
    parentWidget->setAutoFillBackground(true);
    parentWidget->setPalette(Pal);

    parentWidget->setLayout(layout);  //The parent widget contains the above defined layout
    setWindowTitle(tr("calcGPA"));

}

void calcGPA::display1()
{
    QMessageBox messageBox;
    bool errorMessage = false;  //Do not show error message by default
    float inputCredits[courses];
    QString inputLetters[courses];
    float actualAquiredCredits[courses];

    //Errors checking starts
    for(int i=0; i<courses; i++)
    {
        if(lineEditLetter[i].text() == "")
            continue;
        if(lineEditLetter[i].text().size() > 2)
        {
            errorMessage = true;
        }
        if(lineEditLetter[i].text().size() == 2)
        {
            if( lineEditLetter[i].text().at(0) != 'A' &&  lineEditLetter[i].text().at(0) != 'B' &&
                    lineEditLetter[i].text().at(0) != 'C' && lineEditLetter[i].text().at(0) != 'D' &&
                    lineEditLetter[i].text().at(0) != 'E' && lineEditLetter[i].text().at(0) != 'F')
            {
                errorMessage = true;
            }
            if( lineEditLetter[i].text().at(1) != '+' &&  lineEditLetter[i].text().at(1) != '-' &&
                    lineEditLetter[i].text().at(1).isNull() == false)
            {
                errorMessage = true;
            }
        }
        else if(lineEditLetter[i].text().size() == 1)
        {
            if( lineEditLetter[i].text().at(0) != 'A' &&  lineEditLetter[i].text().at(0) != 'B' &&
                    lineEditLetter[i].text().at(0) != 'C' && lineEditLetter[i].text().at(0) != 'D' &&
                    lineEditLetter[i].text().at(0) != 'E' && lineEditLetter[i].text().at(0) != 'F')
            {
                errorMessage = true;
            }
        }
        //qDebug() <<lineEditLetter[i].text().at(0)<<endl;
        //qDebug() <<lineEditLetter[i].text().at(1)<<endl;

        bool ok1, ok2;
        inputLetters[i] = (lineEditLetter[i].text()).toFloat(&ok1);
        inputCredits[i] = (lineEditCredits[i].text()).toFloat(&ok2);
        if(ok1==true || ok2==false)
            errorMessage=true;
        if((lineEditCredits[i].text()).toFloat(&ok2)<0) //|| (lineEditCredits[i].text()).toFloat(&ok2)>5)
            errorMessage=true;
    }
    //Errors checking ends

    if(errorMessage==false)
    {
        for(int i=0; i<courses; i++)
        {
            if(lineEditLetter[i].text() == "")
                continue;
            inputLetters[i] = (lineEditLetter[i].text());
            inputCredits[i] = (lineEditCredits[i].text()).toFloat();
            if(inputLetters[i]=="A+")
                actualAquiredCredits[i]=4;
            if(inputLetters[i]=="A")
                actualAquiredCredits[i]=4;
            if(inputLetters[i]=="A-")
                actualAquiredCredits[i]=3.67;
            if(inputLetters[i]=="B+")
                actualAquiredCredits[i]=3.33;
            if(inputLetters[i]=="B")
                actualAquiredCredits[i]=3;
            if(inputLetters[i]=="B-")
                actualAquiredCredits[i]=2.67;
            if(inputLetters[i]=="C+")
                actualAquiredCredits[i]=2.33;
            if(inputLetters[i]=="C")
                actualAquiredCredits[i]=2;
            if(inputLetters[i]=="C-")
                actualAquiredCredits[i]=1.67;
            if(inputLetters[i]=="D+")
                actualAquiredCredits[i]=1.33;
            if(inputLetters[i]=="D")
                actualAquiredCredits[i]=1;
            if(inputLetters[i]=="D-")
                actualAquiredCredits[i]=0.67;
            if(inputLetters[i]=="E+")
                actualAquiredCredits[i]=0.33;
            if(inputLetters[i]=="E")
                actualAquiredCredits[i]=0;
            if(inputLetters[i]=="E-")
                actualAquiredCredits[i]=0;
            if(inputLetters[i]=="F+")
                actualAquiredCredits[i]=0;
            if(inputLetters[i]=="F")
                actualAquiredCredits[i]=0;
            if(inputLetters[i]=="F-")
                actualAquiredCredits[i]=0;
        }

        float acquiredGpa;
        float totalSumOfActualCreditsTimesCourseCredits = 0.0;
        float totalSumOfCourseCredits = 0.0;
        for(int j=0; j<courses; j++)
        {
            if(lineEditLetter[j].text() == "")
                continue;
            totalSumOfActualCreditsTimesCourseCredits = totalSumOfActualCreditsTimesCourseCredits +
                    actualAquiredCredits[j]*inputCredits[j];

            totalSumOfCourseCredits = totalSumOfCourseCredits + inputCredits[j];
        }
        acquiredGpa = totalSumOfActualCreditsTimesCourseCredits / totalSumOfCourseCredits;

        messageBox.setText(tr("Your GPA is %1, Good Work!").arg(acquiredGpa,0,'g',3));
        messageBox.setStandardButtons(QMessageBox::Close);
        if (messageBox.exec()==QMessageBox::Close)
            messageBox.close();
    }
    else //when there is an error
    {
        messageBox.setText(tr("Error: You have entered invalid value."));
        messageBox.setStandardButtons(QMessageBox::Close);
        if (messageBox.exec()==QMessageBox::Close)
            messageBox.close();
    }

}

void calcGPA::display2()
{
    QMessageBox messageBox;
    bool errorMessage = false;  //Do not show error message by default
    float inputValues[number_of_textboxes];

    for(int i=0; i<number_of_textboxes; i++)
    {
        bool ok;
        inputValues[i] = (lineEdit[i].text()).toFloat(&ok);
        if(ok==false)
            errorMessage=true;
        if((lineEdit[0].text()).toFloat(&ok)<0 || (lineEdit[0].text()).toFloat(&ok)>4)
            errorMessage=true;
        if((lineEdit[2].text()).toFloat(&ok)<0.0 || (lineEdit[2].text()).toFloat(&ok)>4.0)
            errorMessage=true;
    }

    //Initializing the variables
    float currGPA = inputValues[0];
    float cumTotalCred = inputValues[1];
    float goalGPA = inputValues[2];
    float additionalCredits = inputValues[3];

    //find goal points
    float points = 0.0;
    points = goalGPA * (cumTotalCred + additionalCredits);

    // Find points needed now
    points = points - (currGPA * cumTotalCred);

    // Calculate needed GPA
    float neededGPA = 0.0;
    bool impossibleSituation = false;
    neededGPA = (points / additionalCredits);
    if(neededGPA>4.0)
    {
        impossibleSituation = true;
    }

    if(errorMessage==false)
    {
        if(impossibleSituation==false)
            messageBox.setText(tr("Your GPA for your next %1 credits must be %2, Good Luck!")
                               .arg(additionalCredits)
                               .arg(neededGPA,0,'g',3));
        else
            messageBox.setText(tr("Your GPA for your next %1 credits must be %2, which is not possible. Sorry!")
                               .arg(additionalCredits)
                               .arg(neededGPA,0,'g',3));
        messageBox.setStandardButtons(QMessageBox::Close);
        if (messageBox.exec()==QMessageBox::Close)
            messageBox.close();
    }
    else
    {
        messageBox.setText(tr("Error: You have entered invalid value or left one/more box(es) empty."));
        messageBox.setStandardButtons(QMessageBox::Close);
        if (messageBox.exec()==QMessageBox::Close)
            messageBox.close();
    }
}

/*
* Member function(slot) about()
* It displays copyright, version and other info in the menubar
*/
void calcGPA::about()
{
    QMessageBox messageBox;
    //messageBox.setMinimumSize(400, 300);

    messageBox.setWindowTitle(tr("About calcGPA"));
    messageBox.setIconPixmap(QPixmap(":/icon.png"));
    messageBox.setText(tr("calcGPA"));
    messageBox.setInformativeText(tr("Version 2.0 \nCopyright %1 2012-2012 Deep Aggarwal. All rights reserved.")
                                  .arg(QString::fromUtf8("©")));


    QFile file(":/Copyright.txt");
    QString line;
    if (file.open(QIODevice::ReadOnly))
    {
        // file opened successfully
        QTextStream stream( &file ); // use a text stream
        while (!stream.atEnd())    // until end of file...
            line = stream.readAll();

        file.close();   // Close the file
    }

    messageBox.setDetailedText(line);
    messageBox.setStandardButtons(QMessageBox::Close);
    messageBox.exec();
}

/*
* Member function(slot) quit()
* It quits the main application when "Quit" button is clicked
*/
void calcGPA::quit()
{
    //    QMessageBox messageBox;
    //    messageBox.setWindowTitle(tr("calcGPA"));
    //    messageBox.setText(tr("Are you Sure ?"));
    //    messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    //    messageBox.setDefaultButton(QMessageBox::No);
    //    if (messageBox.exec() == QMessageBox::Yes)
    qApp->quit();
}

//Destructor for class calcGPA
calcGPA::~calcGPA()
{
    delete letterGrade;
    delete creditHours;
    delete[] courselabels;
    delete[] lineEditLetter;
    delete[] lineEditCredits;
    delete line;

    delete[] labels;
    delete[] lineEdit;
    delete quitButton;
    delete dispButton1;
    delete dispButton2;
    delete aboutAction;

}
