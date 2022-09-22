
/* mbaffa@usp.br 2021, peq modificações por Guilherme Martiniano de Oliveira, Mateus Miquelino da Silva
                 2022 peq modificações por rvencio 2022
   no shell fazer pra compilar:
       g++ Aula4-Animacao.cpp -o vai  -lglut -lGL -lGLEW -lGLU -lm
   pra rodar:
       ./vai
*/


#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <iostream>
using namespace std;

GLint posMaoEsquerdaX = 150;
GLint posMaoEsquerdaY = 150;

GLint posMaoDireitaX = 260;
GLint posMaoDireitaY = 120;

void DesenharCasa(void){
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

void Timer(int value) {
    //Vamos usar dois tempos para movimentar os bracos
    //Logica: se o time stamp for par, usamos os bracos para esquerda, se for impar usamos os bracos para direita
    if (value % 2 == 0) {
        //caso par: aplica as maos em uma determinada posicao
        posMaoEsquerdaX = 150;
        posMaoEsquerdaY = 150;

        posMaoDireitaX = 260;
        posMaoDireitaY = 120;
    }else {
        //caso impar: altera as posicoes
        posMaoEsquerdaX = 240;
        posMaoEsquerdaY = 120;

        posMaoDireitaX = 350;
        posMaoDireitaY = 150;
    }

    //Redesenha a cena e executa o timer novamente para ter uma animacao continua
    glutPostRedisplay();
    glutTimerFunc(180, Timer, value + 1); //Value recebe o valor anterior + 1, alterando nosso time stamp
}

//Função callback chamada para fazer o desenho
void Desenha(void) {

    glViewport(0, 0, 500, 500);

    //Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    //Define a cor da linha, os parametros sao as cores (R, G, B) e variam de 0-1
    glColor3f(0.0, 0.0, 0.0);

    //antebraco
    glBegin(GL_LINES);
        glVertex2i(posMaoEsquerdaX, posMaoEsquerdaY);
        glVertex2i(200, 200); //fixo

        glVertex2i(posMaoDireitaX, posMaoDireitaY);
        glVertex2i(300, 200); //fixo
    glEnd();

    //cabeca
    double PI = 3.141592;
    double r = 35;
    int nDots = 500;
    double x = 0, y = 0, theta = 0, p = 0;
    p = 2 * PI / nDots;
    theta = p;
    glBegin(GL_POLYGON);
        for (int i = 0; i <= nDots; i++) {
            x = r * cos(theta);
            y = r * sin(theta);
            theta += p;

            glVertex2i(x + 250, y + 170);
        }
    glEnd();

    //bracos
    glBegin(GL_LINES);
        glVertex2i(250, 250);
        glVertex2i(200, 200);

        glVertex2i(250, 250);
        glVertex2i(300, 200);
    glEnd();

    //tronco
    glBegin(GL_LINES);
        glVertex2i(250, 200);
        glVertex2i(250, 350);
    glEnd();

    //pernas
    glBegin(GL_LINES);
        glVertex2i(250, 350);
        glVertex2i(200, 500);

        glVertex2i(250, 350);
        glVertex2i(300, 500);
    glEnd();

    //Executa os comandos OpenGL

    //Define a cor da linha, os parametros sao as cores (R, G, B) e variam de 0-1
    glColor3f(1.0, 0.0, 0.0);

    //Teto
    glBegin(GL_TRIANGLES);
        glVertex2f(200.0, 100.0);
        glVertex2f(200.0, 200.0);
        glVertex2f(200.0, 100.0);
    glEnd();

    glColor3f(1.0, 1.0, 0.0);

    // frente
    glBegin(GL_POLYGON);
        glVertex2f(100.0, 100.0);
        glVertex2f(100.0, 100.0);
        glVertex2f(100.0, 100.0);
        glVertex2f(100.0, 100.0);
    glEnd();

    glColor3f(1.0, 1.0, 0.0);

    // porta
    glBegin(GL_POLYGON);
        glVertex2f(100.0, 100.0);
        glVertex2f(100.0, 100.0);
        glVertex2f(100.0, 100.0);
        glVertex2f(100.0, 100.0);
    glEnd();

    //Executa os comandos OpenGL
    glFlush();
}

void Inicializa(void) {

    //Define a cor de fundo da janela de visualização como branca
    glClearColor(1.0, 1.0, 1.0, 1.0);

    //Define a espessura da linha
    glLineWidth(3.0);

    //Define a janela na tela que sera desenhado
    gluOrtho2D(0.0, 500.0, 500.0, 0.0);
    //Xmin, Xmax, Ymin, Ymax
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv); // adicionado por rvencio set/2022 para executar linux. Sem isso compila mas não roda
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Usa apenas um buffer e o sistema de cores RGB
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(430, 130);  
    glutCreateWindow("Default");
    glutTimerFunc(180, Timer, 1); //params: Tempos(ms) de espera da funcao, Funcao de animacao, Enviar um valor inteiro para a funcao (nesse caso sera usado para time stamp)
    //glutDisplayFunc(DesenharCasaK); //Funcao com os dados primitivos
    glutDisplayFunc(Desenha); //Funcao com os dados primitivos
    Inicializa(); //Funcao de inicializacao da tela e fundo
    glutMainLoop(); //executa todo o processamento
    return 0;
}





