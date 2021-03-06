#ifndef KEYBOARD_H
#define KEYBOARD_H
namespace CoreInput {
	
	class Keyboard {
	private:
		enum Key { UP, DOWN, RELEASED };
		static const int NUMBER_KEYS = 256;
		Key keys[ NUMBER_KEYS ];

	public:

		/** Name: Keyboard()
		 * 
		 * Description: Initialize all keys in the up state 
		 */
		Keyboard();

		/** Name: keyDown()
		 *
		 * Description: Set the key to the down state 
		 * Param: key - the key that is being pressed
		 */
		void keyDown( int key );

		/** Name: keyDown()
		 *
		 * Description: Set the key to the up state 
		 * Param: key - the key that is being released
		 */
		void keyUp( int key );

		/** Name: isKeyDown
		 *
		 * Description: Test to see if the key is being pressed
		 */
		bool isKeyDown( int key );
	};

}
#endif
