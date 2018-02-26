/********************************************************************************
** Form generated from reading UI file 'adminc.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINC_H
#define UI_ADMINC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Adminc
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *Adminc)
    {
        if (Adminc->objectName().isEmpty())
            Adminc->setObjectName(QStringLiteral("Adminc"));
        Adminc->resize(300, 60);
        label = new QLabel(Adminc);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 100, 30));
        lineEdit = new QLineEdit(Adminc);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 0, 200, 30));
        pushButton = new QPushButton(Adminc);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 30, 300, 30));

        retranslateUi(Adminc);

        QMetaObject::connectSlotsByName(Adminc);
    } // setupUi

    void retranslateUi(QDialog *Adminc)
    {
        Adminc->setWindowTitle(QApplication::translate("Adminc", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Adminc", "Admin Password:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Adminc", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Adminc: public Ui_Adminc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINC_H
