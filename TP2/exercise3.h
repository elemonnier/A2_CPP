#ifndef TP2_EXERCISE3_H
#define TP2_EXERCISE3_H

enum Content {VIDE, ROND, CROIX};

class JeuMorpion {
private:
    int grille[3][3];
    bool placer_coup(int ligne, int colonne, Content c);
public:
    void init();
    bool placer_rond(int ligne, int colonne);
    bool placer_croix(int ligne, int colonne);
    void afficher_grille();
    int getGrille(int grille, int colonne);
    bool gameEnds(JeuMorpion jeu);
};

#endif