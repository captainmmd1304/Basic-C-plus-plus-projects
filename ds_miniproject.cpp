#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

class SocialNetwork {
private:
    // Adjacency list: user -> set of friends
    unordered_map<string, unordered_set<string>> graph;
    
public:
    // Add a new user to the network
    void addUser(const string& username) {
        if (graph.find(username) != graph.end()) {
            cout << "User '" << username << "' already exists!\n";
            return;
        }
        graph[username] = unordered_set<string>();
        cout << "User '" << username << "' added successfully.\n";
    }
    
    // Add friendship between two users
    void addFriendship(const string& user1, const string& user2) {
        if (graph.find(user1) == graph.end()) {
            cout << "User '" << user1 << "' does not exist!\n";
            return;
        }
        if (graph.find(user2) == graph.end()) {
            cout << "User '" << user2 << "' does not exist!\n";
            return;
        }
        if (user1 == user2) {
            cout << "Cannot add friendship with yourself!\n";
            return;
        }
        
        graph[user1].insert(user2);
        graph[user2].insert(user1);
        cout << "Friendship added between '" << user1 << "' and '" << user2 << "'.\n";
    }
    
    // View all friends of a user
    void viewFriends(const string& username) {
        if (graph.find(username) == graph.end()) {
            cout << "User '" << username << "' does not exist!\n";
            return;
        }
        
        cout << "\n--- Friends of " << username << " ---\n";
        if (graph[username].empty()) {
            cout << "No friends yet.\n";
        } else {
            for (const string& friendName : graph[username]) {
                cout << "  - " << friendName << "\n";
            }
        }
    }
    
    // Find mutual friends between two users
    void mutualFriends(const string& user1, const string& user2) {
        if (graph.find(user1) == graph.end() || graph.find(user2) == graph.end()) {
            cout << "One or both users do not exist!\n";
            return;
        }
        
        cout << "\n--- Mutual Friends between " << user1 << " and " << user2 << " ---\n";
        vector<string> mutual;
        
        for (const string& friendName : graph[user1]) {
            if (graph[user2].count(friendName)) {
                mutual.push_back(friendName);
            }
        }
        
        if (mutual.empty()) {
            cout << "No mutual friends.\n";
        } else {
            for (const string& name : mutual) {
                cout << "  - " << name << "\n";
            }
        }
    }
    
    // Suggest friends (friends-of-friends who are not already friends)
    void suggestFriends(const string& username) {
        if (graph.find(username) == graph.end()) {
            cout << "User '" << username << "' does not exist!\n";
            return;
        }
        
        cout << "\n--- Friend Suggestions for " << username << " ---\n";
        unordered_map<string, int> suggestions;
        
        // For each friend
        for (const string& friendName : graph[username]) {
            // Check their friends (friends-of-friends)
            for (const string& fof : graph[friendName]) {
                // Skip if it's the user themselves or already a friend
                if (fof != username && graph[username].count(fof) == 0) {
                    suggestions[fof]++;
                }
            }
        }
        
        if (suggestions.empty()) {
            cout << "No suggestions available.\n";
            return;
        }
        
        // Sort suggestions by number of mutual connections
        vector<pair<string, int>> sortedSuggestions(suggestions.begin(), suggestions.end());
        sort(sortedSuggestions.begin(), sortedSuggestions.end(), 
             [](const pair<string, int>& a, const pair<string, int>& b) {
                 return a.second > b.second;
             });
        
        for (const auto& suggestion : sortedSuggestions) {
            cout << "  - " << suggestion.first << " (" << suggestion.second << " mutual connection(s))\n";
        }
    }
    
    // Display all users in the network
    void displayAllUsers() {
        cout << "\n--- All Users in Network ---\n";
        if (graph.empty()) {
            cout << "No users in the network.\n";
            return;
        }
        for (const auto& pair : graph) {
            cout << "  - " << pair.first << " (" << pair.second.size() << " friend(s))\n";
        }
    }
};

void displayMenu() {
    cout << "\n========== SOCIAL NETWORK MENU ==========\n";
    cout << "1.  Add User\n";
    cout << "2.  Add Friendship\n";
    cout << "3.  View Friends\n";
    cout << "4.  Find Mutual Friends\n";
    cout << "5.  Friend Suggestions\n";
    cout << "6.  Display All Users\n";
    cout << "7.  Exit\n";
    cout << "=========================================\n";
    cout << "Enter your choice: ";
}

int main() {
    SocialNetwork network;
    int choice;
    string user1, user2;
    
    cout << "Welcome to the Social Network Graph System!\n";
    
    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); 
        
        switch (choice) {
            case 1:
                cout << "Enter username: ";
                getline(cin, user1);
                network.addUser(user1);
                break;
                
            case 2:
                cout << "Enter first user: ";
                getline(cin, user1);
                cout << "Enter second user: ";
                getline(cin, user2);
                network.addFriendship(user1, user2);
                break;
                
            case 3:
                cout << "Enter username: ";
                getline(cin, user1);
                network.viewFriends(user1);
                break;
                
            case 4:
                cout << "Enter first user: ";
                getline(cin, user1);
                cout << "Enter second user: ";
                getline(cin, user2);
                network.mutualFriends(user1, user2);
                break;
                
            case 5:
                cout << "Enter username: ";
                getline(cin, user1);
                network.suggestFriends(user1);
                break;
                
            case 6:
                network.displayAllUsers();
                break;
                
            case 7:
                cout << "Thank you for using Social Network Graph System!\n";
                return 0;
                
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    
    return 0;
}