/********************************************************************************
** Form generated from reading UI file 'jpeg2000transcoder.ui'
**
** Created: Fri 14. Sep 15:15:49 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JPEG2000TRANSCODER_H
#define UI_JPEG2000TRANSCODER_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Jpeg2000TranscoderClass
{
public:
    QAction *actionHow_to_use_transcoder;
    QAction *actionAbout_Jpeg2000Transcoder;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *inputFileLabel;
    QLineEdit *inputFileLineEdit;
    QPushButton *chooseInputFileButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *outputFolderLabel;
    QLineEdit *outputFolderLineEdit;
    QPushButton *chooseOutputFolderButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *formatLabel;
    QComboBox *formatComboBox;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *profileDisplayGroupBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *profileDisplayTextEdit;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *MessageBoxGroupBox;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *messageBoxTextEdit;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *transcodeButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menuHelp;

    void setupUi(QMainWindow *Jpeg2000TranscoderClass)
    {
        if (Jpeg2000TranscoderClass->objectName().isEmpty())
            Jpeg2000TranscoderClass->setObjectName(QString::fromUtf8("Jpeg2000TranscoderClass"));
        Jpeg2000TranscoderClass->resize(626, 551);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Jpeg2000TranscoderClass->sizePolicy().hasHeightForWidth());
        Jpeg2000TranscoderClass->setSizePolicy(sizePolicy);
        Jpeg2000TranscoderClass->setMaximumSize(QSize(16777215, 16777215));
        actionHow_to_use_transcoder = new QAction(Jpeg2000TranscoderClass);
        actionHow_to_use_transcoder->setObjectName(QString::fromUtf8("actionHow_to_use_transcoder"));
        actionHow_to_use_transcoder->setText(QString::fromUtf8("How to use transcoder"));
        actionAbout_Jpeg2000Transcoder = new QAction(Jpeg2000TranscoderClass);
        actionAbout_Jpeg2000Transcoder->setObjectName(QString::fromUtf8("actionAbout_Jpeg2000Transcoder"));
        actionAbout_Jpeg2000Transcoder->setText(QString::fromUtf8("About Jpeg2000Transcoder"));
        centralWidget = new QWidget(Jpeg2000TranscoderClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        inputFileLabel = new QLabel(centralWidget);
        inputFileLabel->setObjectName(QString::fromUtf8("inputFileLabel"));
        inputFileLabel->setMinimumSize(QSize(93, 0));

        horizontalLayout_2->addWidget(inputFileLabel);

        inputFileLineEdit = new QLineEdit(centralWidget);
        inputFileLineEdit->setObjectName(QString::fromUtf8("inputFileLineEdit"));
        inputFileLineEdit->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(inputFileLineEdit->sizePolicy().hasHeightForWidth());
        inputFileLineEdit->setSizePolicy(sizePolicy1);
        inputFileLineEdit->setLocale(QLocale(QLocale::Czech, QLocale::CzechRepublic));
        inputFileLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(inputFileLineEdit);

        chooseInputFileButton = new QPushButton(centralWidget);
        chooseInputFileButton->setObjectName(QString::fromUtf8("chooseInputFileButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(chooseInputFileButton->sizePolicy().hasHeightForWidth());
        chooseInputFileButton->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(chooseInputFileButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        outputFolderLabel = new QLabel(centralWidget);
        outputFolderLabel->setObjectName(QString::fromUtf8("outputFolderLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(outputFolderLabel->sizePolicy().hasHeightForWidth());
        outputFolderLabel->setSizePolicy(sizePolicy3);
        outputFolderLabel->setMinimumSize(QSize(93, 0));

        horizontalLayout_3->addWidget(outputFolderLabel);

        outputFolderLineEdit = new QLineEdit(centralWidget);
        outputFolderLineEdit->setObjectName(QString::fromUtf8("outputFolderLineEdit"));
        outputFolderLineEdit->setEnabled(true);
        sizePolicy1.setHeightForWidth(outputFolderLineEdit->sizePolicy().hasHeightForWidth());
        outputFolderLineEdit->setSizePolicy(sizePolicy1);
        outputFolderLineEdit->setLocale(QLocale(QLocale::Czech, QLocale::CzechRepublic));
        outputFolderLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(outputFolderLineEdit);

        chooseOutputFolderButton = new QPushButton(centralWidget);
        chooseOutputFolderButton->setObjectName(QString::fromUtf8("chooseOutputFolderButton"));
        sizePolicy2.setHeightForWidth(chooseOutputFolderButton->sizePolicy().hasHeightForWidth());
        chooseOutputFolderButton->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(chooseOutputFolderButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        formatLabel = new QLabel(centralWidget);
        formatLabel->setObjectName(QString::fromUtf8("formatLabel"));
        sizePolicy2.setHeightForWidth(formatLabel->sizePolicy().hasHeightForWidth());
        formatLabel->setSizePolicy(sizePolicy2);
        formatLabel->setMinimumSize(QSize(93, 0));

        horizontalLayout_4->addWidget(formatLabel);

        formatComboBox = new QComboBox(centralWidget);
        formatComboBox->setObjectName(QString::fromUtf8("formatComboBox"));
        sizePolicy1.setHeightForWidth(formatComboBox->sizePolicy().hasHeightForWidth());
        formatComboBox->setSizePolicy(sizePolicy1);
        formatComboBox->setMaximumSize(QSize(16777215, 16777215));
        formatComboBox->setLocale(QLocale(QLocale::Czech, QLocale::CzechRepublic));
        formatComboBox->setMaxVisibleItems(30);

        horizontalLayout_4->addWidget(formatComboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        profileDisplayGroupBox = new QGroupBox(centralWidget);
        profileDisplayGroupBox->setObjectName(QString::fromUtf8("profileDisplayGroupBox"));
        sizePolicy.setHeightForWidth(profileDisplayGroupBox->sizePolicy().hasHeightForWidth());
        profileDisplayGroupBox->setSizePolicy(sizePolicy);
        profileDisplayGroupBox->setMinimumSize(QSize(0, 120));
        profileDisplayGroupBox->setMaximumSize(QSize(16777215, 110));
        verticalLayout_3 = new QVBoxLayout(profileDisplayGroupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        profileDisplayTextEdit = new QTextEdit(profileDisplayGroupBox);
        profileDisplayTextEdit->setObjectName(QString::fromUtf8("profileDisplayTextEdit"));
        profileDisplayTextEdit->setEnabled(true);
        sizePolicy.setHeightForWidth(profileDisplayTextEdit->sizePolicy().hasHeightForWidth());
        profileDisplayTextEdit->setSizePolicy(sizePolicy);
        profileDisplayTextEdit->setAcceptDrops(false);
        profileDisplayTextEdit->setLocale(QLocale(QLocale::Czech, QLocale::CzechRepublic));
        profileDisplayTextEdit->setReadOnly(true);

        verticalLayout_2->addWidget(profileDisplayTextEdit);


        verticalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_6->addWidget(profileDisplayGroupBox);


        verticalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        MessageBoxGroupBox = new QGroupBox(centralWidget);
        MessageBoxGroupBox->setObjectName(QString::fromUtf8("MessageBoxGroupBox"));
        sizePolicy.setHeightForWidth(MessageBoxGroupBox->sizePolicy().hasHeightForWidth());
        MessageBoxGroupBox->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(MessageBoxGroupBox);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        messageBoxTextEdit = new QTextEdit(MessageBoxGroupBox);
        messageBoxTextEdit->setObjectName(QString::fromUtf8("messageBoxTextEdit"));
        sizePolicy.setHeightForWidth(messageBoxTextEdit->sizePolicy().hasHeightForWidth());
        messageBoxTextEdit->setSizePolicy(sizePolicy);
        messageBoxTextEdit->setMinimumSize(QSize(0, 0));
        messageBoxTextEdit->setAcceptDrops(false);
        messageBoxTextEdit->setLocale(QLocale(QLocale::Czech, QLocale::CzechRepublic));
        messageBoxTextEdit->setReadOnly(true);

        verticalLayout_4->addWidget(messageBoxTextEdit);


        verticalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_7->addWidget(MessageBoxGroupBox);


        verticalLayout->addLayout(verticalLayout_7);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy4);
        progressBar->setValue(0);
        progressBar->setTextVisible(true);

        verticalLayout->addWidget(progressBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        transcodeButton = new QPushButton(centralWidget);
        transcodeButton->setObjectName(QString::fromUtf8("transcodeButton"));
        transcodeButton->setMinimumSize(QSize(120, 30));
        transcodeButton->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(transcodeButton);

        cancelButton = new QPushButton(centralWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setEnabled(false);
        sizePolicy2.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy2);
        cancelButton->setMinimumSize(QSize(120, 30));
        cancelButton->setMaximumSize(QSize(120, 16777215));

        horizontalLayout->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        Jpeg2000TranscoderClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Jpeg2000TranscoderClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 626, 21));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuHelp->setTitle(QString::fromUtf8("Help"));
        Jpeg2000TranscoderClass->setMenuBar(menuBar);

        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionHow_to_use_transcoder);
        menuHelp->addAction(actionAbout_Jpeg2000Transcoder);

        retranslateUi(Jpeg2000TranscoderClass);

        QMetaObject::connectSlotsByName(Jpeg2000TranscoderClass);
    } // setupUi

    void retranslateUi(QMainWindow *Jpeg2000TranscoderClass)
    {
        Jpeg2000TranscoderClass->setWindowTitle(QApplication::translate("Jpeg2000TranscoderClass", "Jpeg2000Transcoder", 0, QApplication::UnicodeUTF8));
        inputFileLabel->setText(QApplication::translate("Jpeg2000TranscoderClass", "Input File:", 0, QApplication::UnicodeUTF8));
        chooseInputFileButton->setText(QApplication::translate("Jpeg2000TranscoderClass", "Choose", 0, QApplication::UnicodeUTF8));
        outputFolderLabel->setText(QApplication::translate("Jpeg2000TranscoderClass", "Output Folder:", 0, QApplication::UnicodeUTF8));
        chooseOutputFolderButton->setText(QApplication::translate("Jpeg2000TranscoderClass", "Choose", 0, QApplication::UnicodeUTF8));
        formatLabel->setText(QApplication::translate("Jpeg2000TranscoderClass", "Predefined Profile:", 0, QApplication::UnicodeUTF8));
        profileDisplayGroupBox->setTitle(QApplication::translate("Jpeg2000TranscoderClass", "Current Profile Information", 0, QApplication::UnicodeUTF8));
        MessageBoxGroupBox->setTitle(QApplication::translate("Jpeg2000TranscoderClass", "Processing Information", 0, QApplication::UnicodeUTF8));
        transcodeButton->setText(QApplication::translate("Jpeg2000TranscoderClass", "Transcode", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("Jpeg2000TranscoderClass", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Jpeg2000TranscoderClass: public Ui_Jpeg2000TranscoderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JPEG2000TRANSCODER_H
