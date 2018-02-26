/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Note;
    QHBoxLayout *horizontalLayout;
    QPushButton *YES;
    QPushButton *NO;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(300, 100);
        Register->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(Register);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 281, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Note = new QLabel(layoutWidget);
        Note->setObjectName(QStringLiteral("Note"));
        QFont font;
        font.setFamily(QStringLiteral("Gill Sans MT"));
        font.setPointSize(20);
        Note->setFont(font);

        verticalLayout->addWidget(Note);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        YES = new QPushButton(layoutWidget);
        YES->setObjectName(QStringLiteral("YES"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        YES->setFont(font1);
        YES->setStyleSheet(QLatin1String("background-color: rgb(0, 255, 0);\n"
"alternate-background-color: rgb(0, 255, 0);"));

        horizontalLayout->addWidget(YES);

        NO = new QPushButton(layoutWidget);
        NO->setObjectName(QStringLiteral("NO"));
        NO->setFont(font1);
        NO->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));

        horizontalLayout->addWidget(NO);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Dialog", Q_NULLPTR));
        Note->setText(QApplication::translate("Register", "Have You Had An User?", Q_NULLPTR));
        YES->setText(QApplication::translate("Register", "NO", Q_NULLPTR));
        NO->setText(QApplication::translate("Register", "YES", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
