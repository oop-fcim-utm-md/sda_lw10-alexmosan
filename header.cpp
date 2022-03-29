#include "header.h"

#include <string>
#include <vector>
#include <iostream>


int init_help(node_t** root, std::vector<std::string> name,int id)
{      
    if ((*root) == NULL)
    {    
        (*root) = new node_t;
        (*root)->data_.name_ = name[id];
        (*root)->data_.id_ = id+1;
        (*root)->left_ = NULL;
        (*root)->right_ = NULL;           
        return id+1;       
       
    }
    if ((*root)->data_.name_ < name[id])
    {
        id = init_help(&(*root)->right_, name,id);
        return id ;
    }
    else
    {
        id = init_help(&(*root)->left_, name, id);
        return id;
    }
    
}
void initialize(node_t** root, const std::vector<std::string>& array)
{
    for (size_t i = 0; i < array.size();)
    {
        i = init_help(root, array, i);
    }

}



node_t* bsearch(node_t* root, const std::string search_val)
{
    if (root == NULL) 
        return NULL;
    if (root->data_.name_ == search_val)
        return root; 
    
    else
    {
        if (search_val < root->data_.name_)
        {
            node_t* temp = bsearch(root->left_, search_val);
            if (temp->data_.name_ == search_val)
                return  temp;
        }
        else {
            node_t* temp = bsearch(root->right_, search_val);
            if (temp->data_.name_ == search_val)
                return  temp;
        }
    }   
}

void sort_helper(node_t* root, std::vector<std::string>& array,int id)
{
    if(root)
    {
        if (id == 0) 
        {
            if (root->data_.name_ < array[id])
                array[id] = root->data_.name_;
        }
        else
        {
           
            if (root->data_.name_>array[id - 1] && root->data_.name_ < array[id])
                array[id] = root->data_.name_;
        }
            
        sort_helper(root->left_, array, id);
        sort_helper(root->right_, array, id);
    }
}


void sort(node_t** root, std::vector<std::string>& array)
{
    for (size_t i = 0; i < array.size(); i++)
    {       
        array[i] = "Zzz";
        sort_helper((*root), array, i);
    }
}

unsigned int height(node_t* root)
{
    int count = 0;
    while (root) 
    {
        count++;
        if (root->left_ && root->right_)
        {
            if (root->left_->left_)
                root = root->left_;
            else if (root->right_->right_)
                root = root->right_;
        }
        else if (root->left_)
            root = root->left_;
        else if (root->right_)
            root = root->right_;
        else
            break;
    }
    return count;
}

void print(node_t* root)
{
    if (root != NULL) 
    { 
        std::cout << root->data_.id_ << " "<< root->data_.name_ << std::endl;
        print(root->left_);
        print(root->right_);
    }
}

void clear(node_t* root)
{
    if (root != NULL)
    {
        
        clear(root->left_);
        clear(root->right_);
        delete root;
    }
}
