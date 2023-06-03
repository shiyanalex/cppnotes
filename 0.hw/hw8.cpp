#include <iostream>

using namespace std;

struct node_of_the_one_sided_list
{
    float real_value_of_the_node_of_one_sided_list;
    node_of_the_one_sided_list* next_node_of_the_one_sided_list;
};

void node_plus(node_of_the_one_sided_list* &node, float value_of_the_new_node)
{
    if (!node)
    {
        node = new node_of_the_one_sided_list;
        node->real_value_of_the_node_of_one_sided_list = value_of_the_new_node;
        node->next_node_of_the_one_sided_list = NULL;
    }
    else
    {
        while (node->next_node_of_the_one_sided_list)
            node = node->next_node_of_the_one_sided_list;
        node->next_node_of_the_one_sided_list = new node_of_the_one_sided_list;
        node->next_node_of_the_one_sided_list->real_value_of_the_node_of_one_sided_list = value_of_the_new_node;
        node->next_node_of_the_one_sided_list->next_node_of_the_one_sided_list = NULL;
    }
}

void create_one_sided_list(node_of_the_one_sided_list* node, int kolichestvo_uzlov)
{
    for (int i = 0; i < kolichestvo_uzlov; i++)
    {
        node->next_node_of_the_one_sided_list = new node_of_the_one_sided_list;
        node = node->next_node_of_the_one_sided_list;
    }
}

void delete_one_sided_list(node_of_the_one_sided_list* &node)
{
    while (node->next_node_of_the_one_sided_list)
        delete_one_sided_list(node->next_node_of_the_one_sided_list);
    delete node;
}

node_of_the_one_sided_list* search_for_the_value(node_of_the_one_sided_list* node, float znachenie)
{
    if (!node)
    {
        cout << "your list is empty";
        return NULL;
    }
    while (node)
    {
        if (node->real_value_of_the_node_of_one_sided_list == znachenie)
            break;
        else
            node = node->next_node_of_the_one_sided_list;
    }
    if (!node)
    {
        cout << "there's nothing";
        return NULL;
    }
    else return node;
}

node_of_the_one_sided_list* last_node_in_the_list(node_of_the_one_sided_list* node)
{
    if (!node) { cout << "your list is empty"; return NULL; }
    while (node->next_node_of_the_one_sided_list)
        node = node->next_node_of_the_one_sided_list;
    return node;
}

bool search_for_the_adress(node_of_the_one_sided_list* node, node_of_the_one_sided_list* iskomoe)
{
    if (!node)
    {
        cout << "your list is empty";
        return 0;
    }
    while (node)
    {
        if (node == iskomoe)
            return 1;
        else node = node->next_node_of_the_one_sided_list;
    }
    return 0;
}

node_of_the_one_sided_list* node_n_of_the_one_sided_list(node_of_the_one_sided_list* node, int nomer)
{
    if (!node) { cout << "your list is empty"; return NULL; }
    for (int i = 0; i < nomer - 1; i++)
    {
        if (!(node->next_node_of_the_one_sided_list)) { cout << "there's no such element"; return NULL; }
        node = node->next_node_of_the_one_sided_list;
    }
    return node;
}

void insert_nodes_after_nodes_n(node_of_the_one_sided_list* node, int nomer, float znachenie)
{
    node_of_the_one_sided_list* vremennaya;
    if (!node) cout << "your list is empty";
    for (int i = 0; i < nomer - 1; i++)
    {
        if (!(node->next_node_of_the_one_sided_list)) { break; cout << "there're less elements"; }
        node = node->next_node_of_the_one_sided_list;
    }
    vremennaya->next_node_of_the_one_sided_list = node->next_node_of_the_one_sided_list;
    node->next_node_of_the_one_sided_list = new node_of_the_one_sided_list;
    node->next_node_of_the_one_sided_list->next_node_of_the_one_sided_list = vremennaya;
    node->next_node_of_the_one_sided_list->real_value_of_the_node_of_one_sided_list = znachenie;
}

node_of_the_one_sided_list* previous_node(node_of_the_one_sided_list* node, node_of_the_one_sided_list* tekushchiy)
{
    if (!(node && tekushchiy)) { cout << "something's NULL"; return NULL; }
    if (node == tekushchiy) { cout << "there is no previous"; return NULL; }
    while (node)
    {
        if (node->next_node_of_the_one_sided_list == tekushchiy) return node;
        node = node->next_node_of_the_one_sided_list;
    }
    cout << "your adress is not in the list";
    return NULL;
}

void insert_before_previous(node_of_the_one_sided_list* node, node_of_the_one_sided_list* tekushchiy, float znachenie)
{
    node_of_the_one_sided_list* vremennaya;
    if (!(node && tekushchiy)) cout << "something's NULL";
    if (node == tekushchiy) 
    while (node)
    {
        if (node->next_node_of_the_one_sided_list == tekushchiy) 
        { 
            vremennaya->next_node_of_the_one_sided_list = node->next_node_of_the_one_sided_list;
            node->next_node_of_the_one_sided_list = new node_of_the_one_sided_list;
            node->next_node_of_the_one_sided_list->next_node_of_the_one_sided_list = vremennaya;
            node->next_node_of_the_one_sided_list->real_value_of_the_node_of_one_sided_list = znachenie;
            break;
        }
        node = node->next_node_of_the_one_sided_list;
    }
    if (vremennaya=NULL) cout << "your adress is not in the list";
}

void delete_n_element(node_of_the_one_sided_list* node, node_of_the_one_sided_list* udalit)
{
    if (!(node && udalit)) cout << "something's NULL";
    if (node = udalit)
    {
        cout << "new adress of the first node of your list: " << node->next_node_of_the_one_sided_list;
        delete udalit;
    }
    else
    {
        if (search_for_the_adress(node, udalit))
        {
            (previous_node(node, udalit)->next_node_of_the_one_sided_list) = udalit->next_node_of_the_one_sided_list;
            delete udalit;
        }
        else cout << "it was already out of the list";
    }
}

void print(node_of_the_one_sided_list* node) {
    int i = 1;
    if (node == NULL) cout << "your list is empty";
    else
    {
        while (node)
        {
            cout << i << ". " << node->real_value_of_the_node_of_one_sided_list << "\t" << node->next_node_of_the_one_sided_list << "\n";
            i++;
        }
    }
}

int main()
{
    node_of_the_one_sided_list* pervyi_node = new node_of_the_one_sided_list;
    pervyi_node = NULL;
    node_plus(pervyi_node, 13.09);
}

