#include "lin_interface.h"
#include <QPushButton>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QMessageBox>

#include "ldf_parser.h"

LinInterface::LinInterface(QWidget *parent)
    : QMainWindow(parent), serial(new QSerialPort(this))
{
    // Create a button in the center
    button = new QPushButton("Press Me", this);
    connect(button, &QPushButton::clicked, this, &LinInterface::handleButtonPress);

    // Set up central widget
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button);
    layout->setAlignment(button, Qt::AlignCenter);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Create menu bar with File menu
    createActions();
    createMenus();

    // Set window title
    setWindowTitle("LIN Interface Application");
    resize(400, 300);
}

LinInterface::~LinInterface()
{
    // Clean up if necessary
}

void LinInterface::handleButtonPress()
{
    //QMessageBox::information(this, "Button Pressed", "The button was pressed!");
	
	LdfParser parser("../ldffile/ECM_GAS_LIN_1b_1417_2.1f.ldf");
	parser.parse();
	
}

void LinInterface::createActions()
{
    // Create Exit action
    exitAction = new QAction(tr("E&xit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Exit the application"));
    connect(exitAction, &QAction::triggered, this, &QWidget::close);
}

void LinInterface::createMenus()
{
    // Create File menu
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAction);
}

