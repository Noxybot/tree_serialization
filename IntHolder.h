#pragma once
#include "BaseHolder.h"

class IntHolder : public BaseHolder
{
private:
	int mData;

public:
	IntHolder(std::shared_ptr<BaseHolder> parent, int data);
/*virtual*/
	buffer_t Serialize() const override;
/*virtual*/
	void Deserialize(const buffer_t &buf) override;
/*virtual*/
	std::variant<int, double, std::array<char, 10>> GetData() const override;
};