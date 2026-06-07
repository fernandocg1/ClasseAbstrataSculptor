#include "cutSphere.h"

// Construtor: Inicializa o centro e o raio do corte
cutSphere::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;

    // Cores zeradas, pois não são aplicadas no corte
    this->r = 0.0f;
    this->g = 0.0f;
    this->b = 0.0f;
    this->a = 0.0f;
}

// Método Draw: Varre a região tridimensional e desativa os voxels internos à esfera
void cutSphere::draw(Sculptor &t) {
    // Varre apenas o bloco cúbico que envolve a esfera simulada
    for (int x = xcenter - radius; x <= xcenter + radius; x++) {
        for (int y = ycenter - radius; y <= ycenter + radius; y++) {
            for (int z = zcenter - radius; z <= zcenter + radius; z++) {

                // Calcula a distância ao quadrado do voxel atual até o centro
                int dx = (x - xcenter) * (x - xcenter);
                int dy = (y - ycenter) * (y - ycenter);
                int dz = (z - zcenter) * (z - zcenter);
                int r2 = radius * radius;

                // Se a distância for menor ou igual ao raio ao quadrado, o voxel está dentro
                if (dx + dy + dz <= r2) {
                    // Apaga o voxel nessa posição
                    t.cutVoxel(x, y, z);
                }

            }
        }
    }
}