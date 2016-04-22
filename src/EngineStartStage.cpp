#include "EngineStartStage.h"

EngineStartStage::~EngineStartStage()
{
}

bool EngineStartStage::is_start_stage() const noexcept
{
	return true;
}

bool EngineStartStage::is_first_stage() const noexcept
{
	return false;
}

bool EngineStartStage::is_second_stage() const noexcept
{
	return false;
}

bool EngineStartStage::is_third_stage() const noexcept
{
	return false;
}

bool EngineStartStage::is_final_stage() const noexcept
{
	return false;
}

bool EngineStartStage::check_all_infr(const Game &game) const noexcept
{
	for (size_t i = 0; i < game.num_players(); i++)
	{
		if (game.player(i).num_roads() != 15 || 
			game.player(i).num_towns() != 5 ||
			game.player(i).num_cities() != 4) {
			return false;
		}
	}
	return true;
}
