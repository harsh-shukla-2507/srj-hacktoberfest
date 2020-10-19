#include <bits/stdc++.h>
using namespace std;

//to add node
void add_node(map<int, unordered_set<int> >& adj, int u)
{ //reference passed
    //check if node alreday there
    if (adj.find(u) != adj.end()) {
        cout << "Node already present\n";
    }
    else {
        unordered_set<int> st; //empty list
        adj[u] = st;
        cout << "node added to the graph\n";
    }
}

//to delete node
void delete_node(map<int, unordered_set<int> >& adj, int u)
{ //reference passed
    //check if node is there or not
    if (adj.find(u) == adj.end()) {
        cout << "Node not present\n";
    }
    else {
        //delete list of the node to be deleted
        adj.erase(u);
        //delete from others node's list
        for (auto it = adj.begin(); it != adj.end(); it++) {
            if (it->second.find(u) != it->second.end()) {
                it->second.erase(u);
            }
        }
        cout << "node deleted from the graph\n";
    }
}

//to add an edge
void add_edge(map<int, unordered_set<int> >& adj, int u, int v)
{
    //chcek if nodes are there or not
    if (adj.find(u) == adj.end() && adj.find(v) == adj.end()) {
        cout << "both nodes not found\n";
    }
    else if (adj.find(u) == adj.end()) {
        cout << "source node not found\n";
    }
    else if (adj.find(v) == adj.end()) {
        cout << "destination node not found\n";
    }
    else {
        if (adj[u].find(v) == adj[u].end()) {
            adj[u].insert(v);
            adj[v].insert(u);
            cout << "Edge added to the graph\n";
        }
        else {
            cout << "Edge already exists\n";
        }
    }
}

//to delete an edge
void delete_edge(map<int, unordered_set<int> >& adj, int u, int v)
{
    //chcek if nodes are there or not
    if (adj.find(u) == adj.end() && adj.find(v) == adj.end()) {
        cout << "both nodes not found\n";
    }
    else if (adj.find(u) == adj.end()) {
        cout << "source node not found\n";
    }
    else if (adj.find(v) == adj.end()) {
        cout << "destination node not found\n";
    }
    else {
        if (adj[u].find(v) == adj[u].end()) {
            cout << "Edge doesn't exist\n";
        }
        else {
            adj[u].erase(v);
            adj[v].erase(u);
            cout << "Edge deleted from the graph\n";
        }
    }
}

//to print the graph by adjacency list
void print(map<int, unordered_set<int> >& adj)
{
    if (adj.size() == 0) {
        cout << "Empty graph\n";
        return;
    }

    cout << "printing the graph in terms of adcacency list\n";
    cout << "node     list of adjacency nodes\n";
    for (auto & [ u, v ] : adj) {
        cout << u << "      ";
        if (v.size() == 0) {
            cout << "Empty\n";
        }
        else {
            for (auto& i : v) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    //adjacency list
    map<int, unordered_set<int> > adj;
    int option;
    do {
        cout << "1.press 1 to insert a node\n";
        cout << "2.press 2 to delete a node\n";
        cout << "3.press 3 to insert an edge\n";
        cout << "4.press 4 to delete an edge\n";
        cout << "5.print the graph via adjacency list\n";
        cout << "6.exit\n";

        cin >> option;
        int node, u, v;
        switch (option) {
        case 1: //add node

            cout << "input node to add(an integer denoting node no)\n";
            cin >> node;
            add_node(adj, node);
            break;
        case 2: //delete node

            cout << "input node to delete(an integer denoting node no)\n";
            cin >> node;
            delete_node(adj, node);
            break;
        case 3: //add edge

            cout << "input source and destination node to add an edge\n";
            cout << "input source node\n";
            cin >> u;
            cout << "input destination node\n";
            cin >> v;
            add_edge(adj, u, v);
            break;
        case 4: //delete edge

            cout << "input source and destination node to delete an edge\n";
            cout << "input source node\n";
            cin >> u;
            cout << "input destination node\n";
            cin >> v;
            delete_edge(adj, u, v);
            break;
        case 5: //print graph
            print(adj);
            break;
        case 6: //exit
            cout << "exiting...\n";
            adj = {}; //deleting the graph, good practice to free memory
            return 0;
            break;
        default:
            cout << "Wrong input,only integers b/w 1-6:\n";
            cout << "try again\n";
        }
    } while (true);

    return 0;
}
