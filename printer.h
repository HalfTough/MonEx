#ifndef PRINTER_H
#define PRINTER_H

#include "filter.h"
#include "tracker.h"

#include <QTextStream>

class Printer{
    QTextStream out;
    Tracker *tracker;
    //QDate _from, _to;
    Filter filter;
    int minCol = 3;
    enum Timeframe {year, month, week, day};
    Timeframe timeframe = month;
    int timeInt = 1;
    int line = 0;
    //TODO translations
    QString months[12] = {"styczeń", "luty", "marzec", "kwiecień", "maj",
                       "czerwiec", "lipiec", "sierpień", "wrzesień",
                       "październik", "listopad", "grudzień"};
    QString project = "Projekt";
    QString older = "Starsze";
    QString sum = "Suma";
    QString empty = "Brak projektów spełniających warunki.";
    QString parseErrorMessage = "Nieprawidłowe argomenty\n";
    QString helpMessage = "Użycie donate [akcja] [argumenty]\n";
    QString noProject = "%1 – nie znaleziono projektu o tej nazwie";
    QString donations = "Wpłaty:";
    QString noDonations = "Projekt nie ma żadnych wpłat.";
    QString deleted = "Usunięto projekt – %1";
    QString projectExists = "%1: projekt już istnieje";
    QString projectDoesntExists = "%1: projekt nie istnieje";
    QString emptyProjectsString = "Projekty bez wpłat:";

    //TODO support
    QString line1 = "\e[0m";
    QString line2 = "\e[40m";

    int getTermWidth();
    int fieldWidth(Money) const;
    int fieldWidth(QString) const;
    int fieldWidth(QVector<Money>*) const;
    int namesWidth(QMap<QString,Project*> *) const;
    void printHeader(QList<int> *sizes, bool isOlder = false);
    void printTable(QList<QVector<Money>*>*table, QList<int> *sizes, QMap<QString,Project*> *projects);
    void printString(const QString &string, int space, QTextStream::FieldAlignment align=QTextStream::AlignLeft);
    void printMoney(Money, int space);
    //TODO move it maybe
    void addToVector(QVector<Money>*, QVector<Money>*);
    Money vectorSum(QVector<Money>*);
    QDate getEarliestDate(QMap<QString,Project*> *projects) const;
    QList <QVector<Money>*> * getMoneyTable(QMap<QString,Project*> *projects, const Filter &filter) const;

public:
    Printer(FILE*, Tracker* = nullptr);
    void setTracker(Tracker *);
    void setFilter(const Filter &filter){ this->filter = filter; }
    void print();
    void printProjects();
    void printDeleted(const QString&);
    void printProjectInfo(const QString&);
    void printProjectExists(const QString&);
    void printProjectDoesntExists(const QString&);
    void printParseError();
    void printHelp();
};

#endif
