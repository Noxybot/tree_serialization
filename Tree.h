#pragma once
#include "BaseHolder.h"
#include "IntHolder.h"
#include "DoubleHolder.h"
#include "CharHolder.h"

class Tree
{
private:
	std::shared_ptr<BaseHolder> mRoot = nullptr;

public:
	Tree(std::shared_ptr<BaseHolder> root) : mRoot(root) {
		mRoot = std::make_shared<IntHolder>(nullptr, 57);
		mRoot->Children().push_back(std::make_shared<CharHolder>(mRoot, "gfdgdfgdg" ));
		mRoot->Children().push_back(std::make_shared<DoubleHolder>(mRoot, 421.3213));
	};
	void Print() const;


private:
	void Print_private(std::shared_ptr<BaseHolder> node) const;
	void PrintNode(std::shared_ptr<BaseHolder> node) const;
};

std::ostream& operator<<(std::ostream &out, const std::variant<int, double, std::array<char, 10>> &var);