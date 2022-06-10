#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init_UI();
}

MainWindow::~MainWindow()
{
}

void MainWindow::init_UI()
{
    this->setMinimumSize(500, 400);
    centralWidget = new QWidget(this);

    mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setAlignment(Qt::AlignmentFlag::AlignCenter);

    welcomeWidget = new WelcomeWidget(centralWidget);
    welcomeWidget->setMaximumWidth(400);
    welcomeWidget->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));

    firstSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    secondSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    mainLayout->addItem(firstSpacer);
    mainLayout->addWidget(welcomeWidget, Qt::AlignmentFlag::AlignCenter);
    mainLayout->addItem(secondSpacer);

    this->setCentralWidget(centralWidget);
}
