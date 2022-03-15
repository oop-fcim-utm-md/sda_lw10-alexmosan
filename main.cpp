#include "header.h"

#include <assert.h>
#include <string>
#include <vector>

int main(int argc, char const *argv[])
{
    node_t *root = nullptr;
    std::vector<std::string> input({
        "November", "October", "July", "March", "January", "August", "December", "February", "May", "April"});
    initialize(&root, input);
	print(root);

    assert(6 == height(root));

	assert("November" == root->data_.name_);
	assert("July" == root->left_->data_.name_);
	assert("October" == root->right_->data_.name_);

	assert("August" == bsearch(root, "August")->data_.name_);

	sort(&root, input);

    assert("April" == input.at(0));
    assert("October" == input.at(input.size() - 1));

	clear(root);
}
