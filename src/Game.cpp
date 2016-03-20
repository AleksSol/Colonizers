#include "Game.h"

Game::Game()
	: _field(std::unique_ptr<Field>(new Field())), _players()
{
}

Game::~Game()
{
}

Field &Game::field() const noexcept
{
	return *_field;
} 

Player &Game::add_player(const std::string &name)
{
	Player *new_player = new Player(name);
	_players.push_back(std::unique_ptr<Player> (new_player) );
	return *new_player;
}

size_t Game::num_players() const noexcept
{
	return _players.size();
} 

Player &Game::player(size_t i) const
{
	if (i > (num_players() - 1) || i < 0) {
		throw std::out_of_range("This game haven't enought players!\n");
	}
	return *_players[i];
}
