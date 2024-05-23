#include "mainwindow.h"
#include <QToolBar>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    drawWidget = new DrawWidget;
    setCentralWidget(drawWidget);
    createToolBar();
    setMinimumSize(600, 400);
    ShowStyle(0);
    drawWidget->setWidth(widthSpinBox->value());
    drawWidget->setColor(Qt::black);
}

MainWindow::~MainWindow() {}

void MainWindow::createToolBar() {
    QToolBar *toolBar = addToolBar("Tool");
    styleLabel = new QLabel(tr("线型风格："));
    styleComboBox = new QComboBox;
    styleComboBox->addItem(tr("SolidLine"),static_cast<int>(Qt::SolidLine));
    styleComboBox->addItem(tr("DashLine"),static_cast<int>(Qt::DashLine));
    styleComboBox->addItem(tr("DotLine"),static_cast<int>(Qt::DotLine));
    styleComboBox->addItem(tr("DashDotLine"),static_cast<int>(Qt::DashDotLine));
    styleComboBox->addItem(tr("DashDotDotLine"),static_cast<int>(Qt::DashDotDotLine));
    connect(styleComboBox, &QComboBox::currentIndexChanged, this, &MainWindow::ShowStyle);
    widthLabel = new QLabel(tr("线宽："));
    widthSpinBox = new QSpinBox;
    connect(widthSpinBox, &QSpinBox::valueChanged, drawWidget, &DrawWidget::setWidth);
    colorBtn = new QToolButton;
    QPixmap pixmap(20, 20);
    pixmap.fill(Qt::black);
    colorBtn->setIcon(QIcon(pixmap));
    connect(colorBtn, &QToolButton::clicked, this, &MainWindow::ShowColor);
    clearBtn = new QToolButton();
    colorBtn->setText(tr("清除"));
    connect(clearBtn, &QToolButton::clicked, drawWidget, &DrawWidget::clear);
    toolBar->addWidget(styleLabel);
    toolBar->addWidget(styleComboBox);
    toolBar->addWidget(widthLabel);
    toolBar->addWidget(widthSpinBox);
    toolBar->addWidget(colorBtn);
    toolBar->addWidget(clearBtn);
}

void MainWindow::ShowStyle(int index) {
    drawWidget->setStyle(styleComboBox->itemData(styleComboBox->currentIndex(),Qt::UserRole).toInt());
}

void MainWindow::ShowColor() {
    QColor color = QColorDialog::getColor(static_cast<int> (Qt::black),this);
    if(color.isValid()) {
        drawWidget->setColor(color);
        QPixmap p(20, 20);
        p.fill(color);
        colorBtn->setIcon(QIcon(p));
    }
}
