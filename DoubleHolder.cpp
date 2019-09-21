#include "DoubleHolder.h"

DoubleHolder::DoubleHolder(std::shared_ptr<BaseHolder> parent, double data)
	:
	BaseHolder(parent),
	mData(data)
{}

BaseHolder::buffer_t DoubleHolder::Serialize() const
{
	buffer_t res = std::make_pair(std::make_unique<char[]>(sizeof(double)), sizeof(double));
	std::memcpy(res.first.get(), &mData, sizeof(double));
	return res;
}

void DoubleHolder::Deserialize(const buffer_t &buf)
{
	std:memcpy(&mData, buf.first.get(), sizeof(double));
}

std::variant<int, double, std::array<char, 10>> DoubleHolder::GetData() const
{
	return std::variant<int, double, std::array<char, 10>>(mData);
}
