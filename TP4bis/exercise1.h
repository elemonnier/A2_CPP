#ifndef TP4BIS_EXERCISE1_H
#define TP4BIS_EXERCISE1_H

class PGM {
private:
    int width;
    int height;
    int maxvalue;
    int **data;
public:
    void setWidth(int);
    void setHeight(int);
    void setMaxvalue(int);
    void setData(int**);
    int** initImage();
    void deleteImage();
    int** createImage(int minpix, int maxpix);
    PGM();
    PGM(int, int, int, int);
    ~PGM();
    PGM(PGM const&);
    void afficherImage();
    void writeFile(char*);
    void drawrect(int, int, int, int, int);
    void drawline(int, int, int, int);
    void drawcross(int, int, int = 255);
    void readFile(char*);
    void thresholding(int, char*);
    void filterImage(char*, int);
};

#endif
