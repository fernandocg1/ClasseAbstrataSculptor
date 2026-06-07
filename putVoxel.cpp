#include "putVoxel.h"

// Construtor: inicializa as coordenadas locais e as cores da classe pai
putVoxel::putVoxel(int x, int y, int z, float r, float g, float b, float a) {
    this->x = x;
    this->y = y;
    this->z = z;

    // r, g, b, a são herdados de FiguraGeometrica
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

// Método Draw: aplica as propriedades no objeto Sculptor
void putVoxel::draw(Sculptor &t) {
    // 1. Configura a cor atual que o escultor vai usar
    t.setColor(r, g, b, a);

    // 2. Ativa o voxel na coordenada específica
    t.putVoxel(x, y, z);
}