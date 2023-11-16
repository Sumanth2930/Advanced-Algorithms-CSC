#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure for the Node
struct GraphNode {
    int vertex;         // Vertex (Node) number
    int weight;         // Weight (Distance) to reach this node

    // Overloading ">" operator for priority queue comparison
    bool operator>(const GraphNode &node) const {
        return weight > node.weight;
    }
};

// DijkstraAlgo function, pass function and source and dest
void DijkstraAlgo(const vector<vector<pair<int, int>>> &graph, int source, int destination) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);   // Vector to store the minimum distance to reach each node
    vector<int> parent_node(n, -1);
    priority_queue<GraphNode, vector<GraphNode>, greater<GraphNode>> priorityQueue;

    distance[source] = 0;
    priorityQueue.push({source, 0});

    // Loop priority queue
    while (!priorityQueue.empty()) {
        GraphNode presentNode = priorityQueue.top();
        priorityQueue.pop();

        int currentNode = presentNode.vertex;
        int dist = presentNode.weight;

        // Looping through the adjacent nodes of the current node
        auto neighborNode = graph[currentNode].begin();
        while (neighborNode != graph[currentNode].end()) {
            int neighborVertex = neighborNode->first;
            int weightCost = neighborNode->second;

            // Checking if the weight of the adjacent node is greater than the current weight
            if (dist + weightCost < distance[neighborVertex]) {
                distance[neighborVertex] = dist + weightCost;
                parent_node[neighborVertex] = currentNode;
                priorityQueue.push({neighborVertex, distance[neighborVertex]});
            }

            ++neighborNode;
        }
    }

    // Printing the path from source to destination
    cout << "Shortest Path from " << source << " to " << destination << ":\n";
    cout << "Cost: " << distance[destination] << "\nPath: ";

    int i = destination;
    vector<int> pathTraversal;
    while (i != -1) {
        pathTraversal.push_back(i);
        i = parent_node[i];
    }

    for (int j = pathTraversal.size() - 1; j >= 0; --j) {
        cout << pathTraversal[j];
        if (j != 0) cout << " -> ";
    }
}

// Main function definition
int main() {
    int numOfNodes;

    // Prompting the user for the number of nodes
    cout << "Enter the number of nodes : ";
    cin >> numOfNodes;

    if (numOfNodes <= 0) {
        cout << "Enter at least one node.\n";
        return 1;
    }

    vector<vector<pair<int, int>>> graph(numOfNodes);
    cout << "If there is no connection enter -999:\n ";

    // Letting the user to enter the weights between nodes
    for (int node1 = 0; node1 < numOfNodes; ++node1) {
        for (int node2 = node1 + 1; node2 < numOfNodes; ++node2) {
            int weightInBetween;

            cout << "Enter weight from node " << node1 << " to " << node2 << ": ";
            cin >> weightInBetween;

            if (weightInBetween == -999) {
                continue;
            }

            // Check if the same edge already exists with a different weight
            for (const auto &edgePath : graph[node1]) {
                if (edgePath.first == node2 && edgePath.second != weightInBetween) {
                    cout << "Different weights found between the same nodes.\n";
                    return 1;
                }
            }
            // Pushing the edge and weight to the graph
            graph[node1].push_back({node2, weightInBetween});
            graph[node2].push_back({node1, weightInBetween});
        }
    }

    int start, end;

    cout << "Enter the start node: ";
    cin >> start;

    cout << "Enter the end node: ";
    cin >> end;

    DijkstraAlgo(graph, start, end); // Calling DijkstraAlgo's function

    return 0;
}
