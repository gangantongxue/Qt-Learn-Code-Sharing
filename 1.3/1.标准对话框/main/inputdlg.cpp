#include "inputdlg.h"

InputDlg::InputDlg(QWidget * parent):QDialog(parent)
{
    setWindowTitle(tr("标准输入对话框实例"));
    nameLabel1 = new QLabel(tr("姓名："));
    nameLabel2 = new QLabel(tr("小明"));
    nameLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    nameBtn = new QPushButton(tr("修改姓名"));
    sexLabel1 = new QLabel(tr("性别："));
    sexLabel2 = new QLabel(tr("男"));
    sexLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    sexBtn = new QPushButton(tr("修改性别"));
    ageLabel1 = new QLabel(tr("年龄："));
    ageLabel2 = new QLabel(tr("21"));
    ageLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    ageBtn = new QPushButton(tr("修改年龄"));
    scoreLabel1 = new QLabel(tr("成绩："));
    scoreLabel2 = new QLabel(tr("80"));
    scoreLabel2->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    scoreBtn = new QPushButton(tr("修改成绩"));
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(nameLabel1,0,0);
    mainLayout->addWidget(nameLabel2,0,1);
    mainLayout->addWidget(nameBtn,0,2);
    mainLayout->addWidget(sexLabel1,1,0);
    mainLayout->addWidget(sexLabel2,1,1);
    mainLayout->addWidget(sexBtn,1,2);
    mainLayout->addWidget(ageLabel1,2,0);
    mainLayout->addWidget(ageLabel2,2,1);
    mainLayout->addWidget(ageBtn,2,2);
    mainLayout->addWidget(scoreLabel1,3,0);
    mainLayout->addWidget(scoreLabel2,3,1);
    mainLayout->addWidget(scoreBtn,3,2);
    mainLayout->setSpacing(10);
    connect(nameBtn,SIGNAL(clicked()),this,SLOT(ChangeName()));
    connect(sexBtn,SIGNAL(clicked()),this,SLOT(ChangeSex()));
    connect(ageBtn,SIGNAL(clicked()),this,SLOT(ChangeAge()));
    connect(scoreBtn,SIGNAL(clicked()),this,SLOT(ChangeScore()));
}

void InputDlg::ChangeName(){
    bool ok;
    QString text = QInputDialog::getText(this,tr("标准字符串输入对话框"),tr("请输入姓名："),QLineEdit::Normal,nameLabel2->text(),&ok);
    if(ok && !text.isEmpty()){
        nameLabel2->setText(text);
    }
}

void InputDlg::ChangeSex(){
    QStringList SexItems;
    SexItems<<tr("男")<<tr("女");
    bool ok;
    QString SexItem = QInputDialog::getItem(this,tr("标准条目选择对话框"),tr("请选择性别："),SexItems,0,false,&ok);
    if(ok && !SexItem.isEmpty()){
        sexLabel2->setText(SexItem);
    }
}

void InputDlg::ChangeAge(){
    bool ok;
    int age = QInputDialog::getInt(this,tr("标准int类型输入对话框"),tr("请输入年龄："),ageLabel2->text().toInt(&ok),0,100,1,&ok);
    if(ok){
        ageLabel2->setText(QString(tr("%1")).arg(age));
    }
}

void InputDlg::ChangeScore(){
    bool ok;
    double score = QInputDialog::getDouble(this,tr("标准double类型输入对话框"),tr("请输入成绩："),scoreLabel2->text().toDouble(&ok),0,100,1,&ok);
    if(ok){
        scoreLabel2->setText(QString(tr("%1")).arg(score));
    }
}
