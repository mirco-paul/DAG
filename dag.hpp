/**
 * @file dag.hpp
 * 
 * @author David Gu
 * @author Mirco Paul
 * 
 * @date \today
 */
#pragma once

#include "graph/graph.hpp"

#include <algorithm>

// TODO: using namespace graph;

/**
 * 
 * @namespace DAG
 * 
 */
namespace dag {

    /**
     * @class DAG
     * 
     * @brief Directed acyclic graph.
     * 
     * @todo implement functions to check properties (acyclic, count entries, count exits, no multiple edges, ...)
     * 
     * @tparam T Node type.
     * 
     **/
    template<typename NodeType>
    class DAG : graph::Graph<NodeType>{

            bool is_topo_order_up_to_date_;
            std::vector<size_t> topo_order_;

            void DFS(graph::NodeId id, std::vector<bool>& visited);

        public:

            /**
             * 
             * Constructs an empty directed acyclic graph.
             * 
             **/
            DAG();

            /**
             * 
             * Constructs a directed acyclic graph with n nodes, no edges and uninitialized node data.
             * 
             **/
            DAG(size_t n);
            
            /**
             * 
             * Assumes node_data.size() == adjacency_lists.size() and adjacency_lists valid DAG 
             * that satisfies specification properties.
             * 
             **/
            DAG(std::vector<NodeType> node_data, std::vector<std::vector<graph::NodeId>> adjacency_lists);

            /**
             * 
             * @return Number of nodes in the graph.
             * 
             **/
            using graph::Graph<NodeType>::size;

            /**
             * 
             * @param id Node identifier.
             * 
             * @return Data of node with identifier id.
             * 
             **/
            using graph::Graph<NodeType>::get;

            /**
             * 
             * @param id Node identifier.
             * 
             * @return Immutable reference to vector of predecessors of node with identifier id.
             * 
             **/
            using graph::Graph<NodeType>::getPredecessors;

            /**
             * 
             * @param id Node identifier.
             * 
             * @return Immutable reference to vector of successors of node with identifier id.
             * 
             **/
            using graph::Graph<NodeType>::getSuccessors;

            /**
             * 
             * Adds a node with data node_data to the graph.
             * @param node_data Node data.
             * 
             * @return Identifier of the new node.
             * 
             **/
            graph::NodeId addNode(NodeType node_data);

            /**
             * 
             * Adds a directed edge from node from to node to.
             * @param from Source node.
             * 
             * @param to Destination node.
             * 
             **/
            void addEdge(const graph::NodeId from, const graph::NodeId to);


            /**
             * 
             * Lazily computes a topological order of the nodes in the current DAG.
             * If the graph has been modified the topological order is recomputed.
             * If the graph satisfies the specifications the first node in any topological 
             * order is entry_point and the last node in any topological order is exit_point_.
             * 
             * TO DO: is there a way to keep the topological order up to date in a more efficient way?
             * 
             * @return A vector of node identifiers in topological order.
             * 
             **/
            const std::vector<graph::NodeId>& topoOrder();

    };

} // namespace dag

#include "dag.tpp"
