#include "Tree.h"
#include <iostream>
#include <string>
void Tree::Print() const
{
	Print_private(mRoot);
}

void Tree::Print_private(std::shared_ptr<BaseHolder> node) const
{
	if (node != nullptr) {
		PrintNode(node);
		for (const auto &child : node->Children())
			Print_private(child);
	}
}

void Tree::PrintNode(std::shared_ptr<BaseHolder> node) const
{
	std::cout << "Node: " << node->GetData() << "\nChildren";
	std::string comma = "";
	for (const auto& child : node->Children()) {
		std::cout << comma << child->GetData();
		comma = ", ";
	}	
}

std::ostream & operator<<(std::ostream & out, const std::variant<int, double, std::array<char, 10>>& var)
{
	if (std::holds_alternative<int>(var))
		std::cout << std::get<int>(var);
	else if (std::holds_alternative<double>(var))
		std::cout << std::get<double>(var);
	else
		std::cout << std::get<std::array<char, 10>>(var);
	return out;
}
