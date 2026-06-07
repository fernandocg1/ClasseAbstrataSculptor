#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "FiguraGeometrica.h"
#include "Sculptor.h"

class putVoxel : public FiguraGeometrica {
    int x, y, z;
public:
    putVoxel(int x, int y, int z, float r, float g, float b, float a);

    ~putVoxel() {};

    void draw(Sculptor &t) override;
};

#endif // PUTVOXEL_H