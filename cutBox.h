#ifndef CUTBOX_H
#define CUTBOX_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class cutBox : public FiguraGeometrica {
    int x0, x1, y0, y1, z0, z1; // Limites do bloco de corte
public:
    // O construtor recebe apenas as coordenadas espaciais do bloco
    cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

    ~cutBox() {};

    // Método que varre a região e desativa os voxels
    void draw(Sculptor &t) override;
};

#endif // CUTBOX_H