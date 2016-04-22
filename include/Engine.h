#pragma once

class Engine
{
public:
	virtual ~Engine(){}
	virtual bool is_start_stage() const noexcept = 0;	
	virtual bool is_first_stage() const noexcept = 0;
	virtual bool is_second_stage() const noexcept = 0;
	virtual bool is_third_stage() const noexcept = 0;
	virtual bool is_final_stage() const noexcept = 0;
};

