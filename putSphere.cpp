#include "putSphere.h"

// Construtor: Inicializa o centro, o raio e as cores na classe pai
putSphere::putSphere(int xcenter, int ycenter, int zcenter, int radius,
                     float r, float g, float b, float a) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

// Método Draw: Varre a região tridimensional testando a equação da esfera
void putSphere::draw(Sculptor &t) {
    // Configura a cor que o escultor usará para esta esfera
    t.setColor(r, g, b, a);

    // Varre apenas o bloco que contém a esfera (otimização de processamento)
    for (int x = xcenter - radius; x <= xcenter + radius; x++) {
        for (int y = ycenter - radius; y <= ycenter + radius; y++) {
            for (int z = zcenter - radius; z <= zcenter + radius; z++) {

                // Aplica a equação da esfera: (x-xc)^2 + (y-yc)^2 + (z-zc)^2 <= R^2
                int dx = (x - xcenter) * (x - xcenter);
                int dy = (y - ycenter) * (y - ycenter);
                int dz = (z - zcenter) * (z - zcenter);
                int r2 = radius * radius;

                if (dx + dy + dz <= r2) {
                    // Ativa o voxel se ele estiver dentro do raio computado
                    t.putVoxel(x, y, z);
                }

            }
        }
    }
}