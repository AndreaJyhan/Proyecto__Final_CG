//Semestre 2012 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		OCAÑA CASILLAS ANDREA JYHAN		    ******//
//*************	    REYES ARAGON AURORA					******//
//************************************************************//
#include "texture.h"
#include "figuras.h"
#include "Camera.h"

//Solo para Visual Studio 2015
#if (_MSC_VER == 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

CCamera objCamera;
GLfloat g_lookupdown = 0.0f;

float pos_camX = 0, pos_camY = 0, pos_camZ = -5; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;


GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position


CTexture t_Ajedrez1;               //VARIABLES DE TIPO TEXTURA
CTexture t_Ajedrez2;
CTexture t_metal01;
CTexture t_rocas;
CTexture t_borde;
CTexture t_teja;
CTexture t_cabaña;
CTexture t_cristal;
CTexture t_puerta;
CTexture t_puertaatras;
CTexture t_castillo;
CTexture t_concreto;
CTexture t_floor;
CTexture t_reja;
CTexture t_bosque;
CTexture t_puerta_s;
CTexture t_mesa_picos;
CTexture t_pata_picos;
CTexture t_metal_picos;
CTexture t_sangre;

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras entorno;
CFiguras pico;


int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;



void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Azul de fondo	

	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);


	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	t_Ajedrez1.LoadTGA("01.tga");
	t_Ajedrez1.BuildGLTexture();
	t_Ajedrez1.ReleaseImage();

	t_metal01.LoadBMP("metal2.bmp");
	t_metal01.BuildGLTexture();
	t_metal01.ReleaseImage();

	t_Ajedrez2.LoadTGA("02.tga");
	t_Ajedrez2.BuildGLTexture();
	t_Ajedrez2.ReleaseImage();

	t_rocas.LoadTGA("rocas.tga");          //CARGA EL ARCHIVO
	t_rocas.BuildGLTexture();             //GENERA LA TEXTURA
	t_rocas.ReleaseImage();              //PARA PODER OCUPARLA

	t_borde.LoadTGA("borde.tga");          //CARGA EL ARCHIVO
	t_borde.BuildGLTexture();             //GENERA LA TEXTURA
	t_borde.ReleaseImage();

	t_cristal.LoadTGA("cristal.tga");          //CARGA EL ARCHIVO
	t_cristal.BuildGLTexture();             //GENERA LA TEXTURA
	t_cristal.ReleaseImage();

	t_cabaña.LoadTGA("madera.tga");          //CARGA EL ARCHIVO
	t_cabaña.BuildGLTexture();             //GENERA LA TEXTURA
	t_cabaña.ReleaseImage();

	t_teja.LoadTGA("teja.tga");          //CARGA EL ARCHIVO
	t_teja.BuildGLTexture();             //GENERA LA TEXTURA
	t_teja.ReleaseImage();

	t_puerta.LoadTGA("puerta.tga");          //CARGA EL ARCHIVO
	t_puerta.BuildGLTexture();             //GENERA LA TEXTURA
	t_puerta.ReleaseImage();

	t_puertaatras.LoadTGA("puerta_atras.tga");          //CARGA EL ARCHIVO
	t_puertaatras.BuildGLTexture();             //GENERA LA TEXTURA
	t_puertaatras.ReleaseImage();

	t_castillo.LoadTGA("castillo.tga");          //CARGA EL ARCHIVO
	t_castillo.BuildGLTexture();             //GENERA LA TEXTURA
	t_castillo.ReleaseImage();

	t_floor.LoadTGA("floor.tga");          //CARGA EL ARCHIVO
	t_floor.BuildGLTexture();             //GENERA LA TEXTURA
	t_floor.ReleaseImage();

	t_reja.LoadTGA("reja.tga");          //CARGA EL ARCHIVO
	t_reja.BuildGLTexture();             //GENERA LA TEXTURA
	t_reja.ReleaseImage();

	t_concreto.LoadTGA("concreto.tga");          //CARGA EL ARCHIVO
	t_concreto.BuildGLTexture();             //GENERA LA TEXTURA
	t_concreto.ReleaseImage();

	t_bosque.LoadTGA("bosque.tga");          //CARGA EL ARCHIVO
	t_bosque.BuildGLTexture();             //GENERA LA TEXTURA
	t_bosque.ReleaseImage();

	t_puerta_s.LoadTGA("tela_sangre.tga");          //CARGA EL ARCHIVO
	t_puerta_s.BuildGLTexture();             //GENERA LA TEXTURA
	t_puerta_s.ReleaseImage();

	t_mesa_picos.LoadTGA("mesa_picos.tga");          //CARGA EL ARCHIVO
	t_mesa_picos.BuildGLTexture();             //GENERA LA TEXTURA
	t_mesa_picos.ReleaseImage();

	t_pata_picos.LoadTGA("pata_picos.tga");          //CARGA EL ARCHIVO
	t_pata_picos.BuildGLTexture();             //GENERA LA TEXTURA
	t_pata_picos.ReleaseImage();

	t_metal_picos.LoadTGA("metal_picos.tga");          //CARGA EL ARCHIVO
	t_metal_picos.BuildGLTexture();             //GENERA LA TEXTURA
	t_metal_picos.ReleaseImage();

	t_sangre.LoadTGA("sangre.tga");          //CARGA EL ARCHIVO
	t_sangre.BuildGLTexture();             //GENERA LA TEXTURA
	t_sangre.ReleaseImage();

	objCamera.Position_Camera(10, 4.0f, 13, 10, 4.0f, 10, 0, 1, 0);
}


