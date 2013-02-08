#include <iostream>
#include "Player.h"

#include "Imagebank.h"

// Externally declared imagebank
extern Imagebank imagebank;

#pragma region Base

Player::Player() {
}

Player::~Player() {
}

#pragma endregion

#pragma region Publics

void Player::Init(sf::RenderWindow* window, float* frameTime, float* viewPosition) {
	_window = window;
	_frameTime = frameTime;
	_viewPosition = viewPosition;

	_sprite.SetImage(imagebank["Player"]);
	_sprite.SetCenter(PLAYER_RECT_POS);

	_rect.Top    = PLAYER_START_POS + 420;
	_rect.Bottom = PLAYER_START_POS + 420 + PLAYER_SIZE.y;
	_rect.Left   = PLAYER_START_POS + 300;
	_rect.Right  = PLAYER_START_POS + 300 + PLAYER_SIZE.x;

	_sprite.SetPosition(_rect.Left - *_viewPosition, _rect.Top);
}
void Player::Move(sf::Vector2i dir) {
	float delta = *_frameTime * PLAYER_SPEED;

	if((dir.x != 0) && (dir.y != 0)) {
		delta /= 1.414;
	}

	_rect.Offset(dir.x * delta, dir.y * delta);
	//std::cout << "top: " << _rect.Top << "  bot: " << _rect.Bottom << "  left: " << _rect.Left << "  right: " << _rect.Right << "\n";

	if (_rect.Top < PLAYER_EDGE_TOP) {
		_rect.Offset(0, PLAYER_EDGE_TOP - _rect.Top);
	} else if (_rect.Bottom > PLAYER_EDGE_BOT) {
		_rect.Offset(0, PLAYER_EDGE_BOT - _rect.Bottom);
	}
	// Check scrolling for horizontal movement outside edges.
	if (_rect.Left - *_viewPosition < PLAYER_EDGE_LEFT) {
		*_viewPosition = _rect.Left - PLAYER_EDGE_LEFT;
	} else if (_rect.Right - *_viewPosition > PLAYER_EDGE_RIGHT) {
		*_viewPosition = _rect.Right - PLAYER_EDGE_RIGHT;
	}

	// Check for wastelands end
	if (*_viewPosition < 0) {
		*_viewPosition = 0;
		if (_rect.Left < PLAYER_EDGE_LEFT) {
			_rect.Left  = PLAYER_EDGE_LEFT;
			_rect.Right = PLAYER_EDGE_LEFT + PLAYER_SIZE.x;
		}
	}
	
	
	_sprite.SetPosition(_rect.Left - *_viewPosition, _rect.Top);

	std::cout << *_viewPosition << "\n";
}
void Player::Draw() {
	_window->Draw(_sprite);
}

sf::Rect<float> Player::GetRect() {
	return _rect;
}

#pragma endregion 

#pragma region Privates



#pragma endregion