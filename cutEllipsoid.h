#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class cutEllipsoid : public FiguraGeometrica {
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    // O construtor recebe o centro e os raios nos eixos X, Y e Z
    cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    ~cutEllipsoid() {};

    void draw(Sculptor &t) override;
};

#endif // CUTELLIPSOID_H