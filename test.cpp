#include "dag.hpp"

#include <iostream>

int main(){
    dag::DAG<int> dag;
    for(int i = 0; i < 5; ++i){
        dag.addNode(i);
    }
    std::cout << dag.size() << std::endl;
    dag.addEdge(0, 1);
    dag.addEdge(4, 1);
    dag.addEdge(1, 2);
    dag.addEdge(4, 2);
    dag.addEdge(3, 0);
    auto order = dag.topoOrder();
    for(auto v : order){
        std::cout << v << " ";
    }
    std::cout << std::endl;
    return 0;
}