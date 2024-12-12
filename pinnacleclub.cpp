#include <iostream>
#include <cstring>
using namespace std;

struct node {
    int prn;
    char name[20];
    node *next;
};

class pinnacle {
    node *head = NULL, *tail = NULL;

public:
    // Add a node to the end
    void create() {
        int data;
        char name1[20];
        node *temp = new node;
        cout << "Enter the PRN: ";
        cin >> data;
        cout << "Enter the Name: ";
        cin >> name1;
        temp->prn = data;
        strcpy(temp->name, name1);
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Add a node at the beginning (President)
    void president() {
        int data;
        char name1[20];
        node *temp = new node;
        cout << "Enter the PRN: ";
        cin >> data;
        cout << "Enter the Name: ";
        cin >> name1;
        temp->prn = data;
        strcpy(temp->name, name1);
        temp->next = head;
        head = temp;
    }

    // Add a node after a specific PRN
    void member() {
        int data, pos;
        char name1[20];
        node *temp = new node;
        cout << "Enter the PRN: ";
        cin >> data;
        cout << "Enter the Name: ";
        cin >> name1;
        temp->prn = data;
        strcpy(temp->name, name1);
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            cout << "Enter the PRN after which you want to insert: ";
            cin >> pos;

            node *mem = head;
            while (mem != NULL) {
                if (mem->prn == pos) {
                    temp->next = mem->next;
                    mem->next = temp;
                    if (temp->next == NULL) {
                        tail = temp;
                    }
                    break;
                }
                mem = mem->next;
            }
        }
    }

    // Display the list
    void display() {
        node *print = head;
        while (print != NULL) {
            cout << print->prn << " ---> " << print->name << "\t";
            print = print->next;
        }
        cout << endl;
    }

    // Count and display the total nodes
    void total() {
        int count = 0;
        node *current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        cout << "Total number of nodes: " << count << endl;
    }

    // Delete the first node (President)
    void Delete_pre() {
        if (head != NULL) {
            node *temp = head;
            head = head->next;
            delete temp;
        } else {
            cout << "LIST IS EMPTY!" << endl;
        }
    }

    // Delete the last node (Secretary)
    void Delete_sec() {
        if (head != NULL) {
            node *current = head;
            node *prev = NULL;

            while (current->next != NULL) {
                prev = current;
                current = current->next;
            }

            if (prev != NULL) {
                prev->next = NULL;
                tail = prev;
            } else {
                head = NULL;
                tail = NULL;
            }
            delete current;
        } else {
            cout << "List is Empty!" << endl;
        }
    }

    // Delete a member after a specific PRN
    void Delete_mem() {
        int pos;
        cout << "Enter the PRN after which you want to delete: ";
        cin >> pos;

        node *current = head;
        while (current != NULL && current->prn != pos) {
            current = current->next;
        }

        if (current != NULL && current->next != NULL) {
            node *temp = current->next;
            current->next = temp->next;
            if (temp == tail) {
                tail = current;
            }
            delete temp;
        } else {
            cout << "Position not found or no member after the given PRN." << endl;
        }
    }
};

// Main function
int main() {
    int ch1, ch2, ch3;
    char ch;
    pinnacle p;

    do {
        cout << "\t___________MENU____________" << endl;
        cout << "\t1.CREATE" << endl;
        cout << "\t2.DISPLAY" << endl;
        cout << "\t3.INSERT MEMBER" << endl;
        cout << "\t4.TOTAL MEMBERS" << endl;
        cout << "\t5.DELETE" << endl;
        cout << "********************************************" << endl;
        cout << "\tENTER YOUR CHOICE: ";
        cin >> ch1;

        switch (ch1) {
        case 1:
            p.create();
            break;
        case 2:
            p.display();
            break;
        case 3:
            cout << "\t1.PRESIDENT" << endl;
            cout << "\t2.MEMBERS" << endl;
            cout << "\t3.SECRETARY" << endl;
            cout << "\tENTER YOUR CHOICE: ";
            cin >> ch2;

            switch (ch2) {
            case 1:
                p.president();
                break;
            case 2:
                p.member();
                break;
            case 3:
                p.create();
                break;
            }
            break;
        case 4:
            p.total();
            break;
        case 5:
            cout << "\t1.PRESIDENT" << endl;
            cout << "\t2.MEMBERS" << endl;
            cout << "\t3.SECRETARY" << endl;
            cout << "\tENTER YOUR CHOICE: ";
            cin >> ch3;

            switch (ch3) {
            case 1:
                p.Delete_pre();
                break;
            case 2:
                p.Delete_mem();
                break;
            case 3:
                p.Delete_sec();
                break;
            }
            break;
        default:
            cout << "\tYOU HAVE ENTERED THE WRONG CHOICE!" << endl;
            break;
        }

        cout << "DO YOU WANT TO CONTINUE (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