void renderBitmapCharacter(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}



void prisma (GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		
		glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,1.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);     //0
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);           //4
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);     //7
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);      //1
		glEnd();
	
		glBindTexture(GL_TEXTURE_2D, textura1);
		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textura1);
		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textura1);
		glBegin(GL_POLYGON);  //Left
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);   //1
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]); //7
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);   //6
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);//2
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textura2);
		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
		glEnd();
}


void display ( void )   // Creamos la funcion donde se dibuja

{
	glEnable(GL_LIGHTING);
	glFogf(GL_FOG_MODE, GL_EXP2);
	GLfloat color_de_niebla[4] = { 0.0,0.0,0.0,0.0};
	glFogfv(GL_FOG_COLOR, color_de_niebla);
	glFogf(GL_FOG_DENSITY, 0.01f);
	glFogf(GL_FOG_START, 1.0);
	glFogf(GL_FOG_END, 1.0);
	glEnable(GL_FOG);
	glDisable(GL_FOG);

	glDisable(GL_LIGHTING);

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();

	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);

	glTranslatef(pos_camX, pos_camY, pos_camZ);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);


		glPushMatrix();
		glEnable(GL_FOG);
		glDisable(GL_LIGHTING);
		glTranslatef(0.0,150.0,-80.0);
		entorno.skybox(400, 550, 400, t_bosque.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		///////////////////////////CASTILLO///////////////////
///////////////////////////////////////////////////////////////////////////ESCALERA
		glDisable(GL_LIGHTING);
		glPushMatrix();  
                                    //escalera
			glColor3f(1.0, 2.0, 1.0);
			glScalef(20.0,1.0,2.0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_concreto.GLindex, t_castillo.GLindex);
			glDisable(GL_ALPHA_TEST);

			glTranslatef(0.0,1.0,-1.0);
			prisma(t_concreto.GLindex, t_castillo.GLindex);

			glTranslatef(0.0, 1.0, -1.0);
			prisma(t_concreto.GLindex, t_castillo.GLindex);

			glTranslatef(0.0, 1.0, -1.0);
			prisma(t_concreto.GLindex, t_castillo.GLindex);

			glTranslatef(0.0, 1.0, -1.0);
			prisma(t_concreto.GLindex, t_castillo.GLindex);

			glTranslatef(0.0, 1.0, -1.0);
			prisma(t_concreto.GLindex, t_castillo.GLindex);

			glTranslatef(0.0, 1.0, -1.0);
			prisma(t_concreto.GLindex, t_castillo.GLindex);

			glTranslatef(0.0, 1.0, -1.0);
			prisma(t_concreto.GLindex, t_castillo.GLindex);

			glTranslatef(0.0, 1.0, -1.0);
			prisma(t_concreto.GLindex, t_castillo.GLindex);

			glTranslatef(0.0, 1.0, -1.0);
			prisma(t_concreto.GLindex, t_castillo.GLindex);

			glTranslatef(0.0, 1.0, -1.0);
			prisma(t_concreto.GLindex, t_castillo.GLindex);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0, 33.0, -21.5);             //puerta
			glColor3f(1.0, 2.0, 1.0);
			glScalef(20.0, 45.0, 1.0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_puerta.GLindex, t_puerta.GLindex);
			glDisable(GL_ALPHA_TEST);
		glPopMatrix();

		glPushMatrix();                                  //barda
		glTranslatef(11.25, 9, -10.5);
		glScalef(2.5, 18.0, 22.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();                                  //barda
		glTranslatef(-11.25, 9, -10.5);
		glScalef(2.5, 18.0, 22.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();                                  //reja
			glTranslatef(0.0, 63.5, -21.5);
			glScalef(20.0, 15.0, 1.0);
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.1);
			prisma(t_reja.GLindex, t_reja.GLindex);
			glDisable(GL_ALPHA_TEST);
		glPopMatrix();

		glPushMatrix();                                  //der_puerta
		glTranslatef(27.5, 35.5, -20.5);
		glScalef(35.0, 71.0, 3.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(80.0, 27.5, -20.5);                 //der_torre_pequeña
		glScalef(70.0, 55.0, 3.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(57.5, 60.0, -20.5);                 //pared_izq
		glScalef(25.0, 10.0, 3.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(81, 60.0, -20.5);                 //pared_medio
		glScalef(18.0, 10.0, 3.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(103.5, 60.0, -20.5);                 //pared_der
		glScalef(23.0, 10.0, 3.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		/*glPushMatrix();
		glTranslatef(91, 60.0, -20.5);                 //ventana 1
		glScalef(2.0, 10.0, 3.0);
		prisma(0,0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(71, 60.0, -20.5);                 //ventana 2
		glScalef(2.0, 10.0, 3.0);
		prisma(0,0);
		glPopMatrix();*/

		glPushMatrix();
		glTranslatef(80.0, 92.5, -20.5);                 //der_torre_pequeña_up
		glScalef(70.0, 55.0, 3.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(108, 123.5, -20.5);
		glScalef(14, 7, 6);
		prisma(t_castillo.GLindex, t_castillo.GLindex);

		glTranslatef(-2.0, 0.0, 0.0);
		prisma(t_castillo.GLindex, t_castillo.GLindex);

		glTranslatef(-2.0, 0.0, 0.0);
		prisma(t_castillo.GLindex, t_castillo.GLindex);
		glPopMatrix();

///////////////////////////////////////////////////////////////////////////////////////////////

		glPushMatrix();                                  //izq_puerta
		glTranslatef(-27.5, 35.5, -20.5);
		glScalef(35.0, 71.0, 3.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-80.0, 27.5, -20.5);                 //izq_torre_pequeña_down
		glScalef(70.0, 55.0, 3.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		/*glPushMatrix();
		glTranslatef(-91, 60.0, -20.5);                 //ventana 1
		glScalef(2.0, 10.0, 3.0);
		prisma(0,0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-71, 60.0, -20.5);                 //ventana 2
		glScalef(2.0, 10.0, 3.0);
		prisma(0,0);
		glPopMatrix();*/

		glPushMatrix();
		glTranslatef(-57.5, 60.0, -20.5);                 //pared_izq
		glScalef(25.0, 10.0, 3.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-81, 60.0, -20.5);                 //pared_medio
		glScalef(18.0, 10.0, 3.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-103.5, 60.0, -20.5);                 //pared_der
		glScalef(23.0, 10.0, 3.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-80.0, 92.5, -20.5);                 //izq_torre_pequeña_up
		glScalef(70.0, 55.0, 3.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-108,123.5,-20.5);
		glScalef(14, 7, 6);
		prisma(t_castillo.GLindex, t_castillo.GLindex);

		glTranslatef(2.0,0.0,0.0);
		prisma(t_castillo.GLindex, t_castillo.GLindex);

		glTranslatef(2.0, 0.0, 0.0);
		prisma(t_castillo.GLindex, t_castillo.GLindex);
		glPopMatrix();

/////////////////////////////////////////////////////////////////////////////////////// PARTE SUPERIOR DE LA PUERTA

		glPushMatrix();                                  //up_puerta
		glTranslatef(0.0, 110.5, -20.5);
		glScalef(90.0, 80.0, 3.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(38.575 ,154, -20.5);
		glScalef(12.85, 7, 6);
		prisma(t_castillo.GLindex, t_castillo.GLindex);

		glTranslatef(-2, 0.0,0.0);
		prisma(t_castillo.GLindex, t_castillo.GLindex);

		glTranslatef(-2, 0.0, 0.0);
		prisma(t_castillo.GLindex, t_castillo.GLindex);

		glTranslatef(-2, 0.0, 0.0);
		prisma(t_castillo.GLindex, t_castillo.GLindex);
		glPopMatrix();

////////////////////////////////////////////////////////////////////////////////////////////// TORRE

		glPushMatrix();                                  //torre
		glTranslatef(-133, 0.0, -15);
		fig1.cilindro(20.0, 200.0, 50, t_castillo.GLindex);
		glPopMatrix();

		glPushMatrix();                                  
		glTranslatef(-133, 200, -15);
		fig1.torus(25, 20, 50, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-133, 200, -15);
		fig3.cono(70, 20, 50, t_concreto.GLindex);
		glPopMatrix();

/////////////////////////////////////////////////////////////////////////////////////////////// CONTORNO

		glPushMatrix();                                  //lateral_der
		glTranslatef(113.5,63.5,-141);
		glScalef(3.0, 127.0, 238.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();                                  //lateral_izq
		glTranslatef(-140, 63.5, -141);               
		glScalef(3.0, 127.0, 238.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();                                  //back
		glTranslatef(-13.25, 63.5, -261.5);
		glScalef(256.5, 127.0, 3.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

//////////////////////////////////////////////////////////////////////////////// PAREDES INTERIORES

		glPushMatrix();                                  //base
		glTranslatef(-13.25, 1.5, -141);
		glScalef(250.5,3.0,239.0);
		prisma(t_borde.GLindex, t_borde.GLindex);
		glPopMatrix();

		glPushMatrix();                                  //piso
		glTranslatef(-13.25, 9.5, -117.0);
		glScalef(250.5, 3.0, 190.0);
		prisma(t_floor.GLindex, t_floor.GLindex);
		glPopMatrix();

		glPushMatrix();                                  //pared
		glTranslatef(35.0,64.0,-124);
		glScalef(3.0, 106.0, 170.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();


		//////////////////////////////////////NUEVO (PARED)
		/*glPushMatrix();                                  //puerta
		glTranslatef(36.5, 64.0, -30.5);
		glScalef(0.5, 106.0, 17.0);
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		prisma(t_puerta_s.GLindex, t_puerta_s.GLindex);
		glDisable(GL_ALPHA_TEST);
		glPopMatrix();*/
		
		glPushMatrix();                                  //pared
		glTranslatef(2.5, 64.0, -210.5);
		glScalef(235, 106.0, 3.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();

		glPushMatrix();                                  //techo
		glTranslatef(-13.25, 117, -141);
		glScalef(250.5, 3.0, 239.0);
		prisma(t_concreto.GLindex, t_concreto.GLindex);
		glPopMatrix();
/////////////////////////////////////////////////////////////////////HERRAMIENTAS DE TORTURA

		/*MESA CON PICOS*/
		glPushMatrix();    
		glTranslatef(87.0, 18.75, -235.5); //mesa
		glPushMatrix();
		glScalef(36.0, 1.5, 20.0);
		prisma(t_mesa_picos.GLindex, t_mesa_picos.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(16.0, -8.25, -8.0); //pata 1
		glScalef(4.0, 15.0, 4.0);
		prisma(t_pata_picos.GLindex, t_pata_picos.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-16.0, -8.25, -8.0); //pata 2
		glScalef(4.0, 15.0, 4.0);
		prisma(t_pata_picos.GLindex, t_pata_picos.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-16.0, -8.25, 8.0); //pata 3
		glScalef(4.0, 15.0, 4.0);
		prisma(t_pata_picos.GLindex, t_pata_picos.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(16.0, -8.25, 8.0); //pata 4
		glScalef(4.0, 15.0, 4.0);
		prisma(t_pata_picos.GLindex, t_pata_picos.GLindex);
		glPopMatrix();
////////////////////////////////////////////////////////////////////////////cadenas
		glPushMatrix();
		glTranslatef(16.0, 0.75, -8.0); //pico 1
		glScalef(4.0, 15.0, 4.0);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		/////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		////////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		//////////////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		////////////////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		//////////////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		////////////////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		//////////////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		////////////////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		//////////////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		////////////////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		//////////////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		////////////////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		//////////////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		////////////////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		//////////////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		////////////////////////////////////////////////////////
		glTranslatef(-0.5, 0.0, -0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glTranslatef(0.0, 0.0, 0.5);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-16.0, 0.75, -8.0); //pico 2
		glScalef(4.0, 15.0, 4.0);
		pico.cono(1,0.1,10, t_metal_picos.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-16.0, 0.75, 8.0); //pico 3
		glScalef(4.0, 15.0, 4.0);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(16.0, 0.75, 8.0); //pico 4
		glScalef(4.0, 15.0, 4.0);
		pico.cono(1, 0.1, 10, t_metal_picos.GLindex);
		glPopMatrix();


		glPopMatrix();

		
	glEnable(GL_LIGHTING);


	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Ocaña Casillas Andrea Jyhan");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Reyes Aragon Aurora");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1, -0.1, 0.1, 0.1, 1000.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion()
{
	

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			pos_camZ += 0.9f;
			//eye_camZ -= 0.5f;
			break;

		case 's':
		case 'S':
			pos_camZ -= 0.9f;
			//eye_camZ += 0.5f;
			break;

		case 'a':
		case 'A':
			pos_camX += 0.9f;
			//eye_camX -= 0.5f;
			break;
		case 'd':
		case 'D':
			pos_camX -= 0.9f;
			//eye_camX += 0.5f;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
		break;
    default:
      break;
  }
  glutPostRedisplay();
}

void audio() {
	PlaySound("terror19.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	audio();
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(5000, 5000);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto_CG_OCAJ_RAA"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}