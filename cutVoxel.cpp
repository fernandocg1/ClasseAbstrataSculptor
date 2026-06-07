#include "cutVoxel.h"

// Construtor: Inicializa as coordenadas de corte
cutVoxel::cutVoxel(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;

    // Nota: Como FiguraGeometrica possui r, g, b, a como membros protegidos,
    // você pode opcionalmente inicializá-los com 0, embora para o corte eles não sejam usados.
    this->r = 0.0f;
    this->g = 0.0f;
    this->b = 0.0f;
    this->a = 0.0f;
}

// Método Draw: Executa a remoção do voxel
void cutVoxel::draw(Sculptor &t) {
    // Não precisamos de t.setColor aqui porque estamos apagando um bloco!

    // Chama o método do escultor responsável por desligar a propriedade 'show' do voxel
    t.cutVoxel(x, y, z);
}