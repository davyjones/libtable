#ifndef LIBTABLE_H
#define LIBTABLE_H

#include<QtGui>

class TablePrivate;

class Table : public QMainWindow
{
    Q_OBJECT

private:
    Q_DECLARE_PRIVATE(Table)

protected:
    TablePrivate* const d_ptr;

public:
    Table();
    //Table(QTextStream);

    QStandardItemModel* model() const;
    QTableView* view() const;

    void setData(QStringList);
    void appendData(QStringList);
    void horizontalHeadersOff();
    void verticalHeadersOff();
    void horizontalHeadersOn();
    void verticalHeadersOn();
};

#endif // LIBTABLE_H
