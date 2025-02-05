#include <iostream>
using namespace std;

class user {
private:
    string name;
    long int phoneno;
    float billamt;

public:
    user() {
        name = "";
        phoneno = 0;
        billamt = 0;
    }

    friend class record;
};

class record {
public:
    int n;
    user arr[100];
    
void accept() {
    cout << "Enter the number of users: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter name of the user: ";
        cin >> arr[i].name;
        cout << "Enter mobile number of the user: ";
        cin >> arr[i].phoneno;
        cout << "Enter bill amount of the user: ";
        cin >> arr[i].billamt;
    }
}

void display() {
    for (int i = 0; i < n; i++) {
    	cout<<"NAME \t\t\tPHONE NO \t\t\t BILL AMOUNT"<<endl;
        cout << arr[i].name << "\t\t\t ";
        cout << arr[i].phoneno << "\t\t\t ";
        cout << arr[i].billamt << endl;
    }
}

void linearSearch() {
    long int data;
    int flag = 0;
    cout << "Enter the mobile number to search using Linear Search: ";
    cin >> data;
    for (int i = 0; i < n; i++) {
        if (data == arr[i].phoneno) {
            cout << "Found user: " << arr[i].name << " with bill amount: " << arr[i].billamt << endl;
            flag = 1;
            return;
        }
    }

    if(flag = 0) cout << "User not found!" << endl;

    cout << "Mobile number not found!" << endl;
}

void binarySearch() {
    long int data;
    int l = 0,h= n - 1;
    cout << "Enter the mobile number to search using Binary Search: ";
    cin >> data;

    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[mid].phoneno == data) {
            cout << "Found user: " << arr[mid].name << " with bill amount: " << arr[mid].billamt << endl;
            return;
        } else if (arr[mid].phoneno < data) {
            l = mid + 1;
        } else {
           h= mid - 1;
        }
    }
    cout << "Mobile number not found!" << endl;
}

void heapify(int n, int i) {
    int high = i;
    int l = 2 * i + 1;
    int h= 2 * i + 2;

    if (l < n && arr[l].billamt > arr[high].billamt)
        high = l;

    if (h < n && arr[h].billamt > arr[high].billamt)
        high = h;

    if (high != i) {
        swap(arr[i], arr[high]);
        heapify(n, high);
    }
}

void heapSort() {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(i, 0);
    }
}

int partition(int l, int h) {
    long int pivot = arr[l].phoneno;
    int i = l;
    int j = h;

    while (i < j) {
        while (arr[i].phoneno <= pivot) i++;
        while (arr[j].phoneno > pivot) j--;

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

void quickSort(int l, int h) {
    if (l < h) {
        int pI = partition(l, h);
        quickSort(l, pI - 1);
        quickSort(pI + 1, h);
    }
}
};


int main() {
    record r1;
    int choice;

    while (true) {
        cout<<"\t MENU \t"<<endl;
	cout<<"\t 1: Accept Data \t"<<endl;
	cout<<"\t 2: Display Data \t"<<endl;
	cout<<"\t 3: Heap sort According to phone number  \t"<<endl;
	cout<<"\t 4: Quick sort According to phone number \t"<<endl;
	cout<<"\t 5: Binary Search According to phone number  \t"<<endl;
	cout<<"\t 6: Linear Search \t"<<endl;
	cout<<"\t 7: EXIT \t"<<endl;
	cout<<"Enter Your choice"<<endl;
	cin>>choice;
        switch (choice) {
            case 1:
                cout << "Accept User Records:\n";
		r1.accept();
                break;
            case 2:
		cout << "Displaying all records:\n";               
                r1.display();
                break;
            case 3:
                r1.heapSort();
                cout << "Data sorted by bill amount using Heap Sort:\n";
                break;
            case 4:
            	r1.quickSort(0, r1.n - 1);
                cout << "Data sorted by mobile number using Quick Sort:\n";
                r1.display();    
                break;
            case 5:r1.binarySearch();
            	break;
            case 6:r1.linearSearch();
 		 	
            case 7:
 		 cout << "Exiting program. Goodbye!\n";
                return 0;
                
                break;
           default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
