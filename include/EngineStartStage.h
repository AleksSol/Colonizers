#pragma once
#include "Engine.h"
#include "Game.h"

class EngineStartStage : public Engine
{
public:
	EngineStartStage();
	virtual ~EngineStartStage();
	virtual bool is_start_stage() const noexcept;	
	virtual bool is_first_stage() const noexcept;
	virtual bool is_second_stage() const noexcept;
	virtual bool is_third_stage() const noexcept;
	virtual bool is_final_stage() const noexcept;
	bool check_all_infr(const Game &game) const noexcept;
	bool first_line;
};

