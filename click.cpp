#include "click.h"
#include "ui_click.h"
#include "mainwindow.h"  // phải include header của MainWindow

Click::Click(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Click)
{
    ui->setupUi(this);
}

Click::~Click()
{
    delete ui;
}

void Click::on_pushButton_clicked()
{
    // Ẩn cửa sổ hiện tại
    this->hide();

    // Tạo và hiển thị MainWindow
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}

