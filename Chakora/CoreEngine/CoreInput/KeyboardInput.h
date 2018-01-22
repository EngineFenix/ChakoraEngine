#ifndef KEYBOARDINPUT_H_INCLUDED
#define KEYBOARDINPUT_H_INCLUDED

namespace CoreInput {
	class KeyboardInput {
	private:
		enum Key { UP, DOWN, RELEASED };
		static const int NUMBER_KEYS = 256;
		Key keys[NUMBER_KEYS];
	public:
		KeyboardInput();
		void keyDown(int key);
		void keyUp(int key);
		bool isKeyDown(int key);
	};
}

#endif