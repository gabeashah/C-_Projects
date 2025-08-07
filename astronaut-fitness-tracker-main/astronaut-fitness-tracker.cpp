#include <iostream>
#include <string>
#include <fstream>

float convertToLiters(float minutes); // function prototype to convert minutes to liters

struct Astronaut {
    std::string name;
    int age;
    int mission_duration; // in days
    
    float total_exercise_hours_per_day = 0.0; //average amount of time spent exercising per day
    int total_amount_of_calories_burned = 0; //average amount of calories burned per day
    float oxygen_consumption = 0.0; //average amount of oxygen consumed per day
    int total_logsRecorded = 0; //total amount of logs recorded
    

};
    float convertToLiters(float minutes){
        const float Liters_per_min = 0.84; // average oxygen consumption in liters per minute
        return minutes * Liters_per_min; // converts minutes to liters
    };

    void logDailyStats(Astronaut & astro) { 
        float exercise;
        int calories;
        float oxygenMinutes;
        std::cout << "\n--- Log Daily Fitness ---\n"; // function to log daily fitness stats
        std::cout << "Hours of exercise today: "; //asks for amoutn of hours of exercise
        std::cin >> exercise; //reads the amount of hours of exercise
        
        std::cout << "Calories burned today: "; //asks for amount of calories burned
        std::cin >> calories; //reads the amount of calories burned
        
        std::cout << "Amount of oxygen consumed today (minutes): "; //asks for amount of oxygen consumed
        std::cin >> oxygenMinutes; //reads the amount of oxygen consumed

        float oxygenLiters = convertToLiters(oxygenMinutes);
        std::cout << "Converted: " << oxygenLiters << " liters of oxygen consumed today.\n"; //shows the amount of oxygen consumed in liters 

        
        astro.total_exercise_hours_per_day += exercise; // adds the amount of exercise to the total exercise hours
        astro.total_amount_of_calories_burned += calories; // adds the amount of calories burned to the total calories burned
        astro.oxygen_consumption += oxygenLiters; // adds the amount of oxygen consumed to the total oxygen consumption

        astro.total_logsRecorded ++; //increments the total logs recorded by 1
    }

    void showSummary(const Astronaut & astro) {
        std::cout << "\n--- Summary for " << astro.name << " ---\n"; 
        std::cout <<  "Logs recorded " << astro.total_logsRecorded << "\n"; //shows the total amount of logs recorded

        if (astro.total_logsRecorded > 0) { 
            std::cout << "Average Oxygen Consumption: " 
                      << astro.oxygen_consumption / astro.total_logsRecorded << "L/day\n"; 


        }
    }

    void saveToFile (const Astronaut & astro) {
        std::ofstream outFile("astronaut_data.txt");
        if (!outFile) {
            std::cerr << "Error opening file for writing.\n"; // if the file cannot be opened, it shows an error message
            return; // exits the function if the file cannot be opened
    }
    
        outFile << astro.name << "\n"
                << astro.age << "\n"
                << astro.mission_duration << "\n"
                << astro.total_exercise_hours_per_day << "\n"
                << astro.total_amount_of_calories_burned << "\n"
                << astro.oxygen_consumption << "\n"
                << astro.total_logsRecorded << "\n";
        std::cout << "Data saved to astronaut_data.txt\n"; //confirms that the data has been saved to a file
        outFile.close(); //closes the file
    }   
    
        bool loadFromFile(Astronaut & astro) {
        std::ifstream inFile("astronaut_data.txt");
        if (!inFile) {
            std::cout << "no previous save found.\n"; // if the file does not exist, it shows a message
            return false; // returns false if the file does not exist
        }
        std::getline(inFile, astro.name);
        inFile >> astro.age;
        inFile >> astro.mission_duration;
        inFile >> astro.total_exercise_hours_per_day;
        inFile >> astro.total_amount_of_calories_burned;
        inFile >> astro.oxygen_consumption;
        inFile >> astro.total_logsRecorded;

        std::cout << "Data loaded for astronaut " << astro.name << " .\n"; // confirms that the data has been loaded
        inFile.close(); // closes the file
        return true; // returns true if the file exists and the data has been loaded
    }

int main(){
    Astronaut astro;
    std::cout << "Welcome to the Astronaut Fitness Tracker \n"; // Welcomes the user
    std::cout << "Please enter the astronaut's name: \n"; // Asks for the astronaut's name
    std::getline(std::cin, astro.name); // it reads the asutronaut's name from the input

    std::cout << "Please enter the astronaut's age: \n"; // Asks for the astronaut's name
    std:: cin >> astro.age; // it reads the astronaut's age from the input

    std::cout << "Please enter the amount of days the astronaut has been on the mission: \n"; // This asks for the amount of days in integer form how long the astronaut has been on a mission
    std::cin >>astro.mission_duration; // reads the amount of days the astronaut has been on mission
    std::cin.ignore(); // clears the input buffer to avoid issues with getline after cin
    
    std::cout << "\nAstronaut " << astro.name << " has been registered succesfully!\n"; //confirms that astronaut has been registered
    
    int choice;
    do { 
        std::cout << "\n--- Main Menu ---\n"; //shows the main menu
        std::cout << "1. Log daily fitness\n";
        std::cout << "2. Show summary\n";
        std::cout << "3. Save to file\n";
        std::cout << "4. Load from file\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: "; //asks for the user's choice
        std::cin >> choice; //reads the user's choice

        
        std::cin >> choice;

    // Check for non-integer input
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error state
            std::cin.ignore(1000, '\n'); // Discard the bad input
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                logDailyStats(astro); //calls the function to log daily fitness stats
                break;
            case 2: 
            showSummary(astro); //calls the function to show summary
                break;
            case 3: 
                saveToFile(astro); //calls the function to save the astronaut data to a file
                break;
            case 4:
                loadFromFile(astro); //calls the function to load the astronaut data from a file
                break;
            case 5:
                std::cout << "Exiting the program. Goodbye!\n"; //exits the program
                break;
            default:
            std::cout << "Invalid Option. Try again \n";

        }
    
    } while (choice != 5); //continues to show the main menu until the user chooses to exit
    
    return 0;

}
