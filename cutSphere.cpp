#include "cutSphere.h"

cutSphere::cutSphere(int xcenter, int ycenter, int zcenter, int radius) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;

    this->r = 0.0f;
    this->g = 0.0f;
    this->b = 0.0f;
    this->a = 0.0f;
}

void cutSphere::draw(Sculptor &t) {
    for (int x = xcenter - radius; x <= xcenter + radius; x++) {
        for (int y = ycenter - radius; y <= ycenter + radius; y++) {
            for (int z = zcenter - radius; z <= zcenter + radius; z++) {

                int dx = (x - xcenter) * (x - xcenter);
                int dy = (y - ycenter) * (y - ycenter);
                int dz = (z - zcenter) * (z - zcenter);
                int r2 = radius * radius;

                if (dx + dy + dz <= r2) {
                    t.cutVoxel(x, y, z);
                }

            }
        }
    }
}