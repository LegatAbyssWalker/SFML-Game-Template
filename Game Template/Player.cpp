#include "Player.h"

#include "MoreInfo.h"


Player::Player(sf::Texture* texture, sf::Vector2<unsigned> imageCount, float switchTime, float speed) 
	: Entity(*texture), animation{ texture, imageCount, switchTime } {

	this->speed = speed;

	entity.setOrigin(entity.getGlobalBounds().width / 2, entity.getGlobalBounds().height / 2);
}

void Player::updatePlayer(bool continuous) {
	//Movement/Animation
	sf::Vector2<float> playerMovement(0.f, 0.f);
	using Key = sf::Keyboard::Key;
	auto keyDown = [](sf::Keyboard::Key k) { return sf::Keyboard::isKeyPressed(k); };

	if      (keyDown(Key::W)) { playerMovement.y -= speed; setDirection(Animation::Direction::up);    moving = true; }
	else if (keyDown(Key::A)) { playerMovement.x -= speed; setDirection(Animation::Direction::left);  moving = true; }
	else if (keyDown(Key::S)) { playerMovement.y += speed; setDirection(Animation::Direction::down);  moving = true; }
	else if (keyDown(Key::D)) { playerMovement.x += speed; setDirection(Animation::Direction::right); moving = true; }
	else                      { moving = false; }


	animation.updateAnimation(continuous, moving);
	entity.setTextureRect(animation.uvRect);
	entity.move(playerMovement);
}

void Player::setDirection(const Animation::Direction& direction) {
	animation.direction = direction;
}


void Player::updateBorderBounds() {
	//Entity cannot go through the borders of the screen
	if (getX() <= SCREEN_WIDTH * 0) { setPosition(sf::Vector2<float>(getX() + PLAYER_BORDER_SPEED, getY())); } //Left Side
	if (getX() >= SCREEN_WIDTH)		{ setPosition(sf::Vector2<float>(getX() - PLAYER_BORDER_SPEED, getY())); } //Right Side
}
