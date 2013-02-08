#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SFML/Graphics.hpp>

#include "Player.h"

class InputManager {
public:
	InputManager();
	~InputManager();

	void Init(sf::RenderWindow* window);
	bool Exit();
	void PlayerAction(Player &player);
private:
	bool IsKeyDown(sf::Key::Code);

	sf::RenderWindow* _window;
};
#endif
