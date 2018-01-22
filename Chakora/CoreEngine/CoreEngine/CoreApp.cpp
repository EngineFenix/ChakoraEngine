#include "CoreApp.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../CoreTexture/TGA.h"
#include <stdio.h>

using namespace CoreEngine;

const double CoreApp::FRAME_TIME = 1.0 / CoreApp::FPS * 1000.0;

CoreApp *CoreApp::instance = NULL;

CoreApp::CoreApp(std::string WindowName = "CoreEngine Window", int WindowPrefferedWidth = 800, int WindowPrefferedHeight = 600, bool WindowFullscren = false)
{
	this->SetWindowTitle(WindowName);
	this->SetPrefferedWindowSize(WindowPrefferedWidth, WindowPrefferedHeight);
	this->FullscreenSet = WindowFullscren;
	GameScene = new CoreGameplay::Scene();
}

CoreApp::~CoreApp() {
}

void CoreApp::displayWrapper() { instance->display(); }
void CoreApp::reshapeWrapper(int width, int height) { instance->reshape(width, height); }
void CoreApp::runWrapper() { instance->run(); }
void CoreApp::mouseButtonPressWrapper(int button, int state, int x, int y) { instance->mouseButtonPress(button, state, x, y); }
void CoreApp::mouseButtonWrapper(int button, int state, int x, int y) { instance->mouseButton(button, state, x, y); }
void CoreApp::mouseMoveWrapper(int x, int y) { instance->mouseMove(x, y); }
void CoreApp::keyboardDownWrapper(unsigned char key, int x, int y) { instance->keyboardDown(key, x, y); }
void CoreApp::keyboardUpWrapper(unsigned char key, int x, int y) { instance->keyboardUp(key, x, y); }
void CoreApp::specialKeyboardDownWrapper(int key, int x, int y) { instance->specialKeyboardDown(key, x, y); }
void CoreApp::specialKeyboardUpWrapper(int key, int x, int y) { instance->specialKeyboardUp(key, x, y); }


///////////////////////////////////
// METODY OKNA APLIKACJI
///////////////////////////////////

void CoreApp::SetWindowTitle(std::string WindowTitle)
{
	this->WindowTitle = WindowTitle;
}

void CoreApp::SetWindowIcon(std::string WindowIcon)
{
	this->WindowIcon = WindowIcon;
}

bool CoreApp::SetPrefferedWindowSize(int WindowWidth, int WindowHeight)
{
	if (WindowWidth > 0 && WindowHeight > 0) {
		this->WindowWidth = WindowWidth;
		this->WindowHeight = WindowHeight;
		return true;
	}
	else {
		return false;
	}
}

bool CoreApp::SetMinimumWindowSize(int WindowWidth, int WindowHeight)
{
	if (WindowWidth > 0 && WindowHeight > 0) {
		this->MinimumWindowWidth = WindowWidth;
		this->MinimumWindowHeight = WindowHeight;
		return true;
	}
	else {
		return false;
	}
}

bool CoreApp::SetMaximumWindowSize(int WindowWidth, int WindowHeight)
{
	if (WindowWidth > 0 && WindowHeight > 0) {
		this->MaximumWindowWidth = WindowWidth;
		this->MaximumWindowHeight = WindowHeight;
		return true;
	}
	else {
		return false;
	}
}

void CoreApp::EnableWindowFullscreen()
{ 
	this->FullscreenSet = true;
}

void CoreApp::DisableWindowFullscreen()
{
	this->FullscreenSet = false;
}

void CoreApp::StartApplication(int argc, char *argv[]) {

	setInstance();							

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(WINDOW_X_POSITION, WINDOW_Y_POSITION);
	glutInitWindowSize(this->WindowWidth, this->WindowHeight);
	glutCreateWindow(this->WindowTitle.c_str());
	if(this->FullscreenSet == true) glutFullScreen();

	glutDisplayFunc(displayWrapper);
	glutReshapeFunc(reshapeWrapper);
	glutIdleFunc(runWrapper);

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(keyboardDownWrapper);
	glutSpecialFunc(specialKeyboardDownWrapper);
	glutSpecialUpFunc(specialKeyboardUpWrapper);
	glGenTextures(3, tex);
	CoreTexture::TGA *TGATexture = new CoreTexture::TGA();
	glBindTexture(GL_TEXTURE_2D, tex[0]);
	TGATexture->LoadTGAMipmap("tex0.tga");
	glBindTexture(GL_TEXTURE_2D, tex[1]);
	TGATexture->LoadTGAMipmap("tex1.tga");
	glBindTexture(GL_TEXTURE_2D, tex[2]);
	TGATexture->LoadTGAMipmap("tex2.tga");

	glutKeyboardUpFunc(keyboardUpWrapper);

	glutMouseFunc(mouseButtonWrapper);
	glutMotionFunc(mouseMoveWrapper);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LIGHTING);		        
	glShadeModel(GL_SMOOTH);
	glMateriali(GL_FRONT, GL_SHININESS, 64);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
					
	glutMainLoop();							
}

