#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "FPSCounter.h"
#include "Text.h"
#include "MoreInfo.h"
#include "Random.h"
#include "PlaySound.h"
#include "OStringText.h"

#include "Player.h"


#include "State.h"
#include "MainMenuState.h"
class StateMachine;

#include <iostream>
#include <fstream>
#include <array>
#include <memory>

class PlayingState : public State {
	public:
		PlayingState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);
		~PlayingState();

		void updateKeyboardInputs(sf::Keyboard::Key key, bool isPressed);

		void updateEvents();
		void update();
		void render();

	private:
		//Variables and Booleans



		//Arrays



		//Vectors



		//Class objects
		std::unique_ptr<Player> player = nullptr;

		FPSCounter fpsCounter;
		Text versionText;


		//SFML
		sf::Event sfEvent;
		sf::Texture playerTexture;
		sf::Clock dtClock;
		float	  dtTimer;
};

#endif