#include "Keyboard.h"

namespace CoreInput {
	
	Keyboard::Keyboard() {
		for( int i = 0; i < NUMBER_KEYS; i++ ) {
			keys[ i ] = UP;
		}
	}

	void Keyboard::keyDown( int key ) {
		keys[ key ] = DOWN;
	}

	void Keyboard::keyUp( int key ) {
		keys[ key ] = UP;
	}

	bool Keyboard::isKeyDown( int key ) {
		if( keys[ key ] == DOWN ) {
			return true;
		} else {
			return false;
		}
	}
}	
