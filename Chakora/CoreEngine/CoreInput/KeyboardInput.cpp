#include "KeyboardInput.h"

namespace CoreInput {
	KeyboardInput::KeyboardInput() {
		for (int i = 0; i < NUMBER_KEYS; i++) {
			keys[i] = UP;
		}
	}

	void KeyboardInput::keyDown(int key) {
		keys[key] = DOWN;
	}

	void KeyboardInput::keyUp(int key) {
		keys[key] = UP;
	}

	bool KeyboardInput::isKeyDown(int key) {
		if (keys[key] == DOWN) {
			return true;
		}
		else {
			return false;
		}
	}
}