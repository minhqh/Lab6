template <class T>
bool DGraph<T>::removeEdge(T from, T to) {
    VertexNode* fromNode = getVertexNode(from);
    VertexNode* toNode = getVertexNode(to);

    if (fromNode == nullptr || toNode == nullptr) {
        throw VertexNotFoundException("Vertex doesn't exist!");
    }

    if (fromNode->removeTo(toNode)) {
        this->countEdge--;
        return true;
    }

    return false;
}

template <class T>
void DGraph<T>::removeVertex(T removeVertex) {
    VertexNode* targetNode = getVertexNode(removeVertex);

    if (targetNode == nullptr) {
        throw VertexNotFoundException("Vertex doesn't exist!");
    }

    VertexNode* current = this->nodeList;
    while (current != nullptr) {
        if (current->removeTo(targetNode)) {
            this->countEdge--;
        }

        if (targetNode->removeTo(current)) {
            this->countEdge--;
        }

        current = current->next;
    }

    if (this->nodeList == targetNode) {
        this->nodeList = this->nodeList->next;
        delete targetNode;
    } 
    else {
        VertexNode* prev = this->nodeList;
        while (prev->next != nullptr && prev->next != targetNode) {
            prev = prev->next;
        }
        
        if (prev->next == targetNode) {
            prev->next = targetNode->next;
            delete targetNode;
        }
    }

    this->countVertex--;
}