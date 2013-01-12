#include "libtable_p.h"

Table::Table(QWidget* parent)
    : d_ptr(new TablePrivate)
{
    Q_D(Table);

    d->init();

    setCentralWidget(d->table_view);
    statusBar();
    setParent(parent);
}

void TablePrivate::init()
{
    Q_Q(Table);

    table_model = new QStandardItemModel;
    table_view = new QTableView;
    table_view->setModel(table_model);
}

QStandardItemModel* Table::model() const
{
    Q_D(const Table);

    return d->table_model;
}

QTableView* Table::view() const
{
    Q_D(const Table);

    return d->table_view;
}

/*Table::Table(QTextStream stream)
{
    Q_D(const Table);

    QString line;
    QStringList line_list;
    do {
        line = stream.readLine();
        line_list = line.split("\t");

        QList<QStandardItem*> item_list;
        while(!line_list.isEmpty()) {
            item_list.append(new QStandardItem(line_list.takeFirst()));
        }
        d->table_model->appendRow(item_list);
    } while(!line.isNull());

    d->table_view->setModel(d->table_model);

    setCentralWidget(d->table_view);
    this->statusBar();
    this->show();
}*/

void Table::setData(QStringList string_list)
{
    Q_D(Table);

    qint32 r_c = d->table_model->rowCount();
    qint32 c_c = d->table_model->columnCount();

    for(qint32 i=0; i < r_c; i++) {
        for(qint32 j=0; j < c_c; j++) {
            if(string_list.isEmpty()) {
                return;
            }
            else {
                QStandardItem *item = new QStandardItem(string_list.takeFirst());
                d->table_model->setItem(i, j, item);
            }
        }
    }
}

void Table::appendData(QStringList string_list)
{
    Q_D(Table);

    QString str;
    QList<QStandardItem*> item_list;

    while(!string_list.isEmpty()) {
        str = string_list.takeFirst();
        if(str.at(0).isSpace()) {
            d->table_model->appendRow(item_list);
            item_list.clear();
        }
        else {
            item_list.append(new QStandardItem(str));
        }
    }
    d->table_model->appendRow(item_list);
    item_list.clear();
}

void Table::horizontalHeadersOff()
{
    Q_D(Table);

    d->table_view->horizontalHeader()->setVisible(false);
}

void Table::verticalHeadersOff()
{
    Q_D(Table);

    d->table_view->verticalHeader()->setVisible(false);
}

void Table::horizontalHeadersOn()
{
    Q_D(Table);

    d->table_view->horizontalHeader()->setVisible(true);
}

void Table::verticalHeadersOn()
{
    Q_D(Table);

    d->table_view->verticalHeader()->setVisible(true);
}
