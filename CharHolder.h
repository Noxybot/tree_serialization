#pragma once
#include "BaseHolder.h"
#include <array>
class CharHolder : public BaseHolder
{
private:
	std::array<char, 10> mData;

public:
	CharHolder(std::shared_ptr<BaseHolder> parent, const char (&data)[10]);
	/*virtual*/
	buffer_t Serialize() const override;
	/*virtual*/
	void Deserialize(const buffer_t &buf) override;
	/*virtual*/
	std::variant<int, double, std::array<char, 10>> GetData() const override;
};