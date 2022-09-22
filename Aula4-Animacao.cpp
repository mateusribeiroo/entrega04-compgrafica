
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

void desenhaCastelo(void){
    glColor3f(0.5, 0.2, 0.2); //marrom

    // Torre da direita
        //Teto
        glBegin(GL_TRIANGLES);
            glVertex2f(350 + 0.0,           300.0);
            glVertex2f(350 + (100.0+0.0)/2, 200.0);
            glVertex2f(350 + 100.0,         300.0);
        glEnd();

        glColor3f(0.5, 0.5, 0.5); // cinza

        // coluna
        glBegin(GL_POLYGON);
            glVertex2f(350.0, 300.0);
            glVertex2f(450.0, 300.0);
            glVertex2f(450.0, 400.0);
            glVertex2f(350.0, 400.0);
        glEnd();


        

    //Torre da esquerda
        //Teto
        glColor3f(0.5, 0.2, 0.2); // marrom
        glBegin(GL_TRIANGLES);
            glVertex2f(50 + 0.0,           300.0);
            glVertex2f(50 + (100.0+0.0)/2, 200.0);
            glVertex2f(50 + 100.0,         300.0);
        glEnd();

        // coluna
        glColor3f(0.5, 0.5, 0.5); // cinza
        glBegin(GL_POLYGON);
            glVertex2f(50.0, 300.0);
            glVertex2f(150.0, 300.0);
            glVertex2f(150.0, 400.0);
            glVertex2f(50.0, 400.0);
        glEnd();

        glColor3f(0.0, 0.0, 0.0); // preto
        

        glColor3f(0.0, 0.0, 0.0); // preto
        // margem esquerda
        glBegin(GL_LINES);
            glVertex2f(50.0, 300.0);
            glVertex2f(50.0, 400.0);
        glEnd();

    // frente
    glColor3f(0.5, 0.5, 0.5); // cinza
    glBegin(GL_POLYGON);
        glVertex2f(60.0, 300.0);
        glVertex2f(350.0, 300.0);
        glVertex2f(350.0, 400.0);
        glVertex2f(60.0, 400.0);
    glEnd();

    // porta
    glColor3f(0.5, 0.2, 0.2); // marrom
    glBegin(GL_POLYGON);
        glVertex2f(225.0, 350.0);
        glVertex2f(275.0, 350.0);
        glVertex2f(275.0, 400.0);
        glVertex2f(225.0, 400.0);
    glEnd();


    // MARGENS

        glColor3f(0.0, 0.0, 0.0); // preto
        // margem esquerda da coluna esquerda
        glBegin(GL_LINES);
            glVertex2f(50.0, 300.0);
            glVertex2f(50.0, 400.0);
        glEnd();

        // margem direita da coluna esquerda
        glBegin(GL_LINES);
            glVertex2f(150.0, 300.0);
            glVertex2f(150.0, 400.0);
        glEnd();


        // margem esquerda da coluna direita
        glBegin(GL_LINES);
            glVertex2f(352.0, 300.0);
            glVertex2f(352.0, 400.0);
        glEnd();

        // margem direita da coluna direita
        glBegin(GL_LINES);
            glVertex2f(450.0, 300.0);
            glVertex2f(450.0, 400.0);
        glEnd();

        // margem superior
        glBegin(GL_LINES);
            glVertex2f(50.0, 300.0);
            glVertex2f(450.0, 300.0);
        glEnd();

        // margem inferior
        glBegin(GL_LINES);
            glVertex2f(50.0, 400.0);
            glVertex2f(450.0, 400.0);
        glEnd();
}


void desenhaBoneco(){
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

    glFlush();
}


//Função callback chamada para fazer o desenho
void Desenha(void) {

    glViewport(0, 0, 500, 500);

    //Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    desenhaCastelo();
    desenhaBoneco();
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






