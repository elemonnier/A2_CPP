#ifndef TP4_EXERCISE1_H
#define TP4_EXERCISE1_H

class PGM {
private:
    int width;
    int height;
    int minValue;
    int maxValue;
    int **data;
public:
    void setWidth(int);

    void setHeight(int);

    void setMinValue(int);

    void setMaxValue(int);

    void setData(int **);

    int getWidth();

    int getHeight();

    int getMaxValue();

    int **getData();

    int **initImage(int = 10, int = 10);

    void deleteImage();

    void createImage(int = 0, int = 255);

    void printImage();

    PGM();

    PGM(int, int, int, int);

    ~PGM();

//    PGM(PGM const&);

    void writeFile(char *);

    void drawrect(int, int, int, int, int);

    void drawline(int, int, int, int);

    void drawcross(int, int, int = 255);

    void readFile(char* filename);

    void thresholding(int th, char* filename);

    void filterImage(char* filename, int k);
};

#endif