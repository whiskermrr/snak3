#include "mainGame.h"


void mainGame::Initiate(sf::RenderWindow* window)
{
	snake = new Snake();
	map.Load(backgroundFileName);
	food.setRandomPosition();
}

void mainGame::Render(sf::RenderWindow* window)
{
	window->draw(map);
	snake->Render(window);
	window->draw(food);
}

void mainGame::Update(sf::RenderWindow* window)
{
	snake->getInput();
	snake->Update();

	if (snake->body[0].x == food.getPosition().x / blockSize && snake->body[0].y == food.getPosition().y / blockSize)
	{
		scores++;
		snake->incrementSnakeSize();
		food.setRandomPosition();

		if (isTeleportsOn)
		{
			snake->body[0].x = rand() % N;
			snake->body[0].y = rand() % M;
			snake->direction = rand() % 4;
		}
	}
}

void mainGame::Destroy(sf::RenderWindow* window)
{
	delete snake;
	snake = NULL;
}

void mainGame::Reset(sf::RenderWindow* window)
{
}
