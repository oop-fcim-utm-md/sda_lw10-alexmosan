#ifndef _HEADER_H_
#define _HEADER_H_

#include <string>
#include <vector>

struct data_t
{
    unsigned int id_{0};
    std::string name_{};
};

struct node_t
{
    node_t * left_{nullptr};
    node_t * right_{nullptr};
    data_t data_;
};

void initialize(node_t ** root, const std::vector<std::string> & array);
node_t * bsearch(node_t * root, const std::string search_val);
void sort(node_t ** root, std::vector<std::string> & array);
unsigned int height(node_t * root);
void print(node_t * root);
void clear(node_t * root);

#endif
