#ifndef LIN_INTERFACE_H
#define LIN_INTERFACE_H

#include <QMainWindow>
#include <QSerialPort>
#include <QPushButton>
#include <QMenu>
#include <QAction>

class LinInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit LinInterface(QWidget *parent = nullptr);
    ~LinInterface();

private slots:
    void handleButtonPress();

private:
    void createActions();
    void createMenus();

    QSerialPort *serial;
    QPushButton *button;
    QMenu *fileMenu;
    QAction *exitAction;
};

#endif // LIN_INTERFACE_H

