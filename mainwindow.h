#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void aproximator(int level);
  
private slots:
  //
  void YListAccept(bool checked);
  //использует виджет графиков:
  void titleDoubleClick(QMouseEvent *event, QCPPlotTitle *title);
  void axisLabelDoubleClick(QCPAxis* axis, QCPAxis::SelectablePart part);
  void legendDoubleClick(QCPLegend* legend, QCPAbstractLegendItem* item);
  void selectionChanged();
  void mousePress();
  void mouseWheel();
  void addGraph(QByteArray name,const QVector<double>& x,const QVector<double>& y);
  void removeSelectedGraph();
  void removeAllGraphs();
  void contextMenuRequest(QPoint pos);
  void moveLegend();
  void graphClicked(QCPAbstractPlottable *plottable);
  
private:
  Ui::MainWindow *ui;
  QVector<double> Number,Result,x;
  char* Sliderlabels;
  QString russian(QByteArray string);

};

#endif // MAINWINDOW_H
