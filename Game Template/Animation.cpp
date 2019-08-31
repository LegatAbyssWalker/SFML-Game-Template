
#include "Animation.h"

Animation::Animation(sf::Texture* texture, const sf::Vector2<unsigned>& imageCount, float switchTime) : imageCount(imageCount), switchTime(switchTime) {
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

void Animation::updateAnimation(bool continuousAnimation, bool isMoving) {
	//If the animated entity can either change animation on command or continuous change
	//Continuous change
	if (continuousAnimation == true) {
		if (elapsed() > switchTime) {
			tp = std::chrono::steady_clock::now();
			currentImage.x++;

			if (currentImage.x >= imageCount.x) { currentImage.x = 0; }
		}
	}

	//Changing animation based on command
	else {
		currentImage.y = direction;

		if (isMoving) {
			if (elapsed() > switchTime) {
				tp = std::chrono::steady_clock::now();
				currentImage.x++;

				if (currentImage.x >= imageCount.x) { currentImage.x = 1; }
			}
		}

		else {
			currentImage.x = 0;
		}
	}

	uvRect.top = currentImage.y * uvRect.height;
	uvRect.left = currentImage.x * uvRect.width;
}