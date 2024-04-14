////////////////////////////////////////////////////////////
//
// Snatan - Extreme Snake Game
// Copyright (c) 2024 Oleh Kiprik (oleg.kiprik@proton.me)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
////////////////////////////////////////////////////////////

#ifndef GAME_DRAWABLE_HPP
#define GAME_DRAWABLE_HPP
#include "CentralViewScreen.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include "ChallengeVisual.hpp"
#include "Digits.hpp"

namespace CrazySnakes {

class GameDrawable {
public:

	[[nodiscard]] bool initConfig(const sf::Vector2f& windowSize,
								  const sf::Vector2u& innerViewSize, 
								  const sf::Texture& texture, 
								  const sf::Texture& digitTex,
								  std::uint32_t snakeBodyFill,
								  std::uint32_t snakeBodyOutline,
								  std::uint32_t snakePointerFill,
								  std::uint32_t snakePointerOutline,
								  std::uint32_t scoreColor,
								  std::uint32_t highestScoreColor,
								  std::uint32_t foggColor);

	void setBonusScale(float level);
	void setPowerupScale(float level);
	void setEffectScale(float level);
	void setTimeLimitScale(float level);

	CentraViewScreen centralView;

	sf::CircleShape challengeVisualOutline;
	sf::CircleShape fruitCountToBonusVisualOutline;
	sf::CircleShape bonusCountToPowerupVisualOutline;
	sf::CircleShape snakeCircle;
	sf::CircleShape snakePositionPointer;
	sf::CircleShape snakeEndPositionPointer;

	sf::RectangleShape bonusScale;
	sf::RectangleShape powerupScale;
	sf::RectangleShape effectScale;
	sf::RectangleShape timeLimitScale;

	Digits digits;
	Digits highestScore;

	ParticleSystem particles;
	ChallengeVisual challengeVisual;
	ChallengeVisual fruitCountToBonusVisual;
	ChallengeVisual bonusCountToPowerupVisual;

	// to draw correctly
	sf::Transform centralTransform;
	
	float scaleMaxLength = 0;
	float scaleWidth = 0;
	bool verticalOrientation = false;

private:

	void setScale(sf::RectangleShape& shape, float level);
};

}

#endif // !GAME_DRAWABLE_HPP