#ifndef CPMESH_H
#define CPMESH_H


class CPMesh
{
public:
    CPMesh();
private:
    int m_uMin;
    int m_uMax;
    int m_nu;
    int m_vMin;
    int m_vMax;
    int m_nv;
};

#endif // CPMESH_H
