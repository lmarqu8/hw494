#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <bitset>
#include <cmath>


using namespace std;

//Used to check for correct vector input, no used currently
//Takes a the input matrix, a path, and the number of cities.
int path2distance(const vector<vector<int>> &inputMat, const vector<int> &path, int numCities) {

    int dist = 0;
    for (size_t i = 1; i < numCities; i++)
    {
        dist += inputMat[path[i - 1] - 1][path[i] - 1];
    }
    return dist;
}

//Prints the values in the tour vector.
void printTour(vector<int> vec){
    for (auto i: vec)
        std::cout << i << ' ';
}


bool checkIfVisited(int citiesVisited, int city_ID){
    if (citiesVisited & (1 << (city_ID - 1)))
        return true;
    else
        return false;
}

void markBitVisited(int &citiesVisited, int city_ID){
    int a = 1;

    if (!checkIfVisited(citiesVisited, city_ID)){
        if (city_ID == 1){
            citiesVisited+=1;
        }
        else {
            a = a << (city_ID-1);
            citiesVisited = citiesVisited | a;
        }
    }
}

int find_next(int currentCity, int visited, vector<vector<int>> inputMap){
    int numCities = inputMap.size();
    int nextCity = 0;
    int shortestDist = INT_MAX;

    for (int i = 1; i < numCities+1; ++i) {
        if(!checkIfVisited(visited, i)){
            if(shortestDist > inputMap[currentCity-1][i-1] && inputMap[currentCity-1][i-1] != 0){
                shortestDist = inputMap[currentCity-1][i-1];
                nextCity = i;
            }
        }
    }

    return nextCity;

}

void tsp(vector<vector<int>> inputMat){

    int numCities = inputMat.size();
    int tripCost = 0;
    int bestCost = INT_MAX;
    int visited = 0;
    int allVisited = pow(2, numCities) - 1;
    int next = 0;
    int start;
    vector<int> tour;
    vector<int> bestTour;


    if(numCities == 0){ cout<<"ERROR: empty input vector"<<endl; exit(1);}
    if(numCities == 1){cout<<"ERROR: Only one city"<<endl; exit(1);}
    if(numCities == 2){cout<<"ERROR: Only two cities"<<endl; exit(1);}
    if (numCities != inputMat[0].size()){cout<<"ERROR: Input is not square"<<endl; exit(1);}
    if(numCities > 32){ cout<<"ERROR: Only two cities"<<endl; exit(1);}

    cout<<"end value is: " << allVisited << endl;


    for (int i = 1; i < numCities+1; ++i) {
        visited = 0;
        tripCost = 0;
        tour.clear();

        start = i;
        markBitVisited(visited, start);
        tour.push_back(start);
        //cout<<"at: " << tour.back()<< " cost: "<< tripCost <<" -> ";
        while (visited != allVisited){

            if (tripCost > bestCost){
                cout << "Finished before end" << endl;
                break;}
            next = find_next(tour.back(), visited, inputMat);
            tripCost+=inputMat[next-1][tour.back()-1];
            tour.push_back(next);
            markBitVisited(visited,next);
            //cout<<"at: " << tour.back()<< " cost: "<< tripCost << " -> ";
        }
        //should have visited all cities
        tour.push_back(i);
        tripCost+=inputMat[start-1][next-1];
        //cout<<"at: " << tour.back()<< " total: "<< tripCost << " tally: " << bitset<5>(visited) << " END COST: " << tripCost << endl;
        if (tripCost < bestCost){
            bestCost = tripCost;
            bestTour = tour;
        }


    }

    cout<<"The best tour is: ";
    printTour(bestTour);
    cout<< "with distance: " << bestCost << endl;
    cout<<"End TSP"<<endl;
}

int main()
{
    std::fstream inputFile;
    inputFile.open("tsp2.txt");
=======

    inputFile.open("r30_1.txt");
    int numCities = 0;
    vector<vector<int>> inputVec;
    int countA = 0;
    string temp;
    
    if (inputFile.is_open()) {
        //cout<<"file is open" << endl;
        string numCitiesC;
        getline(inputFile, numCitiesC);

        numCities = stoi(numCitiesC);

        while (getline(inputFile, temp)) {
            
            std::stringstream stream(temp);
            inputVec.emplace_back();
            while (true) {
                int n;
                stream >> n;
                if (!stream)
                    break;

                inputVec[countA].push_back(n);

            }
            countA += 1;
        }

    }
    else cout<<"file not opened" << endl;
    inputFile.close();

    /*
     for (size_t i = 0; i < numCities; i++)
    {
        for (size_t j = 0; j < numCities; j++)
        {
            cout << inputVec[i][j] << " ";
        }
        cout << endl;
    }

    int one = 0;
    markBitVisited(one, 1);
    markBitVisited(one, 3);
    markBitVisited(one, 5);
    cout << one << " " << bitset<5>(one) << endl;
    cout << checkIfVisited(one, 1) << " " << checkIfVisited(one, 2) << endl;
    */
    tsp(inputVec);

  return 69;
}

