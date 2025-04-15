#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CitizenList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CitizenList()
{
    QTableWidget *table = new QTableWidget(this);
    table->setRowCount(20);
    table->setColumnCount(4);


    this->setWindowTitle("DANH SÁCH DÂN CƯ");

    QStringList hlabels;
    hlabels << "Họ và tên" << "Số CMND" << "Ngày sinh" << "Địa chỉ";
    table->setHorizontalHeaderLabels(hlabels);


    QStringList names = {
        "Nguyễn Văn An", "Trần Thị Bình", "Lê Hoàng Cường", "Phạm Thị Dung",
        "Hoàng Văn Đạt", "Vũ Thị Mai", "Đỗ Ngọc Minh", "Bùi Thị Hương",
        "Đặng Văn Phúc", "Ngô Thị Lan", "Trương Văn Sơn", "Lý Thị Hà",
        "Nguyễn Đình Tùng", "Phan Thị Thu", "Hồ Văn Nhật", "Chu Thị Ngọc",
        "Mai Văn Hải", "Đinh Thị Linh", "Võ Văn Tuấn", "Lưu Thị Kim"
    };

    QStringList ids = {
        "001", "002", "003", "004", "005", "006", "007", "008", "009", "010",
        "011", "012", "013", "014", "015", "016", "017", "018", "019", "020"
    };

    QStringList birthdays = {
        "15/05/1990", "22/08/1985", "10/03/1995", "05/12/1988",
        "30/07/1992", "18/09/1987", "25/01/1993", "12/11/1989",
        "08/04/1991", "20/06/1986", "03/02/1994", "14/10/1996",
        "27/12/1984", "09/08/1997", "01/05/1983", "16/03/1998",
        "23/07/1982", "11/09/1999", "06/11/1981", "29/04/2000"
    };


    QStringList addresses = {
        "12/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "24/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "36/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "45/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "57/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "68/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "72/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "83/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "94/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "105/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "112/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "124/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "136/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "145/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "157/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "168/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "172/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "183/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "194/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM",
        "205/15 Nguyễn Văn Linh, Tân Phong, Q7, TP.HCM"
    };

    // insert Data
    for (int i = 0; i < table->rowCount(); i++) {
        table->setItem(i, 0, new QTableWidgetItem(names[i]));
        table->setItem(i, 1, new QTableWidgetItem(ids[i]));
        table->setItem(i, 2, new QTableWidgetItem(birthdays[i]));
        table->setItem(i, 3, new QTableWidgetItem(addresses[i]));
    }


    table->setStyleSheet(
        "QTableWidget {"
        "   font-size: 12pt;"
        "   selection-background-color: #3498db;"
        "}"
        "QHeaderView::section {"
        "   background-color: #2980b9;"
        "   color: white;"
        "   padding: 5px;"
        "   font-weight: bold;"
        "}"
        );

    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    table->resizeColumnsToContents();
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    this->setCentralWidget(table);
    this->resize(800, 600);
}



