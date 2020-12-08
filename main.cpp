#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <random>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Player {

public:

	string name;
	double ppg;
	double steals;
	double blocks;
	double assists;
	double rebounds;

public:

	Player() {
		
		name = "";
		ppg = 0;
		steals = 0;
		blocks = 0;
		assists = 0;
		rebounds = 0;
	}
	Player(string name, double ppg, double steals, double blocks, double assists, double rebounds) {

		this->name = name;
		this->ppg = ppg;
		this->steals = steals;
		this->blocks = blocks;
		this->assists = assists;
		this->rebounds = rebounds;
	}
	string randomName() {

		return name;
	}
	void generateData() {

		name = randomName();
	}
	void printStats() {

		cout << name << ": " << fixed << setprecision(2) << ppg << ", " << steals << ", " << blocks << ", " << assists << ", " << rebounds << endl;
	}
	vector<double> getStats() {

		vector<double> stats;

		stats.push_back(ppg);
		stats.push_back(steals);
		stats.push_back(blocks);
		stats.push_back(assists);
		stats.push_back(rebounds);
		return stats;
	}
};

//* ===== Sorting Algorithms ===== *//

// Quick Sort Helper Functions & Algorthim given as Psuedocode from Lecture Slides
double partitionPPG(vector<Player>& players, int low, int high) {

	double pivot = players[high].ppg;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (players[j].ppg < pivot) {
			i++;
			swap(players[i], players[j]);
		}
	}
	swap(players[i+1], players[high]);
	return i + 1;
}

double partitionSteals(vector<Player>& players, int low, int high) {

	double pivot = players[high].steals;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (players[j].steals < pivot) {
			i++;
			swap(players[i], players[j]);
		}
	}
	swap(players[i + 1], players[high]);
	return i + 1;
}

double partitionBlocks(vector<Player>& players, int low, int high) {

	double pivot = players[high].blocks;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (players[j].blocks < pivot) {
			i++;
			swap(players[i], players[j]);
		}
	}
	swap(players[i + 1], players[high]);
	return i + 1;
}

double partitionAssists(vector<Player>& players, int low, int high) {

	double pivot = players[high].assists;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (players[j].assists < pivot) {
			i++;
			swap(players[i], players[j]);
		}
	}
	swap(players[i + 1], players[high]);
	return i + 1;
}

double partitionRebounds(vector<Player>& players, int low, int high) {

	double pivot = players[high].rebounds;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (players[j].rebounds < pivot) {
			i++;
			swap(players[i], players[j]);
		}
	}
	swap(players[i + 1], players[high]);
	return i + 1;
}

void quickSort(string statToCheck, vector<Player>& players, int low, int high) {

	if (low < high) {
		
		double pivot;
		if (statToCheck == "ppg") {
			pivot = partitionPPG(players, low, high);
		}
		else if (statToCheck == "steals") {
			pivot = partitionSteals(players, low, high);
		}
		else if (statToCheck == "blocks") {
			pivot = partitionBlocks(players, low, high);
		}
		else if (statToCheck == "assists") {
			pivot = partitionAssists(players, low, high);
		}
		else if (statToCheck == "rebounds") {
			pivot = partitionRebounds(players, low, high);
		}
		else {
			cout << "Error with quickSort statToCheck input, program will sort by PPG..." << endl;
			pivot = partitionPPG(players, low, high);
		}
		
		quickSort(statToCheck, players, low, pivot - 1);
		quickSort(statToCheck, players, pivot + 1, high);
	}
}

// Heap Sort Helper Functions & Algorithm given as Pseudocode from Lecture Slides
void heapifyPPG(vector<Player>& players, int i, int n) {

	int smallest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	if (left < n && players[left].ppg < players[smallest].ppg) {
		smallest = left;
	}

	if (right < n && players[right].ppg < players[smallest].ppg) {
		smallest = right;
	}

	if (smallest != i) {
		swap(players[i], players[smallest]);
		heapifyPPG(players, smallest, n);
	}
}

void heapifySteals(vector<Player>& players, int i, int n) {

	int smallest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	if (left < n && players[left].steals < players[smallest].steals) {
		smallest = left;
	}

	if (right < n && players[right].steals < players[smallest].steals) {
		smallest = right;
	}

	if (smallest != i) {
		swap(players[i], players[smallest]);
		heapifySteals(players, smallest, n);
	}
}

