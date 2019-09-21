#include "IntHolder.h"

IntHolder::IntHolder(std::shared_ptr<BaseHolder> parent, int data)
	:
	BaseHolder(parent),
	mData(data)
{}

BaseHolder::buffer_t IntHolder::Serialize() const
{
	buffer_t res = std::make_pair(std::make_unique<char[]>(sizeof(int)), sizeof(int));
	std::memcpy(res.first.get(), &mData, sizeof(int));
	return res;
}

void IntHolder::Deserialize(const buffer_t &buf)
{
	std:memcpy(&mData, buf.first.get(), sizeof(int));
}

std::variant<int, double, std::array<char, 10>> IntHolder::GetData() const
{
	return std::variant<int, double, std::array<char, 10>>(mData);
}
