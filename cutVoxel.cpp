#include "cutVoxel.h"

cutVoxel::cutVoxel(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;

    this->r = 0.0f;
    this->g = 0.0f;
    this->b = 0.0f;
    this->a = 0.0f;
}

void cutVoxel::draw(Sculptor &t) {

    t.cutVoxel(x, y, z);
}