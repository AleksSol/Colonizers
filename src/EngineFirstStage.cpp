#include "EngineFirstStage.h"

EngineFirstStage::EngineFirstStage()
{
}

EngineFirstStage::~EngineFirstStage()
{
}

bool EngineFirstStage::is_start_stage() const noexcept
{
	return false;
}

bool EngineFirstStage::is_first_stage() const noexcept
{
	return true;
}

bool EngineFirstStage::is_second_stage() const noexcept
{
	return false;
}

bool EngineFirstStage::is_third_stage() const noexcept
{
	return false;
}

bool EngineFirstStage::is_final_stage() const noexcept
{
	return false;
}
