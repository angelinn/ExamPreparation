#include "1.cpp"

int main()
{
    float** img = new float*[2];
    img[0] = new float[3] {1, 2, 3};
    img[1] = new float[3] {4.5, 6.5, 7.5};

    subsample(2, 3, img);
}