template<class T>
string DGraph<T>::shape() {
    return "[Vertices: " + to_string(this->countVertex) + ", Edges: " + to_string(this->countEdge) + "]";
}

template<class T>
bool DGraph<T>::empty() {
    //TODO: return if graph is empty (it doesn't have any vertex and edge)
    return this->countVertex == 0;
}

template<class T>
void DGraph<T>::clear() {
    //TODO: remove all edges and vertices of graph.
    while (this->nodeList != nullptr) {
        VertexNode* tempNode = this->nodeList;
        this->nodeList = this->nodeList->next; 

        Edge* currentEdge = tempNode->adList;
        while (currentEdge != nullptr) {
            Edge* tempEdge = currentEdge;
            currentEdge = currentEdge->next;
            delete tempEdge; 
        }

        delete tempNode;
    }

    this->countVertex = 0;
    this->countEdge = 0;
    this->nodeList = nullptr;
}
