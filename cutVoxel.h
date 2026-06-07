#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class cutVoxel : public FiguraGeometrica {
    int x, y, z; // Coordenadas do voxel que será desativado
public:
    // O construtor precisa apenas das coordenadas espaciais
    cutVoxel(int x, int y, int z);

    ~cutVoxel() {};

    // Método que desativa o voxel no Sculptor passado por referência
    void draw(Sculptor &t) override;
};

#endif // CUTVOXEL_H