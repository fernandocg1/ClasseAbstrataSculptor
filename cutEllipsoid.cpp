#include "cutEllipsoid.h"

cutEllipsoid::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;

    this->r = 0.0f;
    this->g = 0.0f;
    this->b = 0.0f;
    this->a = 0.0f;
}

void cutEllipsoid::draw(Sculptor &t) {
    for (int x = xcenter - rx; x <= xcenter + rx; x++) {
        for (int y = ycenter - ry; y <= ycenter + ry; y++) {
            for (int z = zcenter - rz; z <= zcenter + rz; z++) {

                float dx = (float)((x - xcenter) * (x - xcenter)) / (rx * rx);
                float dy = (float)((y - ycenter) * (y - ycenter)) / (ry * ry);
                float dz = (float)((z - zcenter) * (z - zcenter)) / (rz * rz);

                if (dx + dy + dz <= 1.0f) {
                    t.cutVoxel(x, y, z);
                }

            }
        }
    }
}