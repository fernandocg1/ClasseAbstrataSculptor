#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class putEllipsoid : public FiguraGeometrica {
    int xcenter, ycenter, zcenter, rx, ry, rz;
public:
    putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz,
                 float r, float g, float b, float a);

    ~putEllipsoid() {};

    void draw(Sculptor &t) override;
};

#endif // PUTELLIPSOID_H