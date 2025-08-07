# Astronaut Fitness Tracker


## What It Does

- Register an astronaut with name, age, and mission duration
- Log daily fitness activities:
  - Exercise hours
  - Calories consumed
  - Oxygen usage (with automatic conversion from minutes to liters)
- View overall fitness summary and averages
- Save astronaut progress to a file and load it later

## Features

- Struct-based astronaut profile
- Menu-driven user interface
- File saving and loading with 'fstream'
- Realistic oxygen usage conversion (0.84 L/min)
- Data aggregation (totals + per-day averages)

## How to Run

1. Clone or download the repo
2. Open the project folder in a C++ IDE or compiler (e.g., VS Code)
3. Compile and run:

```bash
cd astronaut-fitness-tracker
ls  # confirm the .cpp file
g++ astronaut-fitness-tracker.cpp -o astronaut-fitness-tracker
./astronaut-fitness-tracker
