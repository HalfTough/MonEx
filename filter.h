#ifndef FILTER_H
#define FILTER_H

#include <QDate>
#include <QStringList>

#include "money.h"

class Filter {
    QStringList names;
    QDate from;
    QDate to;
    Money min,max;
    bool _hasMin = false, _hasMax=false;
public:
    void addNames(const QStringList &);
    void setFrom(QDate date) { from = date; }
    void setTo(QDate date) { to = date; }
    void setMin(Money);
    void setMax(Money);
    bool hasMin() const{ return _hasMin; }
    bool hasMax() const{ return _hasMax; }
    bool isEmpty() const;
};

#endif