void CoreApp::load() {
}

///////////////////////////////////
// METODY MECHANIZMU SILNIKA 
///////////////////////////////////


void CoreApp::drawSnowMan() {

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, tex[1]);
	glBegin(GL_QUADS);
	// Œciana bli¿sza
	glTexCoord2f(0, 0); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(1, 0); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(1, 1); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(0, 1); glVertex3f(-0.5f, -0.5f, 0.5f);
	// Œciana dalsza
	glTexCoord2f(0, 0); glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(1, 0); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(1, 1); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(0, 1); glVertex3f(-0.5f, -0.5f, -0.5f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, tex[1]);
	glBegin(GL_QUADS);
	// Œciana górna
	glTexCoord2f(0, 0); glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(1, 0); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(1, 1); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0, 1); glVertex3f(-0.5f, 0.5f, 0.5f);
	// Œciana dolna
	glTexCoord2f(0, 0); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1, 0); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1, 1); glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(0, 1); glVertex3f(-0.5f, -0.5f, 0.5f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, tex[1]);
	glBegin(GL_QUADS);
	// Œciana lewa
	glTexCoord2f(0, 0); glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(1, 0); glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(1, 1); glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(0, 1); glVertex3f(-0.5f, -0.5f, 0.5f);
	// Œciana prawa
	glTexCoord2f(0, 0); glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(1, 0); glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(1, 1); glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(0, 1); glVertex3f(0.5f, -0.5f, 0.5f);
	glEnd();
	glPopMatrix();
}

void CoreApp::DrawBoxes()
{
	
	CColor *Color = new CColor(255, 255, 255);
	CColor *ColorRed = new CColor(240, 173, 219);
	glColor3f(Color->ReturnColorRF(), Color->ReturnColorGF(), Color->ReturnColorBF());
	for (int i = 0; i < 10; i++)
	{
		drawSnowMan();
		glTranslatef(1.0f, 0.0f, 0.0f);
	}
	glPushMatrix();
	glColor3f(ColorRed->ReturnColorRF(), ColorRed->ReturnColorGF(), ColorRed->ReturnColorBF());
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.2f, 10, 10);
	glColor3f(Color->ReturnColorRF(), Color->ReturnColorGF(), Color->ReturnColorBF());
	glPopMatrix();
	for (int i = 0; i < 5; i++)
	{
		drawSnowMan();
		glTranslatef(0.0f, 0.0f, 1.0f);
	}
	glPushMatrix();
		glColor3f(ColorRed->ReturnColorRF(), ColorRed->ReturnColorGF(), ColorRed->ReturnColorBF());
		glTranslatef(0.0f, 1.0f, 0.0f);
		glutSolidSphere(0.2f, 10, 10);
		glColor3f(Color->ReturnColorRF(), Color->ReturnColorGF(), Color->ReturnColorBF());
	glPopMatrix();
	glPushMatrix();
		for (int i = 0; i < 10; i++)
		{
			drawSnowMan();
			glTranslatef(-1.0f, 0.0f, 0.0f);
		}
	glPopMatrix();
	for (int i = 0; i < 5; i++)
	{
		drawSnowMan();
		glTranslatef(0.0f, 0.0f, 1.0f);
	}
	glPushMatrix();
	glColor3f(ColorRed->ReturnColorRF(), ColorRed->ReturnColorGF(), ColorRed->ReturnColorBF());
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.2f, 10, 10);
	glColor3f(Color->ReturnColorRF(), Color->ReturnColorGF(), Color->ReturnColorBF());
	glPopMatrix();
	for (int i = 0; i < 10; i++)
	{
		drawSnowMan();
		glTranslatef(-1.0f, 0.0f, 0.0f);
	}
	glPushMatrix();
	glColor3f(ColorRed->ReturnColorRF(), ColorRed->ReturnColorGF(), ColorRed->ReturnColorBF());
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.2f, 10, 10);
	glColor3f(Color->ReturnColorRF(), Color->ReturnColorGF(), Color->ReturnColorBF());
	glPopMatrix();
	for (int i = 0; i < 10; i++)
	{
		drawSnowMan();
		glTranslatef(0.0f, 0.0f, -1.0f);
	}
	glPushMatrix();
	glColor3f(ColorRed->ReturnColorRF(), ColorRed->ReturnColorGF(), ColorRed->ReturnColorBF());
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.2f, 10, 10);
	glColor3f(Color->ReturnColorRF(), Color->ReturnColorGF(), Color->ReturnColorBF());
	glPopMatrix();
}


void CoreApp::display() 
{
	if (GameScene->GetCamera()->GetDeltaHorizontalMove() || GameScene->GetCamera()->GetDeltaVerticalMove())
		GameScene->GetCamera()->ComputePos(GameScene->GetCamera()->GetDeltaHorizontalMove(), GameScene->GetCamera()->GetDeltaVerticalMove(), GameScene->GetGameMode()->GetActor()->GetMoveSpeed());

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glClearColor(0.75, 0.85 , 0.85, 1);

	glLoadIdentity();

	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Set lighting intensity and color
	GLfloat qaAmbientLight[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat qaDiffuseLight[] = { 1, 1, 1, 1.0 };
	GLfloat qaSpecularLight[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	// Set the light position
	GLfloat qaLightPosition[] = { 10.0, 5, 10.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);


	gluLookAt(GameScene->GetCamera()->GetCameraLocation().x, GameScene->GetCamera()->GetCameraLocation().y, GameScene->GetCamera()->GetCameraLocation().z,
		GameScene->GetCamera()->GetCameraLocation().x + GameScene->GetCamera()->GetCameraCenter().x, GameScene->GetCamera()->GetCameraCenter().y, GameScene->GetCamera()->GetCameraLocation().z + GameScene->GetCamera()->GetCameraCenter().z,
		GameScene->GetCamera()->GetCameraUp().x, GameScene->GetCamera()->GetCameraUp().y, GameScene->GetCamera()->GetCameraUp().z);

	/*printf("%f\t%f\t%f\n", GameScene->GetCamera()->GetCameraLocation().x, GameScene->GetCamera()->GetCameraLocation().y, GameScene->GetCamera()->GetCameraLocation().z);
	printf("%f\t%f\t%f\n", GameScene->GetCamera()->GetCameraLocation().x + GameScene->GetCamera()->GetCameraCenter().x, GameScene->GetCamera()->GetCameraCenter().y, GameScene->GetCamera()->GetCameraLocation().z + GameScene->GetCamera()->GetCameraCenter().z);
	printf("%f\t%f\t%f\n\n\n", GameScene->GetCamera()->GetCameraUp().x, GameScene->GetCamera()->GetCameraUp().y, GameScene->GetCamera()->GetCameraUp().z);*/
	

	CColor *Color = new CColor(117, 173, 195);
	glColor3f(Color->ReturnColorRF(), Color->ReturnColorGF(), Color->ReturnColorBF());
	glTranslatef(0,-0.5f,0);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();
	glTranslatef(0, 0.5f, 0);

	glEnable(GL_TEXTURE_2D);
	DrawBoxes();
		glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();
}

void CoreApp::reshape(int w, int h) 
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void CoreApp::mouseButtonPress(int button, int state, int x, int y) 
{

}

void CoreApp::keyboardDown(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

void CoreApp::keyboardUp(unsigned char key, int x, int y)
{

}

void CoreApp::specialKeyboardDown(int key, int x, int y)
{
	switch (key) {
		case GLUT_KEY_UP:
			GameScene->GetCamera()->SetDeltaVerticalMove(0.5f);
			break;
		case GLUT_KEY_DOWN:
			GameScene->GetCamera()->SetDeltaVerticalMove(-0.5f);
			break;
		case GLUT_KEY_RIGHT:
			GameScene->GetCamera()->SetDeltaHorizontalMove(0.5f);
			break;
		case GLUT_KEY_LEFT:
			GameScene->GetCamera()->SetDeltaHorizontalMove(-0.5f);
			break;
	}
}

void CoreApp::specialKeyboardUp(int key, int x, int y)
{
	switch (key) {
		case GLUT_KEY_UP:
		case GLUT_KEY_DOWN:
			GameScene->GetCamera()->SetDeltaVerticalMove(0);
		case GLUT_KEY_LEFT:
		case GLUT_KEY_RIGHT:
			GameScene->GetCamera()->SetDeltaHorizontalMove(0);
			break;
	}
}

void CoreApp::mouseMove(int x, int y) 
{
	if (GameScene->GetCamera()->GetXOrigin() >= 0) {
		GameScene->GetCamera()->SetDeltaAngle((x - GameScene->GetCamera()->GetXOrigin()) * 0.002f);
		GameScene->GetCamera()->SetCameraCenter(sin(GameScene->GetCamera()->GetAngle() + GameScene->GetCamera()->GetDeltaAngle()), 1.0f, -cos(GameScene->GetCamera()->GetAngle() + GameScene->GetCamera()->GetDeltaAngle()));
	}
}

void CoreApp::mouseButton(int button, int state, int x, int y)
{
	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			GameScene->GetCamera()->SetAngle(GameScene->GetCamera()->GetDeltaAngle() + GameScene->GetCamera()->GetAngle());
			GameScene->GetCamera()->SetXOrigin(-1);
		}
		else {// state = GLUT_DOWN
			GameScene->GetCamera()->SetXOrigin(x);

		}
	}
}

void CoreApp::Init() {
}

DWORD _ptt;
void CoreApp::run() {
	DWORD tt = GetTickCount();
	if (_ptt != 0) {
		float czass = (tt - _ptt) / 1000.0f;
	}
	_ptt = tt;

	glutPostRedisplay();
}

void CoreApp::setInstance() { instance = this; }