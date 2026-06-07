#include "putEllipsoid.h"

putEllipsoid::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz,
                           float r, float g, float b, float a) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;

    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void putEllipsoid::draw(Sculptor &t) {
    t.setColor(r, g, b, a);

    for (int x = xcenter - rx; x <= xcenter + rx; x++) {
        for (int y = ycenter - ry; y <= ycenter + ry; y++) {
            for (int z = zcenter - rz; z <= zcenter + rz; z++) {

                float dx = (float)((x - xcenter) * (x - xcenter)) / (rx * rx);
                float dy = (float)((y - ycenter) * (y - ycenter)) / (ry * ry);
                float dz = (float)((z - zcenter) * (z - zcenter)) / (rz * rz);

                if (dx + dy + dz <= 1.0f) {
                    t.putVoxel(x, y, z);
                }

            }
        }
    }
}