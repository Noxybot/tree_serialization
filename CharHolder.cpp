#include "CharHolder.h"

CharHolder::CharHolder(std::shared_ptr<BaseHolder> parent, const char(&data)[10])
	:
	BaseHolder(parent)
{
	std::memcpy(mData.data(), data, 10);
}

BaseHolder::buffer_t CharHolder::Serialize() const
{
	buffer_t res = std::make_pair(std::make_unique<char[]>(sizeof(char[10])), sizeof(char[10]));
	std::memcpy(res.first.get(), &mData, res.second);
	return res;
}

void CharHolder::Deserialize(const buffer_t &buf)
{
	std:memcpy(&mData, buf.first.get(), buf.second);
}

std::variant<int, double, std::array<char, 10>> CharHolder::GetData() const
{
	return std::variant<int, double, std::array<char, 10>>(mData);
}
