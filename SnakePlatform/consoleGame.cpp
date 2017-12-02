#include "consoleGame.h"



consoleGame::consoleGame(unsigned int width, unsigned int height)
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	halfdelay(1);

	this->width = width * 2;
	this->height = height;

	window = newwin(height, width * 2, 5, 20);
	box(window, 0, 0);
	keypad(window, true);
	refresh();
	wrefresh(window);
}

void consoleGame::Initiate()
{
	snake = new SnakeConsole(window, width, height);
}

void consoleGame::Update()
{
	snake->getInput();
	snake->Update();
}

void consoleGame::Render()
{
	snake->Render();
}

void consoleGame::Destroy()
{
	delete snake;
	snake = NULL;
	delwin(window);
	endwin();
}

void consoleGame::Reset()
{

}

consoleGame::~consoleGame()
{
}