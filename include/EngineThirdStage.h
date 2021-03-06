#pragma once

class EngineThirdStage : public Engine
{
public:
	virtual ~EngineThirdStage(){}
	virtual bool is_start_stage() const noexcept;	
	virtual bool is_first_stage() const noexcept;
	virtual bool is_second_stage() const noexcept;
	virtual bool is_third_stage() const noexcept;
	virtual bool is_final_stage() const noexcept;
};

