#ifndef CNURB_H
#define CNURB_H

#include <QVector>
#include <QVector3D>

class CNurb
{
public:
    CNurb(short p, const QVector<float>& U,
          short q, const QVector<float>& V,
          const QVector<QVector3D>& P) : m_p(p), m_U(U), m_q(q), m_V(V), m_Points(P){}

    CNurb(short p, const QVector<float>& U,
          short q, const QVector<float>& V,
          int numPOints);
private:
    short m_p; //Order p
    QVector<float> m_U; // Knot vector
    short m_q; //Order q
    QVector<float> m_V; // Knot vector
    int m_numPoints;
    QVector<QVector3D> m_Points;
};

#endif // CNURB_H
