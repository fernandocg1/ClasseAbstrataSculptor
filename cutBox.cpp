#include "cutBox.h"

cutBox::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
    this->x0 = x0;
    this->x1 = x1;
    this->y0 = y0;
    this->y1 = y1;
    this->z0 = z0;
    this->z1 = z1;

    this->r = 0.0f;
    this->g = 0.0f;
    this->b = 0.0f;
    this->a = 0.0f;
}

void cutBox::draw(Sculptor &t) {
    for (int x = x0; x <= x1; x++) {
        for (int y = y0; y <= y1; y++) {
            for (int z = z0; z <= z1; z++) {

                t.cutVoxel(x, y, z);

            }
        }
    }
}