#include <iostream>
#include <string>
#include <limits>
#include "DoublyLinkedList.h"

using namespace std;

void showmenu()
{
    cout<<"\n--- BROWSER HISTORY MANAGER---\n";
    cout<<"1. Visit New Page\n";
    cout<<"2. Re-Visit Page\n";
    cout<<"3. Clear Oldest History\n";
    cout<<"4. View History\n";
    cout<<"5. Exit\n";
    cout<<"\n\n";
    cout<<"Enter command: ";
}

int main()
{
    dll<string> history;
    
    int choice;
    string url;
    bool running = true;

    history.push_front("google.com");
    history.push_front("github.com");

    while(running)
    {
        showmenu();
        cin>>choice;
        cout<<"\n\n";

        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch(choice)
        {
            case 1:
                cout<<"Enter url: ";
                cin>>url;
                history.push_front(url);
                cout<<"Visited: "<<url<<endl;
                break;

            case 2: 
                cout << "Enter the URL you want to re-visit: ";
                cin >> url;
                
                { 
                    auto target = history.searcher(url);
                    
                    if (target != nullptr) {
                        history.movetohead(target);
                        cout << "\n Found " << url << "' and moved to top of history!"<< endl;
                    } else {
                        cout << "\n URL not found in history."<< endl;
                    }
                }
                break;

            case 3:
                if(history.gettail() != nullptr)
                {
                    cout<<"Deleting oldest history entry...";
                    history.deletetail();
                    cout<<"Deleted."<<endl;
                }
                else
                {
                    cout<< "History is already empty!"<<endl;
                }
                break;

            case 4:
                cout<<"Current History (Newest -> Oldest): "<<endl;
                history.print();
                break;

            case 5:
                cout<<"Closing Browser..."<<endl;
                running = false;
                break;

            default:
                cout<<"Invalid Choice. Please make a valid choice : 1/2/3/4/5"<<endl;
        }
    }

    cout<<"Bye! Visit again soon!"<<endl;
}