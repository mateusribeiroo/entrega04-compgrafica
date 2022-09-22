#include <iostream>
#include <GL/glut.h>
#include <math.h>

void DesenharHelloWorld(void) {

    //Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    //Define a cor da linha, os parametros sao as cores (R, G, B) e variam de 0-1
    glColor3f(1.0, 0.0, 0.0);

    //Desenha as linhas na tela
    glBegin(GL_LINES);
    //Define os vertices das linhas

    //"H"
    glVertex2f(25.0, 350.0);
    glVertex2f(25.0, 500.0);

    glVertex2f(25.0, 425.0);
    glVertex2f(100.0, 425.0);

    glVertex2f(100.0, 350.0);
    glVertex2f(100.0, 500.0);

    //"E"
    glVertex2f(125.0, 350.0);
    glVertex2f(125.0, 500.0);

    glVertex2f(125.0, 500.0);
    glVertex2f(200.0, 500.0);

    glVertex2f(125.0, 425.0);
    glVertex2f(200.0, 425.0);

    glVertex2f(125.0, 350.0);
    glVertex2f(200.0, 350.0);

    //"L"
    glVertex2f(225.0, 350.0);
    glVertex2f(225.0, 500.0);

    glVertex2f(225.0, 350.0);
    glVertex2f(300.0, 350.0);

    //"L"
    glVertex2f(325.0, 350.0);
    glVertex2f(325.0, 500.0);

    glVertex2f(325.0, 350.0);
    glVertex2f(400.0, 350.0);

    //"O"
    glVertex2f(425.0, 350.0);
    glVertex2f(425.0, 500.0);

    glVertex2f(425.0, 500.0);
    glVertex2f(500.0, 500.0);

    glVertex2f(425.0, 350.0);
    glVertex2f(500.0, 350.0);

    glVertex2f(500.0, 350.0);
    glVertex2f(500.0, 500.0);

    //"W"
    glVertex2f(25.0, 300.0);
    glVertex2f(34.375, 150.0);

    glVertex2f(34.375, 150.0);
    glVertex2f(62.5, 225.0);

    glVertex2f(62.5, 225.0);
    glVertex2f(90.625, 150.0);

    glVertex2f(90.625, 150.0);
    glVertex2f(100.0, 300.0);

    //"O"
    glVertex2f(125.0, 150.0);
    glVertex2f(125.0, 300.0);

    glVertex2f(125.0, 300.0);
    glVertex2f(200.0, 300.0);

    glVertex2f(125.0, 150.0);
    glVertex2f(200.0, 150.0);

    glVertex2f(200.0, 150.0);
    glVertex2f(200.0, 300.0);

    //"R"
    glVertex2f(225.0, 150.0);
    glVertex2f(225.0, 300.0);

    glVertex2f(225.0, 300.0);
    glVertex2f(300.0, 300.0);


    glVertex2f(300.0, 300.0);
    glVertex2f(300.0, 225.0);

    glVertex2f(225.0, 225.0);
    glVertex2f(300.0, 225.0);

    glVertex2f(225.0, 225.0);
    glVertex2f(300.0, 150.0);

    //"L"
    glVertex2f(325.0, 150.0);
    glVertex2f(325.0, 300.0);

    glVertex2f(325.0, 150.0);
    glVertex2f(400.0, 150.0);

    //"D"
    glVertex2f(425.0, 150.0);
    glVertex2f(425.0, 300.0);

    glVertex2f(425.0, 150.0);
    glVertex2f(500.0, 225.0);

    glVertex2f(425.0, 300.0);
    glVertex2f(500.0, 225.0);

    glEnd();

    //Executa os comandos OpenGL
    glFlush();
}