void heapifyBlocks(vector<Player>& players, int i, int n) {

	int smallest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	if (left < n && players[left].blocks < players[smallest].blocks) {
		smallest = left;
	}

	if (right < n && players[right].blocks < players[smallest].blocks) {
		smallest = right;
	}

	if (smallest != i) {
		swap(players[i], players[smallest]);
		heapifyBlocks(players, smallest, n);
	}
}

void heapifyAssists(vector<Player>& players, int i, int n) {

	int smallest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	if (left < n && players[left].assists < players[smallest].assists) {
		smallest = left;
	}

	if (right < n && players[right].assists < players[smallest].assists) {
		smallest = right;
	}

	if (smallest != i) {
		swap(players[i], players[smallest]);
		heapifyAssists(players, smallest, n);
	}
}

void heapifyRebounds(vector<Player>& players, int i, int n) {

	int smallest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	if (left < n && players[left].rebounds < players[smallest].rebounds) {
		smallest = left;
	}

	if (right < n && players[right].rebounds < players[smallest].rebounds) {
		smallest = right;
	}

	if (smallest != i) {
		swap(players[i], players[smallest]);
		heapifyRebounds(players, smallest, n);
	}
}

void HeapSort(string statToCheck, vector<Player>& players) {
	
	if (statToCheck == "ppg") {
		
		//Build Heap
		int n = players.size() - 1;
		for (int i = (n / 2) - 1; i >= 0; i--) {
			heapifyPPG(players, i, n);
		}

		for (int i = n-1; i > 0; i--) {
			
			swap(players[0], players[i]);
			heapifyPPG(players, 0, i);
		}
	} else if (statToCheck == "steals") {
		
		//Build Heap
		int n = players.size() - 1;
		for (int i = (n / 2) - 1; i >= 0; i--) {
			heapifySteals(players, i, n);
		}

		for (int i = n - 1; i > 0; i--) {

			swap(players[0], players[i]);
			heapifySteals(players, 0, i);
		}
	} else if (statToCheck == "blocks") {
		
		//Build Heap
		int n = players.size() - 1;
		for (int i = (n / 2) - 1; i >= 0; i--) {
			heapifyBlocks(players, i, n);
		}

		for (int i = n - 1; i > 0; i--) {

			swap(players[0], players[i]);
			heapifyBlocks(players, 0, i);
		}
	} else if (statToCheck == "assists") {
		
		//Build Heap
		int n = players.size() - 1;
		for (int i = (n / 2) - 1; i >= 0; i--) {
			heapifyAssists(players, i, n);
		}

		for (int i = n - 1; i > 0; i--) {

			swap(players[0], players[i]);
			heapifyAssists(players, 0, i);
		}
	} else if (statToCheck == "rebounds") {
		
		//Build Heap
		int n = players.size() - 1;
		for (int i = (n / 2) - 1; i >= 0; i--) {
			heapifyRebounds(players, i, n);
		}

		for (int i = n - 1; i > 0; i--) {

			swap(players[0], players[i]);
			heapifyRebounds(players, 0, i);
		}
	}
	else {
		
		cout << "Error in HeapSort Stat to check input, program will automatically sort by PPG" << endl;
		
		//Build Heap
		int n = players.size() - 1;
		for (int i = (n / 2) - 1; i >= 0; i--) {
			heapifyPPG(players, i, n);
		}

		for (int i = n - 1; i > 0; i--) {

			swap(players[0], players[i]);
			heapifyPPG(players, 0, i);
		}
	}
}

//* ===== Helper Functions ===== *//

double getRandom(double min, double max) {

	return (max - min) * ((double)rand() / (double)RAND_MAX) + min;
}

void generateStats(vector<Player>& players, string name) {

	double ppg = getRandom(0.0, 50.4);
	double steals = getRandom(0.0, 3.5);
	double blocks = getRandom(0.0, 4.3);
	double assists = getRandom(0.0, 11.2);
	double rebounds = getRandom(0.0, 22.9);

	Player temp(name, ppg, steals, blocks, assists, rebounds);
	players.push_back(temp);
}

bool searchDatabase(string findName, unordered_map<string, vector<double>>& player_stats) 
{

	if (player_stats.find(findName) == player_stats.end()) {
		cout << endl << "Player name not found in Database, Please try another name to search..." << endl;
		return false;
	}
	else {

		cout << endl << "Name | PPG | Steals | Blocks | Assits | Rebounds" << endl;
		cout << "------------------------------------------------" << endl;
		cout << "Player - " << findName << ": ";
		for (int i = 0; i < player_stats[findName].size(); i++) {
			
			cout << fixed << setprecision(2) << player_stats[findName].at(i);
			if (i != player_stats[findName].size() - 1) {
				cout << ", ";
			}
		}
		cout << endl;
	}
	return true;
}

