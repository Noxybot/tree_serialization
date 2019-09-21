#pragma once
#include <list>
#include <memory>
#include <variant>

class BaseHolder
{
protected:
	std::shared_ptr<BaseHolder> mParent = nullptr;
	std::list<std::shared_ptr<BaseHolder>> mChildren{};
	
public:

	BaseHolder(std::shared_ptr<BaseHolder> parent)
		:
		mParent(parent)
	{}

	using buffer_t = std::pair<std::unique_ptr<char[]>, size_t>;

	void AddChild(std::shared_ptr<BaseHolder> child) { mChildren.push_back(child); }
	std::list<std::shared_ptr<BaseHolder>>& Children() { return mChildren; }
	
	virtual std::variant<int, double, std::array<char, 10>> GetData() const = 0;
	virtual buffer_t Serialize() const = 0;
	virtual void Deserialize(const buffer_t &buf) = 0;
};