#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>

#include <QTimer>

//#include "Square.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class mainwidget;
}
QT_END_NAMESPACE


class Flighting_ball : public QGraphicsEllipseItem
{
public:
	Flighting_ball(int yspread);
public:
	virtual void advance(int phase);
private:
	double V_x = 70,
		   V_y = 70,
		   g = 9.81;
	double t,
		   x1, y1,
		   x0, y0,

		   P = 1.29,    // (кг/м^3)
		   S = 0.0314,  // S = M_PI*r^2
		   C = 0.47,    // безразмерный коэффициент сопротивления формы
		   k = C*S*P*(V_x*V_x+V_y*V_y)/2, // безразмерная величина
		   m = 1;       // (кг)
	const int N = 20000;
	double dt = 0.1;
	int i;
	double V_x1 = 2000,
		   V_y1 = 2000,
		   m_p2 = 0.6,
		   V_xt = 40,
		   V_yt = 40,
		   t_detach = 5;

//signals:
//	void signalCheckItem (QGraphicsItem *item); //сигнал передается в ядро игры и требуется принять решение о том, что делать с объектом

//public slots:
//	void slotGameTimer (); //отвечает за обработку перемещения треугольника

//protected:
//	QRectF boundingRect() const;
//	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


class Victim: public QGraphicsRectItem {
public:
	Victim(int pos);
};


class mainwidget : public QWidget
{
	Q_OBJECT
public:
	mainwidget(QWidget *parent = nullptr);
	~mainwidget();

private slots:
	void onGenerate ();
	void slotRebound(QGraphicsItem *item);
//	void slotDeleteVictim (QGraphicsItem *item);

private:
	Ui::mainwidget *ui;
	QGraphicsScene *scene;
	QTimer *animationTimer;
	QTimer *generanorTimer;
	Victim *victim;
	Flighting_ball *ball;

};
#endif // MAINWIDGET_H
