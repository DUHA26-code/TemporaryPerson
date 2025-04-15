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

#include <QRandomGenerator>

void MainWindow::CitizenList()
{
    QTableWidget *table = new QTableWidget(this);
    table->setRowCount(20);
    table->setColumnCount(8);  // Tăng lên 8 cột

    
    this->setWindowTitle("DANH SÁCH DÂN CƯ - KHU PHỐ NGUYỄN VĂN LINH");

    
    QStringList hlabels;
    hlabels << "Họ và tên" << "Số CMND" << "Ngày sinh" << "Địa chỉ thường trú"
            << "Hộ khẩu thường trú" << "Thời hạn tạm trú (tháng)"
            << "Tình trạng hôn nhân" << "Tôn giáo";
    table->setHorizontalHeaderLabels(hlabels);

    // Data
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

    // Địa chỉ 
    QStringList currentAddresses = {
        "12/15 Nguyễn Văn Linh, Tân Phong, Q7", "24/15 Nguyễn Văn Linh, Tân Phong, Q7",
        "36/15 Nguyễn Văn Linh, Tân Phong, Q7", "45/15 Nguyễn Văn Linh, Tân Phong, Q7",
        "57/15 Nguyễn Văn Linh, Tân Phong, Q7", "68/15 Nguyễn Văn Linh, Tân Phong, Q7",
        "72/15 Nguyễn Văn Linh, Tân Phong, Q7", "83/15 Nguyễn Văn Linh, Tân Phong, Q7",
        "94/15 Nguyễn Văn Linh, Tân Phong, Q7", "105/15 Nguyễn Văn Linh, Tân Phong, Q7",
        "112/15 Nguyễn Văn Linh, Tân Phong, Q7", "124/15 Nguyễn Văn Linh, Tân Phong, Q7",
        "136/15 Nguyễn Văn Linh, Tân Phong, Q7", "145/15 Nguyễn Văn Linh, Tân Phong, Q7",
        "157/15 Nguyễn Văn Linh, Tân Phong, Q7", "168/15 Nguyễn Văn Linh, Tân Phong, Q7",
        "172/15 Nguyễn Văn Linh, Tân Phong, Q7", "183/15 Nguyễn Văn Linh, Tân Phong, Q7",
        "194/15 Nguyễn Văn Linh, Tân Phong, Q7", "205/15 Nguyễn Văn Linh, Tân Phong, Q7"
    };


    QStringList permanentAddresses;
    for (int i = 0; i < 10; i++) {
        // Dân thường trú: hộ khẩu gần địa chỉ hiện tại
        permanentAddresses.append(QString("%1/20 Nguyễn Văn Linh, Tân Phong, Q7").arg(100 + i*5));
    }
    for (int i = 10; i < 20; i++) {
        // Code tạo địa chỉ hộ khẩu cho dân tạm trú
        for (int i = 10; i < 20; i++) {
            // Dân tạm trú: hộ khẩu ở tỉnh khác
            QStringList provinces = {"Hà Nội", "Đà Nẵng", "Hải Phòng", "Cần Thơ", "Bình Dương",
                                     "Đồng Nai", "Khánh Hòa", "Lâm Đồng", "An Giang", "Kiên Giang"};
            QStringList streetNames = {"Lê Duẩn", "Trần Hưng Đạo", "Nguyễn Huệ", "Hai Bà Trưng", "Lý Thường Kiệt"};

            int streetNumber = QRandomGenerator::global()->bounded(100) + 1;
            QString street = streetNames[QRandomGenerator::global()->bounded(streetNames.size())];
            QString province = provinces[QRandomGenerator::global()->bounded(provinces.size())];

            permanentAddresses.append(QString("%1 %2, %3")
                                          .arg(streetNumber)
                                          .arg(street)
                                          .arg(province));
        }

    // Thời hạn tạm trú (dân thường trú để trống, dân tạm trú từ 0-24 tháng)
    QStringList temporaryStay;
    for (int i = 0; i < 10; i++) {
        temporaryStay.append("");  // Dân thường trú
    }
    for (int i = 10; i < 20; i++) {
        temporaryStay.append(QString::number(QRandomGenerator::global()->bounded(25)));  // 0-24 tháng
    }

    QStringList maritalStatus = {
        "Đã kết hôn", "Độc thân", "Đã kết hôn", "Ly hôn",
        "Đã kết hôn", "Đã kết hôn", "Độc thân", "Đã kết hôn",
        "Độc thân", "Đã kết hôn", "Đã kết hôn", "Độc thân",
        "Đã kết hôn", "Ly hôn", "Đã kết hôn", "Độc thân",
        "Đã kết hôn", "Độc thân", "Đã kết hôn", "Độc thân"
    };

    QStringList religions = {
        "Không", "Phật giáo", "Không", "Công giáo",
        "Phật giáo", "Cao Đài", "Không", "Phật giáo",
        "Tin Lành", "Không", "Phật giáo", "Hòa Hảo",
        "Công giáo", "Không", "Phật giáo", "Công giáo",
        "Không", "Phật giáo", "Hồi giáo", "Không"
    };

    // Add Data
    for (int i = 0; i < table->rowCount(); i++) {
        table->setItem(i, 0, new QTableWidgetItem(names[i]));
        table->setItem(i, 1, new QTableWidgetItem(ids[i]));
        table->setItem(i, 2, new QTableWidgetItem(birthdays[i]));
        table->setItem(i, 3, new QTableWidgetItem(currentAddresses[i]));
        table->setItem(i, 4, new QTableWidgetItem(permanentAddresses[i]));
        table->setItem(i, 5, new QTableWidgetItem(temporaryStay[i]));
        table->setItem(i, 6, new QTableWidgetItem(maritalStatus[i]));
        table->setItem(i, 7, new QTableWidgetItem(religions[i]));
    }

    // Tùy chỉnh giao diện
    table->setStyleSheet(
        "QTableWidget {"
        "   font-size: 11pt;"
        "}"
        "QHeaderView::section {"
        "   background-color: #2980b9;"
        "   color: white;"
        "   padding: 8px;"
        "   font-weight: bold;"
        "}"
        "QTableWidget::item {"
        "   padding: 5px;"
        "}"
        );

    // Căn chỉnh cột
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    table->resizeColumnsToContents();
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    this->setCentralWidget(table);
    this->resize(1200, 600);  // Tăng kích thước cửa sổ
}
}



