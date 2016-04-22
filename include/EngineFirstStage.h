#pragma once

class EngineFirstStage : public Engine
{
public:
	virtual ~EngineFirstStage(){}
	virtual bool is_start_stage() const noexcept;	
	virtual bool is_first_stage() const noexcept;
	virtual bool is_second_stage() const noexcept;
	virtual bool is_third_stage() const noexcept;
	virtual bool is_final_stage() const noexcept;
};
