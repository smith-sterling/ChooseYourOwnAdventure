#include <iostream>
#include <string>
#include <cctype>
#include <unistd.h>
#include <ctime>
using namespace std;

void MakeUpper (char & choice){
    choice = toupper(choice);
}

char PrintErrorReminder (){
    char newChoice;
    cout << "Invalid input." << endl;
    cout << "Please enter a valid input: " << endl;
    cin >> newChoice;
    MakeUpper(newChoice);
    return newChoice;
}

void OpeningMessage (string & nameUser, string & nameCrush) {
    nameUser.at(0) = toupper(nameUser.at(0));
    nameCrush.at(0) = toupper(nameCrush.at(0));
    cout << "\nWelcome " << nameUser << "! We have noted that you fancy " << nameCrush << ".";
    usleep(750000);
    cout << " Please standby.\n";
    if (rand() % 2) {
        usleep(750000);
        cout << "Calling " << nameCrush << " now... ";
        sleep(1);
        cout << "jk\n\n" << endl;
        sleep(1);
    }
}

void CheckForError (char & choice){
    do {
        if (choice != 'A' && choice != 'B'){
            choice = PrintErrorReminder();
        }
    } while (choice != 'A' && choice != 'B');
}

void CheckForErrorAllowC (char & choice){
    do {
        if (choice != 'A' && choice != 'B' && choice != 'C'){
            choice = PrintErrorReminder();
        }
    } while (choice != 'A' && choice != 'B' && choice != 'C');
}

