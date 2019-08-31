#include "ManagerExample.h"

#include "MoreInfo.h"

/*
ManagerExample::ManagerExample() {
	cactiTexture[0].loadFromFile(SMALL_CACTUS_T);
	cactiTexture[1].loadFromFile(LARGE_CACTUS_T);
	cactiTexture[2].loadFromFile(MULTIPLE_CACTUS_T);

	for (int x = 0; x < 1; x++) {
		cactiVector.emplace_back(new Cacti(cactiTexture[0], CACTI_SPEED_LEVEL_1));
		cactiVector[x]->setPosition(sf::Vector2<float>(SCREEN_WIDTH, CACTI_ORIGIN_Y));
	}
}

void ManagerExample::renderTo(sf::RenderWindow& window) {
	for (auto& cacti : cactiVector) {
		cacti->renderTo(window);
	}
}

void ManagerExample::update() {
	for (auto& cacti : cactiVector) {
		cacti->update();

		//Determines when new cacti is added
		if (cacti->getX() == SCREEN_WIDTH / 2) {
			addCacti(1);
		}
	}

	//Removal of cacti from vector
	auto newEnd = std::remove_if(cactiVector.begin(), cactiVector.end(), [](std::unique_ptr<Cacti> & cacti) {
		return !cacti->isOnScreen();
		});
	cactiVector.erase(newEnd, cactiVector.end());

}

void ManagerExample::addCacti(unsigned int textureType) {
	std::unique_ptr<Cacti> cacti(new Cacti(cactiTexture[0], CACTI_SPEED_LEVEL_1));
	cacti->setPosition(sf::Vector2<float>(SCREEN_WIDTH, CACTI_ORIGIN_Y));
	cactiVector.push_back(std::move(cacti));
}

bool ManagerExample::collision(sf::FloatRect bounds) {
	for (auto& cacti : cactiVector) {
		if (cacti->getGlobalBounds().intersects(bounds)) {
			return true;
		}
	}
	return false;
}
*/
