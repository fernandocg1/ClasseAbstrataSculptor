#include "cutEllipsoid.h"

// Construtor: Inicializa o centro e os três raios do elipsoide
cutEllipsoid::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;

    // Cores zeradas por padrão
    this->r = 0.0f;
    this->g = 0.0f;
    this->b = 0.0f;
    this->a = 0.0f;
}

// Método Draw: Varre o bloco espacial ao redor do elipsoide de corte
void cutEllipsoid::draw(Sculptor &t) {
    // Delimita a caixa de varredura usando os respectivos raios de cada eixo
    for (int x = xcenter - rx; x <= xcenter + rx; x++) {
        for (int y = ycenter - ry; y <= ycenter + ry; y++) {
            for (int z = zcenter - rz; z <= zcenter + rz; z++) {

                // Conversão para float para calcular a equação normalizada da elipse
                float dx = (float)((x - xcenter) * (x - xcenter)) / (rx * rx);
                float dy = (float)((y - ycenter) * (y - ycenter)) / (ry * ry);
                float dz = (float)((z - zcenter) * (z - zcenter)) / (rz * rz);

                // Se a soma das frações for menor ou igual a 1, o ponto está dentro do elipsoide
                if (dx + dy + dz <= 1.0f) {
                    // Apaga o voxel encontrado na posição
                    t.cutVoxel(x, y, z);
                }

            }
        }
    }
}