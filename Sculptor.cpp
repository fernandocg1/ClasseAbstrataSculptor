#include "Sculptor.h"
#include <iostream>
#include <fstream>
#include <cmath>

Sculptor::Sculptor(int _nx, int _ny, int _nz) {
    nx = _nx;
    ny = _ny;
    nz = _nz;

    r = g = b = a = 1.0f;

    v = new Voxel**[nx];

    for (int i = 0; i < nx; i++) {
        v[i] = new Voxel*[ny];

        for (int j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];

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

Sculptor::~Sculptor() {
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            delete[] v[i][j];
        }
        delete[] v[i];
    }
    delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z) {
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        v[x][y][z].show = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}

void Sculptor::cutVoxel(int x, int y, int z) {
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        v[x][y][z].show = false;
    }
}

void Sculptor::writeOFF(const char* filename) {
    std::ofstream file;
    file.open(filename);

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << filename << " para escrita.\n";
        return;
    }

    int totalVoxels = 0;

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    totalVoxels++;
                }
            }
        }
    }

    file << "OFF\n";
    file << totalVoxels * 8 << " " << totalVoxels * 6 << " 0\n";

    float P = 0.5f;

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
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

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    int idx = voxelContador * 8;

                    int vr = (int)(v[i][j][k].r * 255);
                    int vg = (int)(v[i][j][k].g * 255);
                    int vb = (int)(v[i][j][k].b * 255);
                    int va = (int)(v[i][j][k].a * 255);

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