#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

#include "Consts.h"

class Enemy {
public:
	Enemy();
	~Enemy();

	void Init(sf::RenderWindow* window, float* _frameTime, float* viewPosition);
	void Update(sf::Rect<float> playerRect);
	void Draw();

private:
	sf::Sprite        _sprite;
	sf::Rect<float>   _rect;
	sf::RenderWindow* _window;
	float*			  _frameTime;
	float*            _viewPosition;
};
#endif
