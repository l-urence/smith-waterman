#ifndef GUI_H
#define GUI_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QTextEdit;
QT_END_NAMESPACE

//! [class definition]
class Gui : public QWidget
{
    Q_OBJECT

public:
    Gui(QWidget *parent = 0);

private:
    QLineEdit *nameLine;
    QTextEdit *addressText;
};
//! [class definition]

#endif
