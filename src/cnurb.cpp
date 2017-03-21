#include "cnurb.h"


CNurb::CNurb(short p, const QVector<float>& U,
      short q, const QVector<float>& V,
      int numPoints)
{
    m_p = p;
    m_U = U;
    m_q = q;
    m_V = V;
    m_Points.reserve(numPoints);
    for (int i = 0; i < numPoints; i++)
        m_Points.push_back(QVector3D(0.f,0.f,0.f));
}
