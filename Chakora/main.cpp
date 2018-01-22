#include "CoreEngine/CoreEngine/CoreApp.h"
#include "CoreEngine/CoreGameplay/Scene.h"
#include "CoreEngine/CoreGameplay/GameMode.h"

using namespace CoreEngine;

int main(int argc, char *argv[]) 
{
	CoreApp Application(
		"Ball Game",
		800,
		600,
		false
	);
	Application.StartApplication(argc, argv);
}