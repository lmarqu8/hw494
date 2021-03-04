#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>      


using namespace std;

class Routes {
public:

    vector<int> path;
    int distance = 0;

};

int path2distance(const vector<vector<int>> &inputMat, const vector<int> &path, int numCities) {

    int dist = 0;

    for (size_t i = 1; i < numCities; i++)
    {
        dist += inputMat[path[i - 1] - 1][path[i] - 1];
    }

    return dist;
}

int main()
{
    std::fstream inputFile;
    inputFile.open("tsp1.txt", std::ios::in);
    int numCities = 0;
    vector<vector<int>> inputVec;
    int countA = 0;
    int countB = 0;
    string temp;
    
    if (inputFile.is_open()) {
        string numCitiesC;
        getline(inputFile, numCitiesC);

        numCities = stoi(numCitiesC);

        while (getline(inputFile, temp)) {
            
            std::stringstream stream(temp);
            inputVec.push_back(std::vector<int>());
            while (1) {
                int n;
                stream >> n;
                if (!stream)
                    break;

                inputVec[countA].push_back(n);

            }
            countB = 0;
            countA += 1;
        }

    }
    inputFile.close();

    /*
    for (size_t i = 0; i < numCities; i++)
    {
        for (size_t j = 0; j < numCities; j++)
        {
            cout << inputVec[i][j] << " ";
        }
        cout << endl;
    } */
    
    vector<vector<int>> tempVec(inputVec);

    vector<int> testPath = { 1,4,3,5,2 };

    cout << path2distance(tempVec, testPath, numCities) << endl;
  
}

