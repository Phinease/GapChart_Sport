//
// Created by phinease on 12/11/2019.
//
#include "data.cpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "common/shader.cpp"

float vertices[20][246];
vector< vector<int> > pts;
vector< vector<int> > ranks;

GLfloat couleur[] = {
    0.5f, 0.6f, 0.6f,
    0.7f, 0.6f, 0.1f,
    0.6f, 0.4f, 0.3f,
};

GLfloat couleur1[82*3];
GLfloat couleur2[82*3];
GLfloat couleur3[82*3];




void loadVAO(float (&pDouble)[20][246]){
    loadData("data/rankspts.csv",pts,ranks);
    for (int i = 0; i < 20 ; ++i) {
        for (int j = 0; j < 41 ; ++j) {
            pDouble[i][j*6] = (float) j*25.6;
            pDouble[i][j*6+1] = (float)ranks[i][j]*49;
            pDouble[i][j*6+2] = 0.0f;
            pDouble[i][j*6+3] = (float) j*25.6;
            pDouble[i][j*6+4] = (float)ranks[i][j]*49+24.5;
            pDouble[i][j*6+5] = 0.0f;
        }
    }
}

void  loadCouleur (){
    for (int i = 0; i < 82 ; ++i) {
        couleur1[i*3]   = couleur[0];
        couleur1[i*3+1] = couleur[1];
        couleur1[i*3+2] = couleur[2];

        couleur2[i*3]   = couleur[3];
        couleur2[i*3+1] = couleur[4];
        couleur2[i*3+2] = couleur[5];

        couleur3[i*3]   = couleur[6];
        couleur3[i*3+1] = couleur[7];
        couleur3[i*3+2] = couleur[8];
    }
}