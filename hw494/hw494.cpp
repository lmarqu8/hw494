#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <bitset>
#include <cmath>


using namespace std;


int path2distance(const vector<vector<int>> &inputMat, const vector<int> &path, int numCities) {

    int dist = 0;

    for (size_t i = 1; i < numCities; i++)
    {
        dist += inputMat[path[i - 1] - 1][path[i] - 1];
    }
    return dist;
}

bool checkIfVisited(int citiesVisited, int city_ID){
    int a = 1;

    if (city_ID == 1){
        return 1 & citiesVisited;
    }
    else {
        a = a << city_ID;
        return citiesVisited & a;
    }
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
    int numCities
    for (int i = 0; i < ; ++i) {
        if(check)
    }

}

void tsp(vector<vector<int>> inputMat){

    int numCities = inputMat.size();
    int tripCost = 0;
    int visited = 0;
    int allVisited = pow(2, numCities);
    int next;
    vector<int> tour;
    vector<int> bestTour;


    if(numCities == 0){ cout<<"ERROR: empty input vector"<<endl; exit(1);}
    if(numCities == 1){cout<<"ERROR: Only one city"<<endl; exit(1);}
    if(numCities == 2){cout<<"ERROR: Only two cities"<<endl; exit(1);}
    if (numCities != inputMat[0].size()){cout<<"ERROR: Input is not square"<<endl; exit(1);}
    if(numCities > 32){ cout<<"ERROR: Only two cities"<<endl; exit(1);}


    int start = 0;
    for (int i = 0; i < numCities; ++i) {
        visited = 0;
        start = i;
        markBitVisited(visited, start+1);
        tour.clear();
        tour.push_back(i+1);

        //while (visited != b){}

        //tripCost+=inputMat[next][start];

    }





    cout<<"End TSP"<<endl;
}

int main()
{
    std::fstream inputFile;
    inputFile.open("tsp1.txt");
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
    */
    vector<vector<int>> tempVec(inputVec);

    std::vector<int> testPath = { 1,4,3,5,2 };

    int five = 0;
    markBitVisited(five, 1);
    cout<<(five)<<endl;
    cout<<bitset<5>(five)<<endl;
    markBitVisited(five, 2);
    cout<<(five)<<endl;
    cout<<bitset<5>(five)<<endl;
    markBitVisited(five, 3);
    cout<<(five)<<endl;
    cout<<bitset<5>(five)<<endl;
    markBitVisited(five, 4);
    cout<<(five)<<endl;
    cout<<bitset<5>(five)<<endl;
    markBitVisited(five, 5);
    cout<<(five)<<endl;
    cout<<bitset<5>(five)<<endl;




    tsp(inputVec);
    //cout << path2distance(tempVec, testPath, numCities) << endl << "reached end" << endl;

  return 69;
}

