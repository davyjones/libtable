#ifndef LIBTABLE_P_H
#define LIBTABLE_P_H

#include <QtGui>
#include "libtable.h"

class TablePrivate
{
    Q_DECLARE_PUBLIC(Table)

public:
    TablePrivate(Table *t) : q_ptr(t) { }
    Table *q_ptr;
    QStandardItemModel *table_model;
    QTableView *table_view;

    TablePrivate(){}
    ~TablePrivate()
    {
        table_view->close();
    }

    void init();
};

#endif // LIBTABLE_P_H
