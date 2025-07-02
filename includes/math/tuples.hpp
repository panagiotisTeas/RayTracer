#pragma once

//* An ordered list of points which will be used to represent points and vectors
class Tuple
{
private:
    float x;
    float y;
    float z;
    float w; //* w = 0.0f -> vector | w = 1.0f -> point

public:
    Tuple();
    Tuple(float ux, float uy, float uz, float uw);

    float getX() const;
    float getY() const;
    float getZ() const;
    float getW() const;

    bool isPoint() const;
    bool isVector() const;

};