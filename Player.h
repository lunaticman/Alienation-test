#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "Consts.h"

class Player {
public:
	Player();
	~Player();

	void Init(sf::RenderWindow* window, float* frameTime, float* viewPosition);
	void Move(sf::Vector2i dir);
	void Draw();

	sf::Rect<float> GetRect();
private:
	sf::Sprite        _sprite;
	sf::Rect<float>   _rect;
	sf::RenderWindow* _window;
	float*			  _frameTime;
	float*            _viewPosition;
};
#endif

