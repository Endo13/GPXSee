#ifndef HEARTRATEGRAPH_H
#define HEARTRATEGRAPH_H

#include "graphview.h"
#include "units.h"

class GPX;

class HeartRateGraph : public GraphView
{
	Q_OBJECT

public:
	HeartRateGraph(QWidget *parent = 0);

	void loadGPX(const GPX &gpx);
	void clear();
	void setUnits(enum Units units);

	qreal avg() const;
	qreal max() const {return bounds().bottom();}

private:
	void setXUnits();
	void addInfo();

	QList<QPointF> _avg;
	enum Units _units;
};

#endif // HEARTRATEGRAPH_H