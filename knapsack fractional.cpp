// Permasalahan Knapsack Fractional dengan greedy 
#include <bits/stdc++.h>

using namespace std;

// Structure untuk item/barang
// dimana terdapat weight dan profit
struct Item {
	int profit, weight;

	Item(int profit, int weight)
	{
	this->profit=profit;
	this->weight=weight;
	}
};

// Fungsi untuk mengurutkan item/barang
// berdasarkan rasio perbandingan profit dengan weight
bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.profit / (double)a.weight;
	double r2 = (double)b.profit / (double)b.weight;
	return r1 > r2;
}

// Fungsi utama greedy untuk memecahkan knapsack
double fractionalKnapsack(int W, struct Item arr[], int n)
{
	// sorting untuk greedy by density
	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i].profit << " " << arr[i].weight << " : "
			<< ((double)arr[i].profit / arr[i].weight) <<
	endl;
	}
	
	int curWeight = 0; // weight saat ini di knapsack
	double finalprofit = 0.0; // Hasil (profit di Knapsack)

	// Looping item
	for (int i = 0; i < n; i++) {
		// Jika item yang akan diambil belum melebihi kapasitas
		// maka diambil sepenuhnya
		if (curWeight + arr[i].weight <= W) {
			curWeight += arr[i].weight;
			finalprofit += arr[i].profit;
		}

		// Jika melebihi kapasitas
		// maka diambil sebagian(pecahan) untuk memenuhi sisa
		else {
			int remain = W - curWeight;
			finalprofit += arr[i].profit
						* ((double)remain
							/ (double)arr[i].weight);
			break;
		}
	}

	// Mengembalikan hasil profit
	return finalprofit;
}

// Program utama
int main()
{
	int M = 20; // kapasitas knapsack
	Item arr[] = { { 25, 18 }, { 24, 15 }, { 15, 10 } }; //{profit,weight}

	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call, untuk output
	cout << "\nProfit maksimal yang bisa kita dapatkan = "
		<< fractionalKnapsack(M, arr, n);
	return 0;
}

