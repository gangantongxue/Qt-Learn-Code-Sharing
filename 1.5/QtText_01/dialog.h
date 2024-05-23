#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QGridLayout>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void updateLabel();
private:
    QLabel * xLabel, * xValueLabel, * yLabel, * yValueLabel, * FrmLabel, * FrmValueLabel,
        * posLabel, * posValueLabel, * geoLabel, * geoValueLabel, * wideLabel, * wideValueLabel,
        * heightLabel, * heightValueLabel, * rectLabel, * rectValueLabel, * sizeLabel, * sizeValueLabel;
    QGridLayout * mainLayout;
protected:
    void moveEvent(QMoveEvent *);
    void resizeEvent(QResizeEvent *);
};
#endif // DIALOG_H
