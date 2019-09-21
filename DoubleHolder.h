#pragma once
#include "BaseHolder.h"

class DoubleHolder : public BaseHolder
{
private:
	double mData;

public:
	DoubleHolder(std::shared_ptr<BaseHolder> parent, double data);
	/*virtual*/
	buffer_t Serialize() const override;
	/*virtual*/
	void Deserialize(const buffer_t &buf) override;
	/*virtual*/
	std::variant<int, double, std::array<char, 10>> GetData() const override;
};