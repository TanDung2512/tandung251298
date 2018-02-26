/********************************************************************************
** Form generated from reading UI file 'registeraccount.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERACCOUNT_H
#define UI_REGISTERACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_RegisterAccount
{
public:

    void setupUi(QDialog *RegisterAccount)
    {
        if (RegisterAccount->objectName().isEmpty())
            RegisterAccount->setObjectName(QStringLiteral("RegisterAccount"));
        RegisterAccount->resize(300, 400);

        retranslateUi(RegisterAccount);

        QMetaObject::connectSlotsByName(RegisterAccount);
    } // setupUi

    void retranslateUi(QDialog *RegisterAccount)
    {
        RegisterAccount->setWindowTitle(QApplication::translate("RegisterAccount", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterAccount: public Ui_RegisterAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERACCOUNT_H
