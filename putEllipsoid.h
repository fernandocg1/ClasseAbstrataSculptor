#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class putEllipsoid : public FiguraGeometrica {
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    // O construtor recebe o centro, os raios (X, Y, Z) e as propriedades de cor
    putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz,
                 float r, float g, float b, float a);

    ~putEllipsoid() {};

    // Método que varre a região e desenha o elipsoide na matriz 3D
    void draw(Sculptor &t) override;
};

#endif // PUTELLIPSOID_H