#ifndef IP_H
#define IP_H

#include <QDialog>

namespace Ui {
class IP;
}

class IP : public QDialog
{
    Q_OBJECT

public:
    explicit IP(QWidget *parent = 0);
    ~IP();

private:
    Ui::IP *ui;
};

#endif // IP_H
