#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class cutSphere : public FiguraGeometrica {
    int xcenter, ycenter, zcenter, radius;
public:
    // O construtor recebe apenas a posição do centro e o raio de remoção
    cutSphere(int xcenter, int ycenter, int zcenter, int radius);

    ~cutSphere() {};

    // Método que varre a região delimitada e apaga os voxels da esfera
    void draw(Sculptor &t) override;
};

#endif // CUTSPHERE_H