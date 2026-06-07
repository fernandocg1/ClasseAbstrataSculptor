#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class cutSphere : public FiguraGeometrica {
    int xcenter, ycenter, zcenter, radius;
public:
    cutSphere(int xcenter, int ycenter, int zcenter, int radius);

    ~cutSphere() {};

    void draw(Sculptor &t) override;
};

#endif // CUTSPHERE_H