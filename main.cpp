#include <iostream>
#include <string>
#include <vector>

struct Location{
    std::string name;
    std::string latitude;
    std::string longitude;
};

std::vector<Location> readInput(){

    std::string input;

    std::vector<Location> locations;

    while(true){
        getline(std::cin, input);

        if(input == "."){
            break;
        }

        Location currentLocation;

        std::string current;

        int counter = 0;

        for (size_t i = 0; i < input.size(); ++i) {

            if(input[i] == ','){

                counter++;

                if(counter == 1){
                    currentLocation.name = current;
                }
                else if(counter == 2){
                    currentLocation.latitude = current;
                }
                else if(counter == 3){

                }

                current = "";
            }
            else {
                current += input[i];
            }
        }

        currentLocation.longitude = current;
        locations.push_back(currentLocation);
    }

    return locations;
}

std::string parameterName(const std::string& outputData){

    std::string town = outputData;

    return town;
}

void selectWords(const std::string& outputData, std::string& latitudeStr, std::string& longitudeStr){

    int selectDelimeter = 0;

    for (size_t i = 0; i < outputData.size(); ++i) {

        if(outputData[i] == ' '){
            selectDelimeter++;
            break;
        }
        else {
            selectDelimeter++;
            latitudeStr += outputData[i];
        }
    }

    for (size_t i = selectDelimeter; i < outputData.size(); ++i) {
        longitudeStr += outputData[i];
    }
}

int wordsCounter(const std::string& outputData){

    int counter = 1;

    std::string word;

    for (size_t i = 0; i < outputData.size(); ++i) {

        if(outputData[i] == ' '){
            counter = 2;
            return counter;
        }
    }

    return counter;
}

void printLocations(std::vector<Location>& locations){

    while(true){

        std::string outputData;
        std::getline(std::cin, outputData);

        if(outputData == "."){
            break;
        }

        int counter = wordsCounter(outputData);

        std::string data;

        if(counter == 1){
            data = parameterName(outputData);
            for (const auto& current : locations) {

                if(data == current.name){
                    std::cout << current.name << "," << current.latitude << "," << current.longitude << std::endl;
                }
            }
        }
        else if(counter == 2){

            std::string latitudeStr;
            std::string longitudeStr;

            selectWords(outputData, latitudeStr, longitudeStr);

            for (const auto& current : locations) {

                if(latitudeStr == current.latitude || longitudeStr == current.longitude){
                    std::cout << current.name << "," << current.latitude << "," << current.longitude << std::endl;
                }
            }
        }
    }
}

int main(){

    std::vector<Location> locations = readInput();

    printLocations(locations);

    return 0;
}

/*
Sofia,42.70,23.33
New York,40.6976701,-74.2598732
SoftUni,42.70,23.33
.
Sofia
40.6976701 -74.2598732
42.70 23.33
.
 */