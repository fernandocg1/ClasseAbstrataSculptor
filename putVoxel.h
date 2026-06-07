#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class putVoxel : public FiguraGeometrica {
    int x, y, z; // Coordenadas do voxel individual
public:
    // Construtor que recebe a posição e as propriedades de cor/transparência
    putVoxel(int x, int y, int z, float r, float g, float b, float a);

    // Destrutor
    ~putVoxel() {};

    // Desenha o voxel no Sculptor passado por referência
    void draw(Sculptor &t) override;
};

#endif // PUTVOXEL_H