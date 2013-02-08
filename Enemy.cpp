#include <iostream>
#include "Enemy.h"

#include "Imagebank.h"

// Externally declared imagebank
extern Imagebank imagebank;

#pragma region Base

Enemy::Enemy() {
}

Enemy::~Enemy() {
}

#pragma endregion

#pragma region Publics

void Enemy::Init(sf::RenderWindow* window, float* frameTime, float* viewPosition) {
	_window = window;
	_frameTime = frameTime;
	_viewPosition = viewPosition;

	_sprite.SetImage(imagebank["Enemy"]);
	_sprite.SetCenter(ENEMY_RECT_POS);

	_rect.Top    = 420;
	_rect.Bottom = 420 + ENEMY_SIZE.y;
	_rect.Left   = *_viewPosition + SCREEN_SIZE.x - 400;
	_rect.Right  = *_viewPosition + SCREEN_SIZE.x - 400 + ENEMY_SIZE.x;

	_sprite.SetPosition(_rect.Left - *_viewPosition, _rect.Top);
}
void Enemy::Update(sf::Rect<float> playerRect) {
	if (_rect.Left > *_viewPosition + ENEMY_STABLE_POS) {
		_rect.Offset(*_frameTime * ENEMY_SPEED * -1, 0);
	}
	_sprite.SetPosition(_rect.Left - *_viewPosition, _rect.Top);
}
void Enemy::Draw() {
	_window->Draw(_sprite);
}

#pragma endregion 

#pragma region Privates



#pragma endregion
