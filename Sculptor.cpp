#include "Sculptor.h"
#include <iostream>
#include <fstream>
#include <cmath>

// Construtor: Aloca a matriz 3D dinamicamente e inicializa as dimensões e cores
Sculptor::Sculptor(int _nx, int _ny, int _nz) {
    nx = _nx;
    ny = _ny;
    nz = _nz;

    // Inicializa a cor padrão como branco e totalmente opaco
    r = g = b = a = 1.0f;

    // 1. Aloca as linhas do eixo X (ponteiros para ponteiros de ponteiros)
    v = new Voxel**[nx];

    // 2. Aloca as colunas do eixo Y para cada X
    for (int i = 0; i < nx; i++) {
        v[i] = new Voxel*[ny];

        // 3. Aloca a profundidade do eixo Z para cada Y
        for (int j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];

            // Inicializa todos os voxels como "desligados"
            for (int k = 0; k < nz; k++) {
                v[i][j][k].show = false;
                v[i][j][k].r = 0.0f;
                v[i][j][k].g = 0.0f;
                v[i][j][k].b = 0.0f;
                v[i][j][k].a = 0.0f;
            }
        }
    }
}

// Destrutor: Libera a memória alocada na ordem inversa da alocação
Sculptor::~Sculptor() {
    // Libera de dentro para fora
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            delete[] v[i][j]; // Libera os arrays do eixo Z
        }
        delete[] v[i]; // Libera os arrays do eixo Y
    }
    delete[] v; // Libera o array principal do eixo X
}

// Define a cor e a transparência atuais do pincel de desenho
void Sculptor::setColor(float r, float g, float b, float a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

// Ativa um voxel específico na matriz tridimensional se ele estiver nos limites válidos
void Sculptor::putVoxel(int x, int y, int z) {
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        v[x][y][z].show = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

// Desativa (apaga) um voxel específico na matriz tridimensional
void Sculptor::cutVoxel(int x, int y, int z) {
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        v[x][y][z].show = false;
    }
}

// Exporta a matriz de voxels ativos para o formato de malha 3D (.off)
void Sculptor::writeOFF(const char* filename) {
    std::ofstream file;
    file.open(filename);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << filename << " para escrita.\n";
        return;
    }

    int totalVoxels = 0;

    // Conta quantos voxels estão ativos para calcular os vértices e faces
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    totalVoxels++;
                }
            }
        }
    }

    // Cabeçalho clássico do formato OFF
    file << "OFF\n";
    // Cada voxel (cubo) possui 8 vértices e 6 faces
    file << totalVoxels * 8 << " " << totalVoxels * 6 << " 0\n";

    // Posição de escala espacial de cada bloco (ajuste se seu projeto pedir float)
    float P = 0.5f;

    // Escreve as coordenadas geométricas de todos os vértices dos cubos ativos
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    // Mapeia os 8 cantos tridimensionais do cubo atual isolado
                    file << i - P << " " << j + P << " " << k - P << "\n"; // Vértice 0
                    file << i - P << " " << j - P << " " << k - P << "\n"; // Vértice 1
                    file << i + P << " " << j - P << " " << k - P << "\n"; // Vértice 2
                    file << i + P << " " << j + P << " " << k - P << "\n"; // Vértice 3
                    file << i - P << " " << j + P << " " << k + P << "\n"; // Vértice 4
                    file << i - P << " " << j - P << " " << k + P << "\n"; // Vértice 5
                    file << i + P << " " << j - P << " " << k + P << "\n"; // Vértice 6
                    file << i + P << " " << j + P << " " << k + P << "\n"; // Vértice 7
                }
            }
        }
    }

    int voxelContador = 0;

    // Escreve a conectividade das 6 faces quadrangulares de cada cubo com suas cores RGBA
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    int idx = voxelContador * 8; // Deslocamento de índice dos vértices

                    // Cores convertidas de float [0,1] para exibição em MeshLab
                    float vr = v[i][j][k].r;
                    float vg = v[i][j][k].g;
                    float vb = v[i][j][k].b;
                    float va = v[i][j][k].a;

                    // Cada linha descreve uma face: "4" (vértices por face) seguido dos índices locais e cor
                    file << "4 " << idx+0 << " " << idx+3 << " " << idx+2 << " " << idx+1 << " " << vr << " " << vg << " " << vb << " " << va << "\n";
                    file << "4 " << idx+4 << " " << idx+5 << " " << idx+6 << " " << idx+7 << " " << vr << " " << vg << " " << vb << " " << va << "\n";
                    file << "4 " << idx+0 << " " << idx+1 << " " << idx+5 << " " << idx+4 << " " << vr << " " << vg << " " << vb << " " << va << "\n";
                    file << "4 " << idx+0 << " " << idx+4 << " " << idx+7 << " " << idx+3 << " " << vr << " " << vg << " " << vb << " " << va << "\n";
                    file << "4 " << idx+3 << " " << idx+7 << " " << idx+6 << " " << idx+2 << " " << vr << " " << vg << " " << vb << " " << va << "\n";
                    file << "4 " << idx+1 << " " << idx+2 << " " << idx+6 << " " << idx+5 << " " << vr << " " << vg << " " << vb << " " << va << "\n";

                    voxelContador++;
                }
            }
        }
    }

    file.close();
    std::cout << "Arquivo exportado com sucesso para: " << filename << "\n";
}