#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class putSphere : public FiguraGeometrica {
    int xcenter, ycenter, zcenter, radius;
public:
    // Construtor que recebe as coordenadas do centro, o raio e a cor
    putSphere(int xcenter, int ycenter, int zcenter, int radius,
              float r, float g, float b, float a);

    ~putSphere() {};

    // Método que varre a região e desenha a esfera
    void draw(Sculptor &t) override;
};

#endif // PUTSPHERE_H