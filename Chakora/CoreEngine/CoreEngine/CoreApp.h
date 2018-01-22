#pragma once

#include "../BasicHeaders.h"
#include "../CoreEngine/Structures.h"
#include "../CoreEngine/PerformanceTimer.h"
#include "../CoreInput/KeyboardInput.h"
#include "../CoreGameplay/Scene.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//!  Silnik gry
namespace CoreEngine {
	//!  Aplikacja. 
	/*!
	Klasa aplikacji
	*/
	class CoreApp {
	protected:
		////////////////////////////////
		// Kontrolery aplikacji
		////////////////////////////////
		static CoreApp				*instance; /*!< Instancja aplikacji */
		CoreInput::KeyboardInput	keyStates; /*!< Kontroler klawiatury */

	private:
		////////////////////////////////
		// Zmienne okna aplikacji
		////////////////////////////////
		const static int FPS = 120;
		const static int WINDOW_X_POSITION = 100;
		const static int WINDOW_Y_POSITION = 100;
		int				WindowWidth;
		int				WindowHeight;
		int				MinimumWindowWidth;
		int				MinimumWindowHeight;
		int				MaximumWindowWidth;
		int				MaximumWindowHeight;
		bool			FullscreenSet;
		std::string		WindowTitle;
		std::string		WindowIcon;
		float			old_t;
		float			DeltaTime;
		GLuint tex[3];	/* Trzy tekstury */

		////////////////////////////////
		// Podstawowe komponenty 
		////////////////////////////////
		CoreGameplay::Scene * GameScene;

		////////////////////////////////
		// Zmienne œrodowiskowe
		////////////////////////////////
		double frameTimeElapsed;

		////////////////////////////////
		// Metody statyczne 
		////////////////////////////////
		static void displayWrapper();
		static void reshapeWrapper(int width, int height);
		static void runWrapper();
		static void mouseButtonPressWrapper(int button, int state, int x, int y);
		static void keyboardDownWrapper(unsigned char key, int x, int y);
		static void keyboardUpWrapper(unsigned char key, int x, int y);
		static void specialKeyboardDownWrapper(int key, int x, int y);
		static void specialKeyboardUpWrapper(int key, int x, int y);
		static void mouseMoveWrapper(int x, int y);
		static void mouseButtonWrapper(int button, int state, int x, int y);

		////////////////////////////////
		// Metody dzia³ania OpenGL
		////////////////////////////////
		virtual void load();
		virtual void display();
		virtual void reshape(int width, int height);
		virtual void mouseButtonPress(int button, int state, int x, int y);
		virtual void keyboardDown(unsigned char key, int x, int y);
		virtual void keyboardUp(unsigned char key, int x, int y);
		virtual void specialKeyboardDown(int key, int x, int y);
		virtual void specialKeyboardUp(int key, int x, int y);
		virtual void mouseMove(int x, int y);
		virtual void mouseButton(int button, int state, int x, int y);
		virtual void drawSnowMan();
		virtual void DrawBoxes();
	public:

		const static double FRAME_TIME;

		GLuint obiekt1;
		GLfloat lookA = 30;
		GLfloat angle;

		/**
		* Konstruktor klasy CoreApp
		* @param  WindowName
			Nazwa pojawiajaca sie w tytule okna.
		* @param  WindowPrefferedWidth
			Domyœlna szerokoœæ okna.
		* @param  WindowPrefferedHeight
			Domyœlna wysokoœæ okna.
		* @param  WindowFullscren
			Tryb pe³nego ekranu.
		* @see ~CoreApp()
		*/
		CoreApp(std::string WindowName, int WindowPrefferedWidth, int WindowPrefferedHeight, bool WindowFullscren);
		virtual ~CoreApp();
		void SetInstance();
		/**
		* Ustawianie tytu³u aplikacji
		* @param  WindowTitle
			Nazwa pojawiajaca sie w tytule okna.
		*/
		void SetWindowTitle(std::string WindowTitle);
		/**
		* Ustawianie ikony aplikacji
		* @param  WindowTitle
			Ikona pojawiaj¹ca siê w tytule okna oraz na pasku.
		*/
		void SetWindowIcon(std::string WindowIcon);
		/**
		* Ustawianie preferowanego rozmiaru okna aplikacji
		* @param  WindowWidth
			Szerokoœæ okna
		* @param  WindowHeight
			Wysokoœæ okna
		*/
		bool SetPrefferedWindowSize(int WindowWidth, int WindowHeight);
		/**
		* Ustawianie minimalnego rozmiaru okna aplikacji
		* @param  WindowWidth
			Szerokoœæ okna
		* @param  WindowHeight
			Wysokoœæ okna
		*/
		bool SetMinimumWindowSize(int WindowWidth, int WindowHeight);
		/**
		* Ustawianie maksymalnego rozmiaru okna aplikacji
		* @param  WindowWidth
			Szerokoœæ okna
		* @param  WindowHeight
			Wysokoœæ okna
		*/
		bool SetMaximumWindowSize(int WindowWidth, int WindowHeight);
		/**
		* Ustawienie aplikacji w trybie pe³nego ekranu
		*/
		void EnableWindowFullscreen();
		/**
		* Ustawienie aplikacji w trybie okienkowym
		*/
		void DisableWindowFullscreen();

		void StartApplication(int argc, char *argv[]);
		void setDisplayMatricies();
		void setupLights();
		void setLookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
		void Init();
		void setInstance();
		void run();
		CoreVector3D<float> getEyeCoreVector3D() const;
		CoreVector3D<float> getCenterCoreVector3D() const;
		CoreVector3D<float> getUpCoreVector3D() const;
	};
}