void readFile(vector<string>& names, string filename) {

	ifstream file;
	string currentRow;

	file.open(filename);

	if (file.is_open()) {

		while (getline(file, currentRow)) {

			istringstream ss(currentRow);
			
			getline(ss, currentRow, '\n');
			names.push_back(currentRow);
		}
	}
	file.close();
}

int main()
{
	vector<string> names; // For reading Names from file 
	vector<Player> players; // For Sorting Algorithms
	vector<Player> copyPlayers; // To Compare Sorting
	unordered_map<string, vector<double>> player_stats; // For instant Access during Search
	vector<double> stats;

	string selection;
	
	readFile(names, "randomNames.txt");
	
	for (int i = 0; i < names.size(); i++) {
		
		generateStats(players, names[i]);
		player_stats[names[i]] = players[i].getStats();
	}

	for (int i = 0; i < players.size(); i++) {

		copyPlayers.push_back(players[i]);
	}


	//* ===== Main User Interface ===== *//
	
	cout << "|| Welcome to the Best Basketball Player [Men & Women] Database Software!!! ||" << endl;
	cout << "|| ***Copyright Pending*** The Reference& Referees LLC, Best Basketball Player Software ||" << endl;
	cout << endl << "Here are your database search options, please select an option to proceed" << endl;
	cout << "- [A] Print All Player Stats" << endl;
	cout << "- [B] Search for a player by name" << endl;
	cout << "- [C] Compare Sorting Algorithms, Print The Top 10 players by Statistic ex. (PPG)" << endl;
	cout << "- [Q] Quit Program" << endl;
	getline(cin, selection);

	while (selection != "Q" && selection != "q") {
		
		string option;
		
		if (selection == "A" || selection == "a") {
			
			cout << endl << "Name | PPG | Steals | Blocks | Assits | Rebounds" << endl;
			cout << "------------------------------------------------" << endl;
			for (int i = 0; i < names.size(); i++) {
				cout << i+1 << ". ";
				players[i].printStats();
			}
		}
		else if (selection == "B" || selection == "b") {
			
			string input;
			bool foundName = false;
			cout << endl << "Please enter a player name to search..." << endl;

			getline(cin, input);

			while (!foundName) {
				
				foundName = searchDatabase(input, player_stats);
				if (!foundName) {

					string newName;
					getline(cin, newName);
					input = newName;
				}
			}
		}
		else if (selection == "C" || selection == "c") {

			string input;
			bool correctInput = false;
			cout << endl << "Please choose a stat to explore sorting algorthim speeds, as well as the top 10 players for that statistic" << endl;
			cout << "- [A] PPG (Points Per Game)" << endl;
			cout << "- [B] Steals" << endl;
			cout << "- [C] Blocks" << endl;
			cout << "- [D] Assists" << endl;
			cout << "- [E] Rebounds" << endl;
			
			getline(cin, input);

			while (!correctInput) {

				string statSelect;

				if (input == "A" || input == "a") {
					
					correctInput = true;

					// Max Heap Sort
					cout << endl << " ----- Heap Sort (PPG) ----- " << endl;
					
					auto start = high_resolution_clock::now();
					HeapSort("ppg", players);
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<microseconds>(stop - start);
					
					cout << endl;
					cout << "Name | PPG | Steals | Blocks | Assits | Rebounds" << endl;
					cout << "------------------------------------------------" << endl;
					for (int i = 0; i < 10; i++) {
						cout << i + 1 << ". ";
						players[i].printStats();
					}
					cout << endl << "Heap Sort Time: " << duration.count() << " microseconds" << endl;

					// Quick Sort
					cout << endl << " ----- Quick Sort (PPG) ----- " << endl;
					
					auto beg = high_resolution_clock::now();
					quickSort("ppg", copyPlayers, 0, copyPlayers.size()-1);
					auto end = high_resolution_clock::now();
					auto time = duration_cast<microseconds>(end - beg);
					
					cout << endl;
					cout << "Name | PPG | Steals | Blocks | Assits | Rebounds" << endl;
					cout << "------------------------------------------------" << endl;
					for (int i = copyPlayers.size()-1; i > copyPlayers.size()-11; i--) {
						cout << copyPlayers.size() - i << ". ";
						copyPlayers[i].printStats();
					}
					cout << endl << "Quick Sort Time: " << time.count() << " microseconds" << endl;

					if (duration.count() > time.count()) {
						cout << endl << "Quick Sort Performed Faster for this Search by " << duration.count() - time.count() << " microseconds" << endl;
					}
					else {
						cout << endl << "Heap Sort Performed Faster for this Search by " << time.count() - duration.count() << " microseconds" << endl;
					}
				}
				else if (input == "B" || input == "b") {
					
					correctInput = true;

					// Max Heap Sort
					cout << endl << " ----- Heap Sort (Steals) ----- " << endl;

					auto start = high_resolution_clock::now();
					HeapSort("steals", players);
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<microseconds>(stop - start);

					cout << endl;
					cout << "Name | PPG | Steals | Blocks | Assits | Rebounds" << endl;
					cout << "------------------------------------------------" << endl;
					for (int i = 0; i < 10; i++) {
						cout << i + 1 << ". ";
						players[i].printStats();
					}
					cout << endl << "Heap Sort Time: " << duration.count() << " microseconds" << endl;

					// Quick Sort
					cout << endl << " ----- Quick Sort (Steals) ----- " << endl;

					auto beg = high_resolution_clock::now();
					quickSort("steals", copyPlayers, 0, copyPlayers.size() - 1);
					auto end = high_resolution_clock::now();
					auto time = duration_cast<microseconds>(end - beg);

					cout << endl;

					cout << "Name | PPG | Steals | Blocks | Assits | Rebounds" << endl;
					cout << "------------------------------------------------" << endl;
					for (int i = copyPlayers.size() - 1; i > copyPlayers.size() - 11; i--) {
						cout << copyPlayers.size() - i << ". ";
						copyPlayers[i].printStats();
					}
					cout << endl << "Quick Sort Time: " << time.count() << " microseconds" << endl;

					if (duration.count() > time.count()) {
						cout << endl << "Quick Sort Performed Faster for this Search by " << duration.count() - time.count() << " microseconds" << endl;
					}
					else {
						cout << endl << "Heap Sort Performed Faster for this Search by " << time.count() - duration.count() << " microseconds" << endl;
					}
					
				}
				else if (input == "C" || input == "c") {
					
					correctInput = true;

					// Max Heap Sort
					cout << endl << " ----- Heap Sort (Blocks) ----- " << endl;
					
					auto start = high_resolution_clock::now();
					HeapSort("blocks", players);
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<microseconds>(stop - start);
					
					cout << endl;

					cout << "Name | PPG | Steals | Blocks | Assits | Rebounds" << endl;
					cout << "------------------------------------------------" << endl;
					for (int i = 0; i < 10; i++) {
						cout << i + 1 << ". ";
						players[i].printStats();
					}
					cout << endl << "Heap Sort Time: " << duration.count() << " microseconds" << endl;

					// Quick Sort
					cout << endl << " ----- Quick Sort (Blocks) ----- " << endl;
					
					auto beg = high_resolution_clock::now();
					quickSort("blocks", copyPlayers, 0, copyPlayers.size() - 1);
					auto end = high_resolution_clock::now();
					auto time = duration_cast<microseconds>(end - beg);

					cout << endl;

					cout << "Name | PPG | Steals | Blocks | Assits | Rebounds" << endl;
					cout << "------------------------------------------------" << endl;
					for (int i = copyPlayers.size() - 1; i > copyPlayers.size() - 11; i--) {
						cout << copyPlayers.size() - i << ". ";
						copyPlayers[i].printStats();
					}
					cout << endl << "Quick Sort Time: " << time.count() << " microseconds" << endl;

					if (duration.count() > time.count()) {
						cout << endl << "Quick Sort Performed Faster for this Search by " << duration.count() - time.count() << " microseconds" << endl;
					}
					else {
						cout << endl << "Heap Sort Performed Faster for this Search by " << time.count() - duration.count() << " microseconds" << endl;
					}
					
				}
				else if (input == "D" || input == "d") {
					
					correctInput = true;

					// Max Heap Sort
					cout << endl << " ----- Heap Sort (Assists) ----- " << endl;

					auto start = high_resolution_clock::now();
					HeapSort("assists", players);
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<microseconds>(stop - start);

					cout << endl;

					cout << "Name | PPG | Steals | Blocks | Assits | Rebounds" << endl;
					cout << "------------------------------------------------" << endl;
					for (int i = 0; i < 10; i++) {
						cout << i + 1 << ". ";
						players[i].printStats();
					}
					cout << endl << "Heap Sort Time: " << duration.count() << " microseconds" << endl;

					// Quick Sort
					cout << endl << " ----- Quick Sort (Assists) ----- " << endl;

					auto beg = high_resolution_clock::now();
					quickSort("assists", copyPlayers, 0, copyPlayers.size() - 1);
					auto end = high_resolution_clock::now();
					auto time = duration_cast<microseconds>(end - beg);

					cout << endl;

					cout << "Name | PPG | Steals | Blocks | Assits | Rebounds" << endl;
					cout << "------------------------------------------------" << endl;
					for (int i = copyPlayers.size() - 1; i > copyPlayers.size() - 11; i--) {
						cout << copyPlayers.size() - i << ". ";
						copyPlayers[i].printStats();
					}
					cout << endl << "Quick Sort Time: " << time.count() << " microseconds" << endl;

					if (duration.count() > time.count()) {
						cout << endl << "Quick Sort Performed Faster for this Search by " << duration.count() - time.count() << " microseconds" << endl;
					}
					else {
						cout << endl << "Heap Sort Performed Faster for this Search by " << time.count() - duration.count() << " microseconds" << endl;
					}
					
				}
				else if (input == "E" || input == "e") {
					
					correctInput = true;

					// Max Heap Sort
					cout << endl << " ----- Heap Sort (Rebounds)----- " << endl;

					auto start = high_resolution_clock::now();
					HeapSort("rebounds", players);
					auto stop = high_resolution_clock::now();
					auto duration = duration_cast<microseconds>(stop - start);

					cout << endl;

					cout << "Name | PPG | Steals | Blocks | Assits | Rebounds" << endl;
					cout << "------------------------------------------------" << endl;
					for (int i = 0; i < 10; i++) {
						cout << i+1 << ". ";
						players[i].printStats();
					}
					cout << endl << "Heap Sort Time: " << duration.count() << " microseconds" << endl;

					// Quick Sort
					cout << endl << " ----- Quick Sort (Rebounds) ----- " << endl;

					auto beg = high_resolution_clock::now();
					quickSort("rebounds", copyPlayers, 0, copyPlayers.size() - 1);
					auto end = high_resolution_clock::now();
					auto time = duration_cast<microseconds>(end - beg);

					cout << endl;

					cout << "Name | PPG | Steals | Blocks | Assits | Rebounds" << endl;
					cout << "------------------------------------------------" << endl;
					for (int i = copyPlayers.size() - 1; i > copyPlayers.size() - 11; i--) {
						cout << copyPlayers.size() - i << ". ";
						copyPlayers[i].printStats();
					}
					cout << endl << "Quick Sort Time: " << time.count() << " microseconds" << endl;

					if (duration.count() > time.count()) {
						cout << endl << "Quick Sort Performed Faster for this Search by " << duration.count() - time.count() << " microseconds" << endl;
					}
					else {
						cout << endl << "Heap Sort Performed Faster for this Search by " << time.count() - duration.count() << " microseconds" << endl;
					}
			
				}
				else {
					
					cout << "Sorry can't process that input, please try again with a proper selection..." << endl;
				}
				if (!correctInput) {
					
					cout << endl << "Please choose a stat to explore sorting algorthim speeds, as well as the top 10 players for that statistic" << endl;
					cout << "- [A] PPG (Points Per Game)" << endl;
					cout << "- [B] Steals" << endl;
					cout << "- [C] Blocks" << endl;
					cout << "- [D] Assists" << endl;
					cout << "- [E] Rebounds" << endl;
					getline(cin, statSelect);
					input = statSelect;
				}
				
			}
			
		} 
		else  {

			cout << "Sorry can't process that input, please try again with a proper selection..." << endl;
		}

		cout << endl << "Here are your database search options, please select another option to proceed" << endl;
		cout << "- [A] Print All Player Stats" << endl;
		cout << "- [B] Search for a player by name" << endl;
		cout << "- [C] Compare Sorting Algorithms, Print The Top 10 players by Statistic ex. (PPG)" << endl;
		cout << "- [Q] Quit Program" << endl;
		
		getline(cin, option);
		selection = option;
	}

	return 0;
}
