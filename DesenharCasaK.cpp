#include <iostream>
#include <GL/glut.h>
#include <math.h>

void DesenharCasaK(void){
    //Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    //Define a cor da linha, os parametros sao as cores (R, G, B) e variam de 0-1
    glColor3f(1.0, 0.0, 0.0);

    //Desenha as linhas na tela
    glBegin(GL_LINES);
    //Define os vertices das linhas

    // '/'
    glVertex2f(100.0, 100.0);
    glVertex2f(200.0, 200.0);

    // '\'
    glVertex2f(200.0, 200.0);
    glVertex2f(300.0, 100.0);

    // '-'
    glVertex2f(100.0, 100.0);
    glVertex2f(450.0, 100.0);

    // '| esquerdo'
    glVertex2f(100.0, 100.0);
    glVertex2f(100.0, 1.0);

    // '| direito'
    glVertex2f(300.0, 100.0);
    glVertex2f(300.0, 1.0);

    //Porta
    glVertex2f(150.0, 0.0);
    glVertex2f(150.0, 60.0);

    glVertex2f(150.0, 60.0);
    glVertex2f(190.0, 60.0);

    glVertex2f(190.0, 60.0);
    glVertex2f(190.0, 1.0);
    
    // base da casa
    glVertex2f(100.0, 0.0);
    glVertex2f(450.0, 0.0);

    // teto da casa mais longo
    glVertex2f(200.0, 200.0);
    glVertex2f(400.0, 200.0);

    // diagonal
    glVertex2f(400.0, 200.0);
    glVertex2f(450.0, 100.0);

    glVertex2f(450.0, 100.0);
    glVertex2f(450.0, 1.0);

    glEnd();

    //Executa os comandos OpenGL
    glFlush();
}