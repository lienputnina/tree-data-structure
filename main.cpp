#include <iostream>
#include <sstream>
#include <string>

#include "TreeObject.h"

using namespace std;

void HelpDesk()
{
    cout << "Instructions:" << endl;
    cout << "h[Enter] - Print the instructions." << endl;
    cout << "+id,parentId,name,type[Enter] - Add a new node to the tree." << endl;
    cout << "Enter a positive integer for the node id and its parent id, a string for node name and type. Node type can be either a folder (d) or a file (f)."
         << endl;
    cout << "-id[Enter] - Delete a node with a given id from the tree. Enter a positive integer for the node id." << endl;
    cout << "*id[Enter] - Display the tree, starting from a node with the given id. Enter a positive integer for the node id." << endl;
    cout << "*[Enter] - Display the whole tree." << endl;
    cout << "$[Enter] - Stop the program." << endl;
};

int main()
{
    cout << "Hello! Welcome to the Tree Manipulation Program!" << endl;

    TreeObject ChristmasTree;
    string userInput = "";

    while (true)
    {
        cout << "\nEnter a command (h for help):" << endl;
        cin >> userInput;

        if (userInput == "h")
        {
            HelpDesk();
        }

        if (userInput[0] == '+')
        {
            vector<string> userParameters;
            istringstream userInputStream(userInput.substr(1));
            string token;
            while (getline(userInputStream, token, ','))
            {
                userParameters.push_back(token);
            }

            int uniqueId = stoi(userParameters[0]);
            int parentId = stoi(userParameters[1]);
            string name = userParameters[2];
            string type = userParameters[3];

            if (uniqueId <= 0)
            {
                cout << "Invalid format. Please, enter a positive integer for the node id." << endl;
                continue;
            };

            if (parentId <= 0)
            {
                cout << "Invalid format. Please, enter a positive integer for the node parent id." << endl;
                continue;
            };

            if (name.empty())
            {
                cout << "Node name cannot be empty. Please, enter the node name." << endl;
                continue;
            };

            if (name.length() == 0)
            {
                cout << "The provided node name is too short. It needs to be a least one character long." << endl;
                continue;
            };

            if (type.empty())
            {
                cout << "Node type cannot be empty. Please provide a valid node type." << endl;
                continue;
            };

            if (type.length() == 0)
            {
                cout << "The provided node type is too short. It needs to be a least one character long." << endl;
                continue;
            };

            if (type != "d" && type != "f")
            {
                cout << "Invalid node type. Please, enter 'd' for 'katalogs' or 'f' for 'fails'." << endl;
                continue;
            };

            ChristmasTree.AddNode(uniqueId, parentId, name, type);
        }

        else if (userInput[0] == '-')
        {
            string id = userInput.substr(1);

            if (!id.empty() && stoi(id) <= 0)
            {
                cout << "Please, enter a positive integer for the node id." << endl;
                continue;
            }

            ChristmasTree.DeleteNode(stoi(id));
        }

        else if (userInput[0] == '*')
        {
            string id = userInput.substr(1);

            if (!id.empty() && stoi(id) <= 0)
            {
                cout << "Please, enter a positive integer for the node id." << endl;
                continue;
            }

            if (!id.empty())
            {
                ChristmasTree.PrintTree(stoi(id));
            }
            else
            {
                ChristmasTree.PrintTree(1);
            }
        }

        else if (userInput == "$")
        {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }

        else
        {
            cout << "Invalid command. Press 'h' for help." << endl;
        };
    }

    return 0;
}