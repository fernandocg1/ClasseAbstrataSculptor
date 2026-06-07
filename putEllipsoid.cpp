#include "putEllipsoid.h"

// Construtor: Armazena o formato do elipsoide e repassa as cores para a classe base
putEllipsoid::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz,
                           float r, float g, float b, float a) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;

    // Atributos herdados de FiguraGeometrica
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

// Método Draw: Varre a caixa delimitadora aplicando as cores nos voxels internos
void putEllipsoid::draw(Sculptor &t) {
    // Configura a cor e transparência do pincel do escultor
    t.setColor(r, g, b, a);

    // Três laços de repetição ajustados para o raio específico de cada coordenada
    for (int x = xcenter - rx; x <= xcenter + rx; x++) {
        for (int y = ycenter - ry; y <= ycenter + ry; y++) {
            for (int z = zcenter - rz; z <= zcenter + rz; z++) {

                // Calcula os termos da equação analítica do elipsoide: (d_eixo)^2 / (raio_eixo)^2
                float dx = (float)((x - xcenter) * (x - xcenter)) / (rx * rx);
                float dy = (float)((y - ycenter) * (y - ycenter)) / (ry * ry);
                float dz = (float)((z - zcenter) * (z - zcenter)) / (rz * rz);

                // Se a soma dos eixos normalizados for menor ou igual a 1.0, o voxel faz parte da figura
                if (dx + dy + dz <= 1.0f) {
                    // Ativa o voxel na matriz do Sculptor
                    t.putVoxel(x, y, z);
                }

            }
        }
    }
}