#include "putSphere.h"

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

void putSphere::draw(Sculptor &t) {
    t.setColor(r, g, b, a);

    for (int x = xcenter - radius; x <= xcenter + radius; x++) {
        for (int y = ycenter - radius; y <= ycenter + radius; y++) {
            for (int z = zcenter - radius; z <= zcenter + radius; z++) {

                int dx = (x - xcenter) * (x - xcenter);
                int dy = (y - ycenter) * (y - ycenter);
                int dz = (z - zcenter) * (z - zcenter);
                int r2 = radius * radius;

                if (dx + dy + dz <= r2) {
                    t.putVoxel(x, y, z);
                }

            }
        }
    }
}