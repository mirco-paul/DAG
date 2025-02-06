namespace dag{

    template<typename NodeType>
    DAG<NodeType>::DAG() : graph::Graph<NodeType>::Graph(), is_topo_order_up_to_date_(false){}

    template<typename NodeType>
    DAG<NodeType>::DAG(size_t n) : graph::Graph<NodeType>::Graph(n), is_topo_order_up_to_date_(false){}

    template<typename NodeType>
    DAG<NodeType>::DAG(std::vector<NodeType> node_data, std::vector<std::vector<graph::NodeId>> adjacency_lists) : graph::Graph<NodeType>::Graph(node_data, adjacency_lists), is_topo_order_up_to_date_(false){}

    template<typename NodeType>
    graph::NodeId DAG<NodeType>::addNode(NodeType node_data) {
        is_topo_order_up_to_date_ = false;
        return graph::Graph<NodeType>::addNode(node_data);
    }

    template<typename NodeType>
    void DAG<NodeType>::addEdge(const graph::NodeId from, const graph::NodeId to){
        is_topo_order_up_to_date_ = false;
        graph::Graph<NodeType>::addEdge(from, to);
    }

    template<typename NodeType>
    void DAG<NodeType>::DFS(graph::NodeId id, std::vector<bool>& visited){
        visited[id] = true;
        for(const graph::NodeId successor : getSuccessors(id)){
            if(!visited[successor]) DFS(successor, visited);
        }
        topo_order_.push_back(id);
    }

    template<typename NodeType>
    const std::vector<graph::NodeId>& DAG<NodeType>::topoOrder(){
        if (!is_topo_order_up_to_date_){
            // (Re)compute topo_order_
            topo_order_.clear();
            std::vector<bool> visited(size(), false);
            // Maybe make graph.getNodes()
            for(graph::NodeId node = 0; node < size(); ++node){
                if(!visited[node]) DFS(node, visited);
            }
            std::reverse(topo_order_.begin(), topo_order_.end());
            is_topo_order_up_to_date_ = true;
        }
        return topo_order_;
    }

}   // namespace dag