int main() {
    char choice;
    string nameUser;
    string nameCrush;
    srand(time(0));
    bool wantsToPlay = true;

    while (wantsToPlay) {
        cout << "Please enter your first name: ";
        cin >> nameUser;
        cout << "Please enter the first name of a person you think is cute: ";
        cin >> nameCrush;

        OpeningMessage(nameUser, nameCrush);

        cout << "You walk past " << nameCrush
             << ", and want to ask them on a date, but you feel massive butterflies in your stomach. What do you do?\n"
             << "A) Bite the bullet and ask them out\n"
             << "B) It isn't worth it, run and hide" << endl;
        cin >> choice;
        MakeUpper(choice);

        CheckForError(choice);
        if (choice == 'B') {
            cout << "\nYou turn around to run, but in doing so, you trip. Do you\n"
                 << "A) Just lie there\n"
                 << "B) Get up like nothing happened and run home" << endl;
            cin >> choice;
            MakeUpper(choice);

            CheckForError(choice);
            if (choice == 'B') {
                cout << "\nYou die alone\n"
                     << "THE END" << endl;
            } else if (choice == 'A') {
                cout << "\n" << nameCrush << " immediately notices you and asks if you're ok. Do you \n"
                     << "A) Pretend you died\n"
                     << "B) Kiss them" << endl;
                cin >> choice;
                MakeUpper(choice);
                CheckForError(choice);

                if (choice == 'B') {
                    cout << "\nThey slap you indignantly.\n"
                         << "You die alone\n"
                         << "THE END" << endl;
                } else if (choice == 'A') {
                    cout << "\n911 is called and you are rushed to the (mental) hospital, where... \n"
                         << "You die alone\n"
                         << "THE END" << endl;
                }
            }

        } else if (choice == 'A') {
            cout << "\nYou walk up to them, nervous as heck. Do you\n"
                 << "A) Freeze up and pass out\n"
                 << "B) Ask for their number\n"
                 << "C) Start a conversation\n";
            cin >> choice;
            MakeUpper(choice);
            CheckForErrorAllowC(choice);

            if (choice == 'A') {
                cout << "\n" << nameCrush << " immediately notices you and asks if you're ok. Do you \n"
                     << "A) Pretend you died\n"
                     << "B) Kiss them\n";
                cin >> choice;
                MakeUpper(choice);
                CheckForError(choice);

                if (choice == 'B') {
                    cout << "\nThey slap you indignantly.\n"
                         << "You die alone\n"
                         << "THE END" << endl;
                } else if (choice == 'A') {
                    cout << "\n911 is called and you are rushed to the (mental) hospital, where... \n"
                         << "You die alone\n"
                         << "THE END" << endl;
                }
            } else if (choice == 'B') {
                cout << "\n" << nameCrush << " stares at you... \"Um, do I know you?\"\n"
                                             "Do you\n"
                                             "A) Lie (poorly)\n"
                                             "B) Chuckle nervously\n";
                cin >> choice;
                MakeUpper(choice);
                CheckForError(choice);

                if (choice == 'A') {
                    cout << "\n" << nameCrush << " sees straight through it, and ... \nslaps you indignantly.\n"
                                                 "You die alone\n"
                                                 "THE END\n";
                } else if (choice == 'B') {
                    cout << "\n" << nameCrush
                         << " backs away slowly, and calls in a favor, getting a restraining order. \n"
                            "You die alone. \n"
                            "THE END\n";
                }
            } else if (choice == 'C') {
                string convo[16] = {"\n" + nameUser +
                                    ": \"Is your name Virtue? Because you sure garnish my thoughts unceasingly!\"\n\n",
                                    nameCrush + ": \"... Ummm... I don't know how to say this\"\n\n",
                                    nameUser + ": \"I understand. You are nervous because of my witty charm.\"\n\n",
                                    nameCrush + ": \"Well...\"\n\n",
                                    nameUser +
                                    ": \"Let me guess, you've never dated before, you beautiful creature.\"\n\n",
                                    nameCrush + ": \"Excuse me?\"\n\n",
                                    nameUser + ": \"Your hair shines in the moonlight\"\n\n",
                                    nameCrush + ": \"Roses are red\"\n\n",
                                    nameUser + ": \" Even though it's noon\"\n\n",
                                    nameCrush + ": \"You don't comprehend\"\n\n",
                                    nameUser + ": \"I'll be your white knight\"\n\n",
                                    nameCrush + ": \"You seem nice enough\"\n\n",
                                    nameUser + ": \"Riding a baboon\"\n\n",
                                    nameCrush + ": \"But I have a boyfriend\"\n\n",
                                    nameUser + ": \" ... \"\n\n",
                                    "You die alone\nTHE END\n"};
//            cout << "\n" << nameUser << ": \"Is your name Virtue? Because you sure garnish my thoughts unceasingly!\"\n"
//                 << endl
//                 << nameCrush << ": \"... Ummm... I don't know how to say this\"\n"
//                 << endl
//                 << nameUser << ": \"I understand. You are nervous because of my witty charm.\"\n"
//                 << endl
//                 << nameCrush << ": \"Well...\"\n"
//                 << endl
//                 << nameUser << ": \"Let me guess, you've never dated before, you beautiful creature.\"\n"
//                 << endl
//                 << nameCrush << ": \"Excuse me?\"\n"
//                 << endl
//                 << nameUser << ": \"Your hair shines in the moonlight\"\n"
//                 << endl
//                 << nameCrush << ": \"Roses are red\"\n"
//                 << endl
//                 << nameUser << ": \" Even though it's noon\"\n"
//                 << endl
//                 << nameCrush << ": \"You don't comprehend\"\n"
//                 << endl
//                 << nameUser << ": \"I'll be your white knight\"\n"
//                 << endl
//                 << nameCrush << ": \"You seem nice enough\"\n"
//                 << endl
//                 << nameUser << ": \"Riding a baboon\"\n"
//                 << endl
//                 << nameCrush << ": \"But I have a boyfriend\"\n"
//                 << endl
//                 << nameUser << ": \" ... \"\n"
//                 << endl <<
//                    "You die alone\n"
//                    "THE END\n";
                for (int i = 0; i < 16; ++i) {
                    cout << convo[i];
                    usleep(1300000);
                }

            }
        }

        usleep(1500000);
        cout << "\n\n\nDo you want to play again?" << endl;
        cout << "If you would like to continue, input y" << endl;
        cout << "If you would like to quit, enter anything else." << endl;
        cin >> choice;
        if (choice == 'y' || choice == 'Y'){
            wantsToPlay = true;
        } else {
            wantsToPlay = false;
        }

        cout << "\n\n";
    }
    return 0;
}
