#include<bits/stdc++.h>
using namespace std;

class Node {
    int userId;
    string userName;
    Node *nextFriend;

public:
    Node() {
        userId = -1;
        userName = "N/A";
        nextFriend = nullptr;
    }
    friend class SocialNetwork;
};

class SocialNetwork {
    Node *users[20]; 

public:
    int totalUsers; 

    SocialNetwork() {
        cout << "Enter the number of users: ";
        cin >> totalUsers;

        for (int i = 0; i < totalUsers; i++) {
            users[i] = new Node;
            users[i]->userId = i;
            cout << "Enter name for user " << i + 1 << ": ";
            cin >> users[i]->userName;
            users[i]->nextFriend = nullptr;
        }
    }

    void addConnections() {
        for (int i = 0; i < totalUsers; i++) {
            Node *current = users[i];
            string hasMore;
            do {
                int friendId;
                cout << "Enter the ID of a friend of " << users[i]->userName << " (0 to " << totalUsers - 1 << "): ";
                cin >> friendId;

                if (friendId == users[i]->userId) {
                    cout << "Cannot add yourself as a friend.\n";
                } else if (friendId < 0 || friendId >= totalUsers) {
                    cout << "Invalid ID. Try again.\n";
                } else {
                    Node *newFriend = new Node;
                    newFriend->userId = friendId;
                    newFriend->userName = users[friendId]->userName;
                    newFriend->nextFriend = nullptr;

                    current->nextFriend = newFriend;
                    current = newFriend;
                }

                cout << "Do you want to add more friends for " << users[i]->userName << "? (yes/no): ";
                cin >> hasMore;
            } while (hasMore == "yes");
        }
    }

    void displayNetwork() {
        cout << "\nSocial Network Connections:\n";
        for (int i = 0; i < totalUsers; i++) {
            Node *current = users[i];
            cout << current->userName << " (" << current->userId << ") --> ";
            current = current->nextFriend;
            while (current != nullptr) {
                cout << current->userName << " (" << current->userId << ") ";
                current = current->nextFriend;
                if (current != nullptr) cout << "-> ";
            }
            cout << endl;
        }
    }

    void bfsTraversal(int start) {
        cout << "\nBFS Traversal starting from " << users[start]->userName << " (" << start << "):\n";
        bool visited[totalUsers] = {false};
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
            cout << users[currentNode]->userName << " (" << currentNode << ") ";

            Node *temp = users[currentNode]->nextFriend;
            while (temp != nullptr) {
                if (!visited[temp->userId]) {
                    q.push(temp->userId);
                    visited[temp->userId] = true;
                }
                temp = temp->nextFriend;
            }
        }
        cout << endl;
    }

    void dfsTraversal(int start) {
        cout << "\nDFS Traversal starting from " << users[start]->userName << " (" << start << "):\n";
        bool visited[totalUsers] = {false};
        stack<int> s;

        s.push(start);

        while (!s.empty()) {
            int currentNode = s.top();
            s.pop();

            if (!visited[currentNode]) {
                cout << users[currentNode]->userName << " (" << currentNode << ") ";
                visited[currentNode] = true;

                Node *temp = users[currentNode]->nextFriend;
                while (temp != nullptr) {
                    if (!visited[temp->userId]) {
                        s.push(temp->userId);
                    }
                    temp = temp->nextFriend;
                }
            }
        }
        cout << endl;
    }

    void dfsRecursiveUtil(int node, bool visited[]) {
        visited[node] = true;
        cout << users[node]->userName << " (" << node << ") ";

        Node *temp = users[node]->nextFriend;
        while (temp != nullptr) {
            if (!visited[temp->userId]) {
                dfsRecursiveUtil(temp->userId, visited);
            }
            temp = temp->nextFriend;
        }
    }

    void dfsRecursive(int start) {
        bool visited[totalUsers] = {false};
        cout << "\nDFS Recursive Traversal starting from " << users[start]->userName << " (" << start << "):\n";
        dfsRecursiveUtil(start, visited);
        cout << endl;
    }
};

int main() {
	    SocialNetwork network;
	    network.addConnections();
	    network.displayNetwork();
    int choice;
    int startUser;
	    cout << "Enter the starting user ID for traversal: ";
	    cin >> startUser;
	while(choice!=4){
	    if (startUser >= 0 && startUser < network.totalUsers) {
	        cout << "Choose the traversal method:\n1. BFS\n2. DFS \n3. DFS (Recursive)\n4. Exit\n";
	        cin >> choice;
		}

	        switch (choice) {
	            case 1:
	                network.bfsTraversal(startUser);
	                break;
	            case 2:
	                network.dfsTraversal(startUser);
	                break;
	            case 3:
	                network.dfsRecursive(startUser);
	                break;
	            case 4:
	             	cout<<"Exited successfully... Goodbyeee!!"<<endl;
	            default:
	                cout << "Invalid choice. Please select 1, 2, or 3.\n";
	        }
	}
    return 0;
}

