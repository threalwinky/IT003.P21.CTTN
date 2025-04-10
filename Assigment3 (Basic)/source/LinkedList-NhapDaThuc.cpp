#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};

void Nhap(DATHUC &B, double heso, int somu){
    if (heso == 0){
        return;
    }
    DONTHUC* newNode = new DONTHUC(heso,somu);
    Node* node = new Node(newNode);
    if (B.head == nullptr){
        B.head = node;
        B.tail = node;
    }
    else{
        B.tail->next = node;
        B.tail = node;
    }
}

void Xuat(DATHUC B){
    Node* cur = B.head;
    if (B.head == nullptr){
        cout << "0";
        return;
    }
    while (cur != nullptr){
        if (cur->data->heso > 0 && cur != B.head) cout << "+";
        else if (cur->data->heso < 0) cout << "-";
        if (cur->data->heso == 0){
            cur = cur->next;
            continue;
        }
        if (cur->data->somu == 0){
            cout << abs(cur->data->heso);
            cur = cur->next;
            continue;
        }
        if (cur->data->somu == 1){
            cout << abs(cur->data->heso) << "x";
            cur = cur->next;
            continue;
        }
        if (abs(cur->data->heso) == 1){
            cout << "x^" << cur->data->somu;
            cur = cur->next;
            continue;
        }
        cout << abs(cur->data->heso) << "x^" << cur->data->somu;
        cur = cur->next;
    }
}

double TinhDaThuc(DATHUC B, double x){
    if (!B.head) return 0;
    double ans = 0;

    Node* cur = B.head;
    while (cur != nullptr){
        // cout << cur->data->heso << " " << cur->data->somu << "\n";
        ans += cur->data->heso * pow(x, cur->data->somu);
        cur = cur->next;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("TASK.INP", "r")){
    freopen("TASK.INP", "r", stdin);
    freopen("TASK.OUT", "w", stdout);}
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
