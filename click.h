#ifndef CLICK_H
#define CLICK_H

#include <QMainWindow>

// Thêm forward declaration nếu cần
class MainWindow;

namespace Ui {
class Click;
}

class Click : public QMainWindow
{
    Q_OBJECT
public:
    Click(QWidget *parent = nullptr);
    ~Click();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Click *ui;
};

#endif // CLICK